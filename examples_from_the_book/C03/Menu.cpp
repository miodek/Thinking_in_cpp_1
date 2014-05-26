//: C03:Menu.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prosty program menu, ilustrujacy
// uzycie instrukcji "break" i "continue"
#include <iostream>
using namespace std;

int main() {
  char c; // Do przechowywania odpowiedzi
  while(true) {
    cout << "GLOWNE MENU:" << endl;
    cout << "l: lewe, p: prawe, w: wyjscie -> ";
    cin >> c;
    if(c == 'w')
      break; // Wyjscie z "while(1)"
    if(c == 'l') {
      cout << "LEWE MENU:" << endl;
      cout << "wybierz a lub b: ";
      cin >> c;
      if(c == 'a') {
        cout << "wybrales 'a'" << endl;
        continue; // Powrot do glownego menu
      }
      if(c == 'b') {
        cout << "wybrales 'b'" << endl;
        continue; // Powrot do glownego menu
      }
      else {
        cout << "nie wybrales a ani b!"
             << endl;
        continue; // Powrot do glownego menu
      }
    }
    if(c == 'p') {
      cout << "PRAWE MENU:" << endl;
      cout << "wybierz c lub d: ";
      cin >> c;
      if(c == 'c') {
        cout << "wybrales 'c'" << endl;
        continue; // Powrot do glownego menu
      }
      if(c == 'd') {
        cout << "wybrales 'd'" << endl;
        continue; // Powrot do glownego menu
      }
      else {
        cout << "nie wybrales c ani d!" 
             << endl;
        continue; // Powrot do glownego menu
      }
    }
    cout << "musisz wpisac l, p albo w!" << endl;
  }
  cout << "wyjscie z menu..." << endl;
} ///:~
