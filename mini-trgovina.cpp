#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int brojArtikla = 0;
    int izbor;
    int MAX = 50;
    string artikli[MAX];
    unsigned long long int barkod [MAX] ;
    float cijena [MAX];
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;

    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos novog artikla" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema bar kodu artikla" << endl;
        cout << "4. Pretraga prema nazivu artikla" << endl;
        cout << "5. Izmjena podataka prema bar kodu" << endl;
        cout << "6. Ispisi sortirano prema nazivu artikla" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout << "Unesito bar kod artikla" ;
            cin >> barkod [brojArtikla];
            cout << "Unesite naziv artikla: ";
            cin.ignore();
            getline(cin, artikli[brojArtikla]);
            cout << "Unesite cijenu artikla" ;
            cin >> barkod [brojArtikla];

            datotekaUpisivanje.open("artikli.txt", ios::app);
            datotekaUpisivanje << barkod [brojArtikla] << endl;
            datotekaUpisivanje << cijena [brojArtikla] << endl;
            datotekaUpisivanje << artikli [brojArtikla] << endl;
            datotekaUpisivanje.close();

            brojArtikla++;
        }
        else if( izbor == 2 )
        {
            cout << "bar kod" << "\t" << "naziv artikla" << "\t" << "cijena" << endl;
            for( int i = 0; i < brojArtikla; i++ )
            {
                cout << barkod [i] <<"\t";
                cout << artikli[i] <<"\t";
                cout << cijena [i] << endl;
            }
        }
        else if( izbor == 3 )
        {
            unsigned long long int barkod_pretraga;
            cout << "upisite barkod";
            cin >> barkod_pretraga;
            bool pronadjen = false;
            for (int i = 0; i<brojArtikla; i++)
            {
                if (barkod_pretraga == barkod[i])
                {
                    cout << barkod [i] <<"\t";
                    cout << artikli[i] <<"\t";
                    cout << cijena [i] << endl;
                    pronadjen==true;
                    break;
                }
                if (pronadjen == false)
                {
                    cout << "unijeli ste krivi barkod";
                }
            }
        }
        else if( izbor == 4 )
        {
            string naziv_pretraga;
            cout << "Upisite naziv artikla";
            cin.ignore();
            getline(cin, naziv_pretraga);
            bool pronadjen = false;
            for (int i = 0; i<brojArtikla; i++)
            {
                if (naziv_pretraga == artikli[i])
                {
                    cout << barkod [i] <<"\t";
                    cout << artikli[i] <<"\t";
                    cout << cijena [i] << endl;
                    pronadjen = true;
                    break;
                }
            }
            if (pronadjen == false)
            {
                cout << "artikl ne postoji";
            }
        }
        else if( izbor == 5 )
        {
        }
        else if( izbor == 6 )
        {
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
