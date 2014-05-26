//: C12:Byte.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przeciazone operatory bedace funkcjami skladowymi
#ifndef BYTE_H
#define BYTE_H
#include "../require.h"
#include <iostream>
// Funkcje skladowe (niejawny argument "this"):
class Byte { 
  unsigned char b;
public:
  Byte(unsigned char bb = 0) : b(bb) {}
  // Brak skutkow ubocznych - stale funkcje skladowe:
  const Byte
    operator+(const Byte& right) const {
    return Byte(b + right.b);
  }
  const Byte
    operator-(const Byte& right) const {
    return Byte(b - right.b);
  }
  const Byte
    operator*(const Byte& right) const {
    return Byte(b * right.b);
  }
  const Byte
    operator/(const Byte& right) const {
    require(right.b != 0, "dzielenie przez zero");
    return Byte(b / right.b);
  }
  const Byte
    operator%(const Byte& right) const {
    require(right.b != 0, "modulo zero");
    return Byte(b % right.b);
  }
  const Byte
    operator^(const Byte& right) const {
    return Byte(b ^ right.b);
  }
  const Byte
    operator&(const Byte& right) const {
    return Byte(b & right.b);
  }
  const Byte
    operator|(const Byte& right) const {
    return Byte(b | right.b);
  }
  const Byte
    operator<<(const Byte& right) const {
    return Byte(b << right.b);
  }
  const Byte
    operator>>(const Byte& right) const {
    return Byte(b >> right.b);
  }
  // Przypisania modyfikujace i zwracajace l-wartosc:
  // operator= moze byc tylko funkcja skladowa:
  Byte& operator=(const Byte& right) {
    // Obsluga przypisania do siebie samego:
    if(this == &right) return *this;
    b = right.b;
    return *this;
  }
  Byte& operator+=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b += right.b;
    return *this;
  }
  Byte& operator-=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b -= right.b;
    return *this;
  }
  Byte& operator*=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b *= right.b;
    return *this;
  }
  Byte& operator/=(const Byte& right) {
    require(right.b != 0, "dzielenie przez zero");
    if(this == &right) {/* przypisanie do siebie samego */}
    b /= right.b;
    return *this;
  }
  Byte& operator%=(const Byte& right) {
    require(right.b != 0, "modulo zero");
    if(this == &right) {/* przypisanie do siebie samego */}
    b %= right.b;
    return *this;
  }
  Byte& operator^=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b ^= right.b;
    return *this;
  }
  Byte& operator&=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b &= right.b;
    return *this;
  }
  Byte& operator|=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b |= right.b;
    return *this;
  }
  Byte& operator>>=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b >>= right.b;
    return *this;
  }
  Byte& operator<<=(const Byte& right) {
    if(this == &right) {/* przypisanie do siebie samego */}
    b <<= right.b;
    return *this;
  }
  // Operatory warunkowe, zwracajace wartosci true lub false:
  int operator==(const Byte& right) const {
      return b == right.b;
  }
  int operator!=(const Byte& right) const {
      return b != right.b;
  }
  int operator<(const Byte& right) const {
      return b < right.b;
  }
  int operator>(const Byte& right) const {
      return b > right.b;
  }
  int operator<=(const Byte& right) const {
      return b <= right.b;
  }
  int operator>=(const Byte& right) const {
      return b >= right.b;
  }
  int operator&&(const Byte& right) const {
      return b && right.b;
  }
  int operator||(const Byte& right) const {
      return b || right.b;
  }
  // Zapis wartosci do strumienia wyjsciowego:
  void print(std::ostream& os) const {
    os << "0x" << std::hex << int(b) << std::dec;
  }
}; 
#endif // BYTE_H ///:~
