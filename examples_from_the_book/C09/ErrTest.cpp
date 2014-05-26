//: C09:ErrTest.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{T} ErrTest.cpp
// Test funkcji zawartych w pliku require.h
#include "../require.h"
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
  int i = 1;
  require(i, "wartosc musi byc niezerowa");
  requireArgs(argc, 1);
  requireMinArgs(argc, 1);
  ifstream in(argv[1]);
  assure(in, argv[1]); // Wykorzystanie nazwy pliku
  ifstream nofile("nofile.xxx");
  // Fails:
//!  assure(nofile); // Argument domyslny
  ofstream out("tmp.txt");
  assure(out);
} ///:~
