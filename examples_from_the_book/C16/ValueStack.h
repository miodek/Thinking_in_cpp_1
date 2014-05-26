//: C16:ValueStack.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Stos przechowujacy wartosci obiektow
#ifndef VALUESTACK_H
#define VALUESTACK_H
#include "../require.h"

template<class T, int ssize = 100>
class Stack {
  // Domyslny konstruktor dokonuje inicjalizacji
  // obiektu dla kazdego elementu zawartego w tablicy:
  T stack[ssize];
  int top;
public:
  Stack() : top(0) {}
  // Konstruktor kopiujacy kopiuje obiekty do tablicy:
  void push(const T& x) {
    require(top < ssize, "Zbyt wiele wywolan funkcji push()");
    stack[top++] = x;
  }
  T peek() const { return stack[top]; }
  // Po pobraniu ze stosu, obiekty nadal istnieja
  // - nie sa juz tylko dostepne:
  T pop() {
    require(top > 0, "Zbyt wiele wywolan funkcji pop()");
    return stack[--top];
  }
};
#endif // VALUESTACK_H ///:~
