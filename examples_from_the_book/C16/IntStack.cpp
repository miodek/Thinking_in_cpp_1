//: C16:IntStack.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prosty stos liczb calkowitych
//{L} fibonacci
#include "fibonacci.h"
#include "../require.h"
#include <iostream>
using namespace std;

class IntStack {
  enum { ssize = 100 };
  int stack[ssize];
  int top;
public:
  IntStack() : top(0) {}
  void push(int i) {
    require(top < ssize, "Zbyt wiele wywolan funkcji push()");
    stack[top++] = i;
  }
  int pop() {
    require(top > 0, "Zbyt wiele wywolan funkcji pop()");
    return stack[--top];
  }
};

int main() {
  IntStack is;
  // Umieszczenie na stosie kilku liczb Fibonacciego,
  // w celu uczynienia go bardziej interesujacym:
  for(int i = 0; i < 20; i++)
    is.push(fibonacci(i));
  // Pobranie ze stosu i wydrukowanie liczb:
  for(int k = 0; k < 20; k++)
    cout << is.pop() << endl;
} ///:~
