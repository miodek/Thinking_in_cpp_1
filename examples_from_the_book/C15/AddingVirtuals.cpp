//: C15:AddingVirtuals.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dodawanie funkcji wirtualnych podczas dziedziczenia
#include <iostream>
#include <string>
using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() const { return pname; }
  virtual string speak() const { return ""; }
};

class Dog : public Pet {
  string name;
public:
  Dog(const string& petName) : Pet(petName) {}
  // Nowa wirtualna funkcja w klasie Dog:
  virtual string sit() const {
    return Pet::name() + " siedzi";
  }
  string speak() const { // Zasloniecie
    return Pet::name() + " mowi 'Hau!'";
  }
};

int main() {
  Pet* p[] = {new Pet("zwyczajny"),new Dog("bob")};
  cout << "p[0]->speak() = "
       << p[0]->speak() << endl;
  cout << "p[1]->speak() = "
       << p[1]->speak() << endl;
//! cout << "p[1]->sit() = "
//!      << p[1]->sit() << endl; // Niedozwolone
} ///:~
