#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x;
    double y;
};

double calcularPendiente(Punto p1, Punto p2) {
    if (p2.x - p1.x == 0) {
        return -1; 
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}


int verificarLineas(Punto A1, Punto A2, Punto B1, Punto B2) {
    double m1 = calcularPendiente(A1, A2);
    double m2 = calcularPendiente(B1, B2);
    if (m1 == m2) {
        return 0; 
    }
    
    return 1; 
}


int verificarLineas(Punto A1, Punto A2, Punto B1, Punto B2, bool esPerpendicular) {
    double m1 = calcularPendiente(A1, A2);
    double m2 = calcularPendiente(B1, B2);
    if (m1 == m2) {
        return 0; 
    }
    if (m1 * m2 == -1) {
        return 1; 
    }
    return -1; 
}


double calcularAngulo(Punto A1, Punto A2, Punto B1, Punto B2, bool enGrados = false) {
    double m1 = calcularPendiente(A1, A2);
    double m2 = calcularPendiente(B1, B2);

    double anguloRad = atan(fabs((m2 - m1) / (1 + m1 * m2)));

    if (enGrados) {
        return anguloRad * (180.0 / M_PI); 
    }
    return anguloRad; 
}

int contadorLlamadas = 0;

void realizarProceso() {
    cout << "Proceso realizado." << endl;
    contadorLlamadas++; 
}

int obtenerCantidadLlamadas() {
    return contadorLlamadas;
}
float anguloInterseccion(Punto a, Punto b, bool en_grados = false);

void guardarPuntos(Punto&, Punto&);

int main() {
    Punto A1, A2, B1, B2;
    bool llamarFuncion = true;
    Punto a, b;
    while (llamarFuncion) {
        guardarPuntos(a, b);

        cout << "Ingrese la coordenada x del primer punto de la primera linea: ";
        cin >> A1.x;
        cout << "Ingrese la coordenada y del primer punto de la primera linea: ";
        cin >> A1.y;
        cout << "Ingrese la coordenada x del segundo punto de la primera linea: ";
        cin >> A2.x;  
        cout << "Ingrese la coordenada y del segundo punto de la primera linea: ";
        cin >> A2.y;

        cout << "Ingrese la coordenada x del primer punto de la segunda linea: ";
        cin >> B1.x; 
        cout << "Ingrese la coordenada y del primer punto de la segunda linea: ";
        cin >> B1.y;
        cout << "Ingrese la coordenada x del segundo punto de la segunda linea: ";
        cin >> B2.x;
        cout << "Ingrese la coordenada y del segundo punto de la segunda linea: ";
        cin >> B2.y;

        int resultado = verificarLineas(A1, A2, B1, B2);
        if (resultado == 0) {
            cout << "Las lineas son paralelas." << endl;
        } else {
            cout << "Las lineas se cruzan." << endl;
        }

        int resultadoPerpendicular = verificarLineas(A1, A2, B1, B2, true);
        if (resultadoPerpendicular == 0) {
            cout << "Las lineas son paralelas." << endl;
        } else if (resultadoPerpendicular == 1) {
            cout << "Las lineas son perpendiculares." << endl;;
        } else {
            cout << "Las lineas se cruzan." << endl;
        }

        double anguloRad = calcularAngulo(A1, A2, B1, B2);
        cout << "El angulo entre las lineas en radianes es: " << anguloRad << endl;

        double anguloGrados = calcularAngulo(A1, A2, B1, B2, true);
        cout << "El angulo entre las lineas en grados es: " << anguloGrados << endl;

        cout << "Angulo en el punto de cruce: " << anguloInterseccion(a, b) << " radianes." << endl;
        int opcion;
        cout << "Mostrar angulo en grados? 1.Si | 2.No: "; 
        cin >> opcion;
        if (opcion == 1) {
            cout << "Angulo en el punto de cruce: " << anguloInterseccion(a, b, true) << " grados." << endl;
        }

        realizarProceso();
            cout << "Cantidad de veces que se llamo a la funcion de proceso: " << obtenerCantidadLlamadas() << endl;
            cout << "¿Llamar otra vez? 1.Si | 2.No: "; 
            cin >> opcion;
            if (opcion == 2) {
                llamarFuncion = false;
            }

    return 0;
}

