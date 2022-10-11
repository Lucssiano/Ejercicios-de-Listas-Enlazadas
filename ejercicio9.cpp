/* 9) Hacer una función que dada una lista circular devuelva la cantidad de nodos que tiene */

#include <iostream>
#include <string.h>

using namespace std;

struct Nodo
{
  int dato;
  Nodo *sig;
};

void mostrar(Nodo *listaC);
void insertar(Nodo *&listaC, int nro);
int cantNodosLista(Nodo *&listaC);

int main()
{
  Nodo *lis = NULL;

  int num;
  cin >> num;
  while (num != 0)
  {
    insertar(lis, num);
    cin >> num;
  }

  cout << "La lista contiene " << cantNodosLista(lis) << " nodo/s" << endl;
  mostrar(lis);

  return 0;
}

int cantNodosLista(Nodo *&listaC)
{
  int cantNodos = 0;
  if (listaC != NULL)
  {
    Nodo *p = listaC->sig;
    do
    {
      p = p->sig;
      cantNodos++;
    } while (p != listaC->sig);
  }
  return cantNodos;
}

void mostrar(Nodo *listaC)
{
  if (listaC != NULL)
  {
    Nodo *p = listaC->sig;
    do
    {
      cout << p->dato << endl;
      p = p->sig;
    } while (p != listaC->sig);
  }
}

void insertar(Nodo *&listaC, int nro)
{
  Nodo *n = new Nodo;
  n->dato = nro;
  if (listaC == NULL)
  {
    n->sig = n;
    listaC = n;
  }
  else
  {
    Nodo *p = listaC->sig, *ant = listaC;
    if (p->dato < nro)
    {
      do
      {
        ant = p;
        p = p->sig;
      } while (p != listaC->sig && p->dato < nro);
    }
    n->sig = p;
    ant->sig = n;
    if (n->dato > listaC->dato)
      listaC = n;
  }
}