//: C03:Pitfall.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Pomylki w uzywaniu operatorow

int main() {
  int a = 1, b = 1;
  while(a = b) {
    // ....
  }
} ///:~
