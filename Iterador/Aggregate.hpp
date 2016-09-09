#pragma once
#include "Iterator.hpp"

template <class T>
class Iterator;

template <class T>
class Aggregate
{
public:
  friend class Iterator<T>;
  Aggregate() :index(0), list(new T[size]) {};
  ~Aggregate(){delete [] list;};
  void add(T element)
  {
    if(index < size) //validar
    list[index++] = element;
  }
  Iterator<T> getIterator()
  {
    return new Iterator<T>(*this);
  }
  T getElementAt(int pos)
  {
    return list[pos];
  }
  int getSize()
  {
    return size;
  }
private:
  T* list;
  int size = 10;
  int index;
};
