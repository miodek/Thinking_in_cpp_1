//: C02:Numconv.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zamiana liczby dziesietnej na osemkowa i szesnastkowa
#include <iostream>
using namespace std;

int main() {
  int number;
  cout << "Wprowadz liczbe dziesietna: ";
  cin >> number;
  cout << "wartosc w zapisie osemkowym = 0" 
       << oct << number << endl;
  cout << "wartosc w zapisie szesnastkowym = 0x" 
       << hex << number << endl;
} ///:~
