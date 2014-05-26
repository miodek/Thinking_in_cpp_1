//: C03:Rotation.cpp {O}
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wykonywanie obrotow w lewo i w prawo

unsigned char rol(unsigned char val) {
  int highbit;
  if(val & 0x80) // 0x80 jest najstarszym bitem
    highbit = 1;
  else
    highbit = 0;
  // Przesuniecie w lewo (najmlodszy bit 
  // otrzymuje wartosc 0):
  val <<= 1;
  // Wstawienie najstarszego bitu na najmlodszej pozycji:
  val |= highbit;
  return val;
}

unsigned char ror(unsigned char val) {
  int lowbit;
  if(val & 1) // Sprawdzenie wartosci najmlodszego bitu
    lowbit = 1;
  else
    lowbit = 0;
  val >>= 1; // Przesuniecie w prawo o jedna pozycje
  // Wstawienie najmlodszego bitu na najstarszej pozycji:
  val |= (lowbit << 7);
  return val;
} ///:~
