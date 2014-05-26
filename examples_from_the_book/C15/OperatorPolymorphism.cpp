//: C15:OperatorPolymorphism.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Polimorfizm z przeciazonymi operatorami
#include <iostream>
using namespace std;

class Matrix;
class Scalar;
class Vector;

class Math {
public:
  virtual Math& operator*(Math& rv) = 0;
  virtual Math& multiply(Matrix*) = 0;
  virtual Math& multiply(Scalar*) = 0;
  virtual Math& multiply(Vector*) = 0;
  virtual ~Math() {}
};

class Matrix : public Math { // Macierz
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // Drugi przydzial
  }
  Math& multiply(Matrix*) {
    cout << "Macierz * Macierz" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Skalar * Macierz" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Wektor * Macierz" << endl;
    return *this;
  }
};

class Scalar : public Math  { // Skalar
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // Drugi przydzial
  }
  Math& multiply(Matrix*) {
    cout << "Macierz * Skalar" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Skalar * Skalar" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Wektor * Skalar" << endl;
    return *this;
  }
};

class Vector : public Math  { // Wektor
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // Drugi przydzial
  }
  Math& multiply(Matrix*) {
    cout << "Macierz * Wektor" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Skalar * Wektor" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Wektor * Wektor" << endl;
    return *this;
  }
};

int main() {
  Matrix m; Vector v; Scalar s;
  Math* math[] = { &m, &v, &s };
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
      Math& m1 = *math[i];
      Math& m2 = *math[j];
      m1 * m2;
    }
} ///:~
