#include <iostream>
#include "Aggregate.hpp"
#include "Iterator.hpp"
#include "Persona.hpp"

int main()
{
  Persona p1(20);
  Persona p2(30);
  Persona p3(40);
  Aggregate<Persona> list;
  list.add(p1);
  list.add(p2);
  list.add(p3);

  for(Iterator<Persona> i = list.getIterator(); i.hasNext();)
    std::cout << i.next().getEdad();

    
  return 0;
}
