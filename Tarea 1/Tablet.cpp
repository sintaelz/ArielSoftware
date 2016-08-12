#include "Tablet.h"

Tablet::Tablet()
{
  printComponentes();
  printEnsamblado();
  printInstalacion();
  printEmpaquetado();
}

void Tablet::printComponentes()
{
  cout << "Juntando componentes necesarios para construir la desktop" << endl;
}

void Tablet::printEnsamblado()
{
  cout << "Ensamblando componentes para la desktop" << endl;
}

void Tablet::printInstalacion()
{
  cout << "Instalando software necesario para la desktop" << endl;
}

void Tablet::printEmpaquetado()
{
  cout << "Empaquetando desktop" << endl;
}
