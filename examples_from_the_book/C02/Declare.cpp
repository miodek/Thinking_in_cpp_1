//: C02:Declare.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przyklady deklaracji i definicji
extern int i; // Deklaracja bez definicji
extern float f(float); // Deklaracja funkcji

float b;  // Deklaracja i definicja
float f(float a) {  // Definicja
  return a + 1.0;
}

int i; // Definicja
int h(int x) { // Deklaracja i definicja
  return x + 1;
}

int main() {
  b = 1.0;
  i = 2;
  f(b);
  h(i);
} ///:~
