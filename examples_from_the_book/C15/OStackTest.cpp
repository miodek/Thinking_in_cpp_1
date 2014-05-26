//: C15:OStackTest.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{T} OStackTest.cpp
#include "OStack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Wykorzystanie wielokrotnego dziedziczenia.
// Chcemy, by obiekt byl zarowno klasy string, jak i Object:
class MyString: public string, public Object {
public:
  ~MyString() {
    cout << "usuwanie lancucha: " << *this << endl;
  }
  MyString(string s) : string(s) {}
};

int main(int argc, char* argv[]) {
  requireArgs(argc, 1); // Argumentem jest nazwa pliku
  ifstream in(argv[1]);
  assure(in, argv[1]);
  Stack textlines;
  string line;
  // Odczytywanie pliku i zapamietywanie wierszy na stosie:
  while(getline(in, line))
    textlines.push(new MyString(line));
  // Pobranie kilku wierszy ze stosu:
  MyString* s;
  for(int i = 0; i < 10; i++) {
    if((s=(MyString*)textlines.pop())==0) break;
    cout << *s << endl;
    delete s; 
  }
  cout << "Niech reszte zrobi destruktor:"
    << endl;
} ///:~
