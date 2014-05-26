//: C03:Boolean.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Operatory relacji i operatory logiczne
#include <iostream>
using namespace std;

int main() {
  int i,j;
  cout << "Wprowadz liczbe calkowita: ";
  cin >> i;
  cout << "Wprowadz jeszcze jedna liczbe calkowita: ";
  cin >> j;
  cout << "i > j wynosi " << (i > j) << endl;
  cout << "i < j wynosi " << (i < j) << endl;
  cout << "i >= j wynosi " << (i >= j) << endl;
  cout << "i <= j wynosi " << (i <= j) << endl;
  cout << "i == j wynosi " << (i == j) << endl;
  cout << "i != j wynosi " << (i != j) << endl;
  cout << "i && j wynosi " << (i && j) << endl;
  cout << "i || j wynosi " << (i || j) << endl;
  cout << " (i < 10) && (j < 10) wynosi "
       << ((i < 10) && (j < 10))  << endl;
} ///:~
