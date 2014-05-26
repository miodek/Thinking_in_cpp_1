//: C03:Assert.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Uzycie makroinstrukcji uruchomieniowej assert()
#include <cassert>  // Zawiera makroinstrukcje
using namespace std;

int main() {
  int i = 100;
  assert(i != 100); // Niepowodzenie
} ///:~
