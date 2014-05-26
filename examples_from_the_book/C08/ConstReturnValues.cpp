//: C08:ConstReturnValues.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Stala zwracana przez wartosc
// Wynik nie moze byc uzyty jako l-wartosc

class X {
  int i;
public:
  X(int ii = 0);
  void modify();
};

X::X(int ii) { i = ii; }

void X::modify() { i++; }

X f5() {
  return X();
}

const X f6() {
  return X();
}

// Przekazanie przez referencje obiektu 
// nie bedacego stala:
void f7(X& x) {
  x.modify();
}

int main() {
  f5() = X(1); // W porzadku - zwracana wartosc nie jest stala
  f5().modify(); // W porzadku
// Instrukcje wywolujace bledy podczas kompilacji:
//!  f7(f5());
//!  f6() = X(1);
//!  f6().modify();
//!  f7(f6());
} ///:~
