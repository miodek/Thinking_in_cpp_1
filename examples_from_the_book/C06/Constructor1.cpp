//: C06:Constructor1.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Konstruktory i destruktory
#include <iostream>
using namespace std;

class Tree {
  int height;
public:
  Tree(int initialHeight);  // Konstruktor
  ~Tree();  // Destruktor
  void grow(int years);
  void printsize();
};

Tree::Tree(int initialHeight) {
  height = initialHeight;
}

Tree::~Tree() {
  cout << "wewnatrz destruktora drzewa" << endl;
  printsize();
}

void Tree::grow(int years) {
  height += years;
}

void Tree::printsize() {
  cout << "Wysokosc drzewa wynosi " << height << endl;
}

int main() {
  cout << "przed klamrowym nawiasem otwierajacym" << endl;
  {
    Tree t(12);
    cout << "po utworzeniu drzewa" << endl;
    t.printsize();
    t.grow(4);
    cout << "przed klamrowym nawiasem zamykajacym" << endl;
  }
  cout << "po klamrowym nawiasie zamykajacym" << endl;
} ///:~
