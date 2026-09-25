#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	int texto;
	ifstream archivonum;
	int numgrupo=1;
	
	archivonum.open("promedionumeros.txt");
	if(archivonum.fail()){
		cout<<"El archivo no se pudo abrir.\n";
	}else{
		cout<<"Archivo abierto correctamente.\n";
	}
	
	while(archivonum>>texto){
		double suma=0;
		int valor;
		
		for(int i=0;i<texto;i++){
			archivonum>>valor;
			suma+=valor;
		}
		double promedio= suma/texto;
		cout<<"El promedio del grupo "<<numgrupo<<": "<<promedio<<endl;
		numgrupo++;
	}
	
	
	
	return 0;
}