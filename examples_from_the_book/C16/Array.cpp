//: C16:Array.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "../require.h"
#include <iostream>
using namespace std;

template<class T>
class Array {
  enum { size = 100 };
  T A[size];
public:
  T& operator[](int index) {
    require(index >= 0 && index < size,
      "Indeks poza zakresem");
    return A[index];
  }
};

int main() {
  Array<int> ia;
  Array<float> fa;
  for(int i = 0; i < 20; i++) {
    ia[i] = i * i;
    fa[i] = float(i) * 1.414;
  }
  for(int j = 0; j < 20; j++)
    cout << j << ": " << ia[j]
         << ", " << fa[j] << endl;
} ///:~
