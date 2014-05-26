//: C15:VariantReturn.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zwracanie wskaznika lub referencji
// do typu pochodnego w czasie zaslaniania
#include <iostream>
#include <string>
using namespace std;

class PetFood {
public:
  virtual string foodType() const = 0;
};

class Pet {
public:
  virtual string type() const = 0;
  virtual PetFood* eats() = 0;
};

class Bird : public Pet {
public:
  string type() const { return "Ptak"; }
  class BirdFood : public PetFood {
  public:
    string foodType() const { 
      return "nasiona"; 
    }
  };
  // Rzutowanie w gore do typu podstawowego:
  PetFood* eats() { return &bf; }
private:
  BirdFood bf;
};

class Cat : public Pet {
public:
  string type() const { return "Kot"; }
  class CatFood : public PetFood {
  public:
    string foodType() const { return "ptaki"; }
  };
  // Zwracany jest dokladny typ:
  CatFood* eats() { return &cf; }
private:
  CatFood cf;
};

int main() {
  Bird b; 
  Cat c;
  Pet* p[] = { &b, &c, };
  for(int i = 0; i < sizeof p / sizeof *p; i++)
    cout << p[i]->type() << " je "
         << p[i]->eats()->foodType() << endl;
  // Funkcja moze zwrocic dokladny typ:
  Cat::CatFood* cf = c.eats();
  Bird::BirdFood* bf;
  // Funkcja nie moze zwrocic dokladnego typu:
//!  bf = b.eats();
  // Trzeba rzutowac w dol:
  bf = dynamic_cast<Bird::BirdFood*>(b.eats());
} ///:~
