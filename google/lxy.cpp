#include <iostream>
using namespace std;
class Base
{
    public:
        int a;
        Base()
        {
            a = 1;
        }
        void print()
        {
            cout<<a;
        }
};
class Derived : public Base
{
    public:
        int a;
        Derived()
        {
            a = 2;
        }
};
int main()
{
    Derived* d = new Derived;
    d->print();
    cout<<endl;
    cout<<d->a<<endl;
    return 0;
}
