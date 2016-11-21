//Seung Hoon Lee
//A01021720
//Chain of Responsibility Pattern

#include <iostream>

using namespace std;

class Base
{
    Base *next;
  public:
    Base()
    {
        next = 0;
    }
    void setNext(Base *n)
    {
        next = n;
    }
    void add(Base *n)
    {
        if (next)
          next->add(n);
        else
          next = n;
    }

    virtual void handle(int i)
    {
        next->handle(i);
    }
};

class Taker1: public Base
{
  public:
    void handle(int i)
    {
        if (i % 2 == 0)
        {
            cout << "Yo no puedo tomar este numero, pasandoselo al segundo" << i << "  ";
            Base::handle(i);
        }
        else
          cout << "Yo tome este numero (Taker1) " << i << "  ";
    }
};

class Taker2: public Base
{
  public:
    void handle(int i)
    {
        if (i % 3 == 0)
        {
            cout << "Yo no puedo tomar este numero, pasandoselo al tercero " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "Yo tome este numero (Taker2) " << i << "  ";
    }
};

class Taker3: public Base
{
  public:
    void handle(int i)
    {
        if (i % 7 == 0)
        {
            cout << "Yo no puedo tomar este numero, pasandoselo al primero " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "Yo tome este numero (Taker3) " << i << "  ";
    }
};

int main()
{
  //Hacemos una cadena de responsabilidad en donde si un numero % x no se puede hacer, se lo pasa al siguiente para ver si si lo puede hacer
  Taker1 root; //Creamos los 3 takers
  Taker2 two;
  Taker3 thr;
  root.add(&two); //Agregamos como base a Taker1, a los otros 2 takers
  root.add(&thr);
  thr.setNext(&root); //Agregamos al next del ultimo taker,como nuestro primero
  for (int i = 1; i < 10; i++)
  {
    root.handle(i);
    cout << '\n';
  }
}
