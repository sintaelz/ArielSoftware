#include "Factory.h"
#include <stdio.h>

int choice;

int main()
{
  cout << "Que tipo de dispositivo deseas construir? Escoge el numero del dipositivo" << endl << "1. Laptop" << endl << "2. Desktop" << endl << "3. Tablet" << endl << "4. Netbook" << endl << endl;

  cin >> choice;
  while (choice <= 0 || choice >= 5)
  {
    cout << "Tu numero no esta entre el 1 y el 4, favor de reingresar el numero" << endl;
    cin >> choice;
  }
  cout << endl;

  concreteCreator* client = concreteCreator::singleton();

  switch (choice)
  {
    case 1:
    {
      Computadoras* myComputer = client->crearProducto(1);
      //Computadoras* myComputer2 = myComputer->clone(); // clonar computadora
      break;
    }
    case 2:
    {
      Computadoras* myComputer = client->crearProducto(2);
      break;
    }
    case 3:
    {
      Computadoras* myComputer = client->crearProducto(3);
      break;
    }
    case 4:
    {
      Computadoras* myComputer = client->crearProducto(4);
      break;
    }
  }
  return 0;
}
/* Comentamos el main del pasado
int main()
{
  cout << "Que tipo de dispositivo deseas construir? Escoge el numero del dipositivo" << endl << "1. Laptop" << endl << "2. Desktop" << endl << "3. Netbook" << endl << "4. Tablet" << endl << endl;

  cin >> choice;
  while (choice <= 0 || choice >= 5)
  {
    cout << "Tu numero no esta entre el 1 y el 4, favor de reingresar el numero" << endl;
    cin >> choice;
  }
  cout << endl;

  Factory fabrica;
  switch (choice)
  {
    case 1:
    {
      Computadoras l1 = fabrica.crear("Laptop");
      cout << endl;
      if(askReceipt())
        l1.printReceipt();
      break;
    }
    case 2:
    {
      Computadoras d1 = fabrica.crear("Desktop");
      cout << endl;
      if(askReceipt())
        d1.printReceipt();
      break;
    }
    case 3:
    {
      Computadoras n1 = fabrica.crear("Netbook");
      cout << endl;
      if(askReceipt())
        n1.printReceipt();
      break;
    }
    case 4:
    {
      Computadoras t1 = fabrica.crear("Tablet");
      cout << endl;
      if(askReceipt())
        t1.printReceipt();
      break;
    }
  }
}
bool askReceipt()
{
  char choiceWord;
  cout << "Desea ver su recibo y el resultado del dispositivo? (presione 'y' o 'n')" << endl;
  cin >> choiceWord;

  if (choiceWord == 'y')
  return true;

  else
  return false;
}*/ //Ya no vamos a utilizar este metodo
