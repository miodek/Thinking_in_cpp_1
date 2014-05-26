//: C10:StaticMemberFunctions.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class X {
  int i;
  static int j;
public:
  X(int ii = 0) : i(ii) {
     // Funkcje skladowe, nie bedace funkcjami 
     // statycznymi, maja dostep do statycznych
     // funkcji skladowych oraz statycznych danych:
    j = i;
  }
  int val() const { return i; }
  static int incr() {
    //! i++; // Blad - statyczna funkcja skladowa
    // nie ma dostepu do danych skladowych, ktore 
    // nie sa statyczne
    return ++j;
  }
  static int f() {
    //! val(); // Blad - statyczna funkcja skladowa
    // nie ma dostepu do funkcji skladowej, ktora
    // nie jest funkcja statyczna
    return incr(); // W porzadku - wywolanie funkcji statycznej
  }
};

int X::j = 0;

int main() {
  X x;
  X* xp = &x;
  x.f();
  xp->f();
  X::f(); // Dziala tylko ze skladowymi statycznymi
} ///:~
