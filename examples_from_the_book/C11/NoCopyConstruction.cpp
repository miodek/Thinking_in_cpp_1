//: C11:NoCopyConstruction.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zapobieganie uzyciu konstruktora kopiujacego

class NoCC {
  int i;
  NoCC(const NoCC&); // Brak definicji
public:
  NoCC(int ii = 0) : i(ii) {}
};

void f(NoCC);

int main() {
  NoCC n;
//! f(n); // Blad: wywolanie konstruktora kopiujacego
//! NoCC n2 = n; // Blad: wywolanie konstruktora kopiujacego
//! NoCC n3(n); // Blad: wywolanie konstruktora kopiujacego
} ///:~
