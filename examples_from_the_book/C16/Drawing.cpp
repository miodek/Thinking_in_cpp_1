//: C16:Drawing.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <vector> // Uzywane sa rowniez standardowe wektory!
#include "TPStash2.h"
#include "TStack2.h"
#include "Shape.h"
using namespace std;

// Klasa Drawing jest podstawowym kontenerem klasy Shape:
class Drawing : public PStash<Shape> {
public:
  ~Drawing() { cout << "~Drawing" << endl; }
};

// Klasa Plan jest innym kontenerem klasy Shape:
class Plan : public Stack<Shape> {
public:
  ~Plan() { cout << "~Plan" << endl; }
};

// Klasa Schematic jest innym kontenerem klasy Shape:
class Schematic : public vector<Shape*> {
public:
  ~Schematic() { cout << "~Schematic" << endl; }
};

// Szablon funkcji:
template<class Iter>
void drawAll(Iter start, Iter end) {
  while(start != end) {
    (*start)->draw();
    start++;
  }
}

int main() {
  // Kazdy rodzaj kontenera
  // posiada inny interfejs:
  Drawing d;
  d.add(new Circle);
  d.add(new Square);
  d.add(new Line);
  Plan p;
  p.push(new Line);
  p.push(new Square);
  p.push(new Circle);
  Schematic s;
  s.push_back(new Square);
  s.push_back(new Circle);
  s.push_back(new Line);
  Shape* sarray[] = { 
    new Circle, new Square, new Line 
  };
  // Iteratory oraz szablon funkcji pozwalaja
  // na traktowanie ich w sposob ogolny:
  cout << "Drawing d:" << endl;
  drawAll(d.begin(), d.end());
  cout << "Plan p:" << endl;
  drawAll(p.begin(), p.end());
  cout << "Schematic s:" << endl;
  drawAll(s.begin(), s.end());
  cout << "Array sarray:" << endl;
  // Dziala to nawet w przypadku tablic wskaznikow:
  drawAll(sarray, 
    sarray + sizeof(sarray)/sizeof(*sarray));
  cout << "Koniec funkcji main" << endl;
} ///:~
