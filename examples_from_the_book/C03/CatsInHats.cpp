//: C03:CatsInHats.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prosty przyklad rekurencji
#include <iostream>
using namespace std;

void removeHat(char cat) {
  for(char c = 'A'; c < cat; c++)
    cout << "  ";
  if(cat <= 'Z') {
    cout << "kot " << cat << endl;
    removeHat(cat + 1); // Wywolanie rekurencyjne
  } else
    cout << "MIAAAL!!!" << endl;
}

int main() {
  removeHat('A');
} ///:~
