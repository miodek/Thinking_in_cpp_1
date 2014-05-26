//: C03:Menu2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Menu utworzone za pomoc¹ instrukcji switch
#include <iostream>
using namespace std;

int main() {
  bool quit = false;  // Znacznik wyjscia
  while(quit == false) {
    cout << "Wybierz a, b, c lub w, aby wyjsc: ";
    char response;
    cin >> response;
    switch(response) {
      case 'a' : cout << "wybrales 'a'" << endl;
                 break;
      case 'b' : cout << "wybrales 'b'" << endl;
                 break;
      case 'c' : cout << "wybrales 'c'" << endl;
                 break;
      case 'w' : cout << "wyjscie z menu" << endl;
                 quit = true;
                 break;
      default  : cout << "Uzyj a,b,c lub w!"
                 << endl;
    }
  }
} ///:~
