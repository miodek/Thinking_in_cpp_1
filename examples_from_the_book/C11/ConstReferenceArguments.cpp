//: C11:ConstReferenceArguments.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przekazywanie referencji jako stalych

void f(int&) {}
void g(const int&) {}

int main() {
//!  f(1); // Blad
  g(1);
} ///:~
