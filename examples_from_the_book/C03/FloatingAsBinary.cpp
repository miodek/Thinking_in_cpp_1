//: C03:FloatingAsBinary.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{L} printBinary
//{T} 3.14159
#include "printBinary.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cout << "Musisz podac liczbe" << endl;
    exit(1);
  }
  double d = atof(argv[1]);
  unsigned char* cp = 
    reinterpret_cast<unsigned char*>(&d);
  for(int i = sizeof(double); i > 0 ; i -= 2) {
    printBinary(cp[i-1]);
    printBinary(cp[i]);
  }
} ///:~
