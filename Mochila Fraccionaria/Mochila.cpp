#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Estructura que almacenará 
//el peso y el valor correspondiente 
//de cada item

typedef struct
{
    int v;
    int w;
    float d;
} Item;

void ingresar(Item items[], int sizeItems)
{
    cout<<"Ingrese los valores y los pesos de "<<sizeItems<<" items en total"<<endl;
    
    for(int i=0; i<sizeItems; i++)
    {
        cout<<"Ingresar "<<i+1<<" valor ";
        cin>>items[i].v;
        cout<<"Ingresar "<<i+1<<" peso ";
        cin>>items[i].w;
    }
}

void mostrar(Item items[], int sizeItems)
{
    cout<<"Valores: "<<endl;
    for(int i=0; i<sizeItems; i++)
    {
        cout<<items[i].v<<"\t";
    }
    
    cout<<endl<<"Pesos: "<<endl;
    for(int j=0; j<sizeItems; j++)
    {
       cout<<items[j].w<<"\t"; 
    }
    cout<<endl;
}

//Funcion de comparacion 
//para evaluar cada 
//item segun su valor, 
//peso y proporcion
bool comparacion(Item i1, Item i2)
{
    return (i1.d > i2.d);
}

//Funcion voraz para resolver
//el problema
double knapsack(Item items[], int sizeItems, int W)
{
    int pos;
    Item max, temp;
    double totalV=0.0, totalW=0.0;
    
    for(int i=0; i<sizeItems; i++)
    {
        items[i].d = items[i].v / items[i].w;
    }
    
    sort(items, items + sizeItems, comparacion);
    
    for(int j=0; j<sizeItems; j++)
    {
        if(totalW + items[j].w<=W)
        {
            totalV = totalV + items[j].v;
            totalW = totalW + items[j].w;
        }
        
        else
        {
            int wt = W - totalW;
            totalV = totalV + (wt * items[j].d);
            totalW = totalW + wt;
            break;
        }
    }
    cout<<"El peso total de la mochila es: "<<totalW<<endl;
    return totalV;
}

int main()
{
    int W;
    Item items[4];
    ingresar(items, 4);
    cout<<"Los datos introducidos son: \n";
    mostrar(items, 4);
    cout<<"Ingrese el peso de la mochila \n";
    cin>>W;
    double maxV = knapsack(items, 4, W);
    cout<<"El maximo valor para el peso de "<<W<<" es "<<maxV; 
}