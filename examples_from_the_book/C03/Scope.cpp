//: C03:Scope.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Zasieg zmiennych
int main() {
  int scp1;
  // scp1 jest widoczna
  {
    // scp1 jest nadal widoczna
    //.....
    int scp2;
    // scp2 jest widoczna
    //.....
    {
      // scp1 i scp2 sa nadal widoczne
      //..
      int scp3;
      // scp1, scp2 i scp3 sa widoczne
      // ...
    } // <-- scp3 w tym miejscu przestala istniec
    // scp3 nie jest dostepna
    // scp1 i scp2 sa nadal widoczne
    // ...
  } // <-- scp2 w tym miejscu przestala istniec
  // scp3 i scp2 nie sa w tym miejscu dostepne
  // scp1 jest nadal widoczna
  //..
} // <-- scp1 w tym miejscu przestala istniec
///:~
