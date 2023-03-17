#include <iostream>
#include <string>

using namespace std;

struct Atleta {
    string nombre;
    int numero;
};

const int MAX_RONDAS = 10;

int main() {
    // Declaración de variables
    Atleta atletas[MAX_RONDAS];
    float tiempos[MAX_RONDAS][MAX_RONDAS];
    float promedios[MAX_RONDAS];
    int num_atletas = 0;
    int num_rondas = 0;

    // Bucle principal
    while (true) {
        // Solicitar datos del atleta
        cout << "Ingrese el nombre del atleta (o 'fin' para terminar): ";
        string nombre;
        cin >> nombre;
        if (nombre == "fin") {
            break;
        }
        cout << "Ingrese el número asignado al atleta: ";
        int numero;
        cin >> numero;

        // Registrar datos del atleta
        Atleta atleta = { nombre, numero };
        atletas[num_atletas] = atleta;
        num_atletas++;

        // Registrar tiempo en arreglo de tiempos
        float tiempo;
        cout << "Ingrese el tiempo del atleta en esta ronda: ";
        cin >> tiempo;
        tiempos[num_rondas][num_atletas - 1] = tiempo;

        // Actualizar contador de rondas
        num_rondas++;

        // Calcular promedios
        if (num_rondas >= 2) {
            for (int i = 0; i < num_atletas; i++) {
                float t1 = tiempos[num_rondas - 1][i];
                float t2 = tiempos[num_rondas - 2][i];
                float promedio = (t1 + t2) / 2;
                promedios[i] = promedio;
            }
        }

        // Ordenar promedios
        for (int i = 0; i < num_atletas - 1; i++) {
            for (int j = i + 1; j < num_atletas; j++) {
                if (promedios[i] > promedios[j]) {
                    // Intercambiar elementos
                    float temp = promedios[i];
                    promedios[i] = promedios[j];
                    promedios[j] = temp;
                    Atleta temp2 = atletas[i];
                    atletas[i] = atletas[j];
                    atletas[j] = temp2;
                }
            }
        }
    }

    // Mostrar resultados finales
    cout << "Resultados finales:" << endl;
    for (int i = 0; i < num_atletas; i++) {
        cout << i + 1 << ". " << atletas[i].nombre << " - Promedio: " << promedios[i] << endl;
    }

    return 0;
}
