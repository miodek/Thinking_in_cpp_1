//: C03:Ifthen.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Demonstracja instrukcji warunkowych if i if-else
#include <iostream>
using namespace std;

int main() {
  int i;
  cout << "wpisz liczbe i nacisnij 'Enter'" << endl;
  cin >> i;
  if(i > 5)
    cout << "Jest wieksza niz 5" << endl;
  else
    if(i < 5)
      cout << "Jest mniejsza niz 5 " << endl;
    else
      cout << "Jest rowna 5 " << endl;

  cout << "wpisz liczbe i nacisnij 'Enter'" << endl;
  cin >> i;
  if(i < 10)
    if(i > 5)  // "if" jest po prostu kolejna instrukcja
      cout << "5 < i < 10" << endl;
    else
      cout << "i <= 5" << endl;
  else // Skojarzone z "if(i < 10)"
    cout << "i >= 10" << endl;
} ///:~
