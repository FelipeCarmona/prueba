/* 
 * File:   LstAdy.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 02:32 PM
 */

#include "LstAdy.h"


LstAdy::LstAdy(): cntAdy(0), inicio(nullptr) {
}

LstAdy::LstAdy(const LstAdy& orig) {
    shared_ptr<NdoLstAdy> p = orig.inicio;
    if(p == nullptr)
        inicio = nullptr;
    else{
        inicio = shared_ptr<NdoLstAdy>(new NdoLstAdy(orig.inicio->vrtD));
        p = p->sgt;
        shared_ptr<NdoLstAdy> ultimo = inicio;
        while(p != nullptr){ //mientras no se acabe orig
            ultimo->sgt = shared_ptr<NdoLstAdy>(new NdoLstAdy(p->vrtD));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

LstAdy::~LstAdy() {
}

void LstAdy::agr(int nady) {
    bool rsl = false;
    shared_ptr<NdoLstAdy> p = inicio;
    shared_ptr<NdoLstAdy> ant = nullptr;
    if(inicio == nullptr){//
        inicio = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady));
        rsl = true;
    } else if (inicio->vrtD > nady){ //
        p = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady)); // 
        p->sgt = inicio; // 
        inicio = p; // 
        rsl = true;
    } else{
        p = inicio;
        while (p != nullptr){
            if(p->vrtD == nady) // 
             p = nullptr;
         else{ // 
             if(p->vrtD < nady){
                 ant = p;
                 p = p->sgt;
                 if(p == nullptr)
                     rsl = true;
             }else {// 
                 p = nullptr;
                 rsl = true;//
             }
         }
      }
        if(rsl){ // 
            p = ant->sgt; 
            ant->sgt = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady));
            ant->sgt->sgt = p;
            
        }
     }
   
}

bool LstAdy::bus(int ady) {
    bool rsl = false;
     shared_ptr<NdoLstAdy> p = inicio;
     string comprobacion;
     while (p != nullptr){
         if(p->vrtD == ady){ // ya se encontro ady en *this
             rsl = true;
             p = nullptr;
             comprobacion = "Sí está";
         }else{ // todavia no se encuentra pero puede que eadyista mas adelante
             if(p->vrtD < ady)
                 p = p->sgt;
             else // se concluye que ady no esta en el conjunto
                 p = nullptr;
             comprobacion = "No está";
         }
     }
    // cout << "A: " << comprobacion << endl;
     return rsl;
}

 void LstAdy::elm(int ady){
    bool rsl = false;
   shared_ptr<NdoLstAdy> p = inicio;
   shared_ptr<NdoLstAdy> ant = nullptr;
   if(inicio != nullptr && inicio->vrtD <= ady)
       if( inicio->vrtD == ady){
           p = inicio->sgt;
          //  delete inicio;
           inicio = p;
           rsl = true;
       }else{
           while(p != nullptr){ // hay q buscar a x
               if(p->vrtD == ady){
                   rsl = true;
                   p = nullptr;;
               } else{ // hay q seguir buscando
                   if(p->vrtD < ady){
                       ant = p;
                       p = p->sgt;
                   } else p = nullptr; // no esta y no hay  que eliminar nada
               }
           }
           if(rsl){ // si hay que eliminar en medio o al final
               p = ant->sgt->sgt;
               // delete ant->sgt;
               ant->sgt = p;
           
           }
       }
   //return rsl;
}

int LstAdy::totAdy(){
    int total = 0;
  shared_ptr<NdoLstAdy> p = inicio;
     while(p != nullptr){
       p = p->sgt;
      total++;
  }
  string comp = static_cast<std::ostringstream*>(&(std::ostringstream() << total))->str();;
  cout << "Cantidad de adyacencias: " << comp << endl;
  return total;
}

int* LstAdy::obtAdy(){
   int *adyacentes=new int[10];
    int total = 0;
    shared_ptr<NdoLstAdy> p = inicio;
     while(p != nullptr){
      
       adyacentes[total]= p->vrtD ;
        p = p->sgt;
      total++;
  }
  string comp = static_cast<std::ostringstream*>(&(std::ostringstream() << total))->str();;
  cout << "Cantidad de adyacencias obtenidas: " << comp << endl;
  return adyacentes;
}

string LstAdy::aHil() {
    stringstream fs; 
     shared_ptr<NdoLstAdy> p = inicio;
     fs <<'{';
     while(p != nullptr){
         fs << p->vrtD ;
         p = p->sgt;
         if(p != nullptr)
                 fs << ',';
     };
     fs << '}';
     return fs.str();
}