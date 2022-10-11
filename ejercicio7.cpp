/* 7) Dada una lista doblemente encadenada de números enganchada solo por el puntero al siguiente
y con todos los punteros al anterior en NULL, se pide hacer una rutina que la recorra y
complete los punteros convenientemente incluyendo el puntero externo para recorrerla de atrás
hacia adelante. */

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
void insertar(Nodo *&lis1, int nro);
void completarAnterior(Nodo *&lis1, Nodo *&lis2);

int main()
{
  Nodo *listaD1 = NULL, *listaD2 = NULL;
  int nro;
  cin >> nro;
  while (nro != 0)
  {
    insertar(listaD1, nro);
    cin >> nro;
  }
  completarAnterior(listaD1, listaD2);
  mostrarAsc(listaD1);
  mostrarDesc(listaD2);
  return 0;
}

void completarAnterior(Nodo *&lis1, Nodo *&lis2)
{
  Nodo *p, *q;
  p = lis1;
  q = lis1->sig;
  while (q != NULL)
  {
    q->ant = p;
    p = p->sig;
    q = q->sig;
  }
  lis2 = p;
}

void insertar(Nodo *&lista, int nro)
{
  Nodo *q, *p, *ant;
  q = new Nodo;
  q->dato = nro;
  p = lista;
  while (p != NULL && p->dato < nro)
  {
    ant = p;
    p = p->sig;
  }
  q->sig = p;
  q->ant = NULL;
  if (p != lista)
    ant->sig = q;
  else
    lista = q;
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

// Mi funcion insertar
// void insertar(Nodo *&lis1, int nro)
// {
//   Nodo *n = new Nodo;
//   n->dato = nro;
//   n->ant = NULL;
//   if (lis1 == NULL)
//   {
//     n->sig = NULL;
//     lis1 = n;
//   }
//   else
//   {
//     Nodo *p = lis1;
//     while (p != NULL && p->dato < nro)
//       p = p->sig;
//     if (p == lis1)
//     {
//       n->sig = p;
//       lis1 = n;
//     }
//     else
//     {
//       if (p == NULL)
//       {
//         n->sig = NULL;
//         lis1->sig->sig = n;
//       }
//       else
//       {
//         n->sig = p;
//         lis1->sig->sig = n;
//       }
//     }
//   }
// }