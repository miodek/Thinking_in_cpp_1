//: C04:StackTest.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{L} Stack
//{T} StackTest.cpp
// Test zagniezdzonej listy powiazanej
#include "Stack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  requireArgs(argc, 1); // Argumentem jest nazwa pliku
  ifstream in(argv[1]);
  assure(in, argv[1]);
  Stack textlines;
  textlines.initialize();
  string line;
  // Odczytanie pliku i zapamietanie wierszy na stosie:
  while(getline(in, line))
    textlines.push(new string(line));
  // Pobranie wierszy ze stosu i wydrukowanie ich:
  string* s;
  while((s = (string*)textlines.pop()) != 0) {
    cout << *s << endl;
    delete s; 
  }
  textlines.cleanup();
} ///:~
