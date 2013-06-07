using std::string;
using std::vector;

class JSONNode {
 public:
  JSONNode(const string& key);
  virtual ~JSONNode();

  virtual string Serialize() = 0;

 protected:
  string key_;
};

class KeyValueNode : public JSONNode {
 public:
  KeyValueNode(const string& key, const string& value); 
  virtual string Serialize();

 private:
  string value_;
};

class JSON : public JSONNode {
 public:
  JSON(const string& key);
  virtual ~JSON();
  virtual string Serialize();
  // This class should owns the pushed childNode, which means that the
  // desctructor should delete them.
  void PushChildNode(JSONNode* childNode);

 private:
  vector<JSONNode*> childNodes_;
};

JSONNode::JSONNode(const string& key) : key_(key) {}

JSONNode::~JSONNode() {}

KeyValueNode::KeyValueNode(const string& key, const string& value)
    : JSONNode(key), value_(value) {
}

string KeyValueNode::Serialize() {
  return "\"" + key_ + "\"" + ":" + "\"" + value_ + "\"";
}

JSON::JSON(const string& key) : JSONNode(key) {}

JSON::~JSON() {
  for (int i = 0; i < childNodes_.size(); i++) {
    delete childNodes_[i];
  }
}

string JSON::Serialize() {
  string re;
  re += ("\"" + key_ + "\":");
  re += "{";
  for (int i = 0; i < childNodes_.size(); i++) {
    re += childNodes_[i]->Serialize();
    if (i != childNodes_.size() - 1)
      re += ",";
  }
  re += "}";
  return re;
}

void JSON::PushChildNode(JSONNode* childNode) {
  childNodes_.push_back(childNode);
}
