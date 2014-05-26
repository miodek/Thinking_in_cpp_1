//: C16:AutoCounter.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H
#include "../require.h"
#include <iostream>
#include <set> // Kontener standardowej biblioteki C++
#include <string>

class AutoCounter {
  static int count;
  int id;
  class CleanupCheck {
    std::set<AutoCounter*> trace;
  public:
    void add(AutoCounter* ap) {
      trace.insert(ap);
    }
    void remove(AutoCounter* ap) {
      require(trace.erase(ap) == 1,
        "Proba dwukrotnego usuniecia obiektu klasy AutoCounter");
    }
    ~CleanupCheck() {
      std::cout << "~CleanupCheck()"<< std::endl;
      require(trace.size() == 0,
       "Nie wszystkie obiekty klasy AutoCounter zostaly usuniete");
    }
  };
  static CleanupCheck verifier;
  AutoCounter() : id(count++) {
    verifier.add(this); // Rejestracja samego siebie
    std::cout << "utworzony[" << id << "]" 
              << std::endl;
  }
  // Zapobieganie przypisaniu i wywolaniu konstruktora kopiujacego:
  AutoCounter(const AutoCounter&);
  void operator=(const AutoCounter&);
public:
  // Obiekty mozna tworzyc tylko za pomoca tej funkcji:
  static AutoCounter* create() { 
    return new AutoCounter();
  }
  ~AutoCounter() {
    std::cout << "usuwanie[" << id 
              << "]" << std::endl;
    verifier.remove(this);
  }
  // Wydruk zarowno obiektow, jak i wskaznikow:
  friend std::ostream& operator<<(
    std::ostream& os, const AutoCounter& ac){
    return os << "AutoCounter " << ac.id;
  }
  friend std::ostream& operator<<(
    std::ostream& os, const AutoCounter* ac){
    return os << "AutoCounter " << ac->id;
  }
}; 
#endif // AUTOCOUNTER_H ///:~
