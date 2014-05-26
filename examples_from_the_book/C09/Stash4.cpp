//: C09:Stash4.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "Stash4.h"
#include <iostream>
#include <cassert>
using namespace std;
const int increment = 100;

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
