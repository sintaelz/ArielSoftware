#include<iostream>
using namespace std;

class ArrayPositiveInts;

class Proxy
{
private:
    ArrayPositiveInts& arr;
    int idx;

public:
  friend class ArrayPositiveInts;
    Proxy(ArrayPositiveInts& arr, int idx)
    : arr(arr), idx(idx){}

    Proxy& operator=(int value);

    friend ostream& operator << (ostream& op, Proxy& yo);
};

class ArrayPositiveInts
{
private:
    int* values;
    int size;
public:
    friend class Proxy;
    ArrayPositiveInts()
    {
        size = 100;
        values = new int[size];
    }
    int& operator[](int idx) //se devuelve un elemento del arreglo por referencia
    {
        if(idx < 0)
        {
          cout << "No se aceptan indices negativos" << endl;
          return values[0];
        }
        Proxy temp(*this, idx); //ejecuto el proxy
        return values[idx];  //devuelvo el elemento
    }
    int getList(int idx)
    {
      return *(values+idx);
    }
};

Proxy& Proxy::operator=(int value)
{
  {
    if (value >= 0)
    {
      //arr[index] = value;
      *(arr.values + idx) = value;
      return *this;
    }
    else
    {
      cout << "Error, tu numero tiene que ser positivo" <<endl;
      return *this;
    }
  }
};

ostream& operator << (ostream& op, Proxy& yo)
{
  op << yo.arr.getList(yo.idx);
  return op;
};

int main()
{
    ArrayPositiveInts a;
    a[0] = 1;
    a[1] = -5;
    a[-3] = 5;
    //cout << a[0];
    //cout << a[1];
}
