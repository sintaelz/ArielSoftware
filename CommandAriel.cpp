#include<map>
#include<string>
#include<iostream>

using namespace std;

class Command
{
public:
    template<class T, class Func>
    T execute(T* arr , int size, Func fun)
    {
        return fun(arr, size);
    }
};


template<class T>
T sum(T* arr, int size)
{
    T acum = 0;
    for(int i=0; i<size; i++)
        acum+= arr[i];
    return acum;
}

template<class T>
T mult(T* arr, int size)
{
    T acum = 1;
    for(int i=0; i<size; i++)
        acum*= arr[i];
    return acum;
}

typedef int(*signature)(int*, int);

int main()
{
    double* arrD = new double[5]{2.1,3.5, 2.3,4.3,1.4};
    char* arrC = new char[5]{'A','R','I','E','L'};
    int* arrI = new int[2]{12, 22};
    string* arrS = new string[3]{"Hahah", "Lul", "ekis de"};

    Command c;

    cout << c.execute<double, double(*)(double*,int)>(arrD, 5, sum) << endl; //Aplicar la función a un arreglo de enteros

    cout << c.execute<char, char(*)(char*, int)>(arrC, 5, sum)<< endl; //aplicar la función a un arreglo de chars

    cout << c.execute<int, signature>(arrI, 2, sum)<< endl; //aplicar la función a un arreglo de ints, pero guardando la definición de la función en un typedef

    cout << c.execute<double, double(*)(double*,int)>(arrD, 5, mult) << endl;

    cout << c.execute<string, string(*)(string*,int)>(arrS, 3, sum) << endl;

    signature f = &sum<int>;
    f(arrI, 2);
}
