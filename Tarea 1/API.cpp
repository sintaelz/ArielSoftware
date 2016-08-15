#include "API.h"

Computadoras API::crear(string type_)
{
  Computadoras computer;
  cout << "Preparando Computadora de tipo " << type_ << ". Espere un segundo..."<< endl << endl;
  printComponentes(type_);
  printEnsamblado(type_);
  printInstalacion(type_);
  printEmpaquetado(type_);
  computer.type = type_;
  computer.components = "Componentes listos";
  computer.assembly = "Se han ensamblado los componentes correctamente";
  computer.software = "Las instalaciones han terminado";
  computer.packaging = "Se ha empaquetado el dispositivo de manera exitosa";
  return computer;
}

void API::printComponentes(string type_)
{
  cout << "Juntando componentes necesarios para construir " << type_ <<  "..." << endl << endl;
}

void API::printEnsamblado(string type_)
{
  cout << "Ensamblando componentes para " << type_ <<  "..." << endl << endl;
}

void API::printInstalacion(string type_)
{
  cout << "Instalando software necesario para" << type_ <<  "..." << endl << endl;
}

void API::printEmpaquetado(string type_)
{
  cout << "Empaquetando " << type_ <<  "..." << endl;
}
