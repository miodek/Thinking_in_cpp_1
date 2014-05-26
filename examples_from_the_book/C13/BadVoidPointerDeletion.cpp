//: C13:BadVoidPointerDeletion.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Usuwanie wskaznikow typu void* moze powodowac
// wyciekanie pamieci
#include <iostream>
using namespace std;

class Object {
  void* data; // Jakis obszar pamieci
  const int size;
  const char id;
public:
  Object(int sz, char c) : size(sz), id(c) {
    data = new char[size];
    cout << "Konstrukcja obiektu " << id 
         << ", size = " << size << endl;
  }
  ~Object() { 
    cout << "Destrukcja obiektu " << id << endl;
    delete []data; // W porzadku, tylko zwalniana jest
    // pamiec - nie ma potrzeby wywolywania destruktora
  }
};

int main() {
  Object* a = new Object(40, 'a');
  delete a;
  void* b = new Object(40, 'b');
  delete b;
} ///:~
