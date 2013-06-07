#include <iostream>
#include <string>
#include <vector>

#include "source.cpp"

int main(int argc, char *argv[]) {
  JSON json("Contact Information");
  json.PushChildNode(new KeyValueNode("firstName", "John"));
  json.PushChildNode(new KeyValueNode("lastName", "Smith"));
  json.PushChildNode(new KeyValueNode("age", "25"));

  JSON* j = new JSON("address");
  j->PushChildNode(new KeyValueNode("streetAddress", "21 2nd Street"));
  j->PushChildNode(new KeyValueNode("city", "New York"));
  j->PushChildNode(new KeyValueNode("state", "NY"));
  j->PushChildNode(new KeyValueNode("postalCode", "10021"));

  json.PushChildNode(j);

  std::cout << "{" + json.Serialize() + "}" << std::endl;
  return 0;
}
