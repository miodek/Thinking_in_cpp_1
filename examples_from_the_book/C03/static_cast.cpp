//: C03:static_cast.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
void func(int) {}

int main() {
  int i = 0x7fff; // Maksymalna dodatnia wartosc = 32767
  long l;
  float f;
  // (1) Typowe konwersje bez uzycia rzutowania:
  l = i;
  f = i;
  // Dzialaja rowniez:
  l = static_cast<long>(i);
  f = static_cast<float>(i);

  // (2) Konwersje zawezajace:
  i = l; // Mozliwosc utraty cyfr
  i = f; // Mozliwosc utraty informacji
  // Powiedzenie "wiem o tym" eliminuje ostrzezenia:
  i = static_cast<int>(l);
  i = static_cast<int>(f);
  char c = static_cast<char>(i);

  // (3) Wymuszenie konwersji z typu void* :
  void* vp = &i;
  // Stary sposob powoduje niebezpieczna konwersje:
  float* fp = (float*)vp;
  // Nowy jest rownie niebezpieczny:
  fp = static_cast<float*>(vp);

  // (4) Niejawne konwersje typow, dokonywane
  // zazwyczaj przez kompilator:
  double d = 0.0;
  int x = d; // Automatyczna konwersja typu
  x = static_cast<int>(d); // Bardziej jawna konwersja
  func(d); // Automatyczna konwersja typu
  func(static_cast<int>(d)); // Bardziej jawna konwersja
} ///:~
