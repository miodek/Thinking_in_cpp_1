//: C06:Stash2.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Z konstruktorami i destruktorami
#ifndef STASH2_H
#define STASH2_H

class Stash {
  int size;      // Wielkosc kazdego elementu
  int quantity;  // Liczba elementow pamieci
  int next;      // Nastepny pusty element
  // Dynamicznie przydzielana tablica bajtow:
  unsigned char* storage;
  void inflate(int increase);
public:
  Stash(int size);
  ~Stash();
  int add(void* element);
  void* fetch(int index);
  int count();
};
#endif // STASH2_H ///:~
