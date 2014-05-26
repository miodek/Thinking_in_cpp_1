//: C03:Enum.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zapamiêtywanie ksztaltow

enum ShapeType {
  circle,
  square,
  rectangle
};  // Musi konczyc sie srednikiem, tak jak struct

int main() {
  ShapeType shape = circle;
  // Jakies operacje...
  // A teraz dzialania zalezne od ksztaltu:
  switch(shape) {
    case circle:  /* obsluga okregu */ break;
    case square:  /* obsluga kwadratu */ break;
    case rectangle:  /* obsluga prostokata */ break;
  }
} ///:~
