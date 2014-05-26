//: C12:SmartPointer.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
#include <vector>
#include "../require.h"
using namespace std;

class Obj {
  static int i, j;
public:
  void f() const { cout << i++ << endl; }
  void g() const { cout << j++ << endl; }
};

// Definicje skladowych statycznych:
int Obj::i = 47;
int Obj::j = 11;

// Kontener:
class ObjContainer {
  vector<Obj*> a;
public:
  void add(Obj* obj) { a.push_back(obj); }
  friend class SmartPointer;
};

class SmartPointer {
  ObjContainer& oc;
  int index;
public:
  SmartPointer(ObjContainer& objc) : oc(objc) {
    index = 0;
  }
  // Zwracana wartosc sygnalizuje koniec listy:
  bool operator++() { // Przedrostek
    if(index >= oc.a.size()) return false;
    if(oc.a[++index] == 0) return false;
    return true;
  }
  bool operator++(int) { // Przyrostek
    return operator++(); // Uzycie wersji przedrostkowej
  }
  Obj* operator->() const {
    require(oc.a[index] != 0, "SmartPointer::operator->() "
      "zwrocil wartosc zerowa");
    return oc.a[index];
  }
};

int main() {
  const int sz = 10;
  Obj o[sz];
  ObjContainer oc;
  for(int i = 0; i < sz; i++)
    oc.add(&o[i]); // Wypelnianie kontenera
  SmartPointer sp(oc); // Utworzenie iteratora
  do {
    sp->f(); // Wywolanie operatora wyluskania wskaznika
    sp->g();
  } while(sp++);
} ///:~
