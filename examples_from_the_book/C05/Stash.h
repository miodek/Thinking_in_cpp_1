//: C05:Stash.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zmieniony w celu wykorzystania kontroli dostepu
#ifndef STASH_H
#define STASH_H

class Stash {
  int size;      // Wielkosc kazdego elementu
  int quantity;  // Liczba elementow pamieci
  int next;      // Nastepny pusty element
  // Dynamicznie przydzielana tablica bajtow:
  unsigned char* storage;
  void inflate(int increase);
public:
  void initialize(int size);
  void cleanup();
  int add(void* element);
  void* fetch(int index);
  int count();
};
#endif // STASH_H ///:~
