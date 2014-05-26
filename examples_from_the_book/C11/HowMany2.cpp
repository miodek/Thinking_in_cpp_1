//: C11:HowMany2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Konstruktor kopiujacy
#include <fstream>
#include <string>
using namespace std;
ofstream out("HowMany2.out");

class HowMany2 {
  string name; // Identyfikator obiektu
  static int objectCount;
public:
  HowMany2(const string& id = "") : name(id) {
    ++objectCount;
    print("HowMany2()");
  }
  ~HowMany2() {
    --objectCount;
    print("~HowMany2()");
  }
  // Konstruktor kopiujacy:
  HowMany2(const HowMany2& h) : name(h.name) {
    name += " kopia";
    ++objectCount;
    print("HowMany2(const HowMany2&)");
  }
  void print(const string& msg = "") const {
    if(msg.size() != 0) 
      out << msg << endl;
    out << '\t' << name << ": "
        << "objectCount = "
        << objectCount << endl;
  }
};

int HowMany2::objectCount = 0;

// Przekazywanie i zwracanie PRZEZ WARTOSC:
HowMany2 f(HowMany2 x) {
  x.print("argument x wewnatrz f()");
  out << "Powrot z funkcji f()" << endl;
  return x;
}

int main() {
  HowMany2 h("h");
  out << "Wywolanie funkcji f()" << endl;
  HowMany2 h2 = f(h);
  h2.print("h2 po wywolaniu funkcji f()");
  out << "Wywolanie funkcji f(), brak zwracanej wartosci" << endl;
  f(h);
  out << "Po wywolaniu funkcji f()" << endl;
} ///:~
