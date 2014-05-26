//: C02:HelloStrings.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Podstawy standardowej klasy C++ string
#include <string>
#include <iostream>
using namespace std;

int main() {
  string s1, s2; // Puste lancuchy
  string s3 = "Witaj, swiecie."; // Inicjalizacja
  string s4("Mam dzisiaj"); // Rowniez inicjalizacja
  s2 = "urodziny"; // Przypisanie lancuchowi wartosci
  s1 = s3 + " " + s4; // Laczenie lancuchow
  s1 += " 8 "; // Dolaczanie do lancucha
  cout << s1 + s2 + "!" << endl;
} ///:~
