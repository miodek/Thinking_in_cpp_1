//: C08:Constag.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Stale a agregaty
const int i[] = { 1, 2, 3, 4 };
//! float f[i[3]]; // Niedozwolone
struct S { int i, j; };
const S s[] = { { 1, 2 }, { 3, 4 } };
//! double d[s[1].j]; // Niedozwolone
int main() {} ///:~
