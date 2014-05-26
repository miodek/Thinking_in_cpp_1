//: C08:PointerAssignment.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
int d = 1;
const int e = 2;
int* u = &d; // W porzadku - d nie jest stala
//! int* v = &e; // Niedozwolone - e jest stala
int* w = (int*)&e; // Dozwolone, ale jest to zly styl
int main() {} ///:~
