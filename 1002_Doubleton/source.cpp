Doubleton* Doubleton::instances[2] = {NULL, NULL};
int Doubleton::counter = 0;

Doubleton::Doubleton(int id) : id_(id) {}

// static
Doubleton* Doubleton::getInstance() {
  int index = counter % 2;
  if (instances[index] == NULL)
    instances[index] = new Doubleton(index);

  counter++;
  return instances[index];
}

// static
void Doubleton::deleteInstances() {
  if (instances[0]) {
    delete instances[0];
    instances[0] = NULL;
  }
  if (instances[1]) {
    delete instances[1];
    instances[1] = NULL;
  }
}
