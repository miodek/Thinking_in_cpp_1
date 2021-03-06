//: C11:Linenum.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{T} Linenum.cpp
// Numerowanie wierszy
#include "../require.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
  requireArgs(argc, 1, "Uzycie: linenum plik\n"
    "Numerowanie wierszy pliku");
  ifstream in(argv[1]);
  assure(in, argv[1]);
  string line;
  vector<string> lines;
  while(getline(in, line)) // Wczytanie calego pliku
    lines.push_back(line);
  if(lines.size() == 0) return 0;
  int num = 0;
  // Liczba wierszy w pliku okresla szerokosc:
  const int width = int(log10(lines.size())) + 1;
  for(int i = 0; i < lines.size(); i++) {
    cout.setf(ios::right, ios::adjustfield);
    cout.width(width);
    cout << ++num << ") " << lines[i] << endl;
  }
} ///:~
