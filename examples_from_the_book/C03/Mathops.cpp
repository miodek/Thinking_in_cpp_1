//: C03:Mathops.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Operatory matematyczne
#include <iostream>
using namespace std;

// Makroinstrukcja, wyswietlajaca lancuch i wartosc
#define PRINT(STR, VAR) \
  cout << STR " = " << VAR << endl

int main() {
  int i, j, k;
  float u, v, w;  // Odnosi sie rowniez do liczb double
  cout << "wprowadz liczbe calkowita: ";
  cin >> j;
  cout << "wprowadz jeszcze jedna liczbe calkowita: ";
  cin >> k;
  PRINT("j",j);  PRINT("k",k);
  i = j + k; PRINT("j + k",i);
  i = j - k; PRINT("j - k",i);
  i = k / j; PRINT("k / j",i);
  i = k * j; PRINT("k * j",i);
  i = k % j; PRINT("k % j",i);
  // Nastepne dzialaja tylko z liczbami calkowitymi:
  j %= k; PRINT("j %= k", j);
  cout << "Wprowadz liczbe zmiennopozycyjna: ";
  cin >> v;
  cout << "Wprowadz jeszcze jedna liczbe zmiennopozycyjna:";
  cin >> w;
  PRINT("v",v); PRINT("w",w);
  u = v + w; PRINT("v + w", u);
  u = v - w; PRINT("v - w", u);
  u = v * w; PRINT("v * w", u);
  u = v / w; PRINT("v / w", u);
  // Nastepne dzialaja z liczbami calkowitymi,
  // znakami i liczbami double:
  PRINT("u", u); PRINT("v", v);
  u += v; PRINT("u += v", u);
  u -= v; PRINT("u -= v", u);
  u *= v; PRINT("u *= v", u);
  u /= v; PRINT("u /= v", u);
} ///:~
