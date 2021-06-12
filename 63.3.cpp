  
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class file{
    
    ifstream plik;  
    vector <int> factors(int number);
    vector <int> czynniki;
    
    public:  
    void run();
    
};
void file::run(){
    plik.open("ciagi.txt");
    vector <int> factors(int number){
    	vector <int> czynniki;
		for (int i=2; i<number/2; i++){
   			while (number %i ==0){
        		number /=i;
        		czynniki.push_back(i);
    		}
 		}
 	return czynniki;
	}
}

int main() {
    vector <int> czynniki16 = factors(16);
    
  	for (int i=0; i<czynniki16.size(); i++)
      	cout <<"16=" << czynniki16[i] << "*";
   
    printf( "\n\nKoniec\n" );
    
    return 0;
}
