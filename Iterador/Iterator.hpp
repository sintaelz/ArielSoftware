#pragma once
#include "Aggregate.hpp"

template <class T>
class Iterator
{
public:
  Iterator(const Aggregate<T>& aggregateList)
  {
    this->list = aggregateList;
    index = 0;
  }
  T first()
  {
    return list->getElementAt(0);
  }
  T next()
  {
    if(hasNext())
      return list->getElementAt(index++);
      //return list->aggregateList[index++];
    else
      return NULL;
  }
  bool hasNext()
  {
    return (index < list->getSize());
  }
  ~Iterator(){delete [] list;};
private:
  Iterator(){};
  Aggregate<T>* list;
  int index;
};
