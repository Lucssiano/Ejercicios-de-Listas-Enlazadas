/* 8) Dada una lista doblemente encadenada de números eliminar los últimos n nodos. */

#include <iostream>
#include <string.h>

using namespace std;

struct Nodo
{
  int dato;
  Nodo *sig;
  Nodo *ant;
};

void mostrarAsc(Nodo *l);
void mostrarDesc(Nodo *l);
void insertar(Nodo *&lis1, Nodo *&lis2, int nro);
void eliminarNodos(Nodo *&lis2, int cantNodos);

int main()
{
  Nodo *listaD1 = NULL, *listaD2 = NULL;

  int nro;
  cin >> nro;
  while (nro != 0)
  {
    insertar(listaD1, listaD2, nro);
    cin >> nro;
  }

  int cantNodosAEliminar;
  cout << "Ingrese la cantidad de nodos a eliminar: ";
  cin >> cantNodosAEliminar;

  eliminarNodos(listaD2, cantNodosAEliminar);

  cout << "salio ";

  mostrarAsc(listaD1);
  mostrarDesc(listaD2);

  return 0;
}

void eliminarNodos(Nodo *&lis2, int cantNodos)
{
  Nodo *p;

  for (int i = 0; i < cantNodos; i++) // si cantNodos es mayor o igual a la cantidad de nodos de la lista, se rompe
  {
    p = lis2;
    lis2 = p->ant;
    lis2->sig = NULL;
    delete p;
  }
}

void insertar(Nodo *&lis1, Nodo *&lis2, int nro)
{
  Nodo *n = new Nodo;
  n->dato = nro;
  if (lis1 == NULL && lis2 == NULL)
  {
    n->sig = NULL;
    n->ant = NULL;
    lis1 = n;
    lis2 = n;
  }
  else
  {
    Nodo *p = lis1;
    while (p != NULL && p->dato < nro)
      p = p->sig;
    if (p == lis1)
    {
      n->sig = p;
      n->ant = NULL;
      lis1->ant = n;
      lis1 = n;
    }
    else
    {
      if (p == NULL)
      {
        n->sig = NULL;
        n->ant = lis2;
        lis2->sig = n;
        lis2 = n;
      }
      else
      {
        n->sig = p;
        n->ant = p->ant;
        p->ant->sig = n;
        p->ant = n;
      }
    }
  }
}

void mostrarAsc(Nodo *l)
{
  Nodo *p = l;
  cout << "ASCENDENTE" << endl;
  while (p != NULL)
  {
    cout << p->dato << endl;
    p = p->sig;
  }
}

void mostrarDesc(Nodo *l)
{
  Nodo *p = l;
  cout << "DESCENDENTE" << endl;
  while (p != NULL)
  {
    cout << p->dato << endl;
    p = p->ant;
  }
}

// void eliminarNodos(Nodo *&lis2, int cantNodos)
// {
//   Nodo *p, *q;
//   int i = 0;
//   while (i < cantNodos)
//   {
//     p = lis2;
//     delete p;
//     lis2 = lis2->ant;
//     i++;
//   }
// }