#pragma once
#include "Computadoras.h"

class Factory
{
public:
  virtual Computadoras* factoryMethod(int) = 0;

  Computadoras* crearProducto(int type_)
  {
    Computadoras* newComputer = factoryMethod(type_);
    newComputer->crearDispositivo();
    return newComputer;
  }
};

class concreteCreator : public Factory //Herencia de factory -> concreteCreator
{
  Computadoras* factoryMethod(int type_)
  {
    if(type_ == 1)
      return new Laptop;
    if(type_ == 2)
      return new Desktop;
    if(type_ == 3)
      return new Tablet;
    if(type_ == 4)
      return new Netbook;
  }
public:
  static concreteCreator* singleton()
  {
    static concreteCreator* singleton = new concreteCreator;
    return singleton;
  }
private:
  concreteCreator(){};
  concreteCreator(concreteCreator const&);
  void operator=(concreteCreator const&);
};
