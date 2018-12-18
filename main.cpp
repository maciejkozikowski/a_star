#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <limits>
#include <cstdlib>
using namespace std;
class Punkt
{
    public:
        int x;
        int y;
        int znak;
        int koszt;
        int rodzicX;
        int rodzicY;
};
int wym2 = 20;
int wym1 = 20;
Punkt punkty[20][20];


double h(Punkt start, Punkt cel)
{
        double wynik = sqrt(pow((start.x-cel.x),2) + pow((start.y - cel.y),2));
        return wynik;
}

int wczytaj()
{

    cout<<"Wczytywanie danych z pliku\n";

    string nazwap="grid.txt";

    //teraz deklarujemy dynamicznie tablice do, której wczytamyu nasz plik,
    int rows = wym2+1;
    double **G;
    G = new double*[rows];
    while(rows--) G[rows] = new double[wym1+1];

    cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwap;
    getchar();

    std::ifstream plik(nazwap.c_str());
    for ( unsigned int i=1;i<wym2+1;i++)
    {
        for ( unsigned int j=1;j<wym1+1;j++)
        {
            plik >> G[i][j];
        }
    }
    plik.close();
    cout<<"\nWypisujemy na ekran\n\n";
    //Punkt punkty[wym2+1][wym1+1];
    for(int i=1;i<wym2+1;i++)
    {
        for(int j=1;j<wym1+1;j++)
        {
            cout<<" "<<G[i][j];
            punkty[i][j].x=i;
            punkty[i][j].y=j;
            punkty[i][j].znak=G[i][j];

        }
        cout<<"\n";
    }

   cout<<"\n";
   cout<<"\n";
   cout<<"\n";
   cout<<"wyswietlanie mapy z obiektu";
   cout<<"\n";

    for(int i=1;i<wym2+1;i++)
    {
        for(int j=1;j<wym1+1;j++)
        {
            cout<<" "<<punkty[i][j].znak;

        }
    cout<<"\n";
    }

    //na koniec czyœcimy pamiêæ po naszej tablicy
    for(int i=0;i<wym2+1;i++)
    {delete[] G[i];}//czyscimy wiersze
    delete[] G;//zwalniamy tablice wskaznikow do wierszy

    cout<<"\n\nNacisnij ENTER aby zakonczyc";
    getchar();
}
void PobierzStartCel()
{
    int x,y;
    cout<<"Podaj wspolrzedne startu \nX:";
    cin>>  x;
    cout<<"Y:";
    cin>>  y;
    punkty[x][y].znak=1;
    cout<<"Podaj wspolrzedne celu \nX:";
    cin>> x;
    cout<<"Y:";
    cin>> y;
    punkty[x][y].znak=9;
    cout<<"Wyswietlenie mapy ze startem i meta\n";
    getchar();
    for(int i=1;i<wym2+1;i++)
    {
        for(int j=1;j<wym1+1;j++)
        {
            cout<<" "<<punkty[i][j].znak;

        }
    cout<<"\n";
    }
}
int main()
{
    wczytaj();
    PobierzStartCel();
    h(punkty[1][1], punkty[20][20]);

    return 0;
}
