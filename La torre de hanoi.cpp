//Las Torres de Hanoi
// Programa hecho por: JESUS STEVEN MEDRANO CARBALLO
//carnet: MC18055
//segundo parcial de programacion I
//Fecha de entrega 28-nov-2018; hora limite de entrega: 9:00 PM

#include<iostream> //libreria que es utilizado para operaciones de entrada/salida
#include <stdlib.h> //libreria es el archivo de cabecera de la biblioteca estándar 
#include <time.h> //libreria para el formato de hora y fecha de cabecera de la biblioteca

using namespace std;

int tem;
int tem2;
int n;
int desde;
int hacia;
int con;
int tam;
int tamdisco;
int espacios;
int k;
int matriz[100][3];
char cr='±',si,fondo=177;

int main(); //Declaracion de la funcion main del programa
void moverdisco(); //Declaracion de la funcion mover disco del programa
int menu(); //Declaracion de la funcion menu del programa
int salir(); //Declaracion de la funcion salir del programa
int torres(); //Declaracion de la funcion torres del programa
void p();//Declaracion de la funcion pause del programa
void cl();//Declaracion de la funcion limpiar del programa

//realizamos el procedimiento del menu
int menu ()	{// este sera el panel para mostrar y saber que opcion elige el usuario
	int select; //funcion para seleccionar
	
	//mostramos un texto de bienvenida
	cout<<"\n\t\t      BIENVENIDO AL JUEGO DE LAS TORRES DE HANOI"<<endl;
	//mostramos en pantalla lo que pedimos que haga el usuario
	cout<<"\n\t\t      Elige una opcion de las operaciones a realizar"<<endl;
	cout<<"\n\t\t\t         1- Jugar 'TORRES DE HANOI'."<<endl;
	cout<<"\n\t\t\t         2- Ordenar numeros aleatorios."<<endl;
	cout<<"\n\t\t\t         3- Salir."<<endl;
	cin>>select;
	return select;

 }
 
int salir()//Funcion que se ejecuta para salir del programa 
{
 system("cls"); //funcion para limpiar pantalla
 cout<<cr<<cr<<cr<<cr<<cr<<cr<<cr;
 cout<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr;

 cout<<cr<<" GRACIAS POR JUGAR "<<cr<<endl; //texto de agradecimiento
 cout<<cr<<" DESARROLLADOR DEL JUEGO:STEVEN MEDRANO "<<cr<<endl;//mostrar desarrollador del juego
 return 0;
}
int torres() //esta es la funcion de creacion de torres de hanoi
{
    system("color 5e"); //funcion para el color de fuente y fondo
    system("cls"); //funcion para limpiar pantalla
    cout<<"Las Torres de Hanoi\n"<<endl<<endl;
    cout<<"Digite la cantidad de discos: ";
    cin>>n;
    while(n>13||n<3) //creamos un while
    {
        system("cls"); //funcion para limpiar pantalla
        cout<<"Tiene que jugar minimo con tres discos y maximo con 13"<<endl<<"Digite la cantidad de discos:";
        cin>>n;
    }
    tam=n+(n-1);
    for(int i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
              if(j==0)
                  matriz[i][j]=i+1;
              else
                  matriz[i][j]=0;
              for(k=1;k<=tam;k++)
              {
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                       cout<<fondo;    
                   else
                   {
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"*";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(int i=1;i<=((tam*3));i++)
    {
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    cout<<endl;
    for(int i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    moverdisco();
}
void moverdisco()//usamos una funcion de invocacion para mover discos 
{
    while(matriz[0][1]!=1&&matriz[0][2]!=1) //usamos otro while
    {
    cout<<"\n\n\t\t\tLleva "<<con++<<" movimientos\n";
    do{
        cout<<"¿Desde cual torre (T) desea mover el disco?: ";
        cin>>desde;
        if(matriz[n-1][desde-1]==0){cout<<"No hay disco en esa torre"<<endl;}
    }
    while(matriz[n-1][desde-1]==0); //creamos otro while
    cout<<"¿Hacia cual torre (T) desea mover el disco?: ";
    cin>>hacia;
    desde--;
    hacia--;
    for(int i=0;i<n;i++)
    {
        if(matriz[i][desde]!=0)
        {
        tem=matriz[i][desde];
        tem2=i;        
        i=n;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(matriz[i][hacia]==0)
        {
            if(matriz[i+1][hacia]>tem||i==(n-1))
            {
            matriz[i][hacia]=tem;
            matriz[tem2][desde]=0;
            }
            else
            {
            cout<<"\n\nNo puede colocar un disco grande encima de uno pequeno\nni poner un disco en la misma posicion"<<endl
                <<"Cambie los parametros"<<endl;
                con--;
            moverdisco();
            }       
            i=0;
        }
    }
    system("cls");//funcion para limpiar pantalla
    for(int i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
              for(k=1;k<=tam;k++)
              {
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                      cout<<fondo;
                   else
                   {
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"*";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(int i=1;i<=((tam*3));i++)
    {
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    cout<<endl;
    for(int i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    }
    system("color b3"); //cambiamos el color de consola
    cout<<"\n\nFelicitaciones acaba de ganar en "<<con<<" movimientos\n\nDesea volver a jugar S/N: ";
    cin>>si;
    system("cls");//funcion para limpiar pantalla
    con=0;
    if(si=='s'||si=='S')
         main();
    else
        main();
    getchar();
}

void numeros() //Funcion de crear y ordenar 100 numeros usando random
{
	int num[100];
	int temp;
    srand(time(NULL));
    
    for(int i = 1; i <= 100; i++)
    {
        num[i] = 1 + rand() % (101 - 1);
        cout << num[i]<< "	 ";
    }
    
	cout<<endl<<endl;

	for(int i=0; i<100; i++) //usando el Metodo de la burbuja
	{
		for(int j=i+1; j<=100; j++) //abrimos un for
		{
			if (num[j]<num[i])
			{
				temp=num[j];
				num[j]=num[i];
				num [i]= temp;
			}
		}
	}
	cout<<"ORDENANDO NUMEROS"<<endl;
	for(int i=0; i<100; i++)		//se hace una impresion de numeros ordenados
	{
		cout<<num[i]<<" 	";
	}
	cout<<endl;
}

void cl(){	// uso de la Funcion para limpiar pantalla
	system ("cls");	
}

void p(){ //uso de la Funcion para pausar sistema
	system ("pause"); //hacemos una pausa
}

int main(){
	system ("color 90");  //cambiamos el color de consola
	int op;
	op=menu();
	switch(op){
		case 1: cl();
				torres();
				p();
				return main();
			break;
		case 2: cl();
				numeros();
				p();
				cl();
				return main();
			break;
		case 3: cl();
				salir();
			break; //se usa para interrumpir la ejecución normal del bucle
	}
}

