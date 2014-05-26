//: C15:StaticHierarchyNavigation.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Poruszanie sie w hierarchii klas
// za pomoca static_cast
#include <iostream>
#include <typeinfo>
using namespace std;

class Shape { public: virtual ~Shape() {}; };
class Circle : public Shape {};
class Square : public Shape {};
class Other {};

int main() {
  Circle c;
  Shape* s = &c; // Rzutowanie w gore - normalne i prawidlowe
  // Bardziej jawne, ale niepotrzebne:
  s = static_cast<Shape*>(&c);
  // (poniewaz rzutowanie w gore jest tak bezpieczna 
  // i typowa operacja, ze rzutowanie wprowadza balagan)
  Circle* cp = 0;
  Square* sp = 0;
  // Statyczne poruszanie sie w hierarchii klas
  // wymaga dodatkowej informacji o typie:
  if(typeid(s) == typeid(cp)) // RTTI C++
    cp = static_cast<Circle*>(s);
  if(typeid(s) == typeid(sp))
    sp = static_cast<Square*>(s);
  if(cp != 0)
    cout << "To jest okrag!" << endl;
  if(sp != 0)
    cout << "To jest kwadrat!" << endl;
  // Statyczna nawigacja jest TYLKO obejsciem stosowanym
  // z powodu efektywnosci - rzutowanie dynamic_cast
  // jest zawsze bezpieczniejsze. Jednak instrukcja:
  // Other* op = static_cast<Other*>(s);
  // powoduje zgloszenie bledu, podczas gdy instrukcja:
  Other* op2 = (Other*)s;
  // tego nie robi
} ///:~
