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
    inFile.open("dane_ulamki.txt", ios::in);
    if (!inFile.good())
        {
            cerr << "Blad -  nie da sie otworzyc!\n";
            exit(1);
        }
}
file::~file() {
    inFile.close();
}
class Euklidesa : public file 
{             
	string licz;
	string mian;

    public:
        virtual void loop();       
};
int nwd(int n, int m){
 if (m==0) return n;
 return nwd(m,n%m);
} 
void Euklidesa ::loop()
{	 
	int ileN=0;
 	for(int i=0; i<1000; i++){
 		if (nwd(licz[i],mian[i])==1)
 		ileN++;
 	}
 	cout<< ileN << endl;
}
int main(int argc, char** argv) {
    Euklidesa  eu;
    eu.loop();
    return 0;
} 
