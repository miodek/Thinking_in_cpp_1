//: C13:Framis.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Lokalne przeciazenie operatorow new i delete
#include <cstddef> // size_t
#include <fstream>
#include <iostream>
#include <new>
using namespace std;
ofstream out("Framis.out");

class Framis {
  enum { sz = 10 };
  char c[sz]; // Nie uzywana - zajmuje tylko pamiec
  static unsigned char pool[];
  static bool alloc_map[];
public:
  enum { psize = 100 };  // Liczba dopuszczalnych obiektow
  Framis() { out << "Framis()\n"; }
  ~Framis() { out << "~Framis() ... "; }
  void* operator new(size_t) throw(bad_alloc);
  void operator delete(void*);
};
unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Wielkosc jest ignorowana - zaklada sie,
// ze jest to obiekt klasy Framis
void* 
Framis::operator new(size_t) throw(bad_alloc) {
  for(int i = 0; i < psize; i++)
    if(!alloc_map[i]) {
      out << "uzywany blok " << i << " ... ";
      alloc_map[i] = true; // Oznaczenie bloku jako uzywanego
      return pool + (i * sizeof(Framis));
    }
  out << "brak pamieci" << endl;
  throw bad_alloc();
}

void Framis::operator delete(void* m) {
  if(!m) return; // Sprawdzenie czy wskaznik nie jest pusty
  // Zakladamy, ze obiekt zostal utworzony w dostepnej puli
  // Wyznaczanie numeru przydzielonego bloku:
  unsigned long block = (unsigned long)m
    - (unsigned long)pool;
  block /= sizeof(Framis);
  out << "zwalnianie bloku " << block << endl;
  // Oznaczenie bloku jako wolnego:
  alloc_map[block] = false;
}

int main() {
  Framis* f[Framis::psize];
  try {
    for(int i = 0; i < Framis::psize; i++)
      f[i] = new Framis;
    new Framis; // Brak pamieci
  } catch(bad_alloc) {
    cerr << "Brak pamieci!" << endl;
  }
  delete f[10];
  f[10] = 0;
  // Uzycie zwolnionej pamieci:
  Framis* x = new Framis;
  delete x;
  for(int j = 0; j < Framis::psize; j++)
    delete f[j]; // Usuwanie f[10] - w porzadku
} ///:~
