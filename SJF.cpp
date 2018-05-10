#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream ar;
void inicializar();
void ver();

typedef struct nodo {
 char nom[10];
 int t;  
 nodo *sig;     
}NODO;
NODO *r,*act; 

void inicializar(){
     
   ar.open("procesos.txt");  
   NODO *ant = NULL;
   r = new NODO; 
  
   
   if (!ar.eof()){
    ar>>r->nom;
    ar>>r->t;
    r->sig = NULL;
   }
  
   
   while (!ar.eof()){  
     NODO *aux; 
     NODO *Q = new NODO;
     ar>>Q->nom;
     ar>>Q->t;
     Q->sig = NULL;
    
     act = r;
     
     
     while (act !=NULL){
      if (Q->t < act->t){
        if (ant != NULL )ant->sig = Q;
        Q->sig = act;
        if (act == r ) r = Q;
        break;
      }
      ant= act;
      act = act->sig;
      
     }
     
     if (act == NULL) {
      act=r;
      while (act->sig != NULL) act= act->sig;
      act->sig = Q;     
     }
     
   }  
   ar.close();  
}

void ver(){
  NODO *a = r;
 
  if (a != NULL){
   cout<<"N: "<<a->nom<<" t: "<<a->t<<endl;    
   
   while (a->sig != NULL){
     a = a->sig;
     cout<<"N: "<<a->nom<<" t: "<<a->t<<endl;      
   }    
  }
}

void SJF(){
  inicializar();
  ver();
  cout<<endl;
  NODO *ant;
  int tr =0,x=0;
  float prom=0;
  
  while (r !=NULL){
   x++;
   tr += r->t;
   cout<<"TR"<<r->nom<<" = "<<tr<<endl;
   prom += tr;  
   ant = r;
   r = r->sig;
   delete ant;
  }
  
  (x!=0)?cout<<"TR Promedio "<<float(prom/x)<<endl: cout<<"0";  
     

}


int main(){
 SJF();
 system("pause");
 
 return 0;    
}
