#include <iostream>
#include <cctype>

using namespace std;

int main(){


    int n = 5; // Altura de la mitad del rombo (número de filas)

    // Mitad superior
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "+";
        }
        cout << endl;
    }

    // Mitad inferior
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "+";
        }
        cout << endl;
    }


	return 0;
}