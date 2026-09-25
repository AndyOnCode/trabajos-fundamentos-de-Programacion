#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int longitud;
	int auxiliar;
	bool encontrado=0;
	
	cout<<"vector de cuantos valores??: ";
	cin>>longitud;	
	
	int vector[longitud];
	
	cout<<"Tu vector contiene estos valores: \n";
	
	for(int i=0;i<longitud;i++){
		 vector[i]=rand()%81;
		cout<<vector[i]<<" ";
	}
	cout<<"\nordenando de menor a mayor quedara: \n";
	
	for(int j=0;j<longitud;j++){
		for(int k=0;k<longitud-1;k++){
			auxiliar=vector[k];
			
			if(vector[k+1]<=auxiliar){
				vector[k]=vector[k+1];
				vector[k+1]=auxiliar;
			}
		}
	}
	
	for(int l=0;l<longitud;l++){
		cout<<vector[l]<<" ";
		if(vector[l]==67){
			encontrado=true;
		}
	}
	
	if(encontrado){
		cout<<"SIX SEVEEEEEN";
	}
	
	return 0;
}