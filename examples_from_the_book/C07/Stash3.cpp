//: C07:Stash3.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przeciazanie nazw funkcji
#include "Stash3.h"
#include "../require.h"
#include <iostream>
#include <cassert>
using namespace std;
const int increment = 100;

Stash::Stash(int sz) {
  size = sz;
  quantity = 0;
  next = 0;
  storage = 0;
}

Stash::Stash(int sz, int initQuantity) {
  size = sz;
  quantity = 0;
  next = 0;
  storage = 0;
  inflate(initQuantity);
}

Stash::~Stash() {
  if(storage != 0) {
    cout << "zwalnianie pamieci" << endl;
    delete []storage;
  }
}

int Stash::add(void* element) {
  if(next >= quantity) // Czy wystarczy pamieci?
    inflate(increment);
  // Kopiowanie elementu do pamieci,
  // poczawszy od nastepnego wolnego miejsca:
  int startBytes = next * size;
  unsigned char* e = (unsigned char*)element;
  for(int i = 0; i < size; i++)
    storage[startBytes + i] = e[i];
  next++;
  return(next - 1); // Numer indeksu
}

void* Stash::fetch(int index) {
  require(0 <= index, "Stash::fetch indeks ma wartosc ujemna");
  if(index >= next)
    return 0; // Oznaczenie konca
  // Tworzenie wskaznika do zadanego elementu:
  return &(storage[index * size]);
}

int Stash::count() {
  return next; // Liczba elementow w Stash
}

void Stash::inflate(int increase) {
  assert(increase >= 0);
  if(increase == 0) return;
  int newQuantity = quantity + increase;
  int newBytes = newQuantity * size;
  int oldBytes = quantity * size;
  unsigned char* b = new unsigned char[newBytes];
  for(int i = 0; i < oldBytes; i++)
    b[i] = storage[i]; // Kopiowanie starego obszaru do nowego
  delete [](storage); // Zwolnienie starego obszaru pamieci
  storage = b; // Wskaznik do nowego obszaru
  quantity = newQuantity; // Aktualizacja liczby elementow
} ///:~
