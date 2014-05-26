//: C08:Constval.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zwracanie stalej przez wartosc nie ma
// znaczenia w przypadku typow wbudowanych

int f3() { return 1; }
const int f4() { return 1; }

int main() {
  const int j = f3(); // Dziala znakomicie
  int k = f4(); // Ale to rowniez dziala znakomicie!
} ///:~
