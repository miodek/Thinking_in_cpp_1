//: C14:Order.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Kolejnosc wywolywania konstruktorow i destruktorow
#include <fstream>
using namespace std;
ofstream out("order.out");

#define CLASS(ID) class ID { \
public: \
  ID(int) { out << #ID " konstruktor\n"; } \
  ~ID() { out << #ID " destruktor\n"; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
  Member1 m1;
  Member2 m2;
public:
  Derived1(int) : m2(1), m1(2), Base1(3) {
    out << "Derived1 konstruktor\n";
  }
  ~Derived1() {
    out << "Derived1 destruktor\n";
  }
};

class Derived2 : public Derived1 {
  Member3 m3;
  Member4 m4;
public:
  Derived2() : m3(1), Derived1(2), m4(3) {
    out << "Derived2 konstruktor\n";
  }
  ~Derived2() {
    out << "Derived2 destruktor\n";
  }
};

int main() {
  Derived2 d2;
} ///:~
