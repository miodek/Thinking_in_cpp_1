//: C13:NoMemory.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Konstruktor nie jest wywolywany, gdy wywolanie
// operatora new skonczy sie niepowodzeniem
#include <iostream>
#include <new> // Definicja bad_alloc
using namespace std;

class NoMemory {
public:
  NoMemory() {
    cout << "NoMemory::NoMemory()" << endl;
  }
  void* operator new(size_t sz) throw(bad_alloc){
    cout << "NoMemory::operator new" << endl;
    throw bad_alloc(); // "Brak pamieci"
  }
};

int main() {
  NoMemory* nm = 0;
  try {
    nm = new NoMemory;
  } catch(bad_alloc) {
    cerr << "Wyjatek braku pamieci" << endl;
  }
  cout << "nm = " << nm << endl;
} ///:~
