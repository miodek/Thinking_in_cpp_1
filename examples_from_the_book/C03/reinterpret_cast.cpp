//: C03:reinterpret_cast.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;
const int sz = 100;

struct X { int a[sz]; };

void print(X* x) {
  for(int i = 0; i < sz; i++)
    cout << x->a[i] << ' ';
  cout << endl << "--------------------" << endl;
}

int main() {
  X x;
  print(&x);
  int* xp = reinterpret_cast<int*>(&x);
  for(int* i = xp; i < xp + sz; i++)
    *i = 0;
  // Nie mozna w tym miejscu uzywac zmiennej xp tak,
  // jakby byla typu X*, dopoki nie dokona sie z powrotem
  // jej rzutowania:
  print(reinterpret_cast<X*>(xp));
  // W tym przykladzie mozna rowniez uzyc 
  // oryginalnego identyfikatora:
  print(&x);
} ///:~
