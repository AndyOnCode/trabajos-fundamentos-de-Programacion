#include <iostream>
#include <string>
using namespace std;

int main() {
	string texto;
	cout<<"Ingrese un texto: ";
	getline(cin,texto);
	
	for(int i=0;i<texto.size();i++){
		
		cout<<"'"<<texto[i]<<"'"<<"-> ";
		int numenascii=texto[i];
		string letra="";
		
		while(numenascii>0){
			int residuo=numenascii%16;
			
			char digitoh;
			if(residuo<10){
				digitoh=residuo+'0';
			}else{
				digitoh=(residuo-10)+'A';
			}
				letra=digitoh+letra;
				numenascii=numenascii/16;	
		}
		cout<<letra<<endl;
	}
    return 0;
}
