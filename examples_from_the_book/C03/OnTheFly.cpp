//: C03:OnTheFly.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Definiowanie zmiennych "w locie"
#include <iostream>
using namespace std;

int main() {
  //..
  { // Poczatek nowego zasiegu
    int q = 0; // Jezyk C wymaga definicji w tym miejscu
    //..
    // Definicja w miejscu uzycia:
    for(int i = 0; i < 100; i++) { 
      q++; // q pochodzi z szerszego zasiegu
      // Definicja na koncu zasiegu:
      int p = 12; 
    }
    int p = 1;  // Inne p
  } // Koniec zasiegu zawierajacego q i zewnetrzne p
  cout << "Wpisz znaki:" << endl;
  while(char c = cin.get() != 'q') {
    cout << c << " to nie to" << endl;
    if(char x = c == 'a' || c == 'b')
      cout << "Wpisales a lub b" << endl;
    else
      cout << "Wpisales " << x << endl;
  }
  cout << "Wpisz A, B lub C" << endl;
  switch(int i = cin.get()) {
    case 'A': cout << "Bach" << endl; break;
    case 'B': cout << "Trach" << endl; break;
    case 'C': cout << "Bum" << endl; break;
    default: cout << "To nie jest A, B ani C!" << endl;
  }
} ///:~
