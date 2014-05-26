//: C14:Instrument.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dziedziczenie i rzutowanie w gore
enum note { middleC, Csharp, Cflat }; // Itd.

class Instrument {
public:
  void play(note) const {}
};

// Obiekty klasy Wind sa obiektami typu Instrument
// poniewaz maja one taki sam interfejs:
class Wind : public Instrument {};

void tune(Instrument& i) {
  // ...
  i.play(middleC);
}

int main() {
  Wind flute;
  tune(flute); // Rzutowanie w gore
} ///:~
