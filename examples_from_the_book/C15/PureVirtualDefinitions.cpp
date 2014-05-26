//: C15:PureVirtualDefinitions.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Definicje czysto wirtualnych funkcji
// klasy podstawowej
#include <iostream>
using namespace std;

class Pet {
public:
  virtual void speak() const = 0;
  virtual void eat() const = 0;
  // Czysto wirtualna funkcja nie moze byc funkcja inline:
  //!  virtual void sleep() const = 0 {}
};

// W porzadku, funkcja nie jest zdefiniowana jako funkcja inline
void Pet::eat() const {
  cout << "Pet::eat()" << endl;
}

void Pet::speak() const { 
  cout << "Pet::speak()" << endl;
}

class Dog : public Pet {
public:
  // Wykorzystanie wspolnego kodu klasy Pet:
  void speak() const { Pet::speak(); }
  void eat() const { Pet::eat(); }
};

int main() {
  Dog simba;  // Pies Richarda
  simba.speak();
  simba.eat();
} ///:~
