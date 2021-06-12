#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std; 

class file {  
    protected:
                ifstream inFile;      

    public:    
        file();
        ~file();
        virtual void loop()=0;
};

file::file() {
    inFile.open("dane_obrazki.txt", ios::in);
    if (!inFile.good())
        {
            cerr << "Blad - nie da sie otworzyc!\n";
            exit(1);
        }
}


file::~file() {
    inFile.close();
}

class picture : public file 
{             
		int k; 
		int wynik;
		bool ileBlWiersz();
		bool ileBlKol();
    public:
        virtual void loop();       
};

struct korekta{
 	int wiersz;
 	int kolumna;
 };


bool  picture::ileBlWiersz()
{
	int parzw, ileBlWiersz=0;
	struct korekta wynik;
	wynik.wiersz=21+1;
 	for(int i=0; i<21; i++){
 		string pobraz[21];
 		parzw=0;
 		for(int j=0; j<20; j++)
 		parzw=parzw+pobraz[i][j];
 		if ((parzw%2)!=pobraz[i][21]) ileBlWiersz++;
 		wynik.wiersz=i+1;
 	} 
}

bool picture::ileBlKol()
{
	int parzk, ileBlKol=0;
	struct korekta wynik;
	wynik.kolumna=21+1;
 	for(int i=0; i<21; i++){
 		string pobraz[21];
 		parzk=0;
 		for(int j=0; j<20; j++)
		parzk=parzk+pobraz[j][i];
 		if ((parzk%2)!=pobraz[20][i]) ileBlKol++;
 		wynik.kolumna=i+1;
 	} 
}

void picture::loop()
{ 
	int c = 0;
        while (!inFile.eof()) 
        {	
        	string obraz[21];
           	for(int i=0;i<21;i++) {
            	inFile >> obraz[i];
        	}
        	bool rekurencyjny = true;
			for (int j=k; j<10; j++)
 			{
    			for(int i=j; i<k; i++)
				{
               	 	if(obraz[i][j] != obraz[i][j+10] || obraz[i][j] != obraz[i+10][j] || obraz[i][j]!=obraz[i+10][j+10]) {
                    	rekurencyjny = false;
                	}
				}
			}
			if(rekurencyjny) {
            c++;
        	}
        }
        cout<< c << endl;
}

int main(int argc, char** argv) {
    picture pit;
    pit.loop();
    return 0;
}
