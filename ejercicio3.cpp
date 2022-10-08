/* 3) Hacer una función que devuelva la lista del ejercicio 2 ordenada alfabéticamente */

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

void insertar(Nodo *&lista, Persona pers);
void ordenarAlfabeticamente(Nodo *&lista);
void insertarLogicamente(Nodo *&lista, Nodo *n);
void listar(Nodo *lista);

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
    insertar(listaPersonas, pj);
    cout << "Ingrese el DNI de la persona a agregar a la lista (0 para finalizar): ";
    cin >> pj.dni;
  }
  /* ################## */

  ordenarAlfabeticamente(listaPersonas);
  listar(listaPersonas);

  return 0;
}

void ordenarAlfabeticamente(Nodo *&lista)
{
  Nodo *listaOrd = NULL;
  Nodo *r;
  while (lista != NULL)
  {
    r = lista;
    lista = lista->sig;
    insertarLogicamente(listaOrd, r);
  }
  lista = listaOrd;
}

void insertarLogicamente(Nodo *&lista, Nodo *n)
{
  Nodo *r, *ant;
  r = lista;
  while (r != NULL && r->info.nombre < n->info.nombre)
  {
    ant = r;
    r = r->sig;
  }
  n->sig = r;
  if (r != lista)
    ant->sig = n;
  else
    lista = n;
}

void listar(Nodo *lista)
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.dni << "  " << p->info.nombre << endl;
    p = p->sig;
  }
}

void insertar(Nodo *&lista, Persona pers)
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
