//: C08:Mutable.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Slowo kluczowe "mutable"

class Z {
  int i;
  mutable int j;
public:
  Z();
  void f() const;
};

Z::Z() : i(0), j(0) {}

void Z::f() const {
//! i++; // Blad - stala funkcja skladowa
    j++; // W porzadku - skladowa moze byc zmieniana
}

int main() {
  const Z zz;
  zz.f(); // Funkcja modyfikuje obiekt!
} ///:~
