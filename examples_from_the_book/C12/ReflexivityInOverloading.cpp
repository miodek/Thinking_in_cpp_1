//: C12:ReflexivityInOverloading.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class Number {
  int i;
public:
  Number(int ii = 0) : i(ii) {}
  const Number
  operator+(const Number& n) const {
    return Number(i + n.i);
  }
  friend const Number
    operator-(const Number&, const Number&);
};

const Number
  operator-(const Number& n1,
            const Number& n2) {
    return Number(n1.i - n2.i);
}

int main() {
  Number a(47), b(11);
  a + b; // W porzadku
  a + 1; // Drugi argument przeksztalcony do typu Number
//! 1 + a; // Zle! Pierwszy argument nie jest typu Number
  a - b; // W porzadku
  a - 1; // Drugi argument przeksztalcony do typu Number
  1 - a; // Pierwszy argument przeksztalcony do typu Number
} ///:~
