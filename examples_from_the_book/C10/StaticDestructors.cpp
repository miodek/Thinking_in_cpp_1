//: C10:StaticDestructors.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Destruktory obiektow statycznych
#include <fstream>
using namespace std;
ofstream out("statdest.out"); // Plik sledzenia

class Obj {
  char c; // Identyfikator
public:
  Obj(char cc) : c(cc) {
    out << "Obj::Obj() dla " << c << endl;
  }
  ~Obj() {
    out << "Obj::~Obj() dla " << c << endl;
  }
};

Obj a('a'); // Obiekt globalny (pamiec statyczna)
// Konstruktor i destruktor sa zawsze wywolywane

void f() {
  static Obj b('b');
}

void g() {
  static Obj c('c');
}

int main() {
  out << "wewnatrz funkcji main()" << endl;
  f(); // Wywolanie statycznego konstruktora obiektu b
  // Funkcja g() nie zostala wywolana
  out << "opuszczanie funkcji main()" << endl;
} ///:~
