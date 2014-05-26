//: C03:FileStatic.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Demonstracja zasiegu pliku. Skompilowanie
// i polaczenie pliku wraz z plikiem FileStatic2.cpp
// wywola blad programu laczacego

// Zasieg pliku oznacza dostepnosc wylacznie 
// w biezacym pliku:
static int fs; 

int main() {
  fs = 1;
} ///:~
