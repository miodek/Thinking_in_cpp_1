//: C03:Forward.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wyprzedzajace deklaracje funkcji i danych
#include <iostream>
using namespace std;

// Ponizsze deklaracje nie dotycza w rzeczywistosci
// obiektow zewnetrznych, ale kompilator musi
// wiedziec, ze gdzies one istnieja:
extern int i; 
extern void func();
int main() {
  i = 0;
  func();
}
int i; // Definicja danych
void func() {
  i++;
  cout << i;
} ///:~
