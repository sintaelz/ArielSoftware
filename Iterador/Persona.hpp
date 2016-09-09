#pragma once

class Persona
{
public:
  Persona(int edad) : edad(edad){};
  Persona(){};
  ~Persona();

  int getEdad()
  {
    return edad;
  }
private:
  int edad;
};
