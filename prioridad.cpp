#include <iostream>
#include <fstream>

using namespace std;

ifstream ar;
void ver();

typedef struct nodo {
 char nom[10];
 int t; 
 int p; 
 nodo *sig;     
}NODO;

NODO *r, *act;
int qu;

void inicializar(){
 ar.open("priori.txt");
 
 if (!ar.eof()){
  r = new NODO;
  ar>>r->nom;
  ar>>r->t;
  ar>>r->p;
  r->sig=NULL;
  act = r;  
 }           
 
 //ver();
 //system("pause");
 
 while(!ar.eof()){
   NODO *q =new NODO;
   ar>>q->nom;
   ar>>q->t;
   ar>>q->p;
   q->sig = NULL;
   
   NODO *ini = r;
   NODO *ant = NULL;
   //cout<<q->nom<<" "<<q->t<<" "<<q->p<<endl;  system("pause");  
   
   while (ini != NULL) { 
     if (ini->p < q->p){ 
      //cout<<"mayor prioridad "<<q->nom <<endl;  system("pause");  
      q->sig = ini;
      
      if (ant != NULL) ant->sig = q; else r=q;
      break;
     }
      ant = ini;
      ini = ini->sig;
   }
 
   if (ini ==  NULL){
    NODO *fin = r;
    while (fin->sig != NULL) fin = fin->sig;
    fin->sig = q;
   }
   
  

 }

}

int techo(){
  NODO *ini = r;
  int suma=0,x=0;
  while (ini != NULL) {
   suma += ini->t;
   x++;
   ini = ini->sig;
  }
      
 return suma/x;
 
}

void ver(){
 NODO *ini;
 ini = r;

 while(ini != NULL){
  cout<<" nombre"<<ini->nom<<" : "<<ini->t<<" P "<<ini->p<<endl; 
  ini=ini->sig;
 }    
}

void prioridad(){
  NODO *ini;
  ini = r;
  NODO *fin = r;
  int t=0, x=0;
  float prom =0;
  
  while (fin->sig != NULL) fin = fin->sig;

  
  while (r!=NULL){      
   if (ini->t <= qu){
    t += ini->t;         
    cout<<"Tr"<<ini->nom<<"="<<t<<endl;
    r = r->sig;
    x++;
    prom += t; 
    
    NODO *act = ini;
    ini = ini->sig;
    
    delete act;
    
   }else{
         
    ini->t -= qu;
    ini->p -= 1;
    t += qu;     
    
    cout<<"pasaron "<<qu <<" segundos"<<endl;
    cout<<"N "<<ini->nom<<"T "<<ini->t<<endl;
    
    NODO *q = ini;
    ini = ini->sig;
    r = r->sig;
    
    NODO *act = r;
    NODO *ant = NULL;
    
    while (act != NULL){
      if (act->p < q->p){
        q->sig = act;
        if (ant != NULL ) {ant->sig = q; }else { r = q; }
        break;
      }
      ant= act;
      act= act->sig;
    }
    
    if (act ==  NULL){
     NODO *fin = r;
     q->sig = NULL;
     while (fin->sig != NULL) fin = fin->sig;
     fin->sig = q;
    }

    
   }
  
   
 }
  
  (x!=0)?cout<<"TR Promedio "<<float(prom/x)<<endl: cout<<"0";
  
}

int main(){
 inicializar();
 ver();
 qu = techo();
 cout<<endl<<"Quantum "<<techo()<<endl<<endl;
 prioridad();
 ver();
 system("pause");
 return 0;    
}
