namespace sysu {

class Student {
 public:
  Student(int id, const std::string& name, int age = 18);

  void setID(const int id);
  int getID() const;
  void setName(const std::string& name);
  const std::string& getName() const;
  void setAge(const int age);
  int getAge() const;

 public:
  int id_;
  std::string name_;
  int age_;
};

} // namespace sysu

namespace sysu {

Student::Student(int id, const std::string& name, int age)
    : id_(id), name_(name), age_(age) {}

void Student::setID(const int id) {
  id_ = id;
}

int Student::getID() const {
  return id_;
}

void Student::setName(const std::string& name) {
  name_ = name;
}

const std::string& Student::getName() const {
  return name_;
}

void Student::setAge(const int age) {
  age_ = age;
}

int Student::getAge() const {
  return age_;
}

} // namespace sysu
