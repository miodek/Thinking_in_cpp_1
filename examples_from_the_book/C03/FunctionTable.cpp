//: C03:FunctionTable.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wykorzystanie tablicy wskaznikow do funkcji
#include <iostream>
using namespace std;

// Makroinstrukcja, definiujaca "slepe" funkcje:
#define DF(N) void N() { \
   cout << "funkcja " #N " wywolana..." << endl; }

DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);

void (*func_table[])() = { a, b, c, d, e, f, g };

int main() {
  while(1) {
    cout << "nacisnij klawisz od 'a' do 'g' "
      "albo w, aby wyjsc z programu" << endl;
    char c, cr;
    cin.get(c); cin.get(cr); // drugi dla CR
    if ( c == 'w' ) 
      break; // ... wyjscie z while(1)
    if ( c < 'a' || c > 'g' ) 
      continue;
    (*func_table[c - 'a'])();
  }
} ///:~
