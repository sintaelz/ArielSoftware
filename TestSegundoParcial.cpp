#include <map>
#include <iostream>

using namespace std;

class divObserver
{
  string headline;
public:
  notifyObserver(string headline_)
  {
    headline = headline_;
  }
  void updateMVS(string headline, int value)
  {
    if (value >= 0 && value <= 3)
      cout << "La noticia mas reciente es: " << headline << " brought to you by MVS Noticias"  << endl;
  }
  void updateTelevisa(string headline, int value)
  {
    if (value >= 0 && value <= 3)
      cout << "La noticia mas reciente es: " << headline << " solo por Televisa"  << endl;
  }
  void updateTvAzteca(string headline,int value)
  {
    if (value >= 0 && value <= 3)
      cout << "La noticia mas reciente es: " << headline << " por TV Azteca" << endl;
  }
  void updateRadioFormula(string headline, int value)
  {
    if (value >= 0 && value <= 3)
      cout << "La noticia mas reciente es: "  << headline << "por Radio Formula!" << endl;
  }
  void updateCNN(string headline, int value)
  {
    if (value == 2|| value == 3)
      cout << "Breaking news: " << headline << " brought to you only by CNN " << endl;
  }
};

class Subject
{
  string subHeadline;
  int value;
  divObserver headlineObj;
public:
  Subject(): headlineObj(){};
  void set_value(string headline_, int value_)
  {
    subHeadline = headline_;
    value = value_;
    notify();
  }
  void notify()
  {
    headlineObj.updateMVS(subHeadline, value);
    headlineObj.updateTelevisa(subHeadline, value);
    headlineObj.updateRadioFormula(subHeadline, value);
    headlineObj.updateCNN(subHeadline, value);
    headlineObj.updateTvAzteca(subHeadline, value);
  }
};

int main()
{
  int choice = 0;
  string headlineNews;
  cout << "Como quien deseas entrar?" << endl << "1.Pena Nieto" << endl << "2.Hilary" << endl << "3.Donald Trump" << endl;
  cin >> choice;
  cout << "Cual es el headline que deseas escribir?" << endl;
  cin >> headlineNews;
  Subject news;
  news.set_value(headlineNews, choice);
}
