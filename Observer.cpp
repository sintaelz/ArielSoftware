#include <iostream>

using namespace std;

class divObserver
{
  int m_mult;
public:
  divObserver(int mult)
  {
    m_mult = mult;
  }
  void update(int value)
  {
    cout << "The new value is " << value << " and m_mult * value = " << value*m_mult << endl;
  }
};

class Subject
{
  int subValue;
  divObserver m_mult_obj;
public:
  Subject(): m_mult_obj(4){};
  void set_value(int value)
  {
    subValue = value;
    notify();
  }
  void notify()
  {
    m_mult_obj.update(subValue);
  }

};


int main()
{
  Subject subj;
  subj.set_value(16);
}
