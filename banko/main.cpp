#include <iostream>

using namespace std;




void konto(float &konta)
{
    konta+=1000;
    cout<<"Posiadasz "<<konta<<endl;;
}
void wyplac(float &konta)
{

    int x;
    cout<<"Ile wyplacic?:";
    cin>>x;
    konta-=x;

}

int main()
{
    float konta=1000;
    int pin,y;
    cout<<"Podaj pin:";
    cin>>pin;
    if(pin!=1234)
    {
        cout<<"Zly PIN";
    }
    else
    {
    cout <<"Co robimy? 1.Wyplac, 2.Wplac, 3.Nie robimy nic: ";
    cin>>y;
    switch (y)
    {
        case 1: wyplac(konta); break;
        case 2: cout<<"Test"<<endl;
        default: cout<<"Nie zrobie nic";
    }
    cout<<"Posiadasz "<<konta<<endl;

    return 0;
    }
}
