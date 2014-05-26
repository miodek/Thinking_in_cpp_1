//: C14:PrivateInheritance.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
class Pet {
public:
  char eat() const { return 'a'; }
  int speak() const { return 2; }
  float sleep() const { return 3.0; }
  float sleep(int) const { return 4.0; }
};

class Goldfish : Pet { // Dziedziczenie prywatne
public:
  Pet::eat; // Nazwa upublicznionej skladowej
  Pet::sleep; // Widoczne sa obie przeciazone funkcje skladowe
};

int main() {
  Goldfish bob;
  bob.eat();
  bob.sleep();
  bob.sleep(1);
//! bob.speak();// Blad - prywatna funkcja skladowa
} ///:~
