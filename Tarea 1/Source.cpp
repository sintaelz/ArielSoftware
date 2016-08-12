#include "Laptop.h"
#include "Desktop.h"
#include "Netbook.h"
#include "Tablet.h"
#include <stdio.h>
#include <string>

short choice;

int main()
{
  cout << "Que tipo de dispositivo deseas construir? Escoge el numero del dipositivo" << endl << "1. Laptop" << endl << "2. Desktop" << endl << "3. Netbook" << endl << "4. Tablet" << endl;
  while (choice <= 0 && choice >= 5)
  cin >> choice
  
  switch (choice)
  {
    case'1':
    Laptop *l1 = new Laptop;
    break;

    case'2':
    Desktop *d1 = new Desktop;
    break;

    case'3':
    Netbook *n1 = new Netbook;
    break;

    case'4':
    Tablet *t1 = new Tablet;
    break;
  }

}
