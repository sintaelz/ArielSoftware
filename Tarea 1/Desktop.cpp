#include "Desktop.h"

Desktop::Desktop()
{
  printComponentes();
  printEnsamblado();
  printInstalacion();
  printEmpaquetado();
}

void Desktop::printComponentes()
{
  cout << "Juntando componentes necesarios para construir la desktop" << endl;
}

void Desktop::printEnsamblado()
{
  cout << "Ensamblando componentes para la desktop" << endl;
}

void Desktop::printInstalacion()
{
  cout << "Instalando software necesario para la desktop" << endl;
}

void Desktop::printEmpaquetado()
{
  cout << "Empaquetando desktop" << endl;
}
