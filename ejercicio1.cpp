/* 1)  Se tiene ordenada por código de producto una lista simplemente enlazada donde cada nodo
contiene: código, descripción, importe y stock.
Hacer funciones para:
a. dado un entero K, imprimir el k-ésimo elemento.
b. incrementar en un 10% el importe de un producto dado su código.
c. devolver el stock de un producto dado ó cero si no se lo encuentra. */

#include <iostream>
#include <string.h>

using namespace std;

struct Producto
{
  int cod, imp, stock;
  char descrip[36];
};

struct Nodo
{
  Producto info;
  Nodo *sig;
};

void insertar(Nodo *&lista, Producto prod);
void listar(Nodo *lista);

int main()
{
  Producto prod;
  Nodo *lProductos = NULL;
  cout << "Ingrese el codigo del producto: ";
  cin >> prod.cod;
  while (prod.cod != 0)
  {
    cout << "Ingrese el importe del producto: ";
    cin >> prod.imp;
    cout << "Ingrese el stock del producto: ";
    cin >> prod.stock;
    cout << "Ingrese el codigo del producto: ";
    fflush(stdin);
    cin.getline(prod.descrip, 36);
    insertar(lProductos, prod);
    cout << "Ingrese el codigo del producto: ";
    cin >> prod.cod;
  }
  listar(lAlumnos);

  puntoA();
  // puntoB();
  // puntoC();
  return 0;
}

void puntoA()
{
}

void listar(Nodo *lista)
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.cod << p->info.descrip << p->info.imp << p->info.stock << endl;
    p = p->sig;
  }
}

void insertar(Nodo *&lista, Producto prod)
{
  Nodo *q, *p, *ant;
  q = new Nodo;
  q->info = alu;
  p = lista;
  while (p != NULL && p->info.leg < alu.leg)
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

// Nodo *buscarMejor(Nodo *lista, int unLeg)
// {
//   Nodo *p;
//   p = lista;
//   while (p != NULL && p->info.leg < unLeg)
//     p = p->sig;
//   if (p == NULL || p->info.leg != unLeg)
//     return NULL;
//   else
//     return p;
// }
