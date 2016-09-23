#include <iostream>

using namespace std;

template<class T>
class Iterator;

template<class T>
class Aggregate
{
public:
    friend class Iterator<T>;
    Aggregate()
    {
        pos = 0;
        size = 50; //tamaño predefinido, pero deberíamos hacer que el arreglo fuera dinámico
        lista = new T[size];
    }
    void add(T element)
    {
        if(pos < size)
            lista[pos++] = element;
    }
    Iterator<T>* getIterator()
    {
        return new Iterator<T>(this);
    }

    ~Aggregate()
    {
        delete [] lista;
    }

    T getElementAt(int pos){
        return lista[pos];
    }

    T getElementName(string nombre_){
      for (int i = 0; i < size; i ++)
      {
        if (nombre_ == lista[i]->getNombrePastel())
        {
          return lista[i];
          break;
        }
      }
    }

    int getPos()
    {
        return pos;
    }

private:
    T* lista;
    int size;
    int pos;
};

template<class T>
class Iterator
{
public:
    Iterator(Aggregate<T>* aggregate) : idx(0), aggregate(aggregate)
    {}

    T next()
    {
        if(hasNext())
            //return aggregate->getElementAt(idx++);
            return aggregate->lista[idx++];
        else
            return 0;
    }

    bool hasNext()
    {
        return (idx < aggregate->getPos());
    }
    ~Iterator(){}

private:
    Iterator(){}
    Aggregate<T>* aggregate;
    int idx;
};

// Clase madre
class Product
{
public:
    virtual Product* clone() = 0;
    virtual void batido() = 0;
    virtual void amasado() = 0;
    virtual void horneado() = 0;
    virtual void decorado() = 0;
    virtual void empacado() = 0;
    void crearPastel()
    {
      batido();
      amasado();
      horneado();
      decorado();
      empacado();
    }
    string nombrePastel;
    string lugarDisponible;
    virtual string getLugarDisponible(){return lugarDisponible;}
    virtual string getNombrePastel(){return nombrePastel;}
};

template<class T>
class clonePadre : public Product
{
  virtual Product* clone()
  {
    return new T(dynamic_cast<T&>(*this));
  }
};


// Clases de herencia y variaciones
class tresLeches : public clonePadre<tresLeches>
{
    friend class ConcreteCreator;
  public:
    virtual void batido(){cout << "Batiendo el pastel Tres Leches\n";};
    virtual void amasado(){cout << "Amasando el pastel Tres Leches\n";};
    virtual void horneado(){cout << "Horneando el pastel Tres Leches\n";};
    virtual void decorado(){cout << "Decorando el pastel Tres Leches\n";};
    virtual void empacado(){cout << "Empacando el pastel Tres Leches\n";};

private:
    tresLeches(){nombrePastel = "Tres Leches";
      lugarDisponible = "Aguscalientes";}
};

// Clases de herencia y variaciones

class Sacher : public clonePadre<Sacher>
{
    friend class ConcreteCreator;
public:
    virtual void batido(){cout << "Batiendo el pastel Sacher\n";};
    virtual void amasado(){cout << "Amasando el pastel Sacher\n";};
    virtual void horneado(){cout << "Horneando el pastel Sacher\n";};
    virtual void decorado(){cout << "Decorando el pastel Sacher\n";};
    virtual void empacado(){cout << "Empacando el pastel Sacher\n";};

private:
    Sacher(){nombrePastel = "Sacher";
      lugarDisponible = "Distrito Federal";};
};

// Clases de herencia y variaciones

class Imposible: public clonePadre<Imposible>
{
    friend class ConcreteCreator;
public:
    virtual void batido(){cout << "Batiendo el pastel Imposible\n";};
    virtual void amasado(){cout << "Amasando el pastel Imposible\n";};
    virtual void horneado(){cout << "Horneando el pastel Imposible\n";};
    virtual void decorado(){cout << "Decorando el pastel Imposible\n";};
    virtual void empacado(){cout << "Empacando el pastel Imposible\n";};

private:
    Imposible(){nombrePastel = "Imposible";
      lugarDisponible = "Distrito Federal";}
};

// Principal creador abstracto

class Creator
{

public:

    // Se declara el método abstracto
    virtual Product* factoryMethod(int) = 0;

    Product* createProduct(int tipo)
    {
        Product* myProduct = factoryMethod(tipo);
        myProduct->crearPastel();
        return myProduct;
    }
    string listaIngredientesDF[3] = {"Chocolates", "Frutas",  "Merengue"};
    string listaIngredientesAguascalientes[3] = {"Leche", "Huevo", "Mantequilla"};
};

// Creador concreto

class ConcreteCreator : public Creator
{

public:

    // Se conmuta dentro del método de la fábrica

    Product* factoryMethod(int tipo){
        // Se regresan los nuevos objetos
        if (tipo == 1)
            return new tresLeches;
        else if (tipo == 2)
            return new Sacher;
        else if (tipo == 3)
            return new Imposible;
        else
        // En caso de no funcionar, regresa un apuntador vacío
            std::cout << "Lo sentimos, opción no disponible.\n";
            return NULL;
    }
    static ConcreteCreator* GetInstance(){
        // Retornar la instancia generada
        static ConcreteCreator* instance = new ConcreteCreator;
        return instance;

    }
private:
    ConcreteCreator(){};
};

int main()
{
  //Crear Pasteles Prueba
  ConcreteCreator* client = ConcreteCreator::GetInstance();
  Product* pastelTresLeches = client->createProduct(1);
  cout << endl;
  Product* pastelSacher = client->createProduct(2);
  cout << endl;
  Product* pastelImposible = client->createProduct(3);
  cout << endl;
  //Clonar Pastel Prueba
  Product* pastelTresLechesClon = pastelTresLeches->clone();
  pastelTresLechesClon->crearPastel();

  cout << endl << endl << "Probando Iterador" << endl;
  //Iterador
  Aggregate<Product*> inventory;
  inventory.add(pastelTresLeches);
  inventory.add(pastelSacher);
  inventory.add(pastelImposible);
  inventory.add(pastelTresLechesClon);
  Iterator<Product*>* i;
  for(i = inventory.getIterator(); i->hasNext(); )
  {
      cout << (i->next())->getNombrePastel() << endl;
  }
  cout << endl << endl << "Probando Search nombre Iterador" << endl;
  Product* pastelPruebaSearch = inventory.getElementName("Sacher");
  pastelPruebaSearch->crearPastel();

  delete i;

  return 0;
}
