//: C16:TPStash2.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Szablon klasy PStash, zawierajacy zagniezdzony iterator
#ifndef TPSTASH2_H
#define TPSTASH2_H
#include "../require.h"
#include <cstdlib>

template<class T, int incr = 20>
class PStash {
  int quantity;
  int next;
  T** storage;
  void inflate(int increase = incr);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();
  int add(T* element);
  T* operator[](int index) const;
  T* remove(int index);
  int count() const { return next; }
  // Zagniezdzona klasa iteratora:
  class iterator; // Wymagana deklaracja
  friend class iterator; // Uczyn klase przyjacielem
  class iterator { // A teraz ja zdefiniuj
    PStash& ps;
    int index;
  public:
    iterator(PStash& pStash)
      : ps(pStash), index(0) {}
    // Do utworzenia iteratora-wartownika 
    // bedacego "znacznikiem konca":
    iterator(PStash& pStash, bool)
      : ps(pStash), index(ps.next) {}
    // Konstruktor kopiujacy:
    iterator(const iterator& rv)
      : ps(rv.ps), index(rv.index) {}
    iterator& operator=(const iterator& rv) {
      ps = rv.ps;
      index = rv.index;
      return *this;
    }
    iterator& operator++() {
      require(++index <= ps.next,
        "PStash::iterator::operator++ "
        "przesunal indeks poza zakres");
      return *this;
    }
    iterator& operator++(int) {
      return operator++();
    }
    iterator& operator--() {
      require(--index >= 0,
        "PStash::iterator::operator-- "
        "przesunal indeks poza zakres");
      return *this;
    }
    iterator& operator--(int) { 
      return operator--();
    }
    // Przeskoczenie iteratorem do przodu lub tylu:
    iterator& operator+=(int amount) {
      require(index + amount < ps.next && 
        index + amount >= 0, 
        "PStash::iterator::operator+= "
        "proba uzyskania indeksu poza zakresem");
      index += amount;
      return *this;
    }
    iterator& operator-=(int amount) {
      require(index - amount < ps.next && 
        index - amount >= 0, 
        "PStash::iterator::operator-= "
        "proba uzyskania indeksu poza zakresem");
      index -= amount;
      return *this;
    }
    // Utworzenie nowego iteratora, przesunietego do przodu
    iterator operator+(int amount) const {
      iterator ret(*this);
      ret += amount; // operator+= sprawdza zakres
      return ret;
    }
    T* current() const {
      return ps.storage[index];
    }
    T* operator*() const { return current(); }
    T* operator->() const { 
      require(ps.storage[index] != 0, 
        "PStash::iterator::operator-> zwrocil 0");
      return current(); 
    }
    // Usuniecie biezacego elementu:
    T* remove(){
      return ps.remove(index);
    }
    // Testy porownan do wykrycia konca:
    bool operator==(const iterator& rv) const {
      return index == rv.index;
    }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
  };
  iterator begin() { return iterator(*this); }
  iterator end() { return iterator(*this, true);}
};

// Usuwanie obiektow zawartych w kontenerze:
template<class T, int incr>
PStash<T, incr>::~PStash() {
  for(int i = 0; i < next; i++) {
    delete storage[i]; // Zerowe wskazniki nie sa problemem
    storage[i] = 0; // Dla pewnosci
  }
  delete []storage;
}

template<class T, int incr>
int PStash<T, incr>::add(T* element) {
  if(next >= quantity)
    inflate();
  storage[next++] = element;
  return(next - 1); // Numer indeksu
}

template<class T, int incr> inline
T* PStash<T, incr>::operator[](int index) const {
  require(index >= 0,
    "PStash::operator[] indeks ma wartosc ujemna");
  if(index >= next)
    return 0; // Oznaczenie konca
  require(storage[index] != 0, 
    "PStash::operator[] zwrocony pusty wskaznik");
  return storage[index];
}

template<class T, int incr>
T* PStash<T, incr>::remove(int index) {
  // operator[] sprawdza zakres:
  T* v = operator[](index);
  // "Usuniecie" wskaznika:
  storage[index] = 0;
  return v;
}

template<class T, int incr>
void PStash<T, incr>::inflate(int increase) {
  const int tsz = sizeof(T*);
  T** st = new T*[quantity + increase];
  memset(st, 0, (quantity + increase) * tsz);
  memcpy(st, storage, quantity * tsz);
  quantity += increase;
  delete []storage; // Stary obszar pamieci
  storage = st; // Wskaznik do nowego obszaru pamieci
}
#endif // TPSTASH2_H ///:~
