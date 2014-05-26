//: C13:PStash.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Definicje klasy Stash, przechowujacej wskazniki
#include "PStash.h"
#include "../require.h"
#include <iostream>
#include <cstring> // funkcje 'mem'
using namespace std;

int PStash::add(void* element) {
  const int inflateSize = 10;
  if(next >= quantity)
    inflate(inflateSize);
  storage[next++] = element;
  return(next - 1); // Numer indeksu
}

// Obiekty nie sa wlasnoscia kontenera:
PStash::~PStash() {
  for(int i = 0; i < next; i++)
    require(storage[i] == 0, 
      "PStash nie zostal uprzatniety");
  delete []storage; 
}

// Zamiast funkcji fetch uzyto przeciazonego operatora
void* PStash::operator[](int index) const {
  require(index >= 0,
    "PStash::operator[] indeks ma wartosc ujemna");
  if(index >= next)
    return 0; // Oznaczenie konca
  // Tworzenie wskaznika do zadanego elementu:
  return storage[index];
}

void* PStash::remove(int index) {
  void* v = operator[](index);
  // "Usuwa" wskaznik:
  if(v != 0) storage[index] = 0;
  return v;
}

void PStash::inflate(int increase) {
  const int psz = sizeof(void*);
  void** st = new void*[quantity + increase];
  memset(st, 0, (quantity + increase) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += increase;
  delete []storage; // Stary obszar pamieci
  storage = st; // Wskaznik do nowego obszaru pamieci
} ///:~
