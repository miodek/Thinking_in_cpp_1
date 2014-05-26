//: C12:CopyingWithPointers.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Rozwiazanie problemu utozsamiania wskaznikow
// za pomoca kopiowania wskazywanych przez nie
// obszarow podczas przypisania i wywolania
// konstruktora kopiujacego
#include "../require.h"
#include <string>
#include <iostream>
using namespace std;

class Dog {
  string nm;
public:
  Dog(const string& name) : nm(name) {
    cout << "Tworzenie psa: " << *this << endl;
  }
  // Utworzony przez kompilator konstruktor kopiujacy
  // i operator= sa prawidlowe
  // Utworzenie obiektu klasy Dog na podstawie wskaznika:
  Dog(const Dog* dp, const string& msg) 
    : nm(dp->nm + msg) {
    cout << "Pies " << *this << " skopiowany z "
         << *dp << endl;
  }
  ~Dog() { 
    cout << "Usuniety pies: " << *this << endl;
  }
  void rename(const string& newName) {
    nm = newName;
    cout << "Pies zmienil imie na: " << *this << endl;
  }
  friend ostream&
  operator<<(ostream& os, const Dog& d) {
    return os << "[" << d.nm << "]";
  }
};

class DogHouse {
  Dog* p;
  string houseName;
public:
  DogHouse(Dog* dog, const string& house)
   : p(dog), houseName(house) {}
  DogHouse(const DogHouse& dh)
    : p(new Dog(dh.p, " skopiowany konstruktorem")),
      houseName(dh.houseName 
        + " skopiowany konstruktorem") {}
  DogHouse& operator=(const DogHouse& dh) {
    // Sprawdzanie przypisania do samego siebie:
    if(&dh != this) {
      p = new Dog(dh.p, " przypisany");
      houseName = dh.houseName + " przypisany";
    }
    return *this;
  }
  void renameHouse(const string& newName) {
    houseName = newName;
  }
  Dog* getDog() const { return p; }
  ~DogHouse() { delete p; }
  friend ostream&
  operator<<(ostream& os, const DogHouse& dh) {
    return os << "[" << dh.houseName 
      << "] zawiera " << *dh.p;
  }
}; 

int main() {
  DogHouse fafika(new Dog("Fafik"), "DomekFafika");
  cout << fafika << endl;
  DogHouse fafika2 = fafika; // Uzycie konstruktora kopiujacego
  cout << fafika2 << endl;
  fafika2.getDog()->rename("Burek");
  fafika2.renameHouse("DomekBurka");
  cout << fafika2 << endl;
  fafika = fafika2; // Przypisanie
  cout << fafika << endl;
  fafika.getDog()->rename("Reks");
  fafika2.renameHouse("DomekReksa");
} ///:~
