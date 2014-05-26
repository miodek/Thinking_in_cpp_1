//: C15:ObjectSlicing.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
#include <string>
using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& name) : pname(name) {}
  virtual string name() const { return pname; }
  virtual string description() const {
    return "To jest " + pname;
  }
};

class Dog : public Pet {
  string favoriteActivity;
public:
  Dog(const string& name, const string& activity)
    : Pet(name), favoriteActivity(activity) {}
  string description() const {
    return Pet::name() + " lubi " +
      favoriteActivity;
  }
};

void describe(Pet p) { // Funkcja okraja obiekt
  cout << p.description() << endl;
}

int main() {
  Pet p("Alfred");
  Dog d("Puszek", "spac");
  describe(p);
  describe(d);
} ///:~
