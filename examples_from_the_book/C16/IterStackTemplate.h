//: C16:IterStackTemplate.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prosty szablon stosu z zagniezdzonym iteratorem
#ifndef ITERSTACKTEMPLATE_H
#define ITERSTACKTEMPLATE_H
#include "../require.h"
#include <iostream>

template<class T, int ssize = 100>
class StackTemplate {
  T stack[ssize];
  int top;
public:
  StackTemplate() : top(0) {}
  void push(const T& i) {
    require(top < ssize, "Zbyt wiele wywolan funkcji push()");
    stack[top++] = i;
  }
  T pop() {
    require(top > 0, "Zbyt wiele wywolan funkcji pop()");
    return stack[--top];
  }
  class iterator; // Wymagana deklaracja
  friend class iterator; // Uczyn klase przyjacielem
  class iterator { // A teraz ja zdefiniuj
    StackTemplate& s;
    int index;
  public:
    iterator(StackTemplate& st): s(st),index(0){}
    // Do utworzenia iteratora-wartownika 
    // bedacego "znacznikiem konca":
    iterator(StackTemplate& st, bool) 
      : s(st), index(s.top) {}
    T operator*() const { return s.stack[index];}
    T operator++() { // Postac przedrostkowa
      require(index < s.top, 
        "iterator przesuniety poza zakres");
      return s.stack[++index];
    }
    T operator++(int) { // Postac przyrostkowa
      require(index < s.top, 
        "iterator przesuniety poza zakres");
      return s.stack[index++];
    }
    // Przeskoczenie iteratorem do przodu:
    iterator& operator+=(int amount) {
      require(index + amount < s.top,
        " StackTemplate::iterator::operator+=() "
        "proba przekroczenia zakresu");
      index += amount;
      return *this;
    }
    // Aby sprawdzic, czy znajdujemy sie na koncu:
    bool operator==(const iterator& rv) const {
      return index == rv.index;
    }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
    friend std::ostream& operator<<(
      std::ostream& os, const iterator& it) {
      return os << *it;
    }
  };
  iterator begin() { return iterator(*this); }
  // Tworzenie "znacznika konca":
  iterator end() { return iterator(*this, true);}
};
#endif // ITERSTACKTEMPLATE_H ///:~
