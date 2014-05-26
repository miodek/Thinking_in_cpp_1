//: C10:Dependency1.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#ifndef DEPENDENCY1_H
#define DEPENDENCY1_H
#include <iostream>

class Dependency1 {
  bool init;
public:
  Dependency1() : init(true) {
    std::cout << "konstrukcja Dependency1" 
              << std::endl;
  }
  void print() const {
    std::cout << "Dependency1 init: " 
              << init << std::endl;
  }
};
#endif // DEPENDENCY1_H ///:~
