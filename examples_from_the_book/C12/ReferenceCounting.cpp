//: C12:ReferenceCounting.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zliczanie odwolan, kopiowanie przy zapisie
#include "../require.h"
#include <string>
#include <iostream>
using namespace std;

class Dog {
  string nm;
  int refcount;
  Dog(const string& name) 
    : nm(name), refcount(1) {
    cout << "Tworzenie psa: " << *this << endl;
  }
  // Zablokowanie operacji przypisania:
  Dog& operator=(const Dog& rv);
public:
  // Obiekty klasy Dog moga zostac utworzone tylko na stercie:
  static Dog* make(const string& name) {
    return new Dog(name);
  }
  Dog(const Dog& d) 
    : nm(d.nm + " kopia"), refcount(1) {
    cout << "Konstruktor kopiujacy psa: " 
         << *this << endl;
  }
  ~Dog() { 
    cout << "Usuwanie psa: " << *this << endl;
  }
  void attach() { 
    ++refcount;
    cout << "Pies dolaczony: " << *this << endl;
  }
  void detach() {
    require(refcount != 0);
    cout << "Odlaczanie psa: " << *this << endl;
    // Niszczenie obiektu w przypadku, gdy nikt go nie uzywa:
    if(--refcount == 0) delete this;
  }
  // Warunkowe kopiowanie obiektu klasy Dog.
  // Nalezy je wywolac przed modyfikacja obiektu 
  // klasy Dog i przypisac uzyskany wskaznik do
  // wlasnego wskaznika obiektu klasy Dog.
  Dog* unalias() {
    cout << "Usuwanie polaczenia psa: " << *this << endl;
    // Jezeli nie ma odwolan, to kopiowanie nie jest realizowane:
    if(refcount == 1) return this;
    --refcount;
    // Uzycie konstruktora kopiujacego w celu utworzenia kopii:
    return new Dog(*this);
  }
  void rename(const string& newName) {
    nm = newName;
    cout << "Zmiana imienia psa na: " << *this << endl;
  }
  friend ostream&
  operator<<(ostream& os, const Dog& d) {
    return os << "[" << d.nm << "], rc = " 
      << d.refcount;
  }
};

class DogHouse {
  Dog* p;
  string houseName;
public:
  DogHouse(Dog* dog, const string& house)
   : p(dog), houseName(house) {
    cout << "Utworzono domek: "<< *this << endl;
  }
  DogHouse(const DogHouse& dh)
    : p(dh.p),
      houseName("skopiowany konstruktorem " + 
        dh.houseName) {
    p->attach();
    cout << "Konstruktor kopiowania DogHouse: "
         << *this << endl;
  }
  DogHouse& operator=(const DogHouse& dh) {
    // Sprawdzanie przypisania do samego siebie:
    if(&dh != this) {
      houseName = dh.houseName + " przypisany";
      // Usuniecie poprzedniej wartosci:
      p->detach();
      p = dh.p; // Podobnie jak w konstruktorze kopiujacym
      p->attach();
    }
    cout << "operator= klasy DogHouse: "
         << *this << endl;
    return *this;
  }
  // Zmniejszenie licznika odwolan i warunkowe zniszczenie
  ~DogHouse() {
    cout << "Destruktor klasy DogHouse: " 
         << *this << endl;
    p->detach(); 
  }
  void renameHouse(const string& newName) {
    houseName = newName;
  }
  void unalias() { p = p->unalias(); }
  // Kopiowanie przy zapisie. Za kazdym razem, gdy
  // modyfikowany jest wskazywany obiekt, trzeba go
  // najpierw "odlaczyc":
  void renameDog(const string& newName) {
    unalias();
    p->rename(newName);
  }
  // ...takze w przypadku udostepniania obiektu:
  Dog* getDog() {
    unalias();
    return p; 
  }
  friend ostream&
  operator<<(ostream& os, const DogHouse& dh) {
    return os << "[" << dh.houseName 
      << "] zawiera " << *dh.p;
  }
}; 

int main() {
  DogHouse 
    fafika(Dog::make("Fafik"), "DomekFafika"),
    burka(Dog::make("Burek"), "DomekBurka");
  cout << "Przed uruchomieniem konstruktora kopiujacego" << endl;
  DogHouse reksa(fafika);
  cout << "Po utworzeniu reksa za pomoca konstruktora kopiujacego" << endl;
  cout << "fafika:" << fafika << endl;
  cout << "burka:" << burka << endl;
  cout << "reksa:" << reksa << endl;
  cout << "Przed przypisaniem burka = fafika" << endl;
  burka = fafika;
  cout << "Po przypisaniu burka = fafika" << endl;
  cout << "burka:" << burka << endl;
  cout << "Rozpoczecie kopiowania do samego siebie" << endl;
  reksa = reksa;
  cout << "Po zakonczeniu kopiowania do samego siebie" << endl;
  cout << "reksa:" << reksa << endl;
  // Zaznacz ponizsze wiersze jako komentarze:
  cout << "Przed wywolaniem funkcji rename(\"Reks\")" << endl;
  reksa.getDog()->rename("Reks");
  cout << "Po wywolaniu funkcji rename(\"Reks\")" << endl;
} ///:~
