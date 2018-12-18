#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
class Punkt
{
    public:
        int x;
        int y;
        int pole;
};

int main()
{
    cout<<"Wczytywanie danych z pliku\n";

string nazwap="grid.txt";
int wym2=20;
int wym1=20;

//teraz deklarujemy dynamicznie tablice do, kt�rej wczytamyu nasz plik,
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

Punkt** punkty = 0;
punkty = new Punkt*[wym2+1];
for(int i=1;i<wym2+1;i++)
 {

     punkty[i]=new Punkt[wym1+1];
  for(int j=1;j<wym1+1;j++)
   {
        cout<<" "<<G[i][j];
        punkty[i][j].x=i;
        punkty[i][j].y=j;
        punkty[i][j].pole=G[i][j];

   }
   cout<<"\n";
 }

   cout<<"\n";
   cout<<"\n";
   cout<<"\n";
   cout<<"wy�wietlanie mapy z obiektu";
   cout<<"\n";

for(int i=1;i<wym2+1;i++)
 {
  for(int j=1;j<wym1+1;j++)
   {
        cout<<" "<<punkty[i][j].pole;

   }
   cout<<"\n";
 }

//na koniec czy�cimy pami�� po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy

cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();
    cout << "Hello world!" << endl;
    cout <<"sranie";
    return 0;
}
