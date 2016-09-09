#pragma once
#include "Avion.h"

class Builder
{
protected:
  Avion* a;
public:
  Avion* getAvion()
  {
    return new Avion();
  }
  void createAvion()
  {
    a = new Avion();
  }
  virtual void getAlas() = 0;
  virtual void getMotor() = 0;
  virtual void getBrand() = 0;
  virtual void getModel() = 0;
  virtual void getnumSeries() = 0;
};

class BuilderBoeing : public Builder
{
  void getAlas()
  {
    Alas* theWings = new Alas();
    theWings->setBrand("Boeing");
    a->setAlas(lasAlas);
  }
  void getMotor()
  {
    Motor* theMotor = new Motor();
    theMotor->sethorsePower(3500);
    a->setMotor(theMotor);
  }
  void getBrand()
  {
    a->setBrand("Boeing");
  }
  void getModel()
  {

  }
};
