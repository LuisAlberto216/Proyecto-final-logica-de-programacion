#include <iostream>
using namespace std;

int const filas=4;
int const columnas=5;
void LimpiezaMatrices(bool disponibilidad[filas][columnas],int peso[filas][columnas],int precios[filas][columnas]);
void ImprimirDisponibilidad(bool disponibilidad[filas][columnas]);
void cantidadContenedores(bool disponibilidad[filas][columnas]);
void contenedoresporPuerto(string nombresPuertos[],int contenedoresPuerto[],int numeroPuertos);
void listaZonaEconomica(int precios[filas][columnas],string marca[filas][columnas]);
void listaZonaPremium(int precios[filas][columnas], string marca[filas][columnas]);
int nombreEmpresa(string marca[filas][columnas],int precios[filas][columnas]);
float promedioPeso(bool disponibilidad[filas][columnas],int peso[filas][columnas]);
int filaMayorCarga(int peso[filas][columnas]);
int cantidadArticulo(string tipoArticulo[filas][columnas]);
float promedioPesoPuerto(int peso[filas][columnas],string puertoCarga[filas][columnas]);
int MarcaMayorPeso(int peso[filas][columnas],string marca[filas][columnas]);
int MarcaMenorPeso(int peso[filas][columnas],string marca[filas][columnas]);
void imprimirMatrizEnteros(int matriz[filas][columnas]);
int columnaMenorCarga(int peso[filas][columnas]);
int main(){
    int porcentaje=0;
    int numeroPuertos=0;
    cout<<"Bienvenido al sistema de enbarca ML"<<endl;
    cout<<"____________________________________"<<endl;
    cout<<"Para realizar el embarque con exito, necesitamos los siguientes datos"<<endl;
    cout<<"Cantidad de puertos a ingresar "<<endl;
    cin>>numeroPuertos;
    string nombresPuertos[numeroPuertos];
    for(int i=0;i<numeroPuertos;i++){
        cout<<"Ingrese el nombre del puerto "<<i+1<<endl;
        cin>>nombresPuertos[i];
    }
    cout<<"Los puertos ingresados son:"<<endl;
    for(int i=0;i<numeroPuertos;i++){
        cout<<nombresPuertos[i]<<endl;
    }

    bool disponibilidad[filas][columnas];
    string marca[filas][columnas];
    string puertoCarga[filas][columnas];
    int peso[filas][columnas];
    string tipoArticulo[filas][columnas];
    int precios[filas][columnas];
    int recaudoPuerto[numeroPuertos];
    int contenedoresPuerto[numeroPuertos];

    LimpiezaMatrices(disponibilidad,peso,precios);


    for (int k=0;k<numeroPuertos;k++){
        int numeroContenedores=0;
        cout<<"Ingrese el numero de contenedores para el puerto "<<nombresPuertos[k]<<endl;
        cin>>numeroContenedores;
        contenedoresPuerto[k]=numeroContenedores;
        for(int i=0;i<numeroContenedores;i++){
            bool bandera=0;
            while(bandera==0){
                int fila=0;
                int columna=0;
                cout<<"La disponibilidad del barco se encuentra marcada con 1"<<endl;
                ImprimirDisponibilidad(disponibilidad);
                cout<<"Ingrese la coordenada de la fila "<<endl;
                cin>>fila;
                cout<<"Ingrese la coordenada de la columna "<<endl;
                cin>>columna;
                if(disponibilidad[fila][columna]==1 && fila<4 && fila>=0 && columna<5 && columna>=0){
                    cout<<"Ingrese la marca del contenedor "<<endl;
                    cin>>marca[fila][columna];
                    cout<<"Ingrese el peso del contenedor "<<endl;
                    cin>>peso[fila][columna];
                    puertoCarga[fila][columna]=nombresPuertos[k];
                    cout<<"Ingrese el tipo de articulo"<<endl;
                    cout<<"ingrese (A) si es tipo alimentos"<<endl;
                    cout<<"Ingrese (B) si es tipo dispositivos electronicos"<<endl;
                    cout<<"Ingrese (C) si es tipo ropa y demas textiles"<<endl;
                    cin>>tipoArticulo[fila][columna];
                    disponibilidad[fila][columna]=0;
                    bandera=1;
                }else{
                    cout<<"La coordenada ingresada no es valida o esta ocupada, intente nuevamente"<<endl;
                }
            }
        }
        int contador=0;
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(disponibilidad[i][j]==0){
                    contador=contador+1;
                }
            }
        }
        porcentaje=(contador*100)/20;
        cout<<"EL porcentaje de ocupación actual del barco es del "<<porcentaje<<"%"<<endl;

        int acumulador=0;
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(puertoCarga[i][j]==nombresPuertos[k]){
                    acumulador=acumulador+precios[i][j];
                }
            }
        }
        recaudoPuerto[k]=acumulador;
        cout<<"El valor recaudado del puerto actual es de "<<recaudoPuerto[k]<<"USD"<<endl;
    }
    cout<<"Las matrices son"<<endl;
    ImprimirDisponibilidad(disponibilidad);
    cout<<"La matriz de pesos es "<<endl;
    imprimirMatrizEnteros(peso);
    cantidadContenedores(disponibilidad);
    contenedoresporPuerto(nombresPuertos,contenedoresPuerto,numeroPuertos);
    listaZonaEconomica(precios,marca);
    listaZonaPremium(precios,marca);
    nombreEmpresa(marca,precios);
    promedioPeso(disponibilidad,peso);
    filaMayorCarga(peso);
    columnaMenorCarga(peso);
    cantidadArticulo(tipoArticulo);
    promedioPesoPuerto(peso,puertoCarga);
    MarcaMayorPeso(peso,marca);
    MarcaMenorPeso(peso,marca);

    return 0;
}

void imprimirMatrizEnteros(int matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void LimpiezaMatrices(bool disponibilidad[filas][columnas],int peso[filas][columnas],int precios[filas][columnas]){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            disponibilidad[i][j]=1;
            peso[i][j]=0;
            if(i==0 && j<5 || i==3 && j<5 || j==0 && i<4 || j==4 && i<4){
                precios[i][j]=100;
            }else{
                precios[i][j]=300;
            }
        }
    }
}
void ImprimirDisponibilidad(bool disponibilidad[filas][columnas]){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<disponibilidad[i][j]<<" ";
        }
        cout<<endl;
    }
}
void cantidadContenedores(bool disponibilidad[filas][columnas]){
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(disponibilidad[i][j]==0){
                contador=contador+1;
            }
        }
    }
    cout<<"El numero total de contenedores ingresados es "<<contador<<endl;
}
void contenedoresporPuerto(string nombresPuertos[],int contenedoresPuerto[],int numeroPuertos){
    for(int i=0;i<numeroPuertos;i++){
        for(int j=0;j<numeroPuertos;j++){
            if(contenedoresPuerto[j]<contenedoresPuerto[i]){
                int aux=contenedoresPuerto[i];
                contenedoresPuerto[i]=contenedoresPuerto[j];
                contenedoresPuerto[j]=aux;
                string auxnom=nombresPuertos[i];
                nombresPuertos[i]=nombresPuertos[j];
                nombresPuertos[j]=auxnom;
            }
        }
    }
    for(int i=0;i<numeroPuertos;i++){
        cout<<nombresPuertos[i]<<"-->"<<contenedoresPuerto[i]<<endl;
    }
}
void listaZonaEconomica(int precios[filas][columnas],string marca[filas][columnas]){
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(precios[i][j]==100 && marca[i][j]!=""){
                contador=contador+1;
            }
        }
    }
    string zonaEconomica[contador];
    for(int x=0;x<contador;x++){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(precios[i][j]==100 && marca[i][j]!=""){
                zonaEconomica[x]=marca[i][j];
                }
            }
        }
    }
    cout<<"En las celdas economicas se encuentran la/las siguiente(s) empresa(s) "<<endl;
    for(int i=0;i<contador;i++){
        cout<<zonaEconomica[i]<<endl;
    }
}
void listaZonaPremium(int precios[filas][columnas], string marca[filas][columnas]){
    int contador=0;
        for(int i=0;i<filas;i++){
        	for(int j=0;j<columnas;j++){
            if(precios[i][j]==300 && marca[i][j]!=""){
                contador=contador+1;
            }
        }
    }
    string zonaPremium[contador];
    for(int x=0;x<contador;x++){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(precios[i][j]==300 && marca[i][j]!=""){
                zonaPremium[x]=marca[i][j];
                }
            }
        }
    }
    cout<<"En las celdas premium se encuentran la/las siguiente(s) empresa(s) "<<endl;
    for(int i=0;i<contador;i++){
        cout<<zonaPremium[i]<<endl;
    }
}
int nombreEmpresa(string marca[filas][columnas],int precios[filas][columnas]){
    int acumulador=0;
    int contadorEconomica=0;
    int contadorPremium=0;
    string marcaEmpresa="";
    cout<<"Ingrese el nombre de la empresa "<<endl;
    cin>>marcaEmpresa;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(marcaEmpresa==marca[i][j]){
                if(precios[i][j]==100){
                    acumulador=acumulador+precios[i][j];
                    contadorEconomica=contadorEconomica+1;
                }else if(precios[i][j]==300){
                    acumulador=acumulador+precios[i][j];
                    contadorPremium=contadorPremium+1;
                }
            }
        }
    }
    cout<<"La empresa "<<marcaEmpresa<<" cuenta con "<<contadorEconomica<<" contenedor(es) en la zona economica y "<<contadorPremium<<" contenedor(es) en la zona premium"<<endl;
    return acumulador,contadorPremium,contadorEconomica;
}
float promedioPeso(bool disponibilidad[filas][columnas],int peso[filas][columnas]){
    float promedio=0;
    int acumulador=0;
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(disponibilidad[i][j]==0){
                contador=contador+1;
                acumulador=acumulador+peso[i][j];
            }
        }
    }
    promedio=acumulador/contador;
    cout<<"El promedio del peso de los contenedores es "<<promedio<<endl;
    return promedio;
}
int filaMayorCarga(int peso[filas][columnas]){
    int mayor=0;
    int fila=0;
    int acumulador1=0;
    int acumulador2=0;
    int acumulador3=0;
    int acumulador4=0;
    for(int i=0;i<filas;i++){
        int acumulador=0;
        for(int j=0;j<columnas;j++){
            if(i==0){
                acumulador1=acumulador1+peso[i][j];
            }else if(i==1){
                acumulador2=acumulador2+peso[i][j];
            }else if(i==2){
                acumulador3=acumulador3+peso[i][j];
            }else if(i==3){
                acumulador4=acumulador4+peso[i][j];
            }
        }
    }
    int pesoFila[4];
    for(int i=0;i<4;i++){
        if(i==0){
            pesoFila[i]=acumulador1;
        }else if(i==1){
            pesoFila[i]=acumulador2;
        }else if(i==2){
            pesoFila[i]=acumulador3;
        }else if(i==3){
            pesoFila[i]=acumulador4;
        }
    }
    for(int i=0;i<4;i++){
        if(pesoFila[i]>mayor){
            mayor=pesoFila[i];
            fila=i;
        }
    }
    cout<<"La fila numero "<<fila<<" tiene el mayor peso con "<<mayor<<" toneladas"<<endl;
    return mayor,fila;
}
int columnaMenorCarga(int peso[filas][columnas]){
    int menor=0;
    int columna=0;
    int acumulador1=0;
    int acumulador2=0;
    int acumulador3=0;
    int acumulador4=0;
    int acumulador5=0;
    for(int i=0;i<filas;i++){
        int acumulador=0;
        for(int j=0;j<columnas;j++){
            if(j==0){
                acumulador1=acumulador1+peso[i][j];
            }else if(j==1){
                acumulador2=acumulador2+peso[i][j];
            }else if(j==2){
                acumulador3=acumulador3+peso[i][j];
            }else if(j==3){
                acumulador4=acumulador4+peso[i][j];
            }else if(j==4){
                acumulador5=acumulador5+peso[i][j];
            }
        }
    }
    int pesoColumna[5];
    for(int i=0;i<5;i++){
        if(i==0){
            pesoColumna[i]=acumulador1;
        }else if(i==1){
            pesoColumna[i]=acumulador2;
        }else if(i==2){
            pesoColumna[i]=acumulador3;
        }else if(i==3){
            pesoColumna[i]=acumulador4;
        }else if(i==4){
            pesoColumna[i]=acumulador5;
        }
    }
    for(int i=0;i<5;i++){
        if(pesoColumna[i]<menor){
            menor=pesoColumna[i];
            columna=i;
        }
    }
    cout<<"La columna numero "<<columna<<" tiene el menor peso con "<<menor<<" toneladas"<<endl;
    return menor,columna;
}
int cantidadArticulo(string tipoArticulo[filas][columnas]){
    int contador=0;
    string articulo="";
    cout<<"Ingrese el tipo de articulo"<<endl;
    cout<<"ingrese (A) si es tipo alimentos"<<endl;
    cout<<"Ingrese (B) si es tipo dispositivos electronicos"<<endl;
    cout<<"Ingrese (C) si es tipo ropa y demas textiles"<<endl;
    cin>>articulo;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(articulo==tipoArticulo[i][j]){
                contador=contador+1;
            }
        }
    }
    cout<<"Se encontraron "<<contador<<" contenedores del articulo "<<articulo<<endl;
    return contador;
}
float promedioPesoPuerto(int peso[filas][columnas],string puertoCarga[filas][columnas]){
    float promedio=0;
    int contador=0;
    int acumulador=0;
    string nombrePuerto="";
    cout<<"Ingrese el nombre del puerto a buscar "<<endl;
    cin>>nombrePuerto;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(nombrePuerto==puertoCarga[i][j]){
                contador=contador+1;
                acumulador=acumulador+peso[i][j];
            }
        }
    }
    promedio=acumulador/contador;
    cout<<"El promedio de peso para el puerto "<<nombrePuerto<<" es de "<<promedio<<" kilos"<<endl;
    return promedio;
}
int MarcaMayorPeso(int peso[filas][columnas],string marca[filas][columnas]){
    int mayor=INT_MIN;
    string Empresa="";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(peso[i][j]>mayor){
                mayor=peso[i][j];
                Empresa=marca[i][j];
            }
        }
    }
    cout<<"La empresa "<<Empresa<<" registra el contenedor de mayor peso con "<<mayor<<" toneladas"<<endl;
    return mayor;
}
int MarcaMenorPeso(int peso[filas][columnas],string marca[filas][columnas]){
    int menor=INT_MAX;
    string Empresa="";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(peso[i][j]<menor){
                menor=peso[i][j];
                Empresa=marca[i][j];
            }
        }
    }
    cout<<"La empresa "<<Empresa<<" registra el contenedor de menor peso con "<<menor<<" toneladas"<<endl;
    return menor;
} 
