//: C12:Strings2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Z automatyczna konwersja typow
#include "../require.h"
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

class Stringc {
  string s;
public:
  Stringc(const string& str = "") : s(str) {}
  operator const char*() const { 
    return s.c_str(); 
  }
};

int main() {
  Stringc s1("hello"), s2("there");
  strcmp(s1, s2); // Standardowa funkcja jezyka C
  strspn(s1, s2); // Dowolna funkcja operujaca na lancuchach!
} ///:~
