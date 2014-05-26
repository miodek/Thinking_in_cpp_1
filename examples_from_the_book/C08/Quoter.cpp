//: C08:Quoter.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Losowy wybor cytatu
#include <iostream>
#include <cstdlib> // Generator liczb losowych
#include <ctime> // Do inicjalizacji generatora liczb losowych
using namespace std;

class Quoter {
  int lastquote;
public:
  Quoter();
  int lastQuote() const;
  const char* quote();
};

Quoter::Quoter(){
  lastquote = -1;
  srand(time(0)); // Inicjalizacja generatora liczb losowych
}

int Quoter::lastQuote() const {
  return lastquote;
}

const char* Quoter::quote() {
  static const char* quotes[] = {
    "Czy mamy sie juz smiac?",
    "Lekarze zawsze wiedza najlepiej",
    "Sowy nie sa tym, czym sie wydaja",
    "Strach ma wielkie oczy",
    "Nie ma naukowego dowodu "
    "na poparcie tezy "
    "ze zycie jest na serio",
    "To, co nas bawi, czyni nas madrzejszymi",
  };
  const int qsize = sizeof quotes/sizeof *quotes;
  int qnum = rand() % qsize;
  while(lastquote >= 0 && qnum == lastquote)
    qnum = rand() % qsize;
  return quotes[lastquote = qnum];
}

int main() {
  Quoter q;
  const Quoter cq;
  cq.lastQuote(); // W porzadku
//!  cq.quote(); // Zle - nie jest to funkcja stala
  for(int i = 0; i < 20; i++)
    cout << q.quote() << endl;
} ///:~
