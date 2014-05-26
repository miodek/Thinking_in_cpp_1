//: C03:gotoKeyword.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Nieslawna instrukcja goto jest dostepna w C++
#include <iostream>
using namespace std;

int main() {
  long val = 0;
  for(int i = 1; i < 1000; i++) {
    for(int j = 1; j < 100; j += 10) {
      val = i * j;
      if(val > 47000)
        goto bottom; 
        // Instrukcja 'break' spowodowalaby jedynie
        // przejscie do bardziej zewnetrznej instrukcji 'for'
    }
  }
  bottom: // Etykieta
  cout << val << endl;
} ///:~
