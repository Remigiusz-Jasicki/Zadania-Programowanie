#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int liczby;	
	int min = 1000000;
	int max = 0;


	fstream plik;

    plik.open("liczby1.txt", ios::in);
    if(plik.good() == true){
        while(!plik.eof()){
        	for(liczby=0; liczby<1000; liczby++) {
 				cin >> liczby; 
            	if (liczby > min){
     				min = liczby;
     			}
     			if (liczby < max){
     				max = liczby;
     			}
     		} 
        }
	} 
	    plik.close(); 
  	plik >> oct >> liczby;      
    cout << dec << min;
	cout << dec << min;
    return 0;
}

