#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Paciente {
    public:
        string nombre;
        int numero_documento;
        Paciente(string n, int dn) {
            nombre = n;
            numero_documento = dn;
        }
};

void agregarPaciente(queue<Paciente*>& cola) {
    string nombre;
    int numero_documento;
    cout << "Ingrese el nombre del paciente: ";
    cin >> nombre;
    while (true) {
        cout << "Ingrese el número de documento del paciente: ";
        cin >> numero_documento;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida. Por favor, ingrese un número." << endl;
        }
        else {
            break;
        }
    }
    Paciente* p = new Paciente(nombre, numero_documento);
    cola.push(p);
}

void mostrarPacientes(queue<Paciente*>& cola) {
    if (cola.empty()) {
        cout << "No hay pacientes en la cola." << endl;
    }
    else {
        cout << "Pacientes en la cola:" << endl;
        int i = 1;
        while (!cola.empty()) {
            Paciente* p = cola.front();
            cola.pop();
            cout << i << ". " << p->nombre << " (" << p->numero_documento << ")" << endl;
            delete p;
            i++;
        }
    }
}

int main() {
    queue<Paciente*> pacientes;

    while (true) {
        cout << "1. Agregar un paciente" << endl;
        cout << "2. Mostrar todos los pacientes" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida. Por favor, ingrese un número." << endl;
        }
        else if (opcion == 1) {
            agregarPaciente(pacientes);
        }
        else if (opcion == 2) {
            mostrarPacientes(pacientes);
        }
        else if (opcion == 3) {
            break;
        }
        else {
            cout << "Opción inválida. Por favor, ingrese 1, 2 o 3." << endl;
        }
        cout << endl;
    }

    return 0;
}
