//: C16:TPStashTest.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{L} AutoCounter
#include "AutoCounter.h"
#include "TPStash.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  PStash<AutoCounter> acStash;
  for(int i = 0; i < 10; i++)
    acStash.add(AutoCounter::create());
  cout << "Reczne usuniecie 5 elementow:" << endl;
  for(int j = 0; j < 5; j++)
    delete acStash.remove(j);
  cout << "Usuniecie dwoch elementow bez ich niszczenia:"
       << endl;
  // ... wymuszenie generacji komunikatow o bledach.
  cout << acStash.remove(5) << endl;
  cout << acStash.remove(6) << endl;
  cout << "Reszte usuwa destruktor:"
       << endl;
  // Powtorzenie testow z wczesniejszych rozdzialow: 
  ifstream in("TPStashTest.cpp");
  assure(in, "TPStashTest.cpp");
  PStash<string> stringStash;
  string line;
  while(getline(in, line))
    stringStash.add(new string(line));
  // Drukowanie lancuchow:
  for(int u = 0; stringStash[u]; u++)
    cout << "stringStash[" << u << "] = "
         << *stringStash[u] << endl;
} ///:~
