#include "../Queue2/Queue.cpp"
#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
  Animal() {}
  std::string getType() const {
    return this->type;
  }

  friend std::ostream& operator<<(std::ostream& stream, const Animal &animal){
    stream << animal.getType();
    return stream;
  }

protected:
  std::string type;
};

class Dog: public Animal {
public:
  // Dog(): Animal() { // implicit call to super-constructor
  Dog() {
    this->type = "Dog";
  }
};

class Cat: public Animal {
public:
  Cat() {
    this->type = "Cat";
  }
};

class Shelter {
public:
  Shelter() {}

  void add(const Animal &animal) {
    queue.add(animal);
    std::cout << "Added a: " << animal.getType() << std::endl;
  }

  Animal dequeueAny() {
    Animal animal = queue.peek();
    queue.remove();
    return animal;
  }

  Dog dequeueDog() {
    Queue<Animal> tmp;
    
    while (queue.peek().getType() != "Dog") {
      tmp.add(queue.peek());
      queue.remove();
    }

    Animal animal = queue.peek();
    Dog *dog = static_cast<Dog*>(&animal);
    queue.remove();

    if (!tmp.isEmpty()) {
      tmp.append(queue);
      queue = tmp;
    }

    return *dog;
  }

  Cat dequeueCat() {
    Queue<Animal> tmp;
    
    while (queue.peek().getType() != "Cat") {
      tmp.add(queue.peek());
      queue.remove();
    }

    Animal animal = queue.peek();
    Cat *cat = static_cast<Cat*>(&animal);
    queue.remove();

    if (!tmp.isEmpty()) {
      tmp.append(queue);
      queue = tmp;
    }

    return *cat;
  }

  void showAnimals() {
    this->queue.print();
  }

private:
  Queue<Animal> queue;
};


int main() {
  Shelter shelter;

  static const Animal arr[] = { Dog(), Cat(), Dog(), Cat() };
  std::vector<Animal> animals (arr, arr + sizeof(arr) / sizeof(arr[0]));

  while (!animals.empty()) {
    shelter.add(animals.back());
    animals.pop_back();
  }

  shelter.showAnimals();

  Animal animal = shelter.dequeueAny();
  std::cout << "Delivering a: " << animal.getType() << std::endl;
  Cat cat = shelter.dequeueCat();
  std::cout << "Delivering a: " << cat.getType() << std::endl;

  shelter.showAnimals();

  return 0;
}
