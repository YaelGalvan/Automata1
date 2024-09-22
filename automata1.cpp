#include <iostream>
#include <string>

using namespace std;

// Definición de los estados
enum State { q0, q1, q2 };

// Función que procesa una palabra según el autómata definido
bool procesarPalabra(const string& palabra) {
    State estadoActual = q0;  // Comienza en el estado inicial q0

    // Procesa cada caracter de la palabra
    for (char c : palabra) {
        switch (estadoActual) {
            case q0:
                if (c == 'a') {
                    estadoActual = q1;  // Transición de q0 con 'a' -> q1
                } else if (c == 'b') {
                    estadoActual = q2;  // Transición de q0 con 'b' -> q2
                } else {
                    return false;  // Si hay un caracter inválido, no acepta
                }
                break;
            case q1:
                if (c == 'a') {
                    estadoActual = q1;  // Transición de q1 con 'a' -> q1
                } else if (c == 'b') {
                    estadoActual = q1;  // Transición de q1 con 'b' -> q1
                } else {
                    return false;  // Si hay un caracter inválido, no acepta
                }
                break;
            case q2:
                if (c == 'a') {
                    estadoActual = q0;  // Transición de q2 con 'a' -> q0
                } else if (c == 'b') {
                    estadoActual = q2;  // Transición de q2 con 'b' -> q2
                } else {
                    return false;  // Si hay un caracter inválido, no acepta
                }
                break;
        }
    }

    // Estados finales: q1
    return (estadoActual == q1);
}

int main() {
    // Lista de palabras para probar
    string palabrasAceptadas[] = {"aabb", "bbab", "ababa", "bbaab", "abaab", "babab", "aaab", "aba", "bbbb", "aabab", "aaabb", "aabababab", "ababababa", "aaaaaa", "abb", "abbb"};
    string palabrasNoAceptadas[] = {"babba", "bbabba", "bbababba", "bbabbabba", "bbabbabbaa", "bbabba", "aabbb", "bbabbabba", "bbba", "bbabbabbabba", "bbbbba", "aaaaab", "bba", "bbaa"};

    cout << "Palabras aceptadas:\n";
    for (const string& palabra : palabrasAceptadas) {
        if (procesarPalabra(palabra)) {
            cout << palabra << ": Aceptada\n";
        } else {
            cout << palabra << ": No aceptada\n";
        }
    }

    cout << "\nPalabras no aceptadas:\n";
    for (const string& palabra : palabrasNoAceptadas) {
        if (procesarPalabra(palabra)) {
            cout << palabra << ": Aceptada\n";
        } else {
            cout << palabra << ": No aceptada\n";
        }
    }

    return 0;
}
