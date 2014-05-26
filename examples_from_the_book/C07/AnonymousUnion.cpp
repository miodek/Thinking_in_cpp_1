//: C07:AnonymousUnion.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
int main() {
  union { 
    int i; 
    float f; 
  };
  // Dostêp do sk³adowych bez uzycia kwalifikatorow:
  i = 12;
  f = 1.22;
} ///:~
