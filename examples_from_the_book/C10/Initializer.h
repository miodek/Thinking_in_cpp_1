//: C10:Initializer.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Technika inicjalizacji obiektow statycznych
#ifndef INITIALIZER_H
#define INITIALIZER_H
#include <iostream>
extern int x; // Deklaracje, a nie definicje
extern int y;

class Initializer {
  static int initCount;
public:
  Initializer() {
    std::cout << "Initializer()" << std::endl;
    // Inicjalizacja tylko za pierwszym razem
    if(initCount++ == 0) {
      std::cout << "inicjalizacja"
                << std::endl;
      x = 100;
      y = 200;
    }
  }
  ~Initializer() {
    std::cout << "~Initializer()" << std::endl;
    // Sprzatanie tylko za ostatnim razem
    if(--initCount == 0) {
      std::cout << "sprzatanie" 
                << std::endl;
      // Wszelkie niezbedne czynnosci zwiazane ze sprzataniem
    }
  }
};

// Ponizsza definicja tworzy obiekt, 
// w kazdym pliku, do ktorego jest dolaczony
// plik Initializer.h, ale obiekt ten jest widoczny 
// tylko w obrebie biezacego pliku:
static Initializer init;
#endif // INITIALIZER_H ///:~
