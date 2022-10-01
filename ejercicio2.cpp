/* 2) Se tiene una lista enlazada donde cada nodo contiene nombre y número de documento de las
personas inscriptas en un curso, ordenada por número de documento. Hacer funciones para:
a. agregar un inscripto al curso, considerar que puede estar la lista vacía o ya contener
información.
b. dar de baja una persona que no concurrirá al curso.
c. imprimir la lista completa.
d. Imprimir la lista en orden inverso (ordenada por documento de mayor a menor) */

#include <iostream>
#include <string.h>

using namespace std;

struct Persona
{
  int dni;
  string nombre;
};

struct Nodo
{
  Persona info;
  Nodo *sig;
};

void puntoA(Nodo *&lista, Persona pers);
bool puntoB(Nodo *&lista, int dni);
void puntoC(Nodo *lista);
void puntoD(Nodo *lista);
void apilar(Nodo *&pila, Persona pers);
void desapilar(Nodo *&pila, Persona &pers);

int main()
{
  Persona pj;
  Nodo *listaPersonas = NULL;

  /* PARA ARMAR LA LISTA DE LAS PERSONAS INSCRIPTAS EN UN CURSO (OPCIONAL) */
  cout << "ARMANDO LA LISTA" << endl;
  cout << "Ingrese el DNI de la persona a agregar a la lista (0 para finalizar): ";
  cin >> pj.dni;
  while (pj.dni != 0)
  {
    cout << "Ingrese el nombre de la persona a agregar a la lista: ";
    cin >> pj.nombre;
    puntoA(listaPersonas, pj);
    cout << "Ingrese el DNI de la persona a agregar a la lista (0 para finalizar): ";
    cin >> pj.dni;
  }
  /* ################## */

  cout << "Ingrese el nombre de la persona inscripta al curso: ";
  cin >> pj.nombre;
  cout << "Ingrese el DNI de la persona inscripta al curso: ";
  cin >> pj.dni;
  puntoA(listaPersonas, pj);

  cout << "Ingrese el DNI de la persona que se dara de baja al curso: ";
  cin >> pj.dni;
  if (puntoB(listaPersonas, pj.dni))
    cout << "El alumno de DNI " << pj.dni << " fue dado de baja de forma exitosa" << endl;
  else
    cout << "No existe un alumno con ese DNI en la lista" << endl;

  puntoC(listaPersonas);

  puntoD(listaPersonas);

  return 0;
}

void puntoA(Nodo *&lista, Persona pers) // Función insertar
{
  Nodo *q, *p, *ant;
  q = new Nodo;
  q->info = pers;
  p = lista;
  while (p != NULL && p->info.dni < pers.dni)
  {
    ant = p;
    p = p->sig;
  }
  q->sig = p;
  if (p != lista)
    ant->sig = q;
  else
    lista = q;
}

bool puntoB(Nodo *&lista, int dni) // Función eliminar
{
  Nodo *p, *ant;
  p = lista;

  while (p != NULL && p->info.dni != dni)
  {
    ant = p;
    p = p->sig;
  }

  if (p != NULL)
  {
    if (p == lista)
      lista = p->sig;
    else
      ant->sig = p->sig;
    delete p;
    return true;
  }
  else
    return false;
}

void puntoC(Nodo *lista) // Función listar
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.dni << "  " << p->info.nombre << endl;
    p = p->sig;
  }
}

void puntoD(Nodo *lista) // Funcion listar usando una pila para mostrar la lista en orden inverso
{
  Nodo *pilaAlumnos = NULL;

  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    apilar(pilaAlumnos, p->info);
    p = p->sig;
  }

  while (pilaAlumnos != NULL)
  {
    desapilar(pilaAlumnos, pilaAlumnos->info);
    cout << pilaAlumnos->info.dni << "  " << pilaAlumnos->info.nombre << endl;
  }
}

void apilar(Nodo *&pila, Persona pers)
{
  Nodo *p = new Nodo;
  p->info = pers;
  p->sig = pila;
  pila = p;
}

void desapilar(Nodo *&pila, Persona &pers)
{
  if (pila == NULL)
    cout << "ERROR, la pila esta vacia" << endl;
  else
  {
    Nodo *p;
    p = pila;
    pers = p->info;
    pila = p->sig;
    delete p;
  }
}