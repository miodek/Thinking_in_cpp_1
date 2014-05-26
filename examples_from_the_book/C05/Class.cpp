//: C05:Class.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Podobienstwo struktur i klas

struct A {
private:
  int i, j, k;
public:
  int f();
  void g();
};

int A::f() { 
  return i + j + k; 
}

void A::g() { 
  i = j = k = 0; 
}

// Taki sam rezultat uzyskuje sie za pomoca:

class B {
  int i, j, k;
public:
  int f();
  void g();
};

int B::f() { 
  return i + j + k; 
}

void B::g() { 
  i = j = k = 0; 
} 

int main() {
  A a;
  B b;
  a.f(); a.g();
  b.f(); b.g();
} ///:~
