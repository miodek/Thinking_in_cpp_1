//: C08:Castaway.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// "Odrzucenie" niezmiennosci

class Y {
  int i;
public:
  Y();
  void f() const;
};

Y::Y() { i = 0; }

void Y::f() const {
//!  i++; // Blad - stala funkcja skladowa
  ((Y*)this)->i++; // W porzadku - odrzucenie niezmiennosci
  // Lepsze rozwiazanie - uzycie skladni jawnego rzutowania C++:
  (const_cast<Y*>(this))->i++;
}

int main() {
  const Y yy;
  yy.f(); // W rzeczywistosci zmienia obiekt!
} ///:~
