//: C05:Handle.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Klasy-uchwyty
#ifndef HANDLE_H
#define HANDLE_H

class Handle {
  struct Cheshire; // Tylko deklaracja klasy
  Cheshire* smile;
public:
  void initialize();
  void cleanup();
  int read();
  void change(int);
};
#endif // HANDLE_H ///:~
