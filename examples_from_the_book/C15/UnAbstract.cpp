//: C15:UnAbstract.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wydaje sie, ze czysto wirtualne 
// destruktory zachowuja sie dziwnie

class AbstractBase {
public:
  virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase {};
// Nie jest potrzebne zasloniecie destruktora?

int main() { Derived d; } ///:~
