//: C03:Global2.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dostep do zewnetrznych zmiennych globalnych
extern int globe;  
// (Odwolanie zostanie okreslone przez program laczacy)
void func() {
  globe = 47;
} ///:~
