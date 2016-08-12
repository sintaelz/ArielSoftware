#include "Laptop.h"
#include "Desktop.h"
#include "Netbook.h"
#include "Tablet.h"
#include <stdio.h>
#include <string>

int choice;

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
  switch (choice)
  {
    case 1:
    {
      Laptop *l1 = new Laptop();
      cout << endl;
      break;
    }
    case 2:
    {
      Desktop *d1 = new Desktop();
      cout << endl;
      break;
    }
    case 3:
    {
      Netbook *n1 = new Netbook();
      cout << endl;
      break;
    }
    case 4:
    {
      Tablet *t1 = new Tablet();
      cout << endl;
      break;
    }
  }

}
