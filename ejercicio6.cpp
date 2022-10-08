/* 6) Dada la lista definida en el ejercicio 1 conteniendo productos repetidos, hacer una función que
deje en la lista un solo nodo por producto con el stock sumado. */

// Corte de control

// Dos opciones:
// ☑️ Una nueva lista teniendo un solo nodo por producto, manteniendo la lista original
// ❌ Trabajar sobre la lista original, manteniendo el primer nodo y eliminando todos los repetidos

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

void corteDeControl(Nodo *lista);
void insertar(Nodo *&lista, Producto prod);
void listar(Nodo *lista);

int main()
{
  Producto prod;
  Nodo *listaProductos = NULL;

  /* PARA ARMAR LA LISTA DE LOS PRODUCTOS (OPCIONAL) */
  cout << "Ingrese el codigo del producto: ";
  cin >> prod.cod;
  while (prod.cod != 0)
  {
    // cout << "Ingrese el importe del producto: ";
    // cin >> prod.imp;
    prod.imp = 1000;
    cout << "Ingrese el stock del producto: ";
    cin >> prod.stock;
    cout << "Ingrese una descripcion del producto: ";
    fflush(stdin);
    cin.getline(prod.descrip, 36);
    insertar(listaProductos, prod);
    cout << "Ingrese el codigo del producto: ";
    cin >> prod.cod;
  }
  /* ################## */

  corteDeControl(listaProductos);
  return 0;
}

void corteDeControl(Nodo *lista)
{
  Nodo *listaProductosNoRepetidos = NULL;
  Nodo *p, *q;
  p = q = lista;
  while (p != NULL)
  {
    int stockProd = 0;
    do
    {
      stockProd += q->info.stock;
      q = q->sig;
    } while (q != NULL && q->info.cod == p->info.cod);
    p->info.stock = stockProd;
    insertar(listaProductosNoRepetidos, p->info);
    p = q;
  }
  listar(listaProductosNoRepetidos);
}

void listar(Nodo *lista)
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.cod << "  " << p->info.descrip << "  " << p->info.imp << "  " << p->info.stock << endl;
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
