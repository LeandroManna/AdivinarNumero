#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    // Declaración de variables
    int limiteInferior, limiteSuperior, intentosMax, ciclosDeIntentos, numSecreto, numUsuario;
    int guesses[100];
    int numGuesses = 0;
    bool guessedRight = false;

    // Solicitamos al usuario el rango de números y la cantidad de intentos máximos
    cout << "Ingrese el límite inferior del rango: ";
    cin >> limiteInferior;

    cout << "Ingrese el límite superior del rango: ";
    cin >> limiteSuperior;

    cout << "Ingrese la cantidad de intentos máximos: ";
    cin >> intentosMax;

    // Generamos el número secreto aleatorio
    srand(time(NULL)); // Inicializamos el generador de números aleatorios
    numSecreto = rand() % (limiteSuperior - limiteInferior + 1) + limiteInferior;

    // Iniciamos el ciclo de intentos
    ciclosDeIntentos = intentosMax;
    while (ciclosDeIntentos > 0 && !guessedRight) {
        // Pedimos al usuario que ingrese un número
        cout << "Ingrese un número: ";
        cin >> numUsuario;

        // Verificamos si el número ya fue ingresado anteriormente
        if (find(guesses, guesses + numGuesses, numUsuario) != guesses + numGuesses) {
            cout << "El número " << numUsuario << " ya fue ingresado anteriormente." << endl;
            continue;
        }

        // Agregamos el número al array de intentos
        guesses[numGuesses] = numUsuario;
        numGuesses++;

        // Ordenamos el array de intentos de manera ascendente
        sort(guesses, guesses + numGuesses);

        // Informamos los números ingresados anteriormente
        cout << "Números ingresados anteriormente: ";
        for (int i = 0; i < numGuesses; i++) {
            cout << guesses[i] << " ";
        }
        cout << endl;

        // Verificamos si el usuario adivinó el número secreto
        if (numUsuario == numSecreto) {
            cout << "¡Felicitaciones! Adivinaste el número secreto en " << intentosMax - ciclosDeIntentos + 1 << " intentos." << endl;
            guessedRight = true;
        }
        else {
            // Informamos si el número ingresado es mayor o menor que el número secreto
            if (numUsuario < numSecreto) {
                cout << "El número ingresado es menor que el número secreto." << endl;
            }
            else {
                cout << "El número ingresado es mayor que el número secreto." << endl;
            }

            // Informamos cuántos intentos lleva y cuántos intentos le quedan al usuario
            cout << "Lleva " << intentosMax - ciclosDeIntentos + 1 << " intentos." << endl;
            ciclosDeIntentos--;
            cout << "Le quedan " << ciclosDeIntentos << " intentos." << endl;
        }
    }

    // Verificamos si se quedó sin intentos y le informamos el número secreto
    if (ciclosDeIntentos == 0) {
        cout << "Se quedó sin intentos. El número secreto era " << numSecreto << "." << endl;
    }

    return 0;
}
