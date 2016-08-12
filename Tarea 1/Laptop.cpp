#include "Laptop.h"

Laptop::Laptop()
{
  printComponentes();
  printEnsamblado();
  printInstalacion();
  printEmpaquetado();
}

void Laptop::printComponentes()
{
  cout << "Juntando componentes necesarios para construir la laptop" << endl;
}

void Laptop::printEnsamblado()
{
  cout << "Ensamblando componentes para la laptop" << endl;
}

void Laptop::printInstalacion()
{
  cout << "Instalando software necesario para la laptop" << endl;
}

void Laptop::printEmpaquetado()
{
  cout << "Empaquetando laptop" << endl;
}
