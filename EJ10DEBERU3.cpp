#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	
	string texto;
	int contarlineas=1;
	ifstream archivoleer;
	
	archivoleer.open("C:\\Users\\USER\\Documents\\FUND.PROGRAMACION\\archivostr.txt");
	
	if(archivoleer.fail()){
		cout<<"El archivo no se abrio correctamente.";
	}else{
		cout<<"Archivo abierto con exito! .\n";
	}
	
	while(archivoleer>>texto){
		cout<<"Linea "<<contarlineas<<": "<<texto<<endl;
		contarlineas++;
	}
	
	
	return 0;
}	