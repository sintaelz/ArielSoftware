#pragma once
#include <iostream>

using namespace std;

class Computadoras
{
public:
  virtual Computadoras* clone() = 0;
  virtual void printComponentes() = 0;
  virtual void printEnsamblado() = 0;
  virtual void printInstalacion() = 0;
  virtual void printEmpaquetado() = 0;
  void crearDispositivo()
  {
    printComponentes();
    printEnsamblado();
    printInstalacion();
    printEmpaquetado();
  }
};

template<class T>
class clonePadre : public Computadoras
{
  virtual Computadoras* clone()
  {
    return new T(dynamic_cast<T&>(*this));
  }
};

class Laptop : public clonePadre<Laptop>
{
  friend class concreteCreator;
private:
  Laptop(){};//En privado para que nadie las pueda utilizar mas que el admin
public:
  void printComponentes()
  {
      cout << "Juntando componentes necesarios para construir una Laptop..." << endl << endl;
  }
  void printEnsamblado()
  {
    cout << "Ensamblando componentes para la Laptop..."  << endl << endl;
  }
  void printInstalacion()
  {
    cout << "Instalando software necesario para la Laptop..."  << endl << endl;
  }
  void printEmpaquetado()
  {
    cout << "Empaquetando la Laptop :)" << endl;
  }
};

class Desktop : public clonePadre<Desktop>
{
  friend class concreteCreator;
private:
  Desktop(){}; //En privado para que nadie las pueda utilizar mas que el admin
public:
  void printComponentes()
  {
      cout << "Juntando componentes necesarios para construir una Desktop..." << endl << endl;
  }
  void printEnsamblado()
  {
    cout << "Ensamblando componentes para la Desktop..."  << endl << endl;
  }
  void printInstalacion()
  {
    cout << "Instalando software necesario para la Desktop..."  << endl << endl;
  }
  void printEmpaquetado()
  {
    cout << "Empaquetando la Desktop :)" << endl;
  }
};

class Tablet : public clonePadre<Tablet>
{
  friend class concreteCreator;
private:
  Tablet(){}; //En privado para que nadie las pueda utilizar mas que el admin
public:
  void printComponentes()
  {
      cout << "Juntando componentes necesarios para construir una Tablet..." << endl << endl;
  }
  void printEnsamblado()
  {
    cout << "Ensamblando componentes para la Tablet..."  << endl << endl;
  }
  void printInstalacion()
  {
    cout << "Instalando software necesario para la Tablet..."  << endl << endl;
  }
  void printEmpaquetado()
  {
    cout << "Empaquetando la Tablet :)" << endl;
  }
};

class Netbook : public clonePadre<Netbook>
{
  friend class concreteCreator;
private:
  Netbook(){}; //En privado para que nadie las pueda utilizar mas que el admin
public:
  void printComponentes()
  {
      cout << "Juntando componentes necesarios para construir una Netbook..." << endl << endl;
  }
  void printEnsamblado()
  {
    cout << "Ensamblando componentes para la Netbook..."  << endl << endl;
  }
  void printInstalacion()
  {
    cout << "Instalando software necesario para la Netbook..."  << endl << endl;
  }
  void printEmpaquetado()
  {
    cout << "Empaquetando la Netbook :)" << endl;
  }
};
