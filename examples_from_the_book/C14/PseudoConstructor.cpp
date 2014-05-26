//: C14:PseudoConstructor.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class X {
  int i;
  float f;
  char c;
  char* s;
public:
  X() : i(7), f(1.4), c('x'), s("czesc") {}
};

int main() {
  X x;
  int i(100);  // Zastosowany w zwyklej definicji
  int* ip = new int(47);
} ///:~
