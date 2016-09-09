#pragma once
#include "Builder.h"

class Director
{
private:
  Builder* builder;
public:
  void setBuilder(Builder* bd)
  {
    builder = bd;
  }
  Avion* getAvion()
  {
    return builder->getAvion();
  }
  void construct()
  {
    builder->createAvion();
    builder->getModel();
    builder->getnumSeries();
    builder->getBrand();
    builder->getAlas();
    builder->getMotor();
  }
};
