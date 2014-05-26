//: C04:CLib.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Implementacja przykladowej biblioteki w stylu C
// Deklaracje struktury i funkcji:
#include "CLib.h"
#include <iostream>
#include <cassert> 
using namespace std;
// Liczba elementow dodawanych
// w przypadku powiekszenia pamieci:
const int increment = 100;

void initialize(CStash* s, int sz) {
  s->size = sz;
  s->quantity = 0;
  s->storage = 0;
  s->next = 0;
}

int add(CStash* s, const void* element) {
  if(s->next >= s->quantity) // Czy wystarczy pamieci?
    inflate(s, increment);
  // Kopiowanie elementu do pamieci,
  // poczawszy od nastepnego wolnego miejsca:
  int startBytes = s->next * s->size;
  unsigned char* e = (unsigned char*)element;
  for(int i = 0; i < s->size; i++)
    s->storage[startBytes + i] = e[i];
  s->next++;
  return(s->next - 1); // Numer indeksu
}

void* fetch(CStash* s, int index) {
  // Kontrola zakresu indeksu
  assert(0 <= index);
  if(index >= s->next)
    return 0; // Oznaczenie konca
  // Tworzenie wskaznika do zadanego elementu:
  return &(s->storage[index * s->size]);
}

int count(CStash* s) {
  return s->next;  // Liczba elementow w CStash
}

void inflate(CStash* s, int increase) {
  assert(increase > 0);
  int newQuantity = s->quantity + increase;
  int newBytes = newQuantity * s->size;
  int oldBytes = s->quantity * s->size;
  unsigned char* b = new unsigned char[newBytes];
  for(int i = 0; i < oldBytes; i++)
    b[i] = s->storage[i]; // Kopiowanie starego obszaru do nowego
  delete [](s->storage); // Stary obszar pamieci
  s->storage = b; // Wskaznik do nowego obszaru
  s->quantity = newQuantity;
}

void cleanup(CStash* s) {
  if(s->storage != 0) {
   cout << "zwalnianie pamieci" << endl;
   delete []s->storage;
  }
} ///:~
