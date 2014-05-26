//: C16:NestedIterator.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zagniezdzenie iteratora w kontenerze
//{L} fibonacci
#include "fibonacci.h"
#include "../require.h"
#include <iostream>
#include <string>
using namespace std;

class IntStack {
  enum { ssize = 100 };
  int stack[ssize];
  int top;
public:
  IntStack() : top(0) {}
  void push(int i) {
    require(top < ssize, "Zbyt wiele wywolan funkcji push()");
    stack[top++] = i;
  }
  int pop() {
    require(top > 0, "Zbyt wiele wywolan funkcji pop()");
    return stack[--top];
  }
  class iterator;
  friend class iterator;
  class iterator {
    IntStack& s;
    int index;
  public:
    iterator(IntStack& is) : s(is), index(0) {}
    // Do utworzenia iteratora-wartownika 
    // bedacego "znacznikiem konca":
    iterator(IntStack& is, bool) 
      : s(is), index(s.top) {}
    int current() const { return s.stack[index]; }
    int operator++() { // Przedrostkowy
      require(index < s.top, 
        "iterator przesuniety poza zakres");
      return s.stack[++index];
    }
    int operator++(int) { // Przyrostkowy
      require(index < s.top, 
        "iterator przesuniety poza zakres");
      return s.stack[index++];
    }
    // Przeskoczenie iteratorem do przodu:
    iterator& operator+=(int amount) {
      require(index + amount < s.top,
        "IntStack::iterator::operator+=() "
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
    friend ostream& 
    operator<<(ostream& os, const iterator& it) {
      return os << it.current();
    }
  };
  iterator begin() { return iterator(*this); }
  // Tworzenie "znacznika konca":
  iterator end() { return iterator(*this, true);}
};

int main() {
  IntStack is;
  for(int i = 0; i < 20; i++)
    is.push(fibonacci(i));
  cout << "Przejscie przez caly kontener IntStack\n";
  IntStack::iterator it = is.begin();
  while(it != is.end())
    cout << it++ << endl;
  cout << "Przejscie przez czesc kontenera IntStack\n";
  IntStack::iterator 
    start = is.begin(), end = is.begin();
  start += 5, end += 15;
  cout << "poczatek = " << start << endl;
  cout << "koniec = " << end << endl;
  while(start != end)
    cout << start++ << endl;
} ///:~
