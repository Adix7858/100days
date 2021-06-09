/*
unsigned char zaplon = e; // deklaracja zmiennej poslugujacej za zaplon
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#define zaplon = e;

int i = 0;
int obrotomierz = 0;
int warunek = 0;
using namespace std;

void bieg_up()
{
    if (i<5)
    {
        obrotomierz=1000;
        cout<<"Wrzucono wyzszy bieg. Aktualny bieg: "<<i+1<<endl;
        i++;
    }
    else
    {
        cout<<"Zmiana biegu na wyszy nie jest mozliwa."<<endl;
    }

}

void bieg_down()
{
    obrotomierz=2400;
    cout<<"Wrzucono nizszy bieg. Aktualny bieg "<<i-1<<endl;
    i--;
    if (i<1)
    {
        cout<<"Wrzucony luz. Pamietaj iz jazda na biegu neutralnym nie jest bezpieczna"<<endl;
    }

}

void wsteczny()
{
cout<<"Wsteczny."<<endl;
}

void odciecie()
{
    if (warunek>4 || obrotomierz>10000)
    {
        cout<<"Uklad korbowo tlokowy zostal uszkodzony. Samochod unieruchomiony"<<endl;
    }
}

void szyby_down()
{
    cout<< "Szyby zostaly opuszczone."<<endl;
}

void szyby_up()
{
    cout<<"Szyby zostaly podniesione"<<endl;
}



int main()
{

    srand(time(NULL));

    unsigned char znak; //deklaracja zmiennej, ktora bede badal czy wstanowi przyspieszenie czy tez hamulec
    char zmienna; // zmienna do zaplonu
    int predkosc = 0;
    int pomocnicza = 0;
    int x = 0;
    cout << "Zobaczymy czy zapoznales sie z dokumentacja jaka zostala przygotowana.Podaj zmienna, ktora wskazuje na zaplon: ";
    cin >> zmienna;
    if(zmienna ==101) //sprawdzam czy u¿yszkodnik wprowadzi³ dobr¹ zmienn¹. Je¿eli nie, ka¿e mu szybko uciekaæ do dokumentacji technicznej.
    {


    cout << "Zaplon wlaczony. \n Samochod uruchomiony i jest gotowy do manewrow." << endl;
    obrotomierz= 700;
    do
    {
    znak = getch();
    if (znak==119)
    {

        if (i<1)
    {
        cout<<"Przyspieszenie nie jest mozliwe. Oczekuje na wybranie odpowiedniego biegu."<<endl;
        continue;
    }



            if(obrotomierz>=2200 && obrotomierz<=3500)
            {   if (i<5)
            {


                cout<<"To jest idealny moment na zmiane biegu na wyzszy. Chcesz go zmienic? Jezeli tak wcisnij z:"<<endl;
            }
            }
            pomocnicza= rand() % 5 + 1;
            x = rand() % 250 + 50;
            if (obrotomierz>8000)
            {
                odciecie();
                warunek++;
                predkosc+=pomocnicza;
                obrotomierz+=x;
                cout<<"Zblizasz sie do granicy odciecia mocy. Miej litosc dla samochodu i zwolnij."<<endl;
                if (warunek==5 || obrotomierz>10000)
                {
                odciecie();
                warunek++;
                    break;
                }


            }
            else
            {


            predkosc+=pomocnicza;
            obrotomierz+=x;
            }
    cout << "Aktualna predkosc wynosi: "<<predkosc<<endl;
    cout << "Obroty silnika wynosza: "<<obrotomierz<<endl;
    while( kbhit() )
        {
        znak = getch();
        cout << "Aktualna predkosc wynosi: "<<predkosc<<endl;
        cout << "Obroty silnika wynosza: "<<obrotomierz<<endl;
        }
    }
    else if (znak==115)
    {
        cout << "Rozpoczynam sekwencje hamowania."<<endl;
        cout << "Aktualna predkosc wynosi: "<<predkosc<<endl;
        cout << "Obroty wynosza: "<<obrotomierz<<endl;
            if (predkosc<=1 || obrotomierz<600)
            {
                cout<<"Obroty silnika byly zbyt niskie. Aby uniknac uszkodzenia samochod zostal zgaszony. Ponowne uruchomienie nie jest mozliwe."<<endl;
                break;
            }
            else if (predkosc<0)
            {
                cout<<"Obroty silnika byly zbyt niskie. Aby uniknac uszkodzenia samochod zostal zgaszony. Ponowne uruchomienie nie jest mozliwe."<<endl;
                break;
            }
            else if (obrotomierz <1700)
            {
                cout << "To jest idealny moment na zmiane biegu na nizszy. Chcesz go zmienic? Jezeli tak wcisnij x:"<<endl;
            }
            pomocnicza= rand() % 4 + 1;
            x = rand() % 150 + 50;
            predkosc-=pomocnicza;
            obrotomierz-=x;

    }
    else if (znak==111)
    {
        szyby_down();
    }
    else if (znak==112)
    {
        szyby_up();
    }

    else if (znak==122)
    {
            if (i<1)
            {
            bieg_up();
            }

            else if (obrotomierz<2200)
            {
                cout<<"Niedostosowane obroty do wskazanego biegu silnika. Aby uniknac uszkodzenia skrzyni biegow silnik zostal wylaczony a dalsza praca nie bedzie mozliwa."<<endl;
                break;
            }

            else
            {


        bieg_up();
            }
    }

    else if (znak==120)
    {   if (i>0)
        {
        bieg_down();
        }
        else
        {
            cout<<"Zmiana biegu na nizszy nie jest mozliwa. Samochod nie posiada biegu ujemnego :)"<<endl;
        }
    }

    else if (znak==114)
    {
        if (predkosc==0)
        {
            wsteczny();

        }
        else
        {

        cout<<"Manewr 'Rakieta' nie jest obslugiwany. Skrzynia biegow ulegla uszkodzeniu. Samochod zostal unieruchomiony."<<endl;
        break;

        }
    }


    else
    {
        cout << "Nie znam tej komendy. Nie wiem co pragniesz osiagnac."<<endl;
    }
    }
    while (znak!=27); //Odwzorowanie "ESC"
    cout << "Tak musialo sie stac. Dziekuje za wspolne chwile.";
    }
    else
    {
        cout <<"Uruchomienie samochodu nie powiodlo sie. System nie dopuscil do uruchomienia. \nZapraszam do dokumentacji technicznej. Po cos zostala stworzona :)";
    }
    getch();
    return 0;
}
