//: C16:OwnerStackTest.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{L} AutoCounter 
#include "AutoCounter.h"
#include "OwnerStack.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  Stack<AutoCounter> ac; // Przydzielenie prawa wlasnosci
  Stack<AutoCounter> ac2(false); // Odebranie prawa wlasnosci
  AutoCounter* ap;
  for(int i = 0; i < 10; i++) {
    ap = AutoCounter::create();
    ac.push(ap);
    if(i % 2 == 0)
      ac2.push(ap);
  }
  while(ac2)
    cout << ac2.pop() << endl;
  // Nie jest konieczne niszczenie obiektow,
  // poniewaz kontener ac jest "wlascicielem"
  // wszystkich obiektow
} ///:~
