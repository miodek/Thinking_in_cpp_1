//: C15:NameHiding2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Funkcje wirtualne ograniczaja przeciazanie
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  virtual int f() const { 
    cout << "Base::f()\n"; 
    return 1; 
  }
  virtual void f(string) const {}
  virtual void g() const {}
};

class Derived1 : public Base {
public:
  void g() const {}
};

class Derived2 : public Base {
public:
  // Przeciazenie funkcji wirtualnej:
  int f() const { 
    cout << "Derived2::f()\n"; 
    return 2;
  }
};

class Derived3 : public Base {
public:
  // Nie mozna zmieniac typu zwracanej wartosci:
  //! void f() const{ cout << "Derived3::f()\n";}
};

class Derived4 : public Base {
public:
  // Zmiana listy argumentow:
  int f(int) const { 
    cout << "Derived4::f()\n"; 
    return 4; 
  }
};

int main() {
  string s("czesc");
  Derived1 d1;
  int x = d1.f();
  d1.f(s);
  Derived2 d2;
  x = d2.f();
//!  d2.f(s); // Wersja dla lancuchow zostala ukryta
  Derived4 d4;
  x = d4.f(1);
//!  x = d4.f(); // Wersja f() zostala ukryta
//!  d4.f(s); // Wersja dla lancuchow zostala ukryta
  Base& br = d4; // Rzutowanie w gore
//!  br.f(1); // Wersja z klasy pochodnej nie jest dostepna
  br.f(); // Dostepna wersja z klasy podstawowej
  br.f(s); // Dostepna wersja z klasy podstawowej
} ///:~
