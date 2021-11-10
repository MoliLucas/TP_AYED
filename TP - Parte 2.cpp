#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define F 14
#define C 4

using namespace std;


struct PEDIDO{
	float volumen;
	int importe;
	string calle;
	int NumCalle;
	int zona;
	int CodigoComercio;
};

struct REPARTIDOR{
	int doc;
	int vehi;
	int lugar;
	
} repartidor, *puntero_repartidor = &repartidor ;

struct Nodo{
	PEDIDO info;
	Nodo*sig;
};

void zona(int);
void calle();

void mostrarDatos(REPARTIDOR *);



void listar (Nodo*lista)
{
	Nodo*r;
	r=lista;
	while(r!=NULL)
	{
		cout<< r->info.zona<<r->info.calle<<r->info.NumCalle<<r->info.volumen<<r->info.importe<<r->info.CodigoComercio<<endl;
		r=r->sig;
	}
}

void manejo(REPARTIDOR repart, int lugar,int Matriz[F][C], int &p);

void ArmarVehiculo(char x[18],REPARTIDOR repart, int lugar, int &p);

void Punto2(int Matriz[F][C]);

void Punto3(int Matriz[F][C]);

int cargarVector(REPARTIDOR rep,int v[],FILE *f,int &p);

void ordenar(int v[], unsigned t);



void manejo (REPARTIDOR repart, int lugar, int Matriz[F][C], int &p){
    int vehi;
    char x[18];

    cout<<" Ingrese que tipo de vehiculo tiene: \n";
    cout<<" 1- Moto \n";
    cout<<" 2- Automovil \n";
    cout<<" 3- Camioneta \n";
    cout<<" 4- Camion \n";
    cin<<vehi;
    
    if(vehi < 5){
    	cout<<"Sos un gil, elegi bien"<<endl;
    	
	}

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

void  mostrarDatos(Repartidor *puntero_repartidor){
	cout<<"repartidor "<<puntero_repartidor -> doc <<endl;
	cout<<"repartidor "<<puntero_repartidor -> vehi <<endl;
	cout<<"repartidor "<<puntero_repartidor -> lugar <<endl;
}
                       

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
	    		cout<<" ------------------------------------ \n";
	    		cout<<" Ingrese numero de zona (1-14) o 0 para cancelar: \n";
	    		cin>> lugar;
	    		
	    		if (lugar >= 1 && lugar <= 14){
				
	    		cout<<" Ingrese calle del domicilio: \n";
	    		cin>> domicilio;
	    		
	    		cout<<" Ingrese numero de domicilio: \n";
	    		cin>> Num_Dom;
	    		
	    		cout<<" Ingrese volumen del paquete: \n";
	    		cin>> vol;
	    		if (vol < 0.005){
	    			cout<<" Sera necesaria una Moto para la entrega. \n \n";
	    		}
	    			else{
	    				if (vol >= 0.005 && vol < 0.02){
	    					cout<<" Sera necesario un Auto para la entrega. \n \n";
	    				}
	    					else{
	    						if (vol >= 0.02 && vol < 8){
	    							cout<<" Sera necesaria una Camioneta para la entrega. \n \n";
	    						}
	    							else{
	    								if (vol > 8){
	    									cout<<" Sera necesario un Camion para la entrega. \n \n";
										}
										
									}
								
							} 
						
					}
	    		
	    		cout<<" Ingrese importe del paquete: \n";
	    		cin>> imp;
	    		
	    		cout<< " Ingrese codigo de comercio: \n";
	    		cin>> cod_com;
	    		
	    		lugar1.zona= lugar;
	    		lugar1.calle= domicilio;
	    		lugar1.NumCalle= Num_Dom;
	    		lugar1.volumen= vol;
	    		lugar1.importe= imp;
	    		lugar1.CodigoComercio= cod_com;
	            }
	            else{
	            	if (lugar == 0){
	            	return main ();
	                }
	                    else{
	                	    if (lugar >= 15){
	                	    cout<<" ------------------------------------ \n";
	                	    cout<<" ERROR --- ZONA NO DISPONIBLE \n";
	                	    return main ();
	                        }
					    }
				}
	            
	        	break;
		     	   
	    	case 2:
	    		
	    		manejo (repart, lugar, Matriz, p);
	    		
	    		break;
	    		
	    		
	    		ArmarVehiculo ( x,repart, lugar, p);
	    		 

	    		break;
	     	
	    	case 3:
	    		
	    		mostrarDatos(puntero_repartidor);
	    		
	    		
	    		
	    		
	    		break;
	     	
	    	case 4:
	    		cout<< " Seguro que quiere salir ... ? \n ";
	    		cout<< "\n 1- SI \n";
	    		cout<< "\n 2- NO \n";
	    		cin>> b;
	    		cout<< "\n \n";
	    		if (b == 1)
	    	    {
	    			return 0;
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
	
void mostrarDatos
	

	
while (a != 3);
system("pause");
return main();
}

//void zona (int algo){
	


//void domicilio (char[25] nose){
	


/*PAQUETE unPaquete;

unPaquete.importe = 12;
unPaquete.volumen = 12.2;


cout<<unPaquete.importe; */





