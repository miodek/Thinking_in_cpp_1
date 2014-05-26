//: C12:ExplicitKeyword.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wykorzystanie slowa kluczowego "explicit"
class One {
public:
  One() {}
};

class Two {
public:
  explicit Two(const One&) {}
};

void f(Two) {}

int main() {
  One one;
//!  f(one); // Automatyczna konwersja nie jest dozwolona
  f(Two(one)); // W porzadku - konwersja dokonana przez uzytkownika
} ///:~
