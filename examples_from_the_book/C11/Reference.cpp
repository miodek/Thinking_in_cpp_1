//: C11:Reference.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Proste referencje jezyka C++

int* f(int* x) {
  (*x)++;
  return x; // Bezpieczne, zmienna x znajduje sie poza zasiegiem
}

int& g(int& x) {
  x++; // Taki sam rezultat, jak w funkcji f()
  return x; // Bezpieczne, zmienna x znajduje sie poza zasiegiem
}

int& h() {
  int q;
//!  return q;  // Blad
  static int x;
  return x; // Bezpieczne, zmienna x znajduje sie poza zasiegiem
}

int main() {
  int a = 0;
  f(&a); // Brzydko (choc jawnie)
  g(a);  // Przejrzyscie (lecz w ukryty sposob)
} ///:~
