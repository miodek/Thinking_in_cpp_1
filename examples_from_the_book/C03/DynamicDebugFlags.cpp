//: C03:DynamicDebugFlags.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
#include <string>
using namespace std;
// Znaczniki uruchomieniowe nie musza 
// byc koniecznie globalne:
bool debug = false;

int main(int argc, char* argv[]) {
  for(int i = 0; i < argc; i++)
    if(string(argv[i]) == "--debug=on")
      debug = true;
  bool go = true;
  while(go) {
    if(debug) {
      // Kod uruchomieniowy
      cout << "Program uruchomieniowy wlaczony!" << endl;
    } else {
      cout << "Program uruchomieniowy wylaczony." << endl;
    }  
    cout << "Zmien stan programu [wlacz/wylacz/wyjdz]: ";
    string reply;
    cin >> reply;
    if(reply == "wlacz") debug = true; // Wlacz go
    if(reply == "wylacz") debug = false; // Wylacz
    if(reply == "wyjdz") break; // Wyjscie z petli 'while'
  }
} ///:~
