#include <iostream>

using namespace std;

class divObserver
{
  int m_div;
public:
  divObserver(int div)
  {
    m_div = div;
  }
  void update(int value)
  {
    cout << "The new value for m_div is " << m_div << " and m_div / your value = " << value/m_div << endl;
  }
};

class Subject
{
  int subValue;
  divObserver m_div_obj;
public:
  Subject(): m_div_obj(4){};
  void set_value(int value)
  {
    subValue = value;
    notify();
  }
  void notify()
  {
    m_div_obj.update(subValue);
  }

};


int main()
{
  Subject subj;
  subj.set_value(16);
}
