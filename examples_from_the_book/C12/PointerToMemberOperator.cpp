//: C12:PointerToMemberOperator.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;

class Dog {
public:
  int run(int i) const { 
    cout << "biega\n";  
    return i; 
  }
  int eat(int i) const { 
     cout << "je\n";  
     return i; 
  }
  int sleep(int i) const { 
    cout << "spi\n"; 
    return i; 
  }
  typedef int (Dog::*PMF)(int) const;
  // operator->* musi zwrocic obiekt 
  // posiadajacy operator():
  class FunctionObject {
    Dog* ptr;
    PMF pmem;
  public:
    // Zapamietanie wskaznika obiektu i wskaznika skladowej
    FunctionObject(Dog* wp, PMF pmf) 
      : ptr(wp), pmem(pmf) { 
      cout << "Konstruktor FunctionObject\n";
    }
    // Wywolanie, wykorzystujace wskaznik obiektu
    // i wskaznik skladowej
    int operator()(int i) const {
      cout << "FunctionObject::operator()\n";
      return (ptr->*pmem)(i); // Wywolanie
    }
  };
  FunctionObject operator->*(PMF pmf) { 
    cout << "operator->*" << endl;
    return FunctionObject(this, pmf);
  }
};
 
int main() {
  Dog w;
  Dog::PMF pmf = &Dog::run;
  cout << (w->*pmf)(1) << endl;
  pmf = &Dog::sleep;
  cout << (w->*pmf)(2) << endl;
  pmf = &Dog::eat;
  cout << (w->*pmf)(3) << endl;
} ///:~
