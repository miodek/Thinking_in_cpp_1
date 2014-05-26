//: C09:EvaluationOrder.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Kolejnosc wyliczania funkcji inline

class Forward {
  int i;
public:
  Forward() : i(0) {}
  // Wywolanie niezadeklarowanej funkcji:
  int f() const { return g() + 1; }
  int g() const { return i; }
};

int main() {
  Forward frwd;
  frwd.f();
} ///:~
