//: C03:Guess2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Program odgadujacy, wykorzystujacy petle do-while
#include <iostream>
using namespace std;

int main() {
  int secret = 15;
  int guess; // Nie ma potrzeby inicjalizacji zmiennej
  do {
    cout << "odgadnij numer: ";
    cin >> guess; // Tu ma miejsce inicjalizacja
  }   while(guess != secret);
  cout << "Zgadles!" << endl;
} ///:~
