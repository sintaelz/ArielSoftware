#pragma once
#include <string>
#include <iostream>

using namespace std;

class Computadoras
{
public:
  string type;
  string components;
  string assembly;
  string software;
  string packaging;
  Computadoras();
  void printReceipt();
};
