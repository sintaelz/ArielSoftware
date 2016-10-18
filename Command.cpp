#include <map>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Command
{
public:
  virtual T execute(T *, int) = 0;
};

template <class T>
class Sum : public Command<T>
{
  T execute(T* arr, int size)
  {
    T acum = 0;
    for (int i = 0; i < size; i++)
    {
      acum += arr[i];
    }
    return acum;
  }
};

template <class T>
class Operators
{
private:
  map<string, Command<T>*> operaciones;
public:
  Operators(){}

  void insert(string s, Command<T>* f)
  {
    operaciones.insert(make_pair(s, f));
  }

  Command<T>* getOperator(string op)
  {
    typename map<string, Command<T>*>::iterator it;
    it = operaciones.find(op);
    if (it != operaciones.end())
      return it->second;
    return NULL;
  }
};

int main()
{
  Operators<float> op;
  op.insert("sum", new Sum<double>)
  float* arrF = new float[5]{2.1, 3.5, 2.3, 4.3, 5.5};
  Command<float>* c = op.getOperator("sum");
  cout << c->execute(arrF, 5, 0);
}
