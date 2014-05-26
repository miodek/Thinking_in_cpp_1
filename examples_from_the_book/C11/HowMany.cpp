//: C11:HowMany.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Klasa zliczajaca swoje obiekty
#include <fstream>
#include <string>
using namespace std;
ofstream out("HowMany.out");

class HowMany {
  static int objectCount;
public:
  HowMany() { objectCount++; }
  static void print(const string& msg = "") {
    if(msg.size() != 0) out << msg << ": ";
    out << "objectCount = "
         << objectCount << endl;
  }
  ~HowMany() {
    objectCount--;
    print("~HowMany()");
  }
};

int HowMany::objectCount = 0;

// Przekazywanie i zwracanie PRZEZ WARTOSC:
HowMany f(HowMany x) {
  x.print("argument x wewnatrz f()");
  return x;
}

int main() {
  HowMany h;
  HowMany::print("po utworzeniu h");
  HowMany h2 = f(h);
  HowMany::print("po wywolaniu funkcji f()");
} ///:~
