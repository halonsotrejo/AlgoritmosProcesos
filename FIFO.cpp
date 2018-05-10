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
   
   r = new NODO; 
  
   
   if (!ar.eof()){
    ar>>r->nom;
    ar>>r->t;
    r->sig = NULL;
    act = r;
   }
   
   while (!ar.eof()){   
     NODO *Q = new NODO;
     ar>>Q->nom;
     ar>>Q->t;
     Q->sig = NULL;
     act->sig= Q;
     act = act->sig;
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

void FIFO(){
  inicializar();
  ver();
  system("pause");
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
 FIFO();
 system("pause");
 
 
 return 0;    
}
