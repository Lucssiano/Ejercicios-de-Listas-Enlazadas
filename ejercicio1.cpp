/* 1)  Se tiene ordenada por código de producto una lista simplemente enlazada donde cada nodo
contiene: código, descripción, importe y stock.
Hacer funciones para:
a. dado un entero K, imprimir el k-ésimo elemento. // cuando dice dado es que viene de afuera, la funcion tiene que recibirlo como parámetro
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
Nodo *buscarMejor(Nodo *lista, int cod);
void puntoA(Nodo *lista, int num);
void puntoB(Nodo *lista, int cod);
void puntoC(Nodo *lista, int cod);

int main()
{
  Producto prod;
  Nodo *listaProductos = NULL;
  cout << "Ingrese el codigo del producto: ";
  cin >> prod.cod;
  while (prod.cod != 0)
  {
    cout << "Ingrese el importe del producto: ";
    cin >> prod.imp;
    cout << "Ingrese el stock del producto: ";
    cin >> prod.stock;
    cout << "Ingrese una descripcion del producto: ";
    fflush(stdin);
    cin.getline(prod.descrip, 36);
    insertar(listaProductos, prod);
    cout << "Ingrese el codigo del producto: ";
    cin >> prod.cod;
  }
  // listar(listaProductos);

  int k;
  cout << "Ingrese un entero: ";
  cin >> k;
  puntoA(listaProductos, k);

  int codigo;
  cout << "Ingrese el codigo del producto a incrementar un 10% su importe: ";
  cin >> codigo;
  puntoB(listaProductos, codigo);

  cout << "Ingrese el codigo del producto a consultar stock: ";
  cin >> codigo;
  puntoC(listaProductos, codigo);

  return 0;
}

void puntoA(Nodo *lista, int num)
{

  Nodo *p = lista;
  int i = 1;
  while (p != NULL && i < num)
  {
    p = p->sig;
    i++;
  }

  cout << p->info.cod << endl;
  cout << p->info.descrip << endl;
  cout << p->info.imp << endl;
  cout << p->info.stock << endl;
}

void puntoB(Nodo *lista, int cod)
{
  Nodo *p = buscarMejor(lista, cod);
  if (p == NULL)
    cout << "No hay un producto con ese codigo" << endl;
  else
    p->info.imp = p->info.imp + (p->info.imp / 10);

  cout << p->info.imp << endl;
}

void puntoC(Nodo *lista, int cod)
{
  Nodo *p = buscarMejor(lista, cod);
  if (p == NULL)
    cout << 0 << ", no se encontró el producto" << endl;
  else
    cout << p->info.stock << endl;
}

Nodo *buscarMejor(Nodo *lista, int cod)
{
  Nodo *p;
  p = lista;
  while (p != NULL && p->info.cod < cod)
    p = p->sig;
  if (p == NULL || p->info.cod != cod)
    return NULL;
  else
    return p;
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
