//: C12:TypeConversionAmbiguity.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class Orange; // Deklaracja klasy

class Apple {
public:
  operator Orange() const; // Konwersja z Apple do Orange
};

class Orange {
public:
  Orange(Apple); // Konwersja z Apple do Orange
};

void f(Orange) {}

int main() {
  Apple a;
//! f(a); // Blad – dwuznaczna konwersja
} ///:~
