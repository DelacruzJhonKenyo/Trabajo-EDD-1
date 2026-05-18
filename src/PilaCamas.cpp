#include <iostream>

using namespace std;

// Pila de camas disponibles (LIFO).
struct NodoCama
{
    int numero;
    NodoCama* siguiente;
};

NodoCama* tope = NULL;

// Verifica si hay camas.
bool PilaVacia()
{
    return tope == NULL;
}

// Registra una cama disponible.
void PushCama(int numero)
{
    NodoCama* nueva = new NodoCama;
    nueva->numero = numero;
    nueva->siguiente = tope;
    tope = nueva;
}

// Asigna una cama (saca de la pila).
bool PopCama(int& numero)
{
    if (tope == NULL)
    {
        return false;
    }
    NodoCama* temp = tope;
    numero = temp->numero;
    tope = temp->siguiente;
    delete temp;
    return true;
}

// Muestra las camas disponibles.
void MostrarCamas()
{
    if (tope == NULL)
    {
        cout << "No hay camas disponibles." << endl;
        return;
    }

    int total = 0;
    NodoCama* temp = tope;
    while (temp != NULL)
    {
        total++;
        temp = temp->siguiente;
    }

    cout << "Camas disponibles: " << total << endl;
    temp = tope;
    while (temp != NULL)
    {
        cout << "Cama " << temp->numero << endl;
        temp = temp->siguiente;
    }
}

// Libera toda la pila.
void LiberarPila()
{
    while (tope != NULL)
    {
        NodoCama* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}