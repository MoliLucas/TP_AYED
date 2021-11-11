#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define F 14
#define C 4
#include <iostream>
using namespace std;

enum Vehiculo {
	moto,
	AUTO,
	camioneta,
	camion
};


struct PEDIDO{
	float volumen;
	int importe;
	string domicilio;
	int zona;
	int CodigoComercio;
	Vehiculo vehiculo;
};



struct REPARTIDOR{
	int doc;
	int vehi;
	int lugar;
	
} repartidor, *puntero_repartidor = &repartidor ;

struct Nodo{
	PEDIDO dato;
	Nodo *siguiente;
};

void zona(int);
void calle();

void mostrarDatos(REPARTIDOR *);



void manejo(REPARTIDOR repart, int lugar,int Matriz[F][C], int &p);

void ArmarVehiculo(char x[18],REPARTIDOR repart, int lugar, int &p);

void Punto2(int Matriz[F][C]);

void Punto3(int Matriz[F][C]);

int cargarVector(REPARTIDOR rep,int v[],FILE *f,int &p);

void ordenar(int v[], unsigned t);

void recibirPedido();

//Prototipos de Función

void insertarCola(Nodo *&,Nodo *&,PEDIDO);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&, PEDIDO&);
PEDIDO damePedidoPendiente();
void mostrarPedidos();
void mostrarPedido(PEDIDO);

//
//void  mostrarDatos(Repartidor *puntero_repartidor){
//	cout<<"repartidor "<<puntero_repartidor -> doc <<endl;
//	cout<<"repartidor "<<puntero_repartidor -> vehi <<endl;
//	cout<<"repartidor "<<puntero_repartidor -> lugar <<endl;
//	
//	
//}
// 

//ESTRUCTURAS DINAMICAS

Nodo *pedPendfrente = NULL;
Nodo *pedPendfin = NULL;
	
                      

int main ()
{
	
	int a, b;
	int lugar;
	string domicilio;
	int Num_Dom;
	float vol;
	int cod_com;
	int imp;
	int doc;
	int vehi;
	int moto, autom, camioneta, camion;
	char x[18];
	int p;
	
	REPARTIDOR repart;
	
	
  int Matriz[F][C];
	
	for(int i=0;i<F;i++){
        for(int j=0;j<C;j++){
            Matriz[i][j]=0;
        }
	}
	
	PEDIDO lugar1;
	
	
	Nodo*listaPedidos;
	//listar(listaPedidos);
	


	do{
		cout<<" ------------------------------------ \n";
		cout<<" 1- Recibir Pedido \n";
		cout<<" 2- Entregar Pedido \n";
	    cout<<" 3- Mostrar \n";
	    cout<<" 4- Salir \n";
	    cout<<" ------------------------------------ \n";
	    cin>> a;
	    
	    switch (a)
	    {
	    	case 1:
	    		recibirPedido();
	    	
	    		
//	    		lugar1.zona= lugar;
//	    		lugar1.calle= domicilio;
//	    		lugar1.NumCalle= Num_Dom;
//	    		lugar1.volumen= vol;
//	    		lugar1.importe= imp;
//	    		lugar1.CodigoComercio= cod_com;
	            
	            
	            
	        	break;
		     	   
	    	case 2:
	    		
	    		manejo (repart, lugar, Matriz, p);   		
	    			    		
	    		
	    		ArmarVehiculo ( x,repart, lugar, p);
	    		 

	    		break;
	     	
	    	case 3:
	    		//mostrarPedidos();
	    			    		
	    		break;
	     	
	    	case 4:
	    		cout<< " Seguro que quiere salir ... ? \n ";
	    		cout<< "\n 1- SI \n";
	    		cout<< "\n 2- NO \n";
	    		cin>> b;
	    		cout<< "\n \n";
	    		if (b == 1)
	    	    {
	    			exit(3);
				}
				else  
				{
				    return main ();
			 	}
			 	break;
			 	
			default:
				return main();
				break;
				
			
		} 	  	
	}
	
//void mostrarDatos
	

	
while (a != 3);
system("pause");
return main();
}



void recibirPedido(){
	
	int zona;
	char domicilio[60];
	float vol;
	int imp;
	int cod_com;
	Vehiculo vehiculo;
	
	
		cout<<" ------------------------------------ \n";
	    		cout<<" Ingrese numero de zona (1-14) o 0 para cancelar: \n";
	    		cin>> zona;
	    		
	    		if (zona >= 1 && zona <= 14){
				
	    		cout<<" Ingrese el domicilio: \n";
	    		cin.ignore();
	    		cin.getline(domicilio,60);	    		
	    		
	    		cout<<" Ingrese volumen del paquete: \n";
	    		cin>> vol;
	    		if (vol < 0.005){
	    			cout<<" Sera necesaria una Moto para la entrega. \n \n";
	    			vehiculo = moto;
	    		}
	    			else{
	    				if (vol >= 0.005 && vol < 0.02){
	    					cout<<" Sera necesario un Auto para la entrega. \n \n";
	    					vehiculo = AUTO;
	    				}
	    					else{
	    						if (vol >= 0.02 && vol < 8){
	    							cout<<" Sera necesaria una Camioneta para la entrega. \n \n";
	    							vehiculo = camioneta;
	    						}
	    							else{
	    								if (vol > 8){
	    									cout<<" Sera necesario un Camion para la entrega. \n \n";
	    									vehiculo = camion;
										}
										
									}
								
							} 
						
					}
	    		
	    		cout<<" Ingrese importe del paquete: \n";
	    		cin>> imp;
	    		
	    		cout<< " Ingrese codigo de comercio: \n";
	    		cin>> cod_com;
	    		
	    		PEDIDO unPedido;
	    		
	    		unPedido.CodigoComercio = cod_com;
	    		unPedido.domicilio = domicilio;
	    		unPedido.importe = imp;
	    		unPedido.volumen = vol;
	    		unPedido.zona = zona;
	    		unPedido.vehiculo = vehiculo;
	    		
	    		insertarCola(pedPendfrente, pedPendfin, unPedido);
	    		
			}else if (zona == 0){
	            		main ();
	            		exit;
	                }
            else if (zona >= 15){
        	    cout<<" ------------------------------------ \n";
        	    cout<<" ERROR --- ZONA NO DISPONIBLE \n";
        	    main ();
				exit;	                	    
                }			
	

}

void manejo (REPARTIDOR repart, int lugar, int Matriz[F][C], int &p){
    int vehi;
    char x[18];

    cout<<" Ingrese que tipo de vehiculo tiene: \n";
    cout<<" 1- Moto \n";
    cout<<" 2- Automovil \n";
    cout<<" 3- Camioneta \n";
    cout<<" 4- Camion \n";

    Matriz [lugar-1][vehi-1]+=1;
 
    if(vehi==1){
        strcpy(x,"RepMoto.dat");
	}
    else if(vehi==2){
        strcpy(x,"RepAuto.dat");
    }
    else if(vehi==3){
        strcpy(x,"RepCamion.dat");
    } 
    else if(vehi==4){
        strcpy(x,"RepCamioneta.dat");
    }
 
    ArmarVehiculo(x,repart,lugar,p);
}

                
void ArmarVehiculo(char x[18],REPARTIDOR repart, int lugar, int &p){

    cout<<"Ingrese su numero de documento: \n"<<endl;
    cin>>repart.doc;
    cout<<"Ingrese su zona (1-14): \n"<<endl;
	cin>>lugar;       
}   


void listar (Nodo*lista)
{
	Nodo*r;
	r=lista;
	while(r!=NULL)
	{
		//cout<< r->info.zona<<r->info.calle<<r->info.NumCalle<<r->info.volumen<<r->info.importe<<r->info.CodigoComercio<<endl;
		r=r->siguiente;
	}
}


//Función para insertar elementos en la cola
void insertarCola(Nodo *&frente,Nodo *&fin,PEDIDO n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

//Función para determinar si la cola está vacia
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false; 
}

//Función para eliminar elementos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin, PEDIDO &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}


PEDIDO damePedidoPendiente(){
	
	PEDIDO unPedido;
	
	suprimirCola(pedPendfrente,pedPendfin,unPedido);
	
	return unPedido;
	
	
}

void mostrarPedidos(){
	
	if(cola_vacia(pedPendfrente)){
		cout<<"NO HAY PEDIDOS PENDIENTES \n";
	}
	else
	{	
		while(!cola_vacia(pedPendfrente)){
			PEDIDO pedido = damePedidoPendiente();	
			mostrarPedido(pedido);	
		}
		
	}
	
	
	
}

void mostrarPedido(PEDIDO unPedido){
	
		cout<<"PEDIDO: "<<unPedido.CodigoComercio << " " << unPedido.domicilio<<endl ;
	
}








//void zona (int algo){
	


//void domicilio (char[25] nose){
	


/*PAQUETE unPaquete;

unPaquete.importe = 12;
unPaquete.volumen = 12.2;


cout<<unPaquete.importe; */






