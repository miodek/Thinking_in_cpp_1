//: C03:Charlist.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wyswietlanie wszystkich znakow ASCII
// Demonstracja petli "for"
#include <iostream>
using namespace std;

int main() {
  for(int i = 0; i < 128; i = i + 1)
    if (i != 26)  // Oczyszczenie ekranu terminalu ANSI
      cout << " wartosc: " << i 
           << " znak: " 
           << char(i) // Konwersja typu
           << endl;
} ///:~
