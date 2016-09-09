#include "Builder.h"
#include "Director.h"

int main()
{
  Director* dir = new Director();
  dir->setBuilder(new BuilderBoeing());
  dir->construct();

  Avion* myPlane = dir->getAvion();
  cout << myPlane->getBrand() << endl;
}
