//: C13:PStash.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przechowuje wskazniki zamiast obiektow
#ifndef PSTASH_H
#define PSTASH_H

class PStash {
  int quantity; // Liczba elementow pamieci
  int next; // Nastepny pusty element
   // Pamiec wskaznikow:
  void** storage;
  void inflate(int increase);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();
  int add(void* element);
  void* operator[](int index) const; // Pobranie elementu
  // Usuniecie odwolania do elementu:
  void* remove(int index);
  // Liczba zapamietanych elementow:
  int count() const { return next; }
};
#endif // PSTASH_H ///:~
