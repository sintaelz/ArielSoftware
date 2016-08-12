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
  cout << "Juntando componentes necesarios para construir la netbook..." << endl << endl;
}

void Netbook::printEnsamblado()
{
  cout << "Ensamblando componentes para la netbook..." << endl << endl;
}

void Netbook::printInstalacion()
{
  cout << "Instalando software necesario para la netbook..." << endl << endl;
}

void Netbook::printEmpaquetado()
{
  cout << "Empaquetando netbook" << endl;
}
