//: C03:Guess.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Odgadywanie numeru (demonstracja instrukcji "while")
#include <iostream>
using namespace std;

int main() {
  int secret = 15;
  int guess = 0;
  // "!=" jest warunkiem "nierowne":
  while(guess != secret) { // Instrukcja zlozona
    cout << "odgadnij numer: ";
    cin >> guess;
  }
  cout << "Zgadles!" << endl;
} ///:~
