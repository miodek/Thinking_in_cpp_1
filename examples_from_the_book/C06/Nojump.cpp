//: C06:Nojump.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Nie mozna przeskakiwac konstruktorow

class X {
public:
  X();
};

X::X() {}

void f(int i) {
  if(i < 10) {
   //! goto jump1; // Blad: goto pomija inicjalizacje
  }
  X x1;  // Wywolanie konstruktora
 jump1:
  switch(i) {
    case 1 :
      X x2;  // Wywolanie konstruktora
      break;
  //! case 2 : // Blad: case pomija inicjalizacje
      X x3;  // Wywolanie konstruktora
      break;
  }
} 

int main() {
  f(9);
  f(11);
}///:~
