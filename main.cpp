#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <limits>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <float.h>
using namespace std;
int wym2 = 20;
int wym1 = 20;
int startX = 0;
int startY = 0;
int celX=0;
int celY=0;
int nowX = 0;
int nowY = 0;
class Punkt
{
    public:
        int x; //współrzędna x
        int y; //współrzędna y
        int znak; //wartość pola (1 to start, 9 meta, 5 blokada, 3 trasa
        int g=0; //koszt dotarcia do pola
        int rodzicX; //pozycja X rodzica
        int rodzicY; //pozycja Y rodzica
        double h; //heurystyka tego pola
        double f; //heurystyka + koszt;
        bool visited = false;
        double heur()
        {
            this->h=sqrt(pow((this->x-celX),2) + pow((this->y - celY),2));
            this->f=this->h + g;
        }
        bool operator == (const Punkt& p) const { return x==p.x && y==p.y; }
        bool operator != (const Punkt& p) const { return !operator==(p); }

};

    list<Punkt> listaO;
    list<Punkt> listaZ;
Punkt mapa[20][20];
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
    mapa[startX][startY].visited = true;
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
void SearchUp()
{
    if(nowY>0 && mapa[nowX][nowY-1].znak!=5 && mapa[nowX][nowY-1].visited == false){
        listaO.push_front(mapa[nowX][nowY-1]);
        list<Punkt>::iterator it=listaO.begin();
        it->heur();
        mapa[it->x][it->y].rodzicX = nowX;
        mapa[it->x][it->y].rodzicY = nowY;
        mapa[nowX][nowY-1].visited=true;
        it->rodzicX = nowX;
        it->rodzicY = nowY;

        it->g = it->g+1;
        cout<<it->x<<endl;
            cout<<it->y<<endl;
            cout<<it->znak<<endl;
            cout<<it->h<<endl;
            cout<<mapa[it->x][it->y].rodzicX<<endl;
            cout<<mapa[it->x][it->y].rodzicY<<endl<<endl;
    }
}
void SearchDown()
{
    if(nowY<wym2 && mapa[nowX][nowY+1].znak != 5 && mapa[nowX][nowY+1].visited == false){
        listaO.push_front(mapa[nowX][nowY+1]);
        list<Punkt>::iterator it=listaO.begin();
        it->heur();
        mapa[it->x][it->y].rodzicX = nowX;
        mapa[it->x][it->y].rodzicY = nowY;
        mapa[nowX][nowY+1].visited=true;
        it->rodzicX = nowX;
        it->rodzicY = nowY;
        it->g = it->g+1;
        cout<<it->x<<endl;
            cout<<it->y<<endl;
            cout<<it->znak<<endl;
            cout<<it->h<<endl;
            cout<<mapa[it->x][it->y].rodzicX<<endl;
            cout<<mapa[it->x][it->y].rodzicY<<endl<<endl;
    }
}
void SearchLeft()
{
    if(nowX>0 && mapa[nowX-1][nowY].znak != 5 && mapa[nowX-1][nowY].visited == false){
        listaO.push_front(mapa[nowX-1][nowY]);
        list<Punkt>::iterator it=listaO.begin();
        it->heur();
        mapa[it->x][it->y].rodzicX = nowX;
        mapa[it->x][it->y].rodzicY = nowY;
        mapa[nowX-1][nowY].visited=true;
        it->rodzicX = nowX;
        it->rodzicY = nowY;
        it->g = it->g+1;
        cout<<it->x<<endl;
            cout<<it->y<<endl;
            cout<<it->znak<<endl;
            cout<<it->h<<endl;
            cout<<mapa[it->x][it->y].rodzicX<<endl;
            cout<<mapa[it->x][it->y].rodzicY<<endl<<endl;
    }
}
void SearchRight()
{
    if(nowX<wym1 && mapa[nowX+1][nowY].znak != 5 && mapa[nowX+1][nowY].visited == false){
        listaO.push_front(mapa[nowX+1][nowY]);
        list<Punkt>::iterator it=listaO.begin();
        it->heur();
        mapa[it->x][it->y].rodzicX = nowX;
        mapa[it->x][it->y].rodzicY = nowY;
        mapa[nowX+1][nowY].visited=true;
        it->rodzicX = nowX;
        it->rodzicY = nowY;
        it->g = it->g+1;
        cout<<it->x<<endl;
            cout<<it->y<<endl;
            cout<<it->znak<<endl;
            cout<<it->h<<endl;
            cout<<mapa[it->x][it->y].rodzicX<<endl;
            cout<<mapa[it->x][it->y].rodzicY<<endl<<endl;
    }
}
void SearchAdjacent()
{
    SearchUp();
    SearchDown();
    SearchLeft();
    SearchRight();
}

void Move()
{
    double najmnHeur=listaO.begin()->h;
    for(list<Punkt>::iterator it=listaO.begin(); it!=listaO.end(); it++)
    {
        if(it->f<najmnHeur)
            najmnHeur = it->f;
    }
    for(list<Punkt>::iterator it=listaO.begin(); it!=listaO.end(); it++)
    {
        if(it->f==najmnHeur)
        {
            listaZ.push_front(mapa[it->x][it->y]);
            //it->h=DBL_MAX;
            nowX = it->x;
            nowY = it->y;
            cout<<"Wspolrzedna X: "<<nowX<<endl;
            cout<<"Wspolrzedna Y: "<<nowY<<endl;
            cout<<"Rodzic X: "<<mapa[nowX][nowY].rodzicX<<endl;
            cout<<"Rodzic Y: "<<mapa[nowX][nowY].rodzicY<<endl;

            listaO.erase(it);

            break;
        }

    }
}

void Cofaj()
{
    nowX = celX;
    nowY = celY;

    for(list<Punkt>::iterator it = listaZ.begin(); it!=listaZ.end(); it++)
    {
        cout<<"Wspolrzedna X: "<<it->x<<endl;
        cout<<"Wspolrzedna Y: "<<it->y<<endl;
        cout<<"Rodzic X: "<<it->rodzicX<<endl;
        cout<<"Rodzic Y: "<<it->rodzicY<<endl<<endl;
    }
    for(list<Punkt>::iterator it = listaZ.begin(); it != listaZ.end(); it++)
    {
        if(it->x == nowX && it->y == nowY)
        {
            mapa[nowX][nowY].znak=3;
            nowX = it->rodzicX;
            nowY = it->rodzicY;
        }
    }
}

void trasa()
{
    listaZ.push_front(mapa[startX][startY]);
    list<Punkt>::iterator itZ = listaZ.begin();
    cout<<mapa[itZ->x][itZ->y].znak<<endl;
    list<Punkt>::iterator itO = listaO.begin();



    itZ = listaZ.begin();
    do
    {
        SearchAdjacent();
        Move();
        itZ=listaZ.begin();
        mapa[itZ->x][itZ->y].visited=true;
    }while(itZ->x != celX || itZ->y != celY);


    for(int i=0;i<wym2+1;i++)
    {
        for(int j=0;j<wym1+1;j++)
        {
            cout<<" "<<mapa[i][j].znak;

        }
    cout<<"\n";
    }
    cout<<"Cofanie"<<endl;
    Cofaj();

    for(int i=0;i<wym2+1;i++)
    {
        for(int j=0;j<wym1+1;j++)
        {
            cout<<" "<<mapa[i][j].znak;

        }
    cout<<"\n";
    }
    cout<<"Cofanie zakonczone"<<endl;

}
int main()
{
    wczytaj();
    PobierzStartCel();
    trasa();
    return 0;
}
