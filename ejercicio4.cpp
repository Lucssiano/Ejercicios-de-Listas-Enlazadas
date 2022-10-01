/* 4) Dada la lista del ejercicio 1, hacer una función que devuelva dos listas una con los productos
cuyo stock sea inferior a 50 unidades y otra con los restantes. */

// Dos opciones:
// ☑️ Generar dos listas nuevas
// ❌ Perder la lista original - Usar los mismos nodos que tenia en la original, dividir esa misma lista en dos listas usando los mismos nodos (Cambiar los enganches)

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
void generarDosListas(Nodo *lista);

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

  generarDosListas(listaProductos);

  return 0;
}

void generarDosListas(Nodo *lista)
{
  Nodo *listaStockMenorA50 = NULL;
  Nodo *listaStockMayorA50 = NULL;

  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    if (p->info.stock < 50)
      insertar(listaStockMenorA50, p->info);
    else
      insertar(listaStockMayorA50, p->info);
    p = p->sig;
  }

  cout << "LISTA STOCK MENOR A 50" << endl;
  listar(listaStockMenorA50);
  cout << "LISTA STOCK MAYOR A 50" << endl;
  listar(listaStockMayorA50);
}

void listar(Nodo *lista)
{
  Nodo *p;
  p = lista;
  while (p != NULL)
  {
    cout << p->info.descrip << " " << p->info.stock << endl;
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
