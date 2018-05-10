#include <iostream>
#include <fstream>

using namespace std;

ifstream ar;
void ver();

typedef struct nodo {
 char nom[10];
 int t;  
 nodo *sig;     
}NODO;

NODO *r, *act;
int qu;

void inicializar(){
 ar.open("procesos.txt");
 
 if (!ar.eof()){
  r = new NODO;
  ar>>r->nom;
  ar>>r->t;
  r->sig=NULL;
  act = r;  
 }           
 
 
 while(!ar.eof()){
   NODO *q =new NODO;
   ar>>q->nom;
   ar>>q->t;
   q->sig = NULL;
   act->sig = q;
   act = act->sig;
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

 while (ini != NULL){
  
  cout<<"nombre"<<ini->nom<<" : "<<ini->t<<endl; 
  ini=ini->sig;
 }  
}

void robin(){
  NODO *ini;
  NODO *fin = r;
  int t=0,x=0;
  float prom=0;
  
  ini = r;
  
  while (fin->sig != NULL) fin = fin->sig;
  
  while (r!=NULL){ 
   if (ini->t <= qu){
     t += ini->t;
     
     x++;
    prom += t;         
     cout<<"Tr"<<ini->nom<<"="<<t<<endl;
    r = r->sig;
     
    NODO *act = ini;
    ini = ini->sig;
    delete act;
    
   }else{
    ini->t -= qu;
    t += qu;     
    
    cout<<"Pasaron "<<qu <<" segundos...  ";
    cout<<"N "<<ini->nom<<"T "<<ini->t<<endl;
    
    NODO *act = ini;
    ini = ini->sig;
    act->sig = NULL;
    
    fin->sig = act;
    fin = fin ->sig;
    
   }
 }
 
  (x!=0)?cout<<"TR Promedio "<<float(prom/x)<<endl: cout<<"0";
}


int main(){
 inicializar();
 ver();
 qu = techo();
 cout<<endl<<"Quamtum "<<techo()<<endl<<endl;
 robin();
 system("pause");
 return 0;    
}
