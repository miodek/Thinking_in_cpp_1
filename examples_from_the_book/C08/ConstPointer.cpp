//: C08:ConstPointer.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wskazniki do stalych jako argumenty funkcji
// i zwracane przez nie wartosci

void t(int*) {}

void u(const int* cip) {
//!  *cip = 2; // Niedozwolone - modyfikacja wartosci
  int i = *cip; // W porzadku - kopiowanie wartosci
//!  int* ip2 = cip; // Niedozwolone - nie jest to stala
}

const char* v() {
  // Zwraca adres statycznej tablicy znakow:
  return "wynik funkcji v()";
}

const int* const w() {
  static int i;
  return &i;
}

int main() {
  int x = 0;
  int* ip = &x;
  const int* cip = &x;
  t(ip);  // W porzadku
//!  t(cip); // Zle
  u(ip);  // W porzadku
  u(cip); // Rowniez w porzadku
//!  char* cp = v(); // Zle
  const char* ccp = v(); // W porzadku
//!  int* ip2 = w(); // Zle
  const int* const ccip = w(); // W porzadku
  const int* cip2 = w(); // W porzadku
//!  *w() = 1; // Zle
} ///:~
