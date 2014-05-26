//: C03:const_cast.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
int main() {
  const int i = 0;
  int* j = (int*)&i; // Postac niewskazana
  j  = const_cast<int*>(&i); // Postac preferowana
  // Nie mozna wykonac rownoczesnie dodatkowego rzutowania:
//! long* l = const_cast<long*>(&i); // Blad
  volatile int k = 0;
  int* u = const_cast<int*>(&k);
} ///:~
