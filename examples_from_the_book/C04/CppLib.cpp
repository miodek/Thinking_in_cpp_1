//: C04:CppLib.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Biblioteka w jezyku C, przeniesiona do C++
// Deklaracje struktury i funkcji:
#include "CppLib.h"
#include <iostream>
#include <cassert>
using namespace std;
// Liczba elementow dodawanych
// w przypadku powiekszenia pamieci:
const int increment = 100;

void Stash::initialize(int sz) {
  size = sz;
  quantity = 0;
  storage = 0;
  next = 0;
}

int Stash::add(const void* element) {
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
  // Check index boundaries:
  assert(0 <= index);
  if(index >= next)
    return 0; // Oznaczenie konca
  // Tworzenie wskaznika do zadanego elementu:
  return &(storage[index * size]);
}

int Stash::count() {
  return next; // Liczba elementow w Stash
}

void Stash::inflate(int increase) {
  assert(increase > 0);
  int newQuantity = quantity + increase;
  int newBytes = newQuantity * size;
  int oldBytes = quantity * size;
  unsigned char* b = new unsigned char[newBytes];
  for(int i = 0; i < oldBytes; i++)
    b[i] = storage[i]; // Kopiowanie starego obszaru do nowego
  delete []storage; // Stary obszar pamieci
  storage = b; // Wskaznik do nowego obszaru
  quantity = newQuantity;
}

void Stash::cleanup() {
  if(storage != 0) {
    cout << "zwalnianie pamieci" << endl;
    delete []storage;
  }
} ///:~
