#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <limits>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;
class Punkt
{
    public:
        int x; //współrzędna x
        int y; //współrzędna y
        int znak; //wartość pola (1 to start, 9 meta, 5 blokada, 3 trasa
        int koszt=0; //koszt dotarcia do pola
        int rodzicX; //pozycja X rodzica
        int rodzicY; //pozycja Y rodzica
        double h; //heurystyka tego pola
        bool visited = false;
};

int wym2 = 20;
int wym1 = 20;
Punkt mapa[20][20];
int startX = 0;
int startY = 0;
int celX=0;
int celY=0;
int nowX = 0;
int nowY = 0;
double h(Punkt start, Punkt cel)
{
        double wynik = sqrt(pow((start.x-cel.x),2) + pow((start.y - cel.y),2));
        return wynik;
}

void wczytaj()
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
    for ( unsigned int i=0;i<wym2+1;i++)
    {
        for ( unsigned int j=0;j<wym1+1;j++)
        {
            plik >> G[i][j];
        }
    }
    plik.close();
    cout<<"\nWypisujemy na ekran\n\n";
    //Punkt mapa[wym2+1][wym1+1];
    for(int i=0;i<wym2+1;i++)
    {
        for(int j=0;j<wym1+1;j++)
        {
            cout<<" "<<G[i][j];
            mapa[i][j].x=i;
            mapa[i][j].y=j;
            mapa[i][j].znak=G[i][j];

        }
        cout<<"\n";
    }

   cout<<"\n";
   cout<<"\n";
   cout<<"\n";
   cout<<"wyswietlanie mapy z obiektu";
   cout<<"\n";

    for(int i=0;i<wym2+1;i++)
    {
        for(int j=0;j<wym1+1;j++)
        {
            cout<<" "<<mapa[i][j].znak;

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
    mapa[x][y].znak=1;
    startX=x;
    startY=y;
    nowX = startX;
    nowY = startY;
    cout<<"Podaj wspolrzedne celu \nX:";
    cin>> x;
    cout<<"Y:";
    cin>> y;
    mapa[x][y].znak=9;
    celX = x;
    celY = y;
    cout<<"Wyswietlenie mapy ze startem i meta\n";
    getchar();
    for(int i=0;i<wym2+1;i++)
    {
        for(int j=0;j<wym1+1;j++)
        {
            cout<<" "<<mapa[i][j].znak;

        }
    cout<<"\n";
    }
}
void SearchUp(list<Punkt> listaO, list<Punkt>::iterator it)
{

}
void SearchDown(list<Punkt> listaO, list<Punkt>::iterator it)
{

}
void SearchLeft(list<Punkt> listaO, list<Punkt>::iterator it)
{

}
void SearchRight(list<Punkt> listaO, list<Punkt>::iterator it)
{

}
void SearchAdjacent(list<Punkt> listaO, list<Punkt>::iterator it)
{
    SearchUp(listaO, it);
    SearchDown(listaO, it);
    SearchLeft(listaO, it);
    SearchRight(listaO, it);
}
void trasa()
{
    list<Punkt> listaO;
    list<Punkt> listaZ;
    listaZ.push_back(mapa[startX][startY]);
    list<Punkt>::iterator itZ = listaZ.begin();
    cout<<itZ->x<<endl;
    cout<<itZ->y<<endl;
    cout<<itZ->znak<<endl;
    listaZ.push_back(mapa[celX][celY]);
    advance(itZ, 1);
    cout<<itZ->x<<endl;
    cout<<itZ->y<<endl;
    cout<<itZ->znak<<endl;
    cout<<mapa[itZ->x][itZ->y].znak;
    listaO.push_back(mapa[nowX][nowY-1]);
    list<Punkt>::iterator itO = listaO.begin();
    itO->h = h(mapa[itO->x][itO->y], mapa[celX][celY]);
    cout<<itO->h;

}
int main()
{
    wczytaj();
    PobierzStartCel();
    trasa();
    return 0;
}
