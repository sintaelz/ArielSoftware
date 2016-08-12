#include "Netbook.h"

Netbook::Netbook()
{
  printComponentes();
  printEnsamblado();
  printInstalacion();
  printEmpaquetado();
}

void Netbook::printComponentes()
{
  cout << "Juntando componentes necesarios para construir la desktop" << endl;
}

void Netbook::printEnsamblado()
{
  cout << "Ensamblando componentes para la desktop" << endl;
}

void Netbook::printInstalacion()
{
  cout << "Instalando software necesario para la desktop" << endl;
}

void Netbook::printEmpaquetado()
{
  cout << "Empaquetando desktop" << endl;
}
