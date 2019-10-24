#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

char znak_g, znak_k, zaczyna;

bool pik=true;

bool ruch_komp(char plansza[]);

void czysc_plansze(char plansza[])
{
    for(int i=0; i<9; ++i)
        plansza[i]=' ';
}

void rysuj_plansze(char plansza[])
{
    system("CLS");

    cout << "Tic Tac Toe\n";
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << plansza[0] << "  |  " << plansza[1] << "  |  " << plansza[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << plansza[3] << "  |  " << plansza[4] << "  |  " << plansza[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << plansza[6] << "  |  " << plansza[7] << "  |  " << plansza[8] << endl;
    cout << "     |     |     " << endl << endl;
}

void wybierz_znak()
{
    do{

        cout << "Wybierz znak (X | O): ";
        cin >> znak_g;

    }while(znak_g!='x' && znak_g!='X' && znak_g!='O' && znak_g!='o');

    if(znak_g=='x' || znak_g=='X')
        znak_k='O';

    else if(znak_g=='o' || znak_g=='O')
        znak_k='X';
}

void kto_zaczyna()
{
    do{
    cout << "\n\nWybierz rozpoczynajacego [K | G]: ";
    cin >> zaczyna;

    }while(zaczyna!='k' && zaczyna!='g' && zaczyna!='K' && zaczyna!='G' );
}

void ruch_gracza(char plansza[])
{
    int ruch;

    do{
    cout << "\n\nWybierz pole (0-8): ";
    cin >> ruch;


    }while(ruch > 8 || ruch < 0 || plansza[ruch]==znak_g || plansza[ruch]==znak_k);



    plansza[ruch]=znak_g;
}

bool remis(char plansza[], int licznik)
{
    for(int i=0; i<9; ++i)
    {
        if(plansza[i]!=' ')
            ++licznik;

        if(licznik==8)
        {
            rysuj_plansze(plansza);
            cout << "\nREMIS!!!\n\n";
            return true;
        }

    }
    return false;
}

bool wygrana(char plansza[])
{
  bool test=false;



  if(plansza[0]==znak_k && plansza[1]==znak_k && plansza[2]==znak_k)
    test=true;

  if(plansza[3]==znak_k && plansza[4]==znak_k && plansza[5]==znak_k)
    test=true;

  if(plansza[6]==znak_k && plansza[7]==znak_k && plansza[8]==znak_k)
    test=true;


  if(plansza[0]==znak_k && plansza[3]==znak_k && plansza[6]==znak_k)
    test=true;

  if(plansza[1]==znak_k && plansza[4]==znak_k && plansza[7]==znak_k)
    test=true;

  if(plansza[2]==znak_k && plansza[5]==znak_k && plansza[8]==znak_k)
    test=true;


  if(plansza[0]==znak_k && plansza[4]==znak_k && plansza[8]==znak_k)
    test=true;

  if(plansza[2]==znak_k && plansza[4]==znak_k && plansza[6]==znak_k)
    test=true;


  if(test==true)
  {
      rysuj_plansze(plansza);
      cout << "\nGRACZ " << znak_k << " WYGRYWA!!!\n\n";
      return true;
  }

  return false;
}

void komputer(char plansza[])
{
    int miejsce;

    a:
    miejsce=rand()%9+0;
    if(wygrana(plansza)==false)
    {

        if(ruch_komp(plansza)==true)
            return;

        if(plansza[miejsce]==' ')
        {
            plansza[miejsce]=znak_k;
        }


        else
            goto a;
        }

}

bool ruch_komp(char plansza[])
{

    if((plansza[0]==znak_g || plansza[1]==znak_g || plansza[2]==znak_g || plansza[3]==znak_g || plansza[5]==znak_g || plansza[6]==znak_g || plansza[7]==znak_g || plansza[8]==znak_g) && plansza[4]== ' ')
    {
        plansza[4]=znak_k;
        return true;
    }


    if(plansza[4]==znak_g && pik==true)
    {
        int miejsce;
        b:
        miejsce=rand()%9+0;

        if(miejsce==0 || miejsce==2 || miejsce==6 || miejsce==8)
        {
            plansza[miejsce]=znak_k;
            pik=false;
            return true;
        }
        else
        goto b;
    }






    if(plansza[0]==znak_g && plansza[1]==znak_g && plansza[2]== ' ')//
    {
        plansza[2]=znak_k;
        return true;
    }


    if(plansza[3]==znak_g && plansza[4]==znak_g && plansza[5]== ' ')//
    {
        plansza[5]=znak_k;
        return true;
    }


    if(plansza[6]==znak_g && plansza[7]==znak_g && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }

    if(plansza[0]==znak_g && plansza[2]==znak_g && plansza[1]== ' ')//
    {
        plansza[1]=znak_k;
        return true;
    }


    if(plansza[2]==znak_g && plansza[1]==znak_g && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }


    if(plansza[4]==znak_g && plansza[5]==znak_g && plansza[3]== ' ')//
    {
        plansza[3]=znak_k;
        return true;
    }


    if(plansza[7]==znak_g && plansza[8]==znak_g && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }

    if(plansza[3]==znak_g && plansza[5]==znak_g && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }



    if(plansza[0]==znak_g && plansza[3]==znak_g && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }


    if(plansza[1]==znak_g && plansza[4]==znak_g && plansza[7]== ' ')//
    {
        plansza[7]=znak_k;
        return true;
    }


    if(plansza[2]==znak_g && plansza[5]==znak_g && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }

    if(plansza[6]==znak_g && plansza[8]==znak_g && plansza[7]== ' ')//
    {
        plansza[7]=znak_k;
        return true;
    }



    if(plansza[3]==znak_g && plansza[6]==znak_g && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }


    if(plansza[4]==znak_g && plansza[7]==znak_g && plansza[1]== ' ')//
    {
        plansza[1]=znak_k;
        return true;
    }


    if(plansza[5]==znak_g && plansza[8]==znak_g && plansza[2]== ' ')//
    {
        plansza[2]=znak_k;
        return true;
    }

    if(plansza[0]==znak_g && plansza[6]==znak_g && plansza[3]== ' ')//
    {
        plansza[3]=znak_k;
        return true;
    }



    if(plansza[2]==znak_g && plansza[4]==znak_g && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }


    if(plansza[0]==znak_g && plansza[4]==znak_g && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }


    if(plansza[8]==znak_g && plansza[4]==znak_g && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }

    if(plansza[1]==znak_g && plansza[7]==znak_g && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

    if(plansza[2]==znak_g && plansza[8]==znak_g && plansza[5]== ' ')//
    {
        plansza[5]=znak_k;
        return true;
    }

    if(plansza[2]==znak_g && plansza[6]==znak_g && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

     if(plansza[0]==znak_g && plansza[8]==znak_g && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

    if(plansza[0]==znak_k && plansza[1]==znak_k && plansza[2]== ' ')//
    {
        plansza[2]=znak_k;
        return true;
    }

    if(plansza[3]==znak_k && plansza[4]==znak_k && plansza[5]== ' ')//
    {
        plansza[5]=znak_k;
        return true;
    }

    if(plansza[6]==znak_k && plansza[7]==znak_k && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }

     if(plansza[1]==znak_k && plansza[2]==znak_k && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }

     if(plansza[4]==znak_k && plansza[5]==znak_k && plansza[3]== ' ')//
    {
        plansza[3]=znak_k;
        return true;
    }

     if(plansza[7]==znak_k && plansza[8]==znak_k && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }

     if(plansza[0]==znak_k && plansza[3]==znak_k && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }

     if(plansza[1]==znak_k && plansza[4]==znak_k && plansza[7]== ' ')//
    {
        plansza[7]=znak_k;
        return true;
    }

     if(plansza[2]==znak_k && plansza[5]==znak_k && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }

     if(plansza[3]==znak_k && plansza[6]==znak_k && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }

     if(plansza[4]==znak_k && plansza[7]==znak_k && plansza[1]== ' ')//
    {
        plansza[1]=znak_k;
        return true;
    }

     if(plansza[5]==znak_k && plansza[8]==znak_k && plansza[2]== ' ')//
    {
        plansza[2]=znak_k;
        return true;
    }

     if(plansza[2]==znak_k && plansza[4]==znak_k && plansza[6]== ' ')//
    {
        plansza[6]=znak_k;
        return true;
    }

     if(plansza[0]==znak_k && plansza[4]==znak_k && plansza[8]== ' ')//
    {
        plansza[8]=znak_k;
        return true;
    }

     if(plansza[4]==znak_k && plansza[8]==znak_k && plansza[0]== ' ')//
    {
        plansza[0]=znak_k;
        return true;
    }

     if(plansza[0]==znak_k && plansza[2]==znak_k && plansza[1]== ' ')//
    {
        plansza[1]=znak_k;
        return true;
    }

     if(plansza[3]==znak_k && plansza[5]==znak_k && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

     if(plansza[6]==znak_k && plansza[8]==znak_k && plansza[7]== ' ')//
    {
        plansza[7]=znak_k;
        return true;
    }

     if(plansza[0]==znak_k && plansza[6]==znak_k && plansza[3]== ' ')//
    {
        plansza[3]=znak_k;
        return true;
    }

     if(plansza[1]==znak_k && plansza[7]==znak_k && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

     if(plansza[2]==znak_k && plansza[8]==znak_k && plansza[5]== ' ')//
    {
        plansza[5]=znak_k;
        return true;
    }

     if(plansza[2]==znak_k && plansza[6]==znak_k && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

     if(plansza[0]==znak_k && plansza[8]==znak_k && plansza[4]== ' ')//
    {
        plansza[4]=znak_k;
        return true;
    }

    return false;

}

int main()
{
    srand(time(NULL));

    char petla;
    int licznik=0;

    char plansza[9];

        gra:

    system("CLS");
    czysc_plansze(plansza);
    wybierz_znak();

    kto_zaczyna();

    while(true)
    {


    if(zaczyna=='g' || zaczyna=='G')
        {
            rysuj_plansze(plansza);
            ruch_gracza(plansza);
            komputer(plansza);

            if(wygrana(plansza)==true || remis(plansza, licznik)==true)
            {

                cout << "\n\nJeszcze raz? (T | N) : ";
                cin >> petla;
                if(petla=='T' || petla=='t')
                    goto gra;

                    else
                break;
            }

        }

    if(zaczyna=='k' || zaczyna=='K')
        plansza[4]=znak_k;
        rysuj_plansze(plansza);
        ruch_gracza(plansza);
        komputer(plansza);


            if(wygrana(plansza)==true || remis(plansza, licznik)==true)
            {

                cout << "\n\nJeszcze raz? (T | N) : ";
                cin >> petla;
                if(petla=='T' || petla=='t')
                    goto gra;

                    else
                break;
            }

    }

    return 0;
}
