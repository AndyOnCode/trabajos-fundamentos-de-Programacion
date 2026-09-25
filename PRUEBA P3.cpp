#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string verificarcedula();
string verificarnombre();
string verificarcarrera();
float validarNota(int);
float calcularPromedio(float[3]);

struct estudiante{
	string cedula;
	string nombre;
	string carrera;
	float notas[3];
	float promedio;
	
};

int main(){
	string numest;
	int numestudiantes;
	bool valido;
	do{
		 valido=1;
			cout<<"¿Cuantos estudiantes desea ingresar?: ";
			getline(cin,numest);
		
		for(int i=0;i<numest.size();i++){
			
			if(!isdigit(numest[i])){
				valido=0;
			}
		}
		
		if (valido==0){
				cout<<"dato incorrecto."<<endl;
			}
		else{
				numestudiantes=stoi(numest);
				if(numestudiantes==0){
					valido=0;
					cout<<"no puede ser cero"<<endl;
				}
		}
		
	}while(!valido);

 estudiante ListaEstudiantes[numestudiantes];
 
 for(int i=0;i<numestudiantes;i++){
 	cout<<"-------- Estudiante "<<i+1<<"----------"<<endl;
 	ListaEstudiantes[i].cedula=verificarcedula();
 	ListaEstudiantes[i].nombre=verificarnombre();
 	ListaEstudiantes[i].carrera=verificarcarrera();
 	for(int j=0;j<3;j++){
 		ListaEstudiantes[i].notas[j]= validarNota(j+1);
	 }
	 
 	ListaEstudiantes[i].promedio=calcularPromedio(ListaEstudiantes[i].notas);
 	
	}
	
	
	
	return 0;
}

string verificarcedula(){
	string ced;
	bool verificador;
	
	do{
		verificador=1;
		cout<<"Ingrese la cedula: ";
		getline(cin,ced);
		if(ced.size()!=10){
			cout<<"la cedula tiene hasta 10 caracteres."<<endl;
			verificador=0;
			continue;
		}
		
	for(int i=0;i<ced.size();i++){
		if(!isdigit(ced[i]))
		{
			verificador=0;
		}		
	}
	if(verificador==0){
		cout<<"no debe tener letras."<<endl;
	}
			
	}
	while(!verificador);
	
	return ced;
}

string verificarnombre(){
	string nom;
	bool verificador;
	
	do{
	verificador=1;
	cout<<"Ingrese el nombre: ";
	getline(cin,nom);
	
	for(int i=0;i<nom.size();i++){
		if(!isalpha(nom[i])&&nom[i]!=' '){
			
			cout<<"solo letras y espacios."<<endl;
			verificador=0;
			break;
		}
	}
	
	}
	while(!verificador);
	for (int i=0;i<nom.size();i++){
		nom[i]=toupper(nom[i]);
	}
	return nom;
}

string verificarcarrera(){
	string carr;
	bool verificador;
	do{
	verificador=1;
	cout<<"Ingrese la carrera: ";
	getline(cin,carr);
	for(int i=0;i<carr.size();i++){
		if(!isalpha(carr[i])&&carr[i]!=' '){
			verificador=0;
			cout<<"Solo letras y espacios."<<endl;
			break;
		}	
	}
	
	}while(!verificador);
	
	for(int i=0;i<carr.size();i++){
		carr[i]=toupper(carr[i]);
	}
	return carr;
}

float validarNota(int x){
	string nota;
	bool verificador;
	int puntos;
	float notafloat;
	do{

	do{
	verificador=1;
	puntos=0;
	cout<<"Ingresa la nota "<<x<<": ";
	getline(cin,nota);
	
	for(int i=0;i<nota.size();i++){
		if(nota[i]>='0'&&nota[i]<='9'){			
			
		}
		else{
			if(nota[i]=='.'){
			puntos++;}
			else{
				verificador=0;
				cout<<"ingrese un valor valido."<<endl;
				break;
			}
		}

		
	}
	if(puntos>1||nota.empty()){
		cout<<"Ingrese un valor correcto."<<endl;
		verificador=0;
	}
	
}while(!verificador);

verificador=1;
notafloat=stof(nota);
if(notafloat>20){
	cout<<"debe hasta 20 la nota.\n";
	verificador=0;
}


}while(!verificador);

return notafloat;
}

float calcularPromedio(float x[3]){
	float suma=0.0;
	
	for(int i=0;i<3;i++){
		suma+=x[i];
	}
	suma=suma/3;
	return suma;
}




