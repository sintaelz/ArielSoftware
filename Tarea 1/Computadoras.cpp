#include "Computadoras.h"

Computadoras::Computadoras()
{
  this->type = "No es ningun tipo de dispositivo";
  this->components = "Sin componentes";
  this->assembly = "Sin ensamblar";
  this->software = "Sin software instalado";
  this->packaging = "Sin empaquetar";
}

void Computadoras::printReceipt()
{
  cout << "Costo de 5000 pesos para el dispositivo de tipo " << type  << endl;
  cout << components << endl << endl;
  cout << assembly << endl << endl;
  cout << software << endl << endl;
  cout << packaging << endl << endl;
}
