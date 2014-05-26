//: C02:Scopy.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Kopiowanie jednego pliku do drugiego, po wierszu
#include <string>
#include <fstream>
using namespace std;

int main() {
  ifstream in("Scopy.cpp"); // Otwarcie do odczytu
  ofstream out("Scopy2.cpp"); // Otwarcie do zapisu
  string s;
  while(getline(in, s)) // Usuwa znak nowego wiersza
    out << s << "\n"; // ... musi dodac go z powrotem
} ///:~
