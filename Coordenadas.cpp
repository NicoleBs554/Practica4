#include <iostream>
#include <cmath>
using namespace std;

struct Linea {
    struct Puntos {
        float x;
        float y;
    } punto1, punto2;
};

void guardarPuntos(Linea&, Linea&);
int lineasSeCruzan(Linea, Linea);
int lineasSeCruzan(Linea, Linea, float m1, float m2);
float anguloInterseccion(Linea a, Linea b, bool enGrados = false);
void proceso();
int contadorProceso();

int contador = 0; 

int main() {
    bool llamarFuncion = true;
    Linea a, b;
    
    while (llamarFuncion) {
        guardarPuntos(a, b);
        
        int resultado = lineasSeCruzan(a, b);
        if (resultado == 1) {
            cout << "Las lineas se cruzan." << endl;
        } else if (resultado == 0) {
            cout << "Las lineas son paralelas." << endl;
        } else if (resultado == -1) {
            cout << "Las lineas son perpendiculares." << endl;
        }

        cout << "Angulo en el punto de cruce: " << anguloInterseccion(a, b) << " radianes." << endl;
        
        int opcion;
        cout << "Mostrar angulo en grados? 1.Si | 2.No: "; 
        cin >> opcion;
        if (opcion == 1) {
            cout << "Angulo en el punto de cruce: " << anguloInterseccion(a, b, true) << " grados." << endl;
        }

        proceso(); 

        cout << "¿Llamar otra vez? 1.Si | 2.No: "; 
        cin >> opcion;
        if (opcion == 2) {
            llamarFuncion = false;
        }
    }
    
    cout << "Las llamadas a la funcion fueron: " << contadorProceso() << endl;

    return 0;
}

void guardarPuntos(Linea& a, Linea& b) {
    cout << "Primera linea" << endl;
    cout << "Punto inicial: " << endl;
    cout << "Coordenada x: "; cin >> a.punto1.x;
    cout << "Coordenada y: "; cin >> a.punto1.y;
    cout << "Punto final: " << endl;
    cout << "Coordenada x: "; cin >> a.punto2.x;
    cout << "Coordenada y: "; cin >> a.punto2.y;
    cout << endl;

    cout << "Segunda linea" << endl;
    cout << "Punto inicial: " << endl;
    cout << "Coordenada x: "; cin >> b.punto1.x;
    cout << "Coordenada y: "; cin >> b.punto1.y;
    cout << "Punto final: " << endl;
    cout << "Coordenada x: "; cin >> b.punto2.x;
    cout << "Coordenada y: "; cin >> b.punto2.y;
}

int lineasSeCruzan(Linea a, Linea b) {
    float x1 = a.punto1.x; 
    float y1 = a.punto1.y;
    float x2 = a.punto2.x; 
    float y2 = a.punto2.y;
    float x3 = b.punto1.x; 
    float y3 = b.punto1.y;
    float x4 = b.punto2.x; 
    float y4 = b.punto2.y;

    if (x1 == x2 && x3 != x4) { 
        if (y3 <= y1 && y4 >= y1) return 1; 
    } else if (y1 == y2 && y3 != y4) { 
        if (x3 <= x1 && x4 >= x1) return 1; 
    }

    float pendiente1 = (y2 - y1) / (x2 - x1);
    float pendiente2 = (y4 - y3) / (x4 - x3);
    
    if (pendiente1 == pendiente2) return 0; 

    if (pendiente1 * pendiente2 == -1) return -1; 

    float det = (x2 - x1) * (y3 - y4) - (y2 - y1) * (x3 - x4);
    
    if (det == 0) return 0; 

    float t = ((x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4)) / det;
    float u = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / det;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        return 1; 
    }
    
    return -1; 
}
int lineasSeCruzan(Linea a, Linea b, float m1, float m2) { 
    if (m1 * m2 == -1) return -1; 
    if (m1 == m2) return 0; 
    return 1; 
}

float anguloInterseccion(Linea a, Linea b, bool enGrados) {
    float pendiente1 = (a.punto2.y - a.punto1.y) / (a.punto2.x - a.punto1.x);
    float pendiente2 = (b.punto2.y - b.punto1.y) / (b.punto2.x - b.punto1.x);
    
    float angulo = atan(fabs((pendiente2 - pendiente1) / (1 + pendiente1 * pendiente2)));
    
    return enGrados ? angulo * 180 / M_PI : angulo; 
}

void proceso() {
    contador++; 
}

int contadorProceso() {
    return contador; 
}
