//: C11:DefaultCopyConstructor.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Automatyczne tworzenie konstruktora kopiujacego
#include <iostream>
#include <string>
using namespace std;

class WithCC { // Posiada konstruktor kopiujacy
public:
  // Wymagany jawny domyslny konstruktor:
  WithCC() {}
  WithCC(const WithCC&) {
    cout << "WithCC(WithCC&)" << endl;
  }
};

class WoCC { // Nie posiada konstruktora kopiujacego
  string id;
public:
  WoCC(const string& ident = "") : id(ident) {}
  void print(const string& msg = "") const {
    if(msg.size() != 0) cout << msg << ": ";
    cout << id << endl;
  }
};

class Composite {
  WithCC withcc; // Osadzony obiekt
  WoCC wocc;
public:
  Composite() : wocc("Composite()") {}
  void print(const string& msg = "") const {
    wocc.print(msg);
  }
};

int main() {
  Composite c;
  c.print("Zawartosc obiektu c");
  cout << "Wywolanie zlozonego konstruktora kopiujacego"
       << endl;
  Composite c2 = c;  // Wywolanie konstruktora kopiujacego
  c2.print("Zawartosc obiektu c2");
} ///:~
