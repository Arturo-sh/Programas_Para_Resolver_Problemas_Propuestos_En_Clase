#include <iostream>
#include<windows.h>
struct posicion{
    int f;
    int c;
    float Valor;
};
using namespace std;

const int fila=100,columna=100;
float tabla[columna][fila];
int variables,restricciones;
posicion pos[columna][fila];
posicion aux;

void llenado_tabla();
void ingreso();
void mostrar();
void buscar_pivote();
void fila_negativa();
void dividir_fila();
void operaciones_Renglon();
bool comprobar_negativo();

void ingreso(){
    cout<<"Metodo Simplex por Maximizacion"<<endl;
    cout<<"Digite el numero de variables que tendra la funcion objetivo: ";
    cin>>variables;
    cout<<"Digite el numero de restricciones que habra: ";
    cin>>restricciones;
}

void llenado_tabla(){
    for(int col=0;col<restricciones+1;col++){
        if(col==0){
            cout<<"Ingrese las variables de la funcion objetivo: "<<endl;
            for(int fil=0;fil<variables+restricciones+1;fil++){
                if(fil<variables+restricciones){
                    if(fil<variables){
                        cout<<"X"<<fil+1<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                    }
                    else{
                        cout<<"Variable de holgura S"<<fil-1<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                    }
                }
                else{
                        cout<<"R"<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                }
            }
        }
        else{
            cout<<"Ingrese restricion: "<<col<<endl;
            for(int fil=0;fil<variables+restricciones+1;fil++){
                if(fil<variables+restricciones){
                    if(fil<variables){
                        cout<<"X"<<fil+1<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                    }
                    else{
                        cout<<"Variable de holgura S"<<fil-1<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                    }
                }
                else{
                        cout<<"R"<<": ";
                        cin>>tabla[col][fil];
                        pos[col][fil].c=col;
                        pos[col][fil].f=fil;
                        pos[col][fil].Valor=tabla[col][fil];
                }
            }
        }
    }
}

void mostrar(){
    for(int col=0;col<restricciones+1;col++){
        for(int fil=0;fil<variables+restricciones+1;fil++){
            cout<<"|"<<tabla[col][fil]<<"|";
        }
        cout<<endl;
    }
}

void fila_negativa(){
    for(int r=0;r<variables;r++){
        tabla[0][r]=tabla[0][r]*(-1);
    }
}

void buscar_pivote(){
    aux.Valor=tabla[0][0];
    aux.c=0;
    aux.f=0;
    for(int i=0;i<variables;i++){
        if(aux.Valor<tabla[0][i]){
        }
        else{
            aux.Valor=tabla[0][i];
            aux.c=0;
            aux.f=i;
        }
    }
    
    posicion div[100];
    for(int col=1;col<restricciones+1;col++){
        for(int fil=aux.f;fil<aux.f+1;fil++){
            if(tabla[col][fil]!=0){
                div[col].Valor=tabla[col][restricciones+variables]/tabla[col][fil];
                div[col].c=col;
                div[col].f=fil;
                cout<<"division: "<<div[col].Valor<<endl;
            }
            else{
                div[col].Valor=(-1);
                cout<<"division entre cero"<<endl;
            }
        }
    }
    
    int p;
    float val=0;
    for(int i=1;i<restricciones+1;i++){
        if(div[i].Valor>0){
            if(val==0){
                val=div[i].Valor;
                p=div[i].c;
            }
            else{
                 if(val<div[i].Valor){
                 }
                 else{
                    val=div[i].Valor;
                    p=i;
                 }
            }
        }
    }
    aux.Valor=tabla[p][aux.f];
    aux.c=p;
}
void dividir_fila(){
    for(int fil=0;fil<variables+restricciones+1;fil++){
        tabla[aux.c][fil]=tabla[aux.c][fil]/aux.Valor;
    }
    mostrar();
}

float temp;
void operaciones_Renglon(){
    for(int col=0;col<restricciones+1;col++){
        if(col==aux.c){
        }
        else{
            temp=(-1)*tabla[col][aux.f];
            for(int fil=0;fil<restricciones+variables+1;fil++){
                tabla[col][fil]=tabla[col][fil]+(tabla[aux.c][fil]*temp);
            }
        }
    }
    mostrar();
}

bool comprobar_negativo(){
    int a=0;
    for(int i=0;i<restricciones+variables;i++){
        if(tabla[0][i]<0){
            a++;
        }
        else{
        }
    }
    if(a>0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char resp;
    while(true){
        int l=1;
        ingreso();
        llenado_tabla();
        mostrar();
        fila_negativa();
        cout<<endl;
        system("pause");
        system("cls");
        while(comprobar_negativo()){
            cout<<"\nIteracion: "<<l<<endl;
            buscar_pivote();
            cout<<endl;
            mostrar();
            cout<<"pivote: "<<aux.Valor<<" posicion: "<<aux.c<<","<<aux.f<<endl;
            cout<<endl;
            dividir_fila();
            cout<<endl;
            operaciones_Renglon();
            l++;
        }
        cout<<"\nDesea ingresar otro problema?(s/n): "<<endl;
        cin>>resp;
        if(resp=='s' || resp=='S'){
            system("cls");
		}
		else{
            break;
		}
    }
    return 0;
}
