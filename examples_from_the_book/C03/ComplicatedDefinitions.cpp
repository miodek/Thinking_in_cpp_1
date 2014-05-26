//: C03:ComplicatedDefinitions.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt

/* 1. */     void * (*(*fp1)(int))[10];

/* 2. */     float (*(*fp2)(int,int,float))(int);

/* 3. */     typedef double (*(*(*fp3)())[10])();
             fp3 a;

/* 4. */     int (*(*f4())[10])();

int main() {} ///:~
