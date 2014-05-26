//: C04:Scoperes.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Okreslenie zasiegu globalnego
int a;
void f() {}

struct S {
  int a;
  void f();
};

void S::f() {
  ::f();  // Inaczej wywolanie byloby rekurencyjne!
  ::a++;  // Wybor zmiennej globalnej a
  a--;    // Zmienna a w zasiegu struktury
}
int main() { S s; f(); } ///:~
