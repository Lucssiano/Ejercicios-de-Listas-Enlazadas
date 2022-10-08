/* 5) Dadas dos listas definidas como en el ejercicio 1, conteniendo la información de productos
diferentes manufacturados en dos fábricas, se pide hacer una función que devuelva otra lista
ordenada por código de producto conteniendo la totalidad de la información */

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
void apareo(Nodo *lista1, Nodo *lista2);

int main()
{
  Producto prod;
  Nodo *listaProductosF1 = NULL;
  Nodo *listaProductosF2 = NULL;

  /* PARA ARMAR LA LISTA DE LOS PRODUCTOS DE LAS FÁBRICAS (OPCIONAL) */
  cout << "FABRICA 1" << endl;
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
    insertar(listaProductosF1, prod);
    cout << "Ingrese el codigo del producto: ";
    cin >> prod.cod;
  }

  cout << "FABRICA 2" << endl;
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
    insertar(listaProductosF2, prod);
    cout << "Ingrese el codigo del producto: ";
    cin >> prod.cod;
  }
  /* ################## */

  apareo(listaProductosF1, listaProductosF2);

  return 0;
}

void apareo(Nodo *lista1, Nodo *lista2)
{
  Nodo *listaFinal = NULL;

  Nodo *p1, *p2;
  p1 = lista1;
  p2 = lista2;

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->info.cod < p2->info.cod)
    {
      insertar(listaFinal, p1->info);
      p1 = p1->sig;
    }
    else
    {
      if (p1->info.cod == p2->info.cod)
      {
        p1->info.stock += p2->info.stock;
        insertar(listaFinal, p1->info);
        p1 = p1->sig;
        p2 = p2->sig;
      }
      else
      {
        insertar(listaFinal, p2->info);
        p2 = p2->sig;
      }
    }
  }

  while (p1 != NULL)
  {
    insertar(listaFinal, p1->info);
    p1 = p1->sig;
  }
  while (p2 != NULL)
  {
    insertar(listaFinal, p2->info);
    p2 = p2->sig;
  }

  listar(listaFinal);
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

// void insertarLogicamente(Nodo *&lista, Nodo *n)
// {
//   Nodo *r, *ant;
//   r = lista;
//   while (r != NULL && r->info.cod < n->info.cod)
//   {
//     ant = r;
//     r = r->sig;
//   }
//   n->sig = r;
//   if (r != lista)
//     ant->sig = n;
//   else
//     lista = n;
// }

// void ordenarPorCodigo(Nodo *&lista)
// {
//   Nodo *listaOrd = NULL;
//   Nodo *r;
//   while (lista != NULL)
//   {
//     r = lista;
//     lista = lista->sig;
//     insertarLogicamente(listaOrd, r);
//   }
//   lista = listaOrd;
//   listar(lista);
// }