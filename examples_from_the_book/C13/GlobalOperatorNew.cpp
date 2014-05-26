//: C13:GlobalOperatorNew.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przeciazanie globalnych operatorow new i delete
#include <cstdio>
#include <cstdlib>
using namespace std;

void* operator new(size_t sz) {
  printf("operator new: %d bajtow\n", sz);
  void* m = malloc(sz);
  if(!m) puts("brak pamieci");
  return m;
}

void operator delete(void* m) {
  puts("operator delete");
  free(m);
}

class S {
  int i[100];
public:
  S() { puts("S::S()"); }
  ~S() { puts("S::~S()"); }
};

int main() {
  puts("tworzenie i niszczenie zmiennej calkowitej");
  int* p = new int(47);
  delete p;
  puts("tworzenie i niszczenie obiektu s");
  S* s = new S;
  delete s;
  puts("tworzenie i niszczenie tablicy S[3]");
  S* sa = new S[3];
  delete []sa;
} ///:~
