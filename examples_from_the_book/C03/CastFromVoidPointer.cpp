//: C03:CastFromVoidPointer.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
int main() {
  int i = 99;
  void* vp = &i;
  // Nie mozna dokonac wyluskania ze wskaznika void*:
  // *vp = 3; // Blad kompilacji
  // Przed wyluskaniem, trzeba rzutowac 
  // z powrotem na typ int:
  *((int*)vp) = 3;
} ///:~
