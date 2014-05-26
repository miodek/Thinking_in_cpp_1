//: C08:Safecons.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wykorzystywanie stalych dla bezpieczenstwa
#include <iostream>
using namespace std;

const int i = 100;  // Typowa stala
const int j = i + 10; // Wartosc wyrazenia stalego
long address = (long)&j; // Wymuszenie przydzialu pamieci
char buf[j + 10]; // Nadal jest to wyrazenie stale

int main() {
  cout << "wpisz znak i nacisnij Enter:";
  const char c = cin.get(); // Tej wartosci nie bedzie mozna zmienic
  const char c2 = c + 'a';
  cout << c2;
  // ...
} ///:~
