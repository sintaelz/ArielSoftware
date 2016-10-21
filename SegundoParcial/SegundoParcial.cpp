#include <map>
#include <iostream>
#include <vector>

using namespace std;

class Subject
{
public:
  vector < class Observer * > views;
  string headline;
  string name;
  int value;
  void setName(string name_)
  {
    name = name_;
  }
  void setValue(int value_)
  {
    value = value_;
  }
  string getName()
  {
    return name;
  }
  int getValue()
  {
    return value;
  }
  void attach(Observer * obs)
  {
    views.push_back(obs);
  }
  void setHeadline(string headline_)
  {
    headline = headline_;
    notify();
  }
  string getHeadline()
  {
    return headline;
  }
  void notify();
};

class Observer
{
public:
  Subject *president;
  string headline;
  Observer(Subject *president_, string headline_)
  {
    president = president_;
    headline = headline_;
    president->attach(this);
  }
  virtual void publish() = 0;
protected:
  Subject *getSubject()
  {
    return president;
  }
};

void Subject::notify()
{
  for(int i = 0; i < views.size(); i++)
  {
    views[i]->publish();
  }
}

class MVSnews : public Observer
{
public:
  MVSnews(Subject *pres, string headline_) : Observer(pres,headline_){};
  void publish()
  {
      cout << "La noticia mas reciente acerca de : "<< getSubject()->getName() << endl << getSubject()->getHeadline() << " brought to you by MVS Noticias"  << endl;
  }
};

class Televisa : public Observer
{
public:
  Televisa(Subject *pres, string headline_) : Observer(pres,headline_){};
  void publish()
  {
      cout << "La noticia mas reciente acerca de : "<< getSubject()->getName() << endl << getSubject()->getHeadline() << " solo por Televisa"  << endl;
  }
};

class TVazteca : public Observer
{
public:
  TVazteca(Subject *pres, string headline_) : Observer(pres,headline_){};
  void publish()
  {
      cout << "La noticia mas reciente acerca de : "<< getSubject()->getName() << endl << getSubject()->getHeadline() << " por TV Azteca" << endl;
  }
};

class RadioFormula : public Observer
{
public:
  RadioFormula(Subject *pres, string headline_) : Observer(pres,headline_){};
  void publish()
  {
      cout << "La noticia mas reciente acerca de : "<< getSubject()->getName() << endl << getSubject()->getHeadline() << " por RadioFormula" << endl;
  }
};

class CNN : public Observer
{
public:
  CNN(Subject *pres, string headline_) : Observer(pres,headline_){};
  void publish()
  {
    if(getSubject()->getName() != "Pena Nieto" || getSubject()->getName() != "Pena")
      cout << "Breaking news about: " << getSubject()->getName() << endl << getSubject()->getHeadline() << " brought to you only by CNN " << endl;
  }
};

int main()
{
  string headlineNews;
  string presidentName;
  Subject president;
  cout << "Como quien deseas entrar?" << endl;
  getline(cin, presidentName);
  cout << "Cual es el headline que deseas escribir?" << endl;
  president.setName(presidentName);
  MVSnews mvs(&president, headlineNews);
  Televisa televisa(&president, headlineNews);
  TVazteca tvazteca(&president, headlineNews);
  RadioFormula radio(&president, headlineNews);
  CNN cnn(&president, headlineNews);
  getline(cin,headlineNews);
  president.setHeadline(headlineNews);
}
