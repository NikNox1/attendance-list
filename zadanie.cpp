#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

void WpiszNrIndeksu(int tab[][7], int ile);
void Wyswietl(int tab[][7], int ktory);
int SprawdzObecnosc(int tab[][7], int ile);

int main()
{
	int obecnosc=0;
	cout << "ilu masz studentow?: ";
	int liczba_studentow;
	cin >> liczba_studentow;
	int tablica[liczba_studentow][7];
	system("clear");

	WpiszNrIndeksu(tablica, liczba_studentow);
	obecnosc=SprawdzObecnosc(tablica, liczba_studentow);
	
	cout << "Dzisiaj obecnych jest " << obecnosc << " studentow" << endl;

	return 0;
}

void WpiszNrIndeksu(int tab[][7],int ile){
	for(int i=0; i<ile; i++){
		cout << "Podaj numer indeksu " << i+1 << ". studenta: ";
		int nr_indeksu=0;
		cin >> nr_indeksu;
		ostringstream str;
		str << nr_indeksu;
		string sstr = str.str();
	
		for(int j=0; j<6; j++){
			tab[i][j]=sstr[j];
		}
		system("clear");
	}
}

void Wyswietl(int tab[][7],int ktory){
	for(int i=0; i<6; i++){
		cout << (char)tab[ktory][i];
	}
	cout << endl;
}

int SprawdzObecnosc(int tab[][7], int ile){
	int licznik=0;
	cout << "--------Sprawdzanie obecnosci(1-obecny, 0-nieobecny)--------" << endl;
	for(int i=0; i<ile; i++){
		Wyswietl(tab, i);
		cout << ":";
		cin >> tab[i][6];
		int war;
		bool a=tab[i][6]!=1;
		cout << a << endl;

			while((tab[i][6]!=1)&&(tab[i][6]!=0)){
				cout << "Nieodpowiedni format!" << endl;
				cout << "Wpisz jeszcze raz: ";
				cin >> tab[i][6];
				cout << tab[i][6] << endl;
			}
		if(tab[i][6]==1) licznik++;
	}	
return licznik;
}

