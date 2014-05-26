//: C05:Friend.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Slowo kluczowe friend daje specjalne
// prawa dostepu

// Deklaracja (niekompletna specyfikacja typu):
struct X;

struct Y {
  void f(X*);
};

struct X { // Definicja
private:
  int i;
public:
  void initialize();
  friend void g(X*, int); // Przyjaciel globalny
  friend void Y::f(X*);  // Przyjaciel bedacy skladowa struktury
  friend struct Z; // Cala struktura jako przyjaciel
  friend void h();
};

void X::initialize() { 
  i = 0; 
}

void g(X* x, int i) { 
  x->i = i; 
}

void Y::f(X* x) { 
  x->i = 47; 
}

struct Z {
private:
  int j;
public:
  void initialize();
  void g(X* x);
};

void Z::initialize() { 
  j = 99;
}

void Z::g(X* x) { 
  x->i += j; 
}

void h() {
  X x;
  x.i = 100; // Bezposrednia operacja na danej
}

int main() {
  X x;
  Z z;
  z.g(&x);
} ///:~
