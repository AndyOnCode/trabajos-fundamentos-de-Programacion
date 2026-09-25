#include<iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	
	ofstream archivoautos;
	archivoautos.open("autos.txt");
	short int numauto[5]={54,62,71,85,97};
	short int millas[5]={250,525,123,1322,235};
	short int galones[5]={19,38,6,86,14};
	
	if (archivoautos.fail()){
		cout<<"Archivo no fue creado.";
	}else{
		cout<<"Archivo creado con exito.";
	}
	
	for(int i=0;i<5;i++){
		
		archivoautos<<numauto[i]<<" "<<millas[i]<<" "<<galones[i]<<endl;	
	}
		
	return 0;
}