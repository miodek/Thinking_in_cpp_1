//: C15:Instrument3.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Pozne wiazanie dzieki uzyciu slowa kluczowego virtual
#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Itd.

class Instrument {
public:
  virtual void play(note) const {
    cout << "Instrument::play" << endl;
  }
};

// Obiekty klasy Wind sa obiektami typu Instrument
// poniewaz maja one taki sam interfejs:
class Wind : public Instrument {
public:
  // Zasloniecie funkcji interfejsu:
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
