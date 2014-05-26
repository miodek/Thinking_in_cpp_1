//: C13:MallocClass.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Funkcja malloc() z obiektami klas
// Co trzeba by zrobic, gdyby nie bylo operatora "new"
#include "../require.h"
#include <cstdlib> // malloc() i free()
#include <cstring> // memset()
#include <iostream>
using namespace std;

class Obj {
  int i, j, k;
  enum { sz = 100 };
  char buf[sz];
public:
  void initialize() { // Nie mozna uzyc konstruktora
    cout << "inicjalizacja Obj" << endl;
    i = j = k = 0;
    memset(buf, 0, sz);
  }
  void destroy() const { // Nie mozna uzyc destruktora
    cout << "niszczenie Obj" << endl;
  }
};

int main() {
  Obj* obj = (Obj*)malloc(sizeof(Obj));
  require(obj != 0);
  obj->initialize();
  // ... nieco pozniej:
  obj->destroy();
  free(obj);
} ///:~
