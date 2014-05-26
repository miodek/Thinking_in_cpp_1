//: C10:SimpleStaticMemberFunction.cpp 
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class X {
public:
  static void f(){};
};

int main() {
  X::f();
} ///:~
