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
    inFile.open("dane_obrazki.txt");
    if (!inFile.good())
        {
            cerr << "Blad - nie da sie otworzyc!\n";
            exit(1);
        }}

file::~file() {
    inFile.close();
}

class picture : public file 
{             
		int k; 
		bool checkPicture(string);
    public:
        virtual void loop();       
};

bool picture::checkPicture(string wiersz)
{
	int czarne=0;
	for(int i=k;i<20;i++){
 		if (wiersz[i]=='1') 
       		czarne++; 
}  }

void picture::loop()
{
        int c = 0;
        while (!inFile.eof()) 
        {
            inFile >> c;
           	int t[21][7];
			for (int j=k; j<20; j++)
 			{
    			for(int i=j; i<k; i++)
				{
        		cout << t[j][i] << " ";
   				}
   				cout << c <<endl;}}}

int main(int argc, char** argv) {
    picture pit;
    pit.loop();
    return 0;
}
