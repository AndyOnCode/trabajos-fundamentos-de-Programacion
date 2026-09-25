#include <iostream>
#include <string>
#include <cstdlib> // Libreria requerida para system("cls") y system("pause")

using namespace std;

int main() {
    int opcion = 0;

    // Acumuladores para el informe global de la sesión
    int totalEvaluados = 0;
    float sumaPuntajes = 0.0f;
    int riesgoAltoContador = 0;

    do {
        system("cls"); // Limpia la consola al inicio del menu

        cout << "===============================================\n";
        cout << "   ANALYTICS HUB - PREDICTOR DE CHURN (APP)   \n";
        cout << "===============================================\n";
        cout << "1. Evaluar usuario (Calcular Score & Riesgo)\n";
        cout << "2. Ver informe estadistico de la sesion\n";
        cout << "3. Ver modelo matematico y variables\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion (1-4): ";
        cin >> opcion;

        if (opcion == 1) {
            string idUsuario;
            int diasInactivo;
            float tiempoSesion;
            int frecuenciaSemanal;

            cout << "\n-----------------------------------------------\n";
            cout << "  REGISTRO DE METRICAS DEL USUARIO\n";
            cout << "-----------------------------------------------\n";
            cout << "ID / Nombre del usuario: ";
            cin >> idUsuario;
            cout << "Dias transcurridos sin abrir la app: ";
            cin >> diasInactivo;
            cout << "Tiempo promedio por sesion (minutos): ";
            cin >> tiempoSesion;
            cout << "Frecuencia de uso semanal: ";
            cin >> frecuenciaSemanal;

            // ALGORITMO DE SCORING (Puntaje de 0 a 100)
            float puntaje = 50.0f - (diasInactivo * 3.5f) + (tiempoSesion * 2.0f) + (frecuenciaSemanal * 4.0f);

            if (puntaje > 100.0f) puntaje = 100.0f;
            if (puntaje < 0.0f) puntaje = 0.0f;

            // BARRA VISUAL EN CONSOLA
            int bloques = (int)(puntaje / 10.0f);
            string barra = "[";
            for (int i = 0; i < 10; i++) {
                if (i < bloques) {
                    barra += "#";
                } else {
                    barra += ".";
                }
            }
            barra += "]";

            // REPORTE INDIVIDUAL
            cout << "\n===============================================\n";
            cout << "  DIAGNOSTICO DE RETENCION: " << idUsuario << "\n";
            cout << "===============================================\n";
            cout << "Score de Fidelidad : " << puntaje << " / 100\n";
            cout << "Salud del Usuario  : " << barra << "\n\n";

            if (puntaje < 40.0f) {
                cout << "ESTADO     : [!!!] RIESGO ALTO DE ABANDONO (CHURN)\n";
                cout << "DIAGNOSTICO: Desinteres critico por inactividad prolongada.\n";
                cout << "ACCION     : Enviar cupon de descuento o notificacion urgente.\n";
                riesgoAltoContador++;
            } else if (puntaje < 70.0f) {
                cout << "ESTADO     : [ ! ] RIESGO MEDIO (EN DECLIVE)\n";
                cout << "DIAGNOSTICO: Uso irregular o sesiones muy cortas.\n";
                cout << "ACCION     : Enviar tutorial o recordar funciones clave.\n";
            } else {
                cout << "ESTADO     : [ OK ] USUARIO SALUDABLE / FIDELIZADO\n";
                cout << "DIAGNOSTICO: Alto engagement y patron de uso constante.\n";
                cout << "ACCION     : Mantener la experiencia y sugerir referidos.\n";
            }
            cout << "===============================================\n\n";

            // Actualizar variables globales
            totalEvaluados++;
            sumaPuntajes += puntaje;

            system("pause"); // Pausa antes de limpiar pantalla y volver al menu

        } else if (opcion == 2) {
            cout << "\n-----------------------------------------------\n";
            cout << "  INFORME GENERAL DE LA SESION\n";
            cout << "-----------------------------------------------\n";
            if (totalEvaluados == 0) {
                cout << "Aun no se han evaluado usuarios en esta sesion.\n";
            } else {
                cout << "Total de usuarios evaluados : " << totalEvaluados << "\n";
                cout << "Promedio de Score de la app : " << (sumaPuntajes / totalEvaluados) << " / 100\n";
                cout << "Usuarios en Riesgo Alto     : " << riesgoAltoContador << "\n";
            }
            cout << "-----------------------------------------------\n\n";

            system("pause");

        } else if (opcion == 3) {
            cout << "\n-----------------------------------------------\n";
            cout << "  MODELO MATEMATICO Y VARIABLES\n";
            cout << "-----------------------------------------------\n";
            cout << "Formula aplicada:\n";
            cout << "Score = 50 - (Dias * 3.5) + (Tiempo * 2.0) + (Frecuencia * 4.0)\n\n";
            cout << "* Inactividad : Penaliza el desinteres en el tiempo.\n";
            cout << "* Tiempo/Sesion: Mide el nivel de engagement diario.\n";
            cout << "* Frecuencia  : Valora el habito de retorno a la app.\n";
            cout << "-----------------------------------------------\n\n";

            system("pause");

        } else if (opcion == 4) {
            cout << "\nCerrando el sistema de analitica. ¡Hasta pronto!\n";
        } else {
            cout << "\nOpcion no valida. Intente de nuevo.\n\n";
            system("pause");
        }

    } while (opcion != 4);

    return 0;
}