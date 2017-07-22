#include "Queue/Queue.h"
#include "Queue/Queue.cpp"
#include <iostream>
#include <string>
#include <typeinfo>
#include <regex>
using namespace std;

class Animal {
  public:
  Animal(const string &name) {
    this->name = name;
  }

  string& getName() {
    return this->name;
  }

  virtual void f() {} // At least one virtual function is required!

  private:
  string name;
};

class Dog: public Animal {
  public:
  Dog(const string &name): Animal(name) {}
};

class Cat: public Animal {
  public:
  Cat(const string &name): Animal(name) {}
};

void passAnimal(Animal*);

class Shelter {
  
  Queue<Dog*> dogs;
  Queue<Cat*> cats;

  public:
  void take(Animal *animal) {
    string animalType = typeid(*animal).name();

    if (animalType.find("Dog") != string::npos) {
      Dog *dog = static_cast<Dog*>(animal);
      dogs.add(dog);
    } else {
      Cat *cat = static_cast<Cat*>(animal);
      cats.add(cat);
    }
  }

  Animal* give(const string &type) {
    if (!dogs.empty() && type == "Dog") {
      Dog *dog = dogs.peek();
      dogs.remove();
      return dog;
    }
      
    if (!cats.empty() && type == "Cat") {
      Cat *cat = cats.peek();
      cats.remove();
      return cat;
    }

    return NULL;
  }
};

int main() {
  Animal *dog = new Dog("Mickey");
  Animal *cat = new Cat("Mifi");

  Shelter shelter;

  shelter.take(dog);
  shelter.take(cat);

  Dog *d = static_cast<Dog*>(shelter.give("Dog"));
  if (d != NULL)
    cout << d->getName() << " Adopted :)" << endl;

  Cat *c = static_cast<Cat*>(shelter.give("Cat"));
    if (c != NULL)
      cout << c->getName() << " Adopted :)" << endl;

  return 0;
}
