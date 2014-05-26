//: C09:Rectangle.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Obserwatory i modyfikatory

class Rectangle {
  int wide, high;
public:
  Rectangle(int w = 0, int h = 0)
    : wide(w), high(h) {}
  int width() const { return wide; } // Odczyt
  void width(int w) { wide = w; } // Zapis
  int height() const { return high; } // Odczyt
  void height(int h) { high = h; } // Zapis
};

int main() {
  Rectangle r(19, 47);
  // Zmiana szerokosci (width) i wysokosci (height):
  r.height(2 * r.width());
  r.width(2 * r.height());
} ///:~
