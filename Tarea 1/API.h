#pragma once
#include "Computadoras.h"
#include <string>
#include <iostream>

using namespace std;

class API
{
public:
  Computadoras crear(string type_);
  void printComponentes(string type_);
  void printEnsamblado(string type_);
  void printInstalacion(string type_);
  void printEmpaquetado(string type_);
};
