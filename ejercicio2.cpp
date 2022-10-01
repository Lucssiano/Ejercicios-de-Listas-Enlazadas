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

void puntoA(Nodo *lista, Persona pers);
void puntoB(Nodo *lista, Persona pers);
void puntoC(Nodo *lista);
// void puntoD(Nodo *lista);
// bool eliminar(Nodo *&lista, int unLeg);
// void insertar(Nodo *&lista, Producto prod);

int main()
{
  Persona pj;
  Nodo *listaPersonas = NULL;

  /* PARA ARMAR LA LISTA DE LAS PERSONAS INSCRIPTAS EN UN CURSO */
  // cout << "Ingrese el DNI de la persona inscripta al curso (0 para finalizar): ";
  // cin >> pj.dni;
  // while (pj.dni != 0)
  // {
  //   cout << "Ingrese el nombre de la persona inscripta al curso: ";
  //   cin >> pj.nombre;
  //   cout << "Ingrese el DNI de la persona inscripta al curso (0 para finalizar): ";
  //   cin >> pj.dni;
  // }
  /* ################## */

  cout << "Ingrese el nombre de la persona inscripta al curso: ";
  cin >> pj.nombre;
  cout << "Ingrese el DNI de la persona inscripta al curso: ";
  cin >> pj.dni;
  puntoA(listaPersonas, pj);
  cout << "Ingrese el nombre de la persona que se dara de baja al curso: ";
  cin >> pj.nombre;
  cout << "Ingrese el DNI de la persona que se dara de baja al curso: ";
  cin >> pj.dni;
  puntoB(listaPersonas, pj);
  puntoC(listaPersonas);
  // puntoD();
  return 0;
}

void puntoC(Nodo *lista) // Funcion listar
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.dni << "  " << p->info.nombre << endl;
    p = p->sig;
  }
}

void insertar(Nodo *&lista, Producto prod)
{
  Nodo *q, *p, *ant;
  q = new Nodo;
  q->info = prod;
  p = lista;
  while (p != NULL && p->info.cod < prod.cod)
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

bool eliminar(Nodo *&lista, int unLeg)
{
  Nodo *p, *ant;
  p = lista;
  while (p != NULL && p->info.leg != unLeg)
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
  // cout<<"no existe";
}