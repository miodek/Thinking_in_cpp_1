//: C16:TStack2.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Szablon klasy Stack, zawierajacy zagniezdzony iterator
#ifndef TSTACK2_H
#define TSTACK2_H

template<class T> class Stack {
  struct Link {
    T* data;
    Link* next;
    Link(T* dat, Link* nxt)
      : data(dat), next(nxt) {}
  }* head;
public:
  Stack() : head(0) {}
  ~Stack();
  void push(T* dat) {
    head = new Link(dat, head);
  }
  T* peek() const { 
    return head ? head->data : 0;
  }
  T* pop();
  // Zagniezdzona klasa iteratora:
  class iterator; // Wymagana deklaracja
  friend class iterator; // Uczyn klase przyjacielem
  class iterator { // A teraz ja zdefiniuj
    Stack::Link* p;
  public:
    iterator(const Stack<T>& tl) : p(tl.head) {}
    // Konstruktor kopiujacy:
    iterator(const iterator& tl) : p(tl.p) {}
    // Iterator bedacy znacznikiem konca:
    iterator() : p(0) {}
    // operator++ zwraca wartosc logiczna sygnalizujaca koniec:
    bool operator++() {
      if(p->next)
        p = p->next;
      else p = 0; // Koniec listy
      return bool(p);
    }
    bool operator++(int) { return operator++(); }
    T* current() const {
      if(!p) return 0;
      return p->data;
    }
    // Operator wyluskania wskaznika:
    T* operator->() const { 
      require(p != 0, 
        "PStack::iterator::operator-> zwrocil 0");
      return current(); 
    }
    T* operator*() const { return current(); }
    // Konwersja do typu bool, do testow warunkow:
    operator bool() const { return bool(p); }
    // Porownanie, umozliwiajace wykrycie konca:
    bool operator==(const iterator&) const {
      return p == 0;
    }
    bool operator!=(const iterator&) const {
      return p != 0;
    }
  };
  iterator begin() const { 
    return iterator(*this); 
  }
  iterator end() const { return iterator(); }
};

template<class T> Stack<T>::~Stack() {
  while(head)
    delete pop();
}

template<class T> T* Stack<T>::pop() {
  if(head == 0) return 0;
  T* result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}
#endif // TSTACK2_H ///:~
