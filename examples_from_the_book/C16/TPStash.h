//: C16:TPStash.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#ifndef TPSTASH_H
#define TPSTASH_H

template<class T, int incr = 10>
class PStash {
  int quantity; // Liczba elementow pamieci
  int next; // Nastepny pusty element
  T** storage;
  void inflate(int increase = incr);
public:
  PStash() : quantity(0), next(0), storage(0) {}
  ~PStash();
  int add(T* element);
  T* operator[](int index) const; // Pobranie elementu
  // Usuniecie odwolania do elementu:
  T* remove(int index);
  // Liczba zapamietanych elementow:
  int count() const { return next; }
};

template<class T, int incr>
int PStash<T, incr>::add(T* element) {
  if(next >= quantity)
    inflate(incr);
  storage[next++] = element;
  return(next - 1); // Numer indeksu
}

// Pozostawione obiekty sa wlasnoscia kontenera:
template<class T, int incr>
PStash<T, incr>::~PStash() {
  for(int i = 0; i < next; i++) {
    delete storage[i]; // Zerowe wskazniki nie sa problemem
    storage[i] = 0; // Dla pewnosci
  }
  delete []storage;
}

template<class T, int incr>
T* PStash<T, incr>::operator[](int index) const {
  require(index >= 0,
    "PStash::operator[] indeks ma wartosc ujemna");
  if(index >= next)
    return 0; // Oznaczenie konca
  require(storage[index] != 0, 
    "PStash::operator[] zwrocony pusty wskaznik");
  // Tworzenie wskaznika do zadanego elementu:
  return storage[index];
}

template<class T, int incr>
T* PStash<T, incr>::remove(int index) {
  // operator[] dokonuje sprawdzenia poprawnosci indeksu:
  T* v = operator[](index);
  // "Usuniecie" wskaznika:
  if(v != 0) storage[index] = 0;
  return v;
}

template<class T, int incr>
void PStash<T, incr>::inflate(int increase) {
  const int psz = sizeof(T*);
  T** st = new T*[quantity + increase];
  memset(st, 0, (quantity + increase) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += increase;
  delete []storage; // Stary obszar pamieci
  storage = st; // Wskaznik do nowego obszaru pamieci
}
#endif // TPSTASH_H ///:~
