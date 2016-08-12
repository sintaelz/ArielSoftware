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
  cout << "Juntando componentes necesarios para construir la tablet..." << endl << endl;
}

void Tablet::printEnsamblado()
{
  cout << "Ensamblando componentes para la tablet..." << endl << endl;
}

void Tablet::printInstalacion()
{
  cout << "Instalando software necesario para la tablet..." << endl << endl;
}

void Tablet::printEmpaquetado()
{
  cout << "Empaquetando tablet" << endl;
}
