//: C08:Volatile.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Slowo kluczowe volatile

class Comm {
  const volatile unsigned char byte;
  volatile unsigned char flag;
  enum { bufsize = 100 };
  unsigned char buf[bufsize];
  int index;
public:
  Comm();
  void isr() volatile;
  char read(int index) const;
};

Comm::Comm() : index(0), byte(0), flag(0) {}

// To tylko demonstracja - funkcja w rzeczywistosci
// nie bedzie dzialac jako procedura obslugi przerwan:
void Comm::isr() volatile {
  flag = 0;
  buf[index++] = byte;
  // Przewiniecie do poczatku bufora:
  if(index >= bufsize) index = 0;
}

char Comm::read(int index) const {
  if(index < 0 || index >= bufsize)
    return 0;
  return buf[index];
}

int main() {
  volatile Comm Port;
  Port.isr(); // W porzadku
//!  Port.read(0); // Blad, funkcja read() nie jest typu volatile
} ///:~
