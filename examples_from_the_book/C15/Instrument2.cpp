//: C15:Instrument2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dziedziczenie i rzutowanie w gore
#include <iostream>
using namespace std;
enum note { middleC, Csharp, Eflat }; // Itd.

class Instrument {
public:
  void play(note) const {
    cout << "Instrument::play" << endl;
  }
};

// Obiekty klasy Wind sa obiektami typu Instrument
// poniewaz maja one taki sam interfejs:
class Wind : public Instrument {
public:
  // Redefine interface function:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
};

void tune(Instrument& i) {
  // ...
  i.play(middleC);
}

int main() {
  Wind flute;
  tune(flute); // Rzutowanie w gore
} ///:~
