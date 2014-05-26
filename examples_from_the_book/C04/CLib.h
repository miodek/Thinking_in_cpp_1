//: C04:CLib.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Plik naglowkowy biblioteki w stylu C
// Tablicopodobny twor, tworzony w czasie
// pracy programu

typedef struct CStashTag {
  int size;      // Wielkosc kazdego elementu
  int quantity;  // Liczba elementow pamieci
  int next;      // Nastepny pusty element
  // Dynamicznie przydzielana tablica bajtow:
  unsigned char* storage;
} CStash;

void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);
///:~
