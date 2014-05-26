//: C14:SynthesizedFunctions.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Funkcje generowane przez kompilator
#include <iostream>
using namespace std;

class GameBoard {
public:
  GameBoard() { cout << "GameBoard()\n"; }
  GameBoard(const GameBoard&) { 
    cout << "GameBoard(const GameBoard&)\n"; 
  }
  GameBoard& operator=(const GameBoard&) {
    cout << "GameBoard::operator=()\n";
    return *this;
  }
  ~GameBoard() { cout << "~GameBoard()\n"; }
};

class Game {
  GameBoard gb; // Kompozycja
public:
  // Wywolywany domyslny konstruktor klasy GameBoard:
  Game() { cout << "Game()\n"; }
  // Trzeba jawnie wywolac konstruktor kopiujacy
  // klasy GameBoard, gdyz w przeciwnym przypadku
  // zamiast niego zostanie wywolany 
  // automatycznie domyslny konstruktor:
  Game(const Game& g) : gb(g.gb) { 
    cout << "Game(const Game&)\n"; 
  }
  Game(int) { cout << "Game(int)\n"; }
  Game& operator=(const Game& g) {
    // Trzeba jawnie wywolac operator przypisania
    // klasy GameBoard, gdyz w przeciwnym przypadku
    // przypisywanie gb nie bedzie w ogole
    // realizowane!
    gb = g.gb;
    cout << "Game::operator=()\n";
    return *this;
  }
  class Other {}; // Zagniezdzona klasa
  // Automatyczna konwersja typu:
  operator Other() const {
    cout << "Game::operator Other()\n";
    return Other();
  }
  ~Game() { cout << "~Game()\n"; }
};

class Chess : public Game {};

void f(Game::Other) {}

class Checkers : public Game {
public:
  // Wywolywany domyslny konstruktor klasy podstawowej:
  Checkers() { cout << "Checkers()\n"; }
  // Trzeba jawnie wywolac konstruktor kopiujacy 
  // klasy podstawowej, gdyz w przeciwnym przypadku
  // zostanie zamiast niego wywolany konstruktor domyslny:
  Checkers(const Checkers& c) : Game(c) {
    cout << "Checkers(const Checkers& c)\n";
  }
  Checkers& operator=(const Checkers& c) {
    // Trzeba jawnie wywolac wersje operatora=(),
    // znajdujaca sie w klasie podstawowej, gdyz
    // w przeciwnym przypadku w klasie podstawowej
    // nie zostanie zrealizowana operacja przypisania:
    Game::operator=(c);
    cout << "Checkers::operator=()\n";
    return *this;
  }
};

int main() {
  Chess d1;  // Domyslny konstruktor
  Chess d2(d1); // Konstruktor kopiujacy
//! Chess d3(1); // Blad - nie ma konstruktora z argumentem int
  d1 = d2; // Wygenerowany operator=
  f(d1); // Konwersja typow JEST dziedziczona
  Game::Other go;
//!  d1 = go; // operator= nie jest generowany
           // dla roznych typow
  Checkers c1, c2(c1);
  c1 = c2;
} ///:~
