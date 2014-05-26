//: C02:Stream2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dodatkowe wlasnosci strumieni wejscia-wyjscia
#include <iostream>
using namespace std;

int main() {
  // Okreslanie formatu za pomoca manipulatorow:
  cout << "liczba dziesietna: "
       << dec << 15 << endl;
  cout << "osemkowa: " << oct << 15 << endl;
  cout << "szesnastkowa: " << hex << 15 << endl;
  cout << "liczba zmiennopozycyjna: "
       << 3.14159 << endl;
  cout << "znak niedrukowalny (sterujacy): "
       << char(27) << endl;
} ///:~
