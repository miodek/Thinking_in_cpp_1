//: C03:VoidPointer.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
int main() {
  void* vp;
  char c;
  int i;
  float f;
  double d;
  // Do wskaznika typu void* mozna
  // przypisac adres DOWOLNEGO typu:
  vp = &c;
  vp = &i;
  vp = &f;
  vp = &d;
} ///:~
