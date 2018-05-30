#include <stdio.h>                                           //Librería normal de entrada/salida                                  
#include <time.h>                                            //Aquí está la función tiempo
#include <stdlib.h>                                          //Aquí está la función exit
void menu1(int*);                                            //Menú inicial
void menu2(char A[21][12],int*);                             //Menú de pausa
void terreno_de_juego(int*);                                 //Crea el campo de juego
void elegir_ficha(char A[21][12],int*);                      //Elige ficha
void ficha_L(char A[21][12],int*);                           //Movimiento de la ficha L
void ficha_L_horizontal_1(char A[21][12],int f,int c,int*);  //
void ficha_L_horizontal_2(char A[21][12],int f,int c,int*);  //
void ficha_L_vertical_1(char A[21][12],int f,int c,int*);    //
void ficha_L_vertical_2(char A[21][12],int f,int c,int*);    //
void ficha_I(char A[21][12],int*);                           //Movimiento de la ficha I
void ficha_I_horizontal(char A[21][12],int f,int c,int*);    //
void ficha_I_vertical(char A[21][12],int f,int c,int*);      //
void ficha_O(char A[21][12],int*);                           //Movimiento de la ficha O
void ficha_O_horizontal(char A[21][12],int f,int c,int*);    //
void ficha_T(char A[21][12],int*);                           //Movimiento de la ficha T
void ficha_T_horizontal_1(char A[21][12],int f,int c,int*);  //
void ficha_T_horizontal_2(char A[21][12],int f,int c,int*);  //
void ficha_T_vertical_1(char A[21][12],int f,int c,int*);    //
void ficha_T_vertical_2(char A[21][12],int f,int c,int*);    //
void ficha_S(char A[21][12],int* lineas);                    //Movimiento de la ficha S
void ficha_S_horizontal(char A[21][12],int f,int c,int*);    //
void ficha_S_vertical(char A[21][12],int f,int c,int*);      //
void ficha_Z(char A[21][12],int* lineas);                    //Movimiento de la ficha Z
void ficha_Z_horizontal(char A[21][12],int f,int c,int*);    //
void ficha_Z_vertical(char A[21][12],int f,int c,int*);      //
void ficha_Li(char A[21][12],int*);                          //Movimiento de la ficha L-inversa
void ficha_Li_horizontal_1(char A[21][12],int f,int c,int*); //
void ficha_Li_horizontal_2(char A[21][12],int f,int c,int*); //
void ficha_Li_vertical_1(char A[21][12],int f,int c,int*);   //
void ficha_Li_vertical_2(char A[21][12],int f,int c,int*);   //
void guardar1(char A[21][12],int*);                          //Guarda1
void guardar2(char A[21][12],int*);                          //Guarda2
void guardar3(char A[21][12],int*);                          //Guarda3
void guardar4(char A[21][12],int*);                          //Guarda4
void cargar1(int*);                                          //Carga1
void cargar2(int*);                                          //Carga2
void cargar3(int*);                                          //Carga3
void cargar4(int*);                                          //Carga4
void imprimir(char A[21][12],int*);                          //Imprime el juego
void fila_completa(char A[21][12],int*);                     //Comprueba si la fila está completa y la elimina
void dibujo_menu();                                          //Dibujo del menú
void fin_de_juego(int*);
void main()                                                  //Función principal
{
  int lineas;
  menu1(&lineas);
}
//************************************************************************************************************************************************************
void menu1(int* lineas)
{
  int opcion;
  do
    {
      do
	{
	  system("clear");                      //Limpia el tablero para el menú
	  dibujo_menu();
	  printf("\n\n\t\t1-Iniciar nuevo juego\n\t\t2-Recuperar juego guardado\n\t\t3-Guardar juego\n\t\t4-Salir\n\n\t\tElija una opción:");
	  scanf("%d",&opcion);
	}
      while(opcion != 1&&opcion != 2&&opcion != 3&&opcion != 4);
      switch(opcion)
	{
	case 1:                                //Inicia el juego
	  terreno_de_juego(lineas);
	  break;
	case 2:                                //Carga el juego
	  printf("¿Que partida quieres cargar?(1,2,3,4)");
	  do
	    {
	      scanf("%d",&opcion);
	    }
	  while(opcion<1||opcion>4);
	  switch(opcion)
	    {
	    case 1:
	      cargar1(lineas);
	      break;
	    case 2:
	      cargar2(lineas);
	      break;
	    case 3:
	      cargar3(lineas);
	      break;
	    case 4:
	      cargar4(lineas);
	      break;
	    }
	  break;
	case 3:                                //Guarda el juego
	  printf("No se puede guardar porque no se empezo el juego, o este se ha perdido");
	  break;
	case 4:                                //Salir
	  exit(0);
	  break;
	}
    }
  while(opcion!=4);
}
//************************************************************************************************************************************************************
void menu2(char A[21][12],int* lineas)
{
  int opcion;
  do
    { 
      do
	{
	  system("clear");                     //Limpia el tablero para el menú
	  dibujo_menu();
	  printf("\n\n\t\t1-Continuar\n\t\t2-Iniciar nuevo juego\n\t\t3-Recuperar juego guardado\n\t\t4-Guardar juego\n\t\t5-Salir\n\n\t\tElija una opción:");
	  scanf("%d",&opcion);
	}
      while(opcion != 1&&opcion != 2&&opcion != 3&&opcion != 4&&opcion != 5);
      switch(opcion)
	{
	case 1:                               //Continuar
	  return;
	  break;
	case 2:                               //Iniciar otro juego
	  terreno_de_juego(lineas);
	  break;
	case 3:                                //Carga el juego
	  printf("¿Que partida quieres cargar?(1,2,3,4)");
	  do
	    {
	      scanf("%d",&opcion);
	    }
	  while(opcion<1||opcion>4);
	  switch(opcion)
	    {
	    case 1:
	      cargar1(lineas);
	      break;
	    case 2:
	      cargar2(lineas);
	      break;
	    case 3:
	      cargar3(lineas);
	      break;
	    case 4:
	      cargar4(lineas);
	      break;
	    }
	  break;
	case 4:                                //Guarda el juego
	  printf("¿Que partida quieres guardar?(1,2,3,4)");
	  do
	    {
	      scanf("%d",&opcion);
	    }
	  while(opcion<1||opcion>4);
	  switch(opcion)
	    {
	    case 1:
	      guardar1(A,lineas);
	      break;
	    case 2:
	      guardar2(A,lineas);
	      break;
	    case 3:
	      guardar3(A,lineas);
	      break;
	    case 4:
	      guardar4(A,lineas);
	      break;
	    }
	  break;
	case 5:                               //Salir
	  exit(0);
	  break;
	}
    }
  while(1);
}
//************************************************************************************************************************************************************
void terreno_de_juego(int* lineas)
{
  int i,j;
  char A[21][12];                                  //Crear la matriz que va a ser el campo de juego
  for(i=0;i<21;i++)
    for(j=0;j<12;j++)
      A[i][j] = ' ';                               //Hacer que todos los elementos sean espacios en blanco
  for(j=0;j<12;j++)
    A[20][j] = '=';                                //Línea de abajo
  for(i=0;i<20;i++)
    {
      A[i][0] = '|';                               //Líneas laterales
      A[i][11] = '|';
    }
  *lineas = 0;
  elegir_ficha(A,lineas);
  menu1(lineas);
}
//************************************************************************************************************************************************************
void elegir_ficha(char A[21][12],int* lineas)
{
  int eleccion;
  srand(time(NULL));                               //Aleatoriedad dependiente del momento en el que se inicie el programa (se explica mejor en persona)
  eleccion = rand()%7;                             //Para haya 7 opciones, el resto de dividir entre 7 es 0,1,2,3,4,5,6
  switch(eleccion)
    {
    case 0:                                        
      ficha_L(A,lineas);                                  //Llama a la ficha L
      break;
    case 1:
      ficha_I(A,lineas);                                  //Llama a la ficha I
      break;
    case 2:
      ficha_O(A,lineas);                                  //Llama a la ficha O
      break;
    case 3:
      ficha_T(A,lineas);                                  //Llama a la ficha T
      break;
    case 4:
      ficha_S(A,lineas);                                  //Llama a la ficha S
      break;
    case 5:
      ficha_Z(A,lineas);                                  //Llama a la ficha Z
      break;
    case 6:
      ficha_Li(A,lineas);                                 //Llama a la ficha L-inversa
      break;
    }
}
//************************************************************************************************************************************************************
void ficha_L(char A[21][12],int* lineas)
{
  int f = 0,c = 4;                                 //Inicia la ficha en la posición mandada
  if(A[0][4] != ' '||A[0][5] != ' '||A[0][6] != ' '||A[1][4] != ' ')   //Comprueba que esté libre
    fin_de_juego(lineas);                                        //Si no está libre acaba el programa (cuando esté completo, volverá al menú)
  ficha_L_horizontal_1(A,f,c,lineas);                     //Llama a la posición de inicio de la ficha
}
//************************************************************************************************************************************************************
void ficha_L_horizontal_1(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do                                                //do para repetir el ciclo si no llega hasta abajo
    {
      system("clear");                              //Limpia el terminal para que no se vean dos tableros
      A[f][c] = '#';             
      A[f][c+1] = '#';
      A[f][c+2] = '#';                              //Pone los caracteres de la ficha en la posición que le corresponde
      A[f+1][c] = '#';
      imprimir(A,lineas);                           //Función imprimir
      do
	{
	  scanf("%d",&instruccion);                 //Escanea la flecha introducida
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);    //No deja salir del bucle hasta que sea una de las opciones del siguiente switch
      switch(instruccion)          //Para determinar que flecha pulso
	{
	case 8:                    //Arriba
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';         //Pone en blanco las fichas para que no se queden marcadas
	  A[f+1][c] = ' ';
	  if(A[f+2][c] == ' '&&A[f+2][c+1] == ' ')   //Comprueba que estén libres los huecos necesarios
	    ficha_L_vertical_1(A,f,c,lineas);               //Llama a la siguiente ficha de rotación si están libres los huecos
	  break;
	case 2:                    //Abajo
	  if(A[f+2][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ')   //Comprueba que pueda bajar la ficha para borrar los huecos
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f][c+2] = ' ';
	      A[f+1][c] = ' ';
	    }
	  f += 1;                  //Suma una fila
	  break;
	case 6:                    //Derecha
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';         //Borra los huecos para que no se repitan
	  A[f+1][c] = ' ';
	  if(A[f][c+3] == ' '&&A[f+1][c+1] == ' ')    //Comprueba que pueda moverse hacia la derecha, en ese caso, suma una columna
	    c += 1;
	  break;
	case 4:                    //Izquierda
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';         //Borra los huecos para que no se repitan
	  A[f+1][c] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c-1] == ' ')   //Comprueba que pueda moverse para la izquierda, en ese caso, resta una columna
	    c -= 1;
	  break;
	case 5:                    //Va al menú
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';         //Borra los huecos para evitar que salga del ciclo al volver
	  A[f+1][c] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '#';
	      A[f][c+1] = '#';
	      A[f][c+2] = '#';
	      A[f+1][c] = '#';         
	      if(A[f+2][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ')   //Borra e imprime las fichas hasta que llega abajo
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f][c+2] = ' ';
		  A[f+1][c] = ' ';
		}
	      f += 1;             
	    }
	  while(A[f+1][c] == ' '&&A[f][c+1] == ' '&&A[f][c+2] == ' ');
	}
    }
  while(A[f+1][c] == ' '&&A[f][c+1] == ' '&&A[f][c+2] == ' ');    //Comprueba que no haya nada en los huecos que tiene que ocupar la ficha, si no lo están, se acaba y vuelve a llamar a una ficha
  fila_completa(A,lineas);           //Antes de llamar a otra ficha comprueba si hay que eliminar una línea
  elegir_ficha(A,lineas);            //Llama a otra ficha porque llego hasta abajo
}
//************************************************************************************************************************************************************
void ficha_L_vertical_1(char A[21][12],int f,int c,int* lineas)    //El resto de funciones son la misma explicación excepto la última
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '#';
      A[f+1][c] = '#';
      A[f+2][c] = '#';
      A[f+2][c+1] = '#';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f+1][c+1] == ' '&&A[f+1][c+2] == ' '&&A[f][c+2] == ' ')
	    ficha_L_horizontal_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c] == ' '&&A[f+3][c+1] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f+1][c] = ' ';
	      A[f+2][c] = ' ';
	      A[f+2][c+1] = ' ';
	    }
	  f += 1;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c+1] == ' '&&A[f+1][c+1] == ' '&&A[f+2][c+2] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if (A[f][c-1] == ' '&&A[f+1][c-1] == ' '&&A[f+2][c-1] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '#';
	      A[f+1][c] = '#';
	      A[f+2][c] = '#';
	      A[f+2][c+1] = '#';
	      if(A[f+3][c] == ' '&&A[f+3][c+1] == ' ')
		{
		  A[f][c] = ' ';
		  A[f+1][c] = ' ';
		  A[f+2][c] = ' ';
		  A[f+2][c+1] = ' ';
		}
	      f += 1;
	    }
	  while(A[f+2][c] == ' '&&A[f+2][c+1] == ' ');
	}
    }
  while(A[f+2][c] == ' '&&A[f+2][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_L_horizontal_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f+1][c] = '#';
      A[f+1][c+1] = '#';
      A[f+1][c+2] = '#';
      A[f][c+2] = '#'; 
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f][c] == ' '&&A[f][c+1] == ' '&&A[f+2][c+1] == ' ')
	    ficha_L_vertical_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
	    {
	      A[f+1][c] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+1][c+2] = ' ';
	      A[f][c+2] = ' ';
	    }
	  f += 1;
	  break; 
	case 6:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f+1][c+3] == ' '&&A[f][c+3] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f+1][c-1] == ' '&&A[f][c+1] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f+1][c] = '#';
	      A[f+1][c+1] = '#';
	      A[f+1][c+2] = '#';
	      A[f][c+2] = '#';
	      if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
		{
		  A[f+1][c] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+1][c+2] = ' ';
		  A[f][c+2] = ' ';
		}
	      f += 1;
	    }
	  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
	}
    }
  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_L_vertical_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '#';
      A[f][c+1] = '#';
      A[f+1][c+1] = '#';
      A[f+2][c+1] = '#'; 
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f+1][c] == ' '&&A[f][c+2] == ' ')
	    ficha_L_horizontal_1(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+1][c] == ' '&&A[f+3][c+1] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+2][c+1] = ' ';
	    }
	  f += 1;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' '; 
	  if(A[f][c+2] == ' '&&A[f+1][c+2] == ' '&&A[f+2][c+2] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' '; 
	  if(A[f][c-1] == ' '&&A[f+1][c] == ' '&&A[f+2][c] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '#';
	      A[f][c+1] = '#';
	      A[f+1][c+1] = '#';
	      A[f+2][c+1] = '#';
	      if(A[f+1][c] == ' '&&A[f+3][c+1] == ' ')
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+2][c+1] = ' ';
		}
	      f += 1;
	    }
	  while(A[f][c] == ' '&&A[f+2][c+1] == ' ');
	}
    }
  while(A[f][c] == ' '&&A[f+2][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//****************************************************************************************************************************************************
void ficha_I(char A[21][12],int* lineas)
 {
   int f = 0,c = 4;                                 //Inicia la ficha en la posición mandada
   if(A[0][4] != ' '||A[0][5] != ' '||A[0][6] != ' '||A[0][7] != ' ')   //Comprueba que esté libre
     fin_de_juego(lineas);                                        //Si no está libre acaba el programa (cuando esté completo, volverá al menú)
   ficha_I_horizontal(A,f,c,lineas);                     //Llama a la posición de inicio de la ficha
}
//********************************************************************************
void ficha_I_horizontal(char A[21][12], int f, int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c]= '%';
      A[f][c+1]= '%';
      A[f][c+2]= '%';
      A[f][c+3]= '%';
      imprimir(A,lineas);
      do
	{
	  scanf("%d" , &instruccion);         //EScanea la tecla introducida
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)            //para determinar que flecha pulso
	{
	case 8:
	  A[f][c]= ' ';
	  A[f][c+1]= ' ';
	  A[f][c+2]= ' ';
	  A[f][c+3]= ' ';
	  if(A[f+1][c]== ' ' && A[f+2][c]== ' ' && A[f+3][c]==' ');
	  ficha_I_vertical(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+1][c]==' ' && A[f+1][c+1]==' ' && A[f+1][c+2]==' ' && A[f+1][c+3]==' ')
	    {
	      A[f][c]=' ';
	      A[f][c+1]= ' ';
	      A[f][c+2]= ' ';
	      A[f][c+3]= ' ';
	    }
	  f+=1;
	  break;
	case 6:
	  A[f][c]=' ';
	  A[f][c+1]= ' ';
	  A[f][c+2]= ' ';
	  A[f][c+3]= ' ';
	  if(A[f][c+4]==' ')
	    {
	      c += 1;
	    }
	  break;
	case 4:
	  A[f][c]=' ';
	  A[f][c+1]= ' ';
	  A[f][c+2]= ' ';
	  A[f][c+3]= ' ';
	  if(A[f][c-1]==' ')
	    {
	      c-= 1;
	    }
	  break;
	case 5:
	  A[f][c]=' ';
	  A[f][c+1]= ' ';
	  A[f][c+2]= ' ';
	  A[f][c+3]= ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c]='%';
	      A[f][c+1]= '%';
	      A[f][c+2]= '%';
	      A[f][c+3]= '%';
	      if(A[f+1][c]==' ' && A[f+1][c+1]==' ' && A[f+1][c+2]==' ' && A[f+1][c+3]==' ')
		{
		  A[f][c]=' ';
		  A[f][c+1]= ' ';
		  A[f][c+2]= ' ';
		  A[f][c+3]= ' ';
		}
	      f+=1;
	    }
	  while(A[f][c]==' ' && A[f][c+1]==' ' && A[f][c+2]== ' ' && A[f][c+3]==' ');
	}
    }
  while(A[f][c]==' ' && A[f][c+1]==' ' && A[f][c+2]== ' ' && A[f][c+3]==' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//**************************************************************
void ficha_I_vertical(char A[21][12], int f, int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c]= '%';
      A[f+1][c]= '%';
      A[f+2][c]= '%';
      A[f+3][c]= '%';
      imprimir(A,lineas);
      do
	{
	  scanf("%d", &instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f+2][c]= ' ';
	  A[f+3][c]= ' ';
	  if(A[f+1][c+1]==' ' && A[f+1][c+2]==' ' && A[f+1][c+3]==' ')
	    ficha_I_horizontal(A, f, c,lineas);
	  break;
	case 2:
	  if(A[f+4][c]==' ')
	    {
	      A[f][c]= ' ';
	      A[f+1][c]= ' ';
	      A[f+2][c]= ' ';
	      A[f+3][c]= ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f+2][c]= ' ';
	  A[f+3][c]= ' ';
	  if(A[f][c+1]==' '&& A[f+1][c+1]==' ' && A[f+2][c+1]== ' ' && A[f+3][c+1]==' ')
	    c++;
	  break;
	case 4:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f+2][c]= ' ';
	  A[f+3][c]= ' ';
	  if(A[f][c-1]==' '&& A[f+1][c-1]==' ' && A[f+2][c-1]== ' ' && A[f+3][c-1]==' ')
	    c--;
	  break;
	case 5:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f+2][c]= ' ';
	  A[f+3][c]= ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c]= '%';
	      A[f+1][c]= '%';
	      A[f+2][c]= '%';
	      A[f+3][c]= '%';
	      if(A[f+4][c]==' ')
		{
		  A[f][c]= ' ';
		  A[f+1][c]= ' ';
		  A[f+2][c]= ' ';
		  A[f+3][c]= ' ';
		}
	      f++;
	    }
	  while(A[f+1][c]==' ' && A[f+2][c]== ' ' && A[f+3][c]==' ');
	}
    }
  while(A[f+1][c]==' ' && A[f+2][c]== ' ' && A[f+3][c]==' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_O(char A[21][12],int* lineas)
{
  int f = 0,c = 4;                                 
  if(A[0][4] != ' '||A[1][4] != ' '||A[0][5] != ' '||A[1][5] != ' ')   
    fin_de_juego(lineas);                                        
  ficha_O_horizontal(A,f,c,lineas);
}              
//************************************************************************************************************************************************************
void ficha_O_horizontal(char A[21][12], int f, int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c]= 'O';
      A[f+1][c]= 'O';
      A[f][c+1]= 'O';
      A[f+1][c+1]= 'O';
      imprimir(A,lineas);
      do
	{
	  scanf("%d", &instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  ficha_O_horizontal(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+2][c]==' '&&A[f+2][c+1]==' ')
	    {
	      A[f][c]= ' ';
	      A[f+1][c]= ' ';
	      A[f][c+1]= ' ';
	      A[f+1][c+1]= ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f][c+1]= ' ';
	  A[f+1][c+1]= ' ';
	  if(A[f][c+2]==' ' &&  A[f+1][c+2]==' ')
	    c++;
	  break;
	case 4:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f][c+1]= ' ';
	  A[f+1][c+1]= ' ';
	  if(A[f][c-1]==' '&& A[f+1][c-1]==' ')
	    c--;
	  break;
	case 5:
	  A[f][c]= ' ';
	  A[f+1][c]= ' ';
	  A[f][c+1]= ' ';
	  A[f+1][c+1]= ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c]= 'O';
	      A[f+1][c]= 'O';
	      A[f][c+1]= 'O';
	      A[f+1][c+1]= 'O';
	      if(A[f+2][c]==' '&&A[f+2][c+1]==' ')
		{
		  A[f][c]= ' ';
		  A[f+1][c]= ' ';
		  A[f][c+1]= ' ';
		  A[f+1][c+1]= ' ';
		}
	      f++;
	    }
	  while(A[f+1][c]==' ' && A[f+1][c+1]== ' ');
	}
    }
  while(A[f+1][c]==' ' && A[f+1][c+1]== ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_T(char A[21][12],int* lineas)
{
  int f=0,c=4;
  if(A[0][4] != ' '||A[0][5] != ' '||A[0][6] != ' '||A[1][5] != ' ')
    fin_de_juego(lineas);
  ficha_T_horizontal_1(A,f,c,lineas);
}
//************************************************************************************************************************************************************
void ficha_T_horizontal_1(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '&';
      A[f][c+1] = '&';
      A[f][c+2] = '&';
      A[f+1][c+1] = '&';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f+1][c] == ' '&&A[f+2][c] == ' ')
	    ficha_T_vertical_1(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+1][c] == ' '&&A[f+2][c+1] == ' '&&A[f+1][c+2] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f][c+2] = ' ';
	      A[f+1][c+1] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c+3] == ' '&&A[f+1][c+2] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '&';
	      A[f][c+1] = '&';
	      A[f][c+2] = '&';
	      A[f+1][c+1] = '&';
	      if(A[f+1][c] == ' '&&A[f+2][c+1] == ' '&&A[f+1][c+2] == ' ')
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
	      A[f][c+2] = ' ';
	      A[f+1][c+1] = ' ';
		}
	      f++;
	    }
	  while(A[f][c] == ' '&&A[f+1][c+1] == ' '&&A[f][c+2] == ' ');
	}
    }
  while(A[f][c] == ' '&&A[f+1][c+1] == ' '&&A[f][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_T_vertical_1(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '&';
      A[f+1][c] = '&';
      A[f+2][c] = '&';
      A[f+1][c+1] = '&';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c+1] == ' '&&A[f+1][c+2] == ' ')
	    ficha_T_horizontal_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c] == ' '&&A[f+2][c+1] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f+1][c] = ' ';
	      A[f+2][c] = ' ';
	      A[f+1][c+1] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c+1] == ' '&&A[f+1][c+2] == ' '&&A[f+2][c+1] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c-1] == ' '&&A[f+2][c-1] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  A[f+1][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '&';
	      A[f+1][c] = '&';
	      A[f+2][c] = '&';
	      A[f+1][c+1] = '&';
	      if(A[f+3][c] == ' '&&A[f+2][c+1] == ' ')
		{
		  A[f][c] = ' ';
		  A[f+1][c] = ' ';
		  A[f+2][c] = ' ';
		  A[f+1][c+1] = ' ';
		}
	      f++;
	    }
	  while(A[f+2][c] == ' '&&A[f+1][c+1] == ' ');
	}
    }
  while(A[f+2][c] == ' '&&A[f+1][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_T_horizontal_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f+1][c] = '&';
      A[f][c+1] = '&';
      A[f+1][c+2] = '&';
      A[f+1][c+1] = '&';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f+1][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f+2][c+1] == ' ')
	    ficha_T_vertical_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
	    {
	      A[f+1][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f+1][c+2] = ' ';
	      A[f+1][c+1] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f+1][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f+1][c+3] == ' '&&A[f][c+2] == ' ')
	    c++;
	  break;
	case 4:
	  A[f+1][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c] == ' '&&A[f+1][c-1] == ' ')
	    c--;
	  break;
	case 5:
	  A[f+1][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f+1][c] = '&';
	      A[f][c+1] = '&';
	      A[f+1][c+2] = '&';
	      A[f+1][c+1] = '&';
	      if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
		{
		  A[f+1][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f+1][c+2] = ' ';
		  A[f+1][c+1] = ' ';
		}
	      f++;
	    }
	  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
	}
    }
  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_T_vertical_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c+2] = '&';
      A[f+1][c+1] = '&';
      A[f+1][c+2] = '&';
      A[f+2][c+2] = '&';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c+2] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+2][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c] == ' '&&A[f][c+2] == ' ')
	    ficha_T_horizontal_1(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c+2] == ' '&&A[f+2][c+1] == ' ')
	    {
	      A[f][c+2] = ' ';
	      A[f+1][c+2] = ' ';
	      A[f+2][c+2] = ' ';
	      A[f+1][c+1] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c+2] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+2][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c+3] == ' '&&A[f+1][c+3] == ' '&&A[f+2][c+3] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c+2] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+2][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c+1] == ' '&&A[f+1][c] == ' '&&A[f+2][c+1] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c+2] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+2][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c+2] = '&';
	      A[f+1][c+2] = '&';
	      A[f+2][c+2] = '&';
	      A[f+1][c+1] = '&';
	      if(A[f+3][c+2] == ' '&&A[f+2][c+1] == ' ')
		{
		  A[f][c+2] = ' ';
		  A[f+1][c+2] = ' ';
		  A[f+2][c+2] = ' ';
		  A[f+1][c+1] = ' ';
		}
	      f++;
	    }
	  while(A[f+2][c+2] == ' '&&A[f+1][c+1] == ' ');
	}
    }
  while(A[f+2][c+2] == ' '&&A[f+1][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_S(char A[21][12],int* lineas)
{
  int f=0,c=4;
  if(A[1][4] != ' '||A[0][5] != ' '||A[1][5] != ' '||A[0][6] != ' ')
    fin_de_juego(lineas);
  ficha_S_horizontal(A,f,c,lineas);
}
//************************************************************************************************************************************************************
void ficha_S_horizontal(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f+1][c] = '@';
      A[f+1][c+1] = '@';
      A[f][c+1] = '@';
      A[f][c+2] = '@';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  if(A[f][c] == ' '&&A[f+2][c+1] == ' ')
	    ficha_S_vertical(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+1][c+2] == ' ')
	    {
	      A[f+1][c] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f][c+1] = ' ';
	      A[f][c+2] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f][c+1] = ' ';
	  A[f][c+2] = ' ';
	  if(A[f+1][c+2] == ' '&&A[f][c+3] == ' ')
	    c++;
	  break;
	case 4:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f][c+1] = ' ';
	  if(A[f][c] == ' '&&A[f+1][c-1] == ' ')
	    c--;
	  break;
	case 5:
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f][c+2] = ' ';
	  A[f][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f+1][c] = '@';
	      A[f+1][c+1] = '@';
	      A[f][c+1] = '@';
	      A[f][c+2] = '@';
	      if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+1][c+2] == ' ')
		{
		  A[f+1][c] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f][c+1] = ' ';
		  A[f][c+2] = ' ';
		}
	      f++;
	    }
	  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f][c+2] == ' ');
	}
    }
  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_S_vertical(char A[21][12],int f,int c,int* lineas)
{

  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '@';
      A[f+1][c] = '@';
      A[f+1][c+1] = '@';
      A[f+2][c+1] = '@';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c] == ' '&&A[f][c+2] == ' ')
	    ficha_S_horizontal(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+2][c] == ' '&&A[f+3][c+1] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f+1][c] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+2][c+1] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c+1] == ' '&&A[f+1][c+2] == ' '&&A[f+2][c+2] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c] == ' '&&A[f+2][c] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '@';
	      A[f+1][c] = '@';
	      A[f+1][c+1] = '@';
	      A[f+2][c+1] = '@';
	      if(A[f+2][c] == ' '&&A[f+3][c+1] == ' ')
		{
		  A[f][c] = ' ';
		  A[f+1][c] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+2][c+1] = ' ';
		}
	      f++;
	    }
	  while(A[f+1][c] == ' '&&A[f+2][c+1] == ' ');
	}
    }
  while(A[f+1][c] == ' '&&A[f+2][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_Z(char A[21][12],int* lineas)
{
  int f=0,c=4;
  if(A[0][4] != ' '||A[0][5] != ' '||A[1][5] != ' '||A[1][6] != ' ')
    fin_de_juego(lineas);
  ficha_Z_horizontal(A,f,c,lineas);
}
//************************************************************************************************************************************************************
void ficha_Z_horizontal(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '$';
      A[f][c+1] = '$';
      A[f+1][c+1] = '$';
      A[f+1][c+2] = '$';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';                                                   
	  if(A[f+1][c] == ' '&&A[f+2][c] == ' ')                            
	    ficha_Z_vertical(A,f,c,lineas);                                 
	  break;
	case 2:
	  if(A[f+1][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+1][c+2] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  if(A[f][c+2] == ' '&&A[f+1][c+3] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f+1][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '$';
	      A[f][c+1] = '$';
	      A[f+1][c+1] = '$';
	      A[f+1][c+2] = '$';
	      if(A[f+1][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ')
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+1][c+2] = ' ';
		}
	      f++;
	    }
	  while(A[f][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
	}
    }
  while(A[f][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_Z_vertical(char A[21][12],int f,int c,int* lineas)
{

  int instruccion;
  do
    {
      system("clear");
      A[f][c+1] = '$';
      A[f+1][c] = '$';                 
      A[f+1][c+1] = '$';               
      A[f+2][c] = '$';                 
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  if(A[f][c] == ' '&&A[f+1][c+2] == ' ')
	    ficha_Z_horizontal(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c] == ' '&&A[f+2][c+1] == ' ')
	    {
	      A[f][c+1] = ' ';
	      A[f+1][c] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+2][c] = ' ';
	    }
	  f++;
	  break;
	case 6:
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  if(A[f][c+2] == ' '&&A[f+1][c+2] == ' '&&A[f+2][c+1] == ' ')
	    c++;
	  break;
	case 4:
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  if(A[f][c] == ' '&&A[f+1][c-1] == ' '&&A[f+2][c-1] == ' ')
	    c--;
	  break;
	case 5:
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c+1] = '$';
	      A[f+1][c] = '$';
	      A[f+1][c+1] = '$';
	      A[f+2][c] = '$';
	      if(A[f+3][c] == ' '&&A[f+2][c+1] == ' ')
		{
		  A[f][c+1] = ' ';
		  A[f+1][c] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+2][c] = ' ';
		}
	      f++;
	    }
	  while(A[f+2][c] == ' '&&A[f+1][c+1] == ' ');
	}
    }
  while(A[f+2][c] == ' '&&A[f+1][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_Li(char A[21][12],int* lineas)
{
  int f = 0,c = 4;                                 //Inicia la ficha en la posición mandada
  if(A[1][4] != ' '||A[1][5] != ' '||A[1][6] != ' '||A[0][4] != ' ')   //Comprueba que esté libre
    fin_de_juego(lineas);                                        //Si no está libre acaba el programa (cuando esté completo, volverá al menú)
  ficha_Li_horizontal_1(A,f,c,lineas);                     //Llama a la posición de inicio de la ficha
}
//************************************************************************************************************************************************************
void ficha_Li_horizontal_1(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do                                           
    {
      system("clear");                         
      A[f][c] = '!';             
      A[f+1][c+1] = '!';
      A[f+1][c+2] = '!';                       
      A[f+1][c] = '!';
      imprimir(A,lineas);                      
      do
	{
	  scanf("%d",&instruccion);              
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)   
	{
	case 8:
	  A[f][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';  
	  A[f+1][c] = ' ';
	  if(A[f][c+1] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c] == ' ')
	    ficha_Li_vertical_1(A,f,c,lineas);               
	  break;                 
	case 2:
	  if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ') 
	    {
	      A[f][c] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+1][c+2] = ' ';
	      A[f+1][c] = ' ';
	    }
	  f += 1;            
	  break;            
	case 6:
	  A[f][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' '; 
	  A[f+1][c] = ' ';
	  if(A[f][c+1] == ' '&&A[f+2][c+3] == ' ')  
	    c += 1;
	  break;           
	case 4:
	  A[f][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';         
	  A[f+1][c] = ' ';
	  if(A[f][c-1] == ' '&&A[f+1][c-1] == ' ')   
	    c -= 1;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+1][c+2] = ' ';         
	  A[f+1][c] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do 
	    {
	      A[f][c] = '!';
	      A[f+1][c+1] = '!';
	      A[f+1][c+2] = '!';
	      A[f+1][c] = '!';   
	      if(A[f+2][c] == ' '&&A[f+2][c+1] == ' '&&A[f+2][c+2] == ' ') 
		{
		  A[f][c] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+1][c+2] = ' ';
		  A[f+1][c] = ' ';
		}
	      f += 1;
	    }      
	  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' '); 
	}
    }
  while(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+1][c+2] == ' '); 
  fila_completa(A,lineas);          
  elegir_ficha(A,lineas);           
}
//************************************************************************************************************************************************************
void ficha_Li_vertical_1(char A[21][12],int f,int c,int* lineas)    //El resto de funciones son la misma explicación excepto la última
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c+1] = '!';
      A[f+1][c+1] = '!';
      A[f+2][c+1] = '!';
      A[f+2][c] = '!';
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c] == ' '&&A[f][c+2] == ' '&&A[f+1][c+2] == ' ')
	    ficha_Li_horizontal_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c] == ' '&&A[f+3][c+1] == ' ')
	    {
	      A[f][c+1] = ' ';
	      A[f+1][c+1] = ' ';
	      A[f+2][c] = ' ';
	      A[f+2][c+1] = ' ';
	    }
	  f += 1;
	  break;
	case 6:
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if(A[f][c+2] == ' '&&A[f+1][c+2] == ' '&&A[f+2][c+2] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  if (A[f][c] == ' '&&A[f+1][c] == ' '&&A[f+2][c-1] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f][c+1] = ' ';
	  A[f+1][c+1] = ' ';
	  A[f+2][c] = ' ';
	  A[f+2][c+1] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c+1] = '!';
	      A[f+1][c+1] = '!';
	      A[f+2][c] = '!';
	      A[f+2][c+1] = '!';
	      if(A[f+3][c] == ' '&&A[f+3][c+1] == ' ')
		{
		  A[f][c+1] = ' ';
		  A[f+1][c+1] = ' ';
		  A[f+2][c] = ' ';
		  A[f+2][c+1] = ' ';
		}
	      f += 1;
	    }
	  while(A[f+2][c] == ' '&&A[f+2][c+1] == ' ');
	}
    }
  while(A[f+2][c] == ' '&&A[f+2][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_Li_horizontal_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '!';
      A[f][c+1] = '!';
      A[f][c+2] = '!';
      A[f+1][c+2] = '!'; 
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f+1][c] == ' '&&A[f+2][c] == ' ')
	    ficha_Li_vertical_2(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+2][c+2] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f+1][c+2] = ' ';
	      A[f][c+2] = ' ';
	    }
	  f += 1;
	  break; 
	case 6:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f+1][c+3] == ' '&&A[f][c+3] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  if(A[f+1][c+1] == ' '&&A[f][c-1] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c+2] = ' ';
	  A[f][c+2] = ' '; 
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '!';
	      A[f][c+1] = '!';
	      A[f+1][c+2] = '!';
	      A[f][c+2] = '!';
	      if(A[f+1][c] == ' '&&A[f+1][c+1] == ' '&&A[f+2][c+2] == ' ')
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f+1][c+2] = ' ';
		  A[f][c+2] = ' ';
		}
	      f += 1;
	    }
	  while(A[f][c] == ' '&&A[f][c+1] == ' '&&A[f+1][c+2] == ' ');
	}
    }
  while(A[f][c] == ' '&&A[f][c+1] == ' '&&A[f+1][c+2] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void ficha_Li_vertical_2(char A[21][12],int f,int c,int* lineas)
{
  int instruccion;
  do
    {
      system("clear");
      A[f][c] = '!';
      A[f][c+1] = '!';
      A[f+1][c] = '!';
      A[f+2][c] = '!'; 
      imprimir(A,lineas);
      do
	{
	  scanf("%d",&instruccion);
	}
      while(instruccion != 5&&instruccion != 22&&instruccion != 2&&instruccion != 4&&instruccion != 6&&instruccion != 8);
      switch(instruccion)
	{
	case 8:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  if(A[f+1][c+1] == ' '&&A[f+1][c+2] == ' ')
	    ficha_Li_horizontal_1(A,f,c,lineas);
	  break;
	case 2:
	  if(A[f+3][c] == ' '&&A[f+1][c+1] == ' ')
	    {
	      A[f][c] = ' ';
	      A[f][c+1] = ' ';
	      A[f+1][c] = ' ';
	      A[f+2][c] = ' '; 
	    }
	  f += 1;
	  break;
	case 6:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' '; 
	  if(A[f][c+2] == ' '&&A[f+1][c+1] == ' '&&A[f+2][c+1] == ' ')
	    c += 1;
	  break;
	case 4:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' '; 
	  if(A[f][c-1] == ' '&&A[f+1][c-1] == ' '&&A[f+2][c-1] == ' ')
	    c -= 1;
	  break;
	case 5:
	  A[f][c] = ' ';
	  A[f][c+1] = ' ';
	  A[f+1][c] = ' ';
	  A[f+2][c] = ' ';
	  menu2(A,lineas);
	  break;
	case 22:
	  do
	    {
	      A[f][c] = '!';
	      A[f][c+1] = '!';
	      A[f+1][c] = '!';
	      A[f+2][c] = '!'; 
	      if(A[f+3][c] == ' '&&A[f+1][c+1] == ' ')
		{
		  A[f][c] = ' ';
		  A[f][c+1] = ' ';
		  A[f+1][c] = ' ';
		  A[f+2][c] = ' '; 
		}
	      f += 1;
	    }
	  while(A[f+2][c] == ' '&&A[f][c+1] == ' ');
	}
    }
  while(A[f+2][c] == ' '&&A[f][c+1] == ' ');
  fila_completa(A,lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void fila_completa(char A[21][12],int* lineas)
{
  int i,j;
  for(i=0;i<20;i++)
    if(A[i][1] != ' '&&A[i][2] != ' '&&A[i][3] != ' '&&A[i][4] != ' '&&A[i][5] != ' '&&A[i][6] != ' '&&A[i][7] != ' '&&A[i][8] != ' '&&A[i][9] != ' '&&A[i][10] != ' ')                 //Comprueba si la línea está completa
      {
	*lineas += 1;
	for(;i>0;i--)           //Fila solo de las variables (piezas) (todas menos la última)
	  for(j=10;j>0;j--)         //Columnas solo de las variables (piezas) (todas menos la primera y la última)
	    A[i][j] = A[i-1][j];    //Sustituye cada fila por la anterios (efecto de eliminar línea)
	fila_completa(A,lineas);           //Se llama a si misma por si hay más de una fila por eliminar
      }
}
//************************************************************************************************************************************************************
void guardar1(char A[21][12],int* lineas)
{
  int i,j;
  FILE*pf;
  char opcion;
  printf("Se perderá la ficha en juego, ¿seguro que desea continuar? (Introduzca S o s)");
  scanf(" %c",&opcion);
  if(opcion == 's'||opcion == 'S')
    {
      pf=fopen ("juego_guardado1.txt","w");//Nombre del archivo donde se guarda. La instrucción "w" indica que si no existe el archivo, se crea; y en caso de que exista, lo sobreescribe. En la página 336 de "Piensa en C" tenéis todos los tipos de archivos posibles
      for (i=0;i<21;i++)
	{
	  for(j=0;j<12;j++)
	    {
	      fprintf(pf,"%c",A[i][j]);
	    }
	}
      fclose(pf);// Cierra el archivo al acabar de pasarle los datos
      pf=fopen("lineas1.txt","w");
      fprintf(pf,"%d",*lineas);
      fclose(pf);
    }
}
//************************************************************************************************************************************************************
void guardar2(char A[21][12],int* lineas)
{
  int i,j;
  FILE*pf;
  char opcion;
  printf("Se perderá la ficha en juego, ¿seguro que desea continuar? (Introduzca S o s)");
  scanf(" %c",&opcion);
  if(opcion == 's'||opcion == 'S')
    {
      pf=fopen ("juego_guardado2.txt","w");//Nombre del archivo donde se guarda. La instrucción "w" indica que si no existe el archivo, se crea; y en caso de que exista, lo sobreescribe. En la página 336 de "Piensa en C" tenéis todos los tipos de archivos posibles
      for (i=0;i<21;i++)
	{
	  for(j=0;j<12;j++)
	    {
	      fprintf(pf,"%c",A[i][j]);
	    }
	}
      fclose(pf);// Cierra el archivo al acabar de pasarle los datos
      pf=fopen("lineas2.txt","w");
      fprintf(pf,"%d",*lineas);
      fclose(pf);
    }
}
//************************************************************************************************************************************************************
void guardar3(char A[21][12],int* lineas)
{
  int i,j;
  FILE*pf;
  char opcion;
  printf("Se perderá la ficha en juego, ¿seguro que desea continuar? (Introduzca S o s)");
  scanf(" %c",&opcion);
  if(opcion == 's'||opcion == 'S')
    {
      pf=fopen ("juego_guardado3.txt","w");//Nombre del archivo donde se guarda. La instrucción "w" indica que si no existe el archivo, se crea; y en caso de que exista, lo sobreescribe. En la página 336 de "Piensa en C" tenéis todos los tipos de archivos posibles
      for (i=0;i<21;i++)
	{
	  for(j=0;j<12;j++)
	    {
	      fprintf(pf,"%c",A[i][j]);
	    }
	}
      fclose(pf);// Cierra el archivo al acabar de pasarle los datos
      pf=fopen("lineas3.txt","w");
      fprintf(pf,"%d",*lineas);
      fclose(pf);
    }
}
//************************************************************************************************************************************************************
void guardar4(char A[21][12],int* lineas)
{
  int i,j;
  FILE*pf;
  char opcion;
  printf("Se perderá la ficha en juego, ¿seguro que desea continuar? (Introduzca S o s)");
  scanf(" %c",&opcion);
  if(opcion == 's'||opcion == 'S')
    {
      pf=fopen ("juego_guardado4.txt","w");//Nombre del archivo donde se guarda. La instrucción "w" indica que si no existe el archivo, se crea; y en caso de que exista, lo sobreescribe. En la página 336 de "Piensa en C" tenéis todos los tipos de archivos posibles
      for (i=0;i<21;i++)
	{
	  for(j=0;j<12;j++)
	    {
	      fprintf(pf,"%c",A[i][j]);
	    }
	}
      fclose(pf);// Cierra el archivo al acabar de pasarle los datos
      pf=fopen("lineas4.txt","w");
      fprintf(pf,"%d",*lineas);
      fclose(pf);
    }
}
//************************************************************************************************************************************************************
void cargar1(int* lineas)
{
  int i,j;
  char num;
  char A[21][12];
  FILE *matriz;
  matriz = fopen("juego_guardado1.txt","r+");
  i=j=0;
  while (!feof(matriz))
    {
      fscanf(matriz,"%c",&num);
      // if(feof(matriz))
      //	break;//Evita doble lectura último caracter
      A[i][j]=num;
      j++;
      if (j==12)
  	{
  	  j=0;
  	  i++;
  	}// control de índices del array S
    }
  matriz = fopen("lineas1.txt","r+");
  fscanf(matriz,"%d",lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void cargar2(int* lineas)
{
  int i,j;
  char num;
  char A[21][12];
  FILE *matriz;
  matriz = fopen("juego_guardado2.txt","r+");
  i=j=0;
  while (!feof(matriz))
    {
      fscanf(matriz,"%c",&num);
      if(feof(matriz))
  	break;//Evita doble lectura último número
      A[i][j]=num;
      j++;
      if (j==12)
  	{
  	  j=0;
  	  i++;
  	}// control de índices del array S
    }
  matriz = fopen("lineas2.txt","r+");
  fscanf(matriz,"%d",lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void cargar3(int* lineas)
{
  int i,j;
  char num;
  char A[21][12];
  FILE *matriz;
  matriz = fopen("juego_guardado3.txt","r+");
  i=j=0;
  while (!feof(matriz))
    {
      fscanf(matriz,"%c",&num);
      if(feof(matriz))
  	break;//Evita doble lectura último número
      A[i][j]=num;
      j++;
      if (j==12)
  	{
  	  j=0;
  	  i++;
  	}// control de índices del array S
    }
  matriz = fopen("lineas3.txt","r+");
  fscanf(matriz,"%d",lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void cargar4(int* lineas)
{
  int i,j;
  char num;
  char A[21][12];
  FILE *matriz;
  matriz = fopen("juego_guardado4.txt","r+");
  i=j=0;
  while (!feof(matriz))
    {
      fscanf(matriz,"%c",&num);
      if(feof(matriz))
  	break;//Evita doble lectura último número
      A[i][j]=num;
      j++;
      if (j==12)
  	{
  	  j=0;
  	  i++;
  	}// control de índices del array S
    }
  matriz = fopen("lineas4.txt","r+");
  fscanf(matriz,"%d",lineas);
  elegir_ficha(A,lineas);
}
//************************************************************************************************************************************************************
void imprimir(char A[21][12],int* lineas)
{
  int i,j;
  for(i=0;i<21;i++)
    {
      printf("\t\t");                                   //Cada fila la mueve hacia la derecha para que quede mejor
      for(j=0;j<12;j++)
	  switch(A[i][j])
	    {
	    case '#':
	      printf("\e[101m\e[91m%2c\e[0m",A[i][j]);         //"\e[91m" es para poner color rojo, luego hay que poner "\e[0m" para volver al blanco
	      break;
	    case '%':
	      printf("\e[105m\e[95m%2c\e[0m",A[i][j]);         //"\e[95m" es para poner color morado, "\e[0m" para volver al blanco
	      break;
	    case 'O':
	      printf("\e[94m\e[104m%2c\e[0m",A[i][j]);         //"\e[94m" es para poner color azul, "\e[0m" para volver al blanco
	      break;
	    case '&':
	      printf("\e[92m\e[102m%2c\e[0m",A[i][j]);         //"\e[92m" es para poner color verde, "\e[0m" para volver al blanco
	      break;
	    case '@':
	      printf("\e[93m\e[103m%2c\e[0m",A[i][j]);         //"\e[93m" es para poner color amarillo, "\e[0m" para volver al blanco
	      break;
	    case '$':
	      printf("\e[90m\e[100m%2c\e[0m",A[i][j]);         //"\e[90m" es para poner color gris, "\e[0m" para volver al blanco
	      break;
	    case '!':
	      printf("\e[96m\e[106m%2c\e[0m",A[i][j]);         //"\e[96m" es para poner color turquesa, "\e[0m" para volver al blanco
	      break;
	    default:
	      printf("%2c",A[i][j]);                    //Imprime en blanco os caracteres laterales y de abajo
	      break;
	    }
      printf("\n");                                     //Salto de línea para no poner todo en la misma
    }
  printf("\n");
  if(*lineas<10)
    {
      printf("\t\t   *  *  *  *  *  *  * \n");
      printf("\t\t   *                 * \n");
      printf("\t\t   *        %d        * \n",*lineas);
      printf("\t\t   *                 * \n");
      printf("\t\t   *  *  *  *  *  *  * \n");
    }
  else
    {
      printf("\t\t   *  *  *  *  *  *  * \n");
      printf("\t\t   *                 * \n");
      printf("\t\t   *        %d       * \n",*lineas);
      printf("\t\t   *                 * \n");
      printf("\t\t   *  *  *  *  *  *  * \n");
    }
  printf("\t\tPARA JUGAR PULSAR 2,4,6 Ó 8:\n");
  printf("\t\t  Desplazar derecha(→): 6\n");
  printf("\t\t  Desplazar izquierda(←): 4\n");
  printf("\t\t  Bajar(↓): 2\n");
  printf("\t\t  Bajar hasta abajo(↓↓): 22\n");
  printf("\t\t  Girar: 8\n");
  printf("\t\tPara ir al menú: 5\n");
  printf("\t\t-->");
}
//************************************************************************************************************************************************************
void dibujo_menu()
{
  printf("\n\t   \e[101m      \e[0m \e[102m      \e[0m \e[103m      \e[0m \e[104m      \e[0m \e[105m      \e[0m \e[106m      \e[0m");
  printf("\n\t     \e[101m  \e[0m   \e[102m  \e[0m       \e[103m  \e[0m   \e[104m  \e[0m  \e[104m  \e[0m   \e[105m  \e[0m   \e[106m  \e[0m    ");
  printf("\n\t     \e[101m  \e[0m   \e[102m    \e[0m     \e[103m  \e[0m   \e[104m      \e[0m   \e[105m  \e[0m   \e[106m      \e[0m");
  printf("\n\t     \e[101m  \e[0m   \e[102m  \e[0m       \e[103m  \e[0m   \e[104m  \e[0m \e[104m  \e[0m    \e[105m  \e[0m       \e[106m  \e[0m");
  printf("\n\t     \e[101m  \e[0m   \e[102m      \e[0m   \e[103m  \e[0m   \e[104m  \e[0m  \e[104m  \e[0m \e[105m      \e[0m \e[106m      \e[0m");
  printf("\e[0m");
}




/*************************************************************************************************************************************************************
Para los colores ponemos \e[XXm ,si sustituis XX por los números salen los siguientes colores:

->90: gris oscuro
->91: rojo claro
->92: verde claro
->93: amarillo
->94: azul claro
->95: púrpura claro
->96: turquesa
->100: fondo gris oscuro
->101: fondo rojo claro
->102: fondo verde claro
->103: fondo amarillo
->104: fondo azul claro
->105: fondo púrpura claro
->106: fondo turquesa

Yo prefiero dejar el fondo como viene.
*/


void fin_de_juego(int*lineas)
{
  system("clear");
  printf("\n\n\t\tHas perdido, has realizado %d líneas\n\n\n",*lineas);
  printf("\t\t\e[100m     \e[0m  \e[101m     \e[0m  \e[102m \e[0m   \e[102m \e[0m  \e[103m     \e[0m     \e[104m     \e[0m  \e[105m \e[0m   \e[105m \e[0m   \e[106m     \e[0m  \e[107m     \e[0m\n");
  printf("\t\t\e[100m \e[0m      \e[101m \e[0m   \e[101m \e[0m  \e[102m  \e[0m \e[102m  \e[0m  \e[103m \e[0m         \e[104m \e[0m   \e[104m \e[0m  \e[105m \e[0m   \e[105m \e[0m   \e[106m \e[0m      \e[107m \e[0m   \e[107m \e[0m\n");
  printf("\t\t\e[100m \e[0m  \e[100m  \e[0m  \e[101m     \e[0m  \e[102m \e[0m \e[102m \e[0m \e[102m \e[0m  \e[103m   \e[0m       \e[104m \e[0m   \e[104m \e[0m   \e[105m \e[0m \e[105m \e[0m    \e[106m   \e[0m    \e[107m     \e[0m\n");
  printf("\t\t\e[100m \e[0m   \e[100m \e[0m  \e[101m \e[0m   \e[101m \e[0m  \e[102m \e[0m   \e[102m \e[0m  \e[103m \e[0m         \e[104m \e[0m   \e[104m \e[0m   \e[105m \e[0m \e[105m \e[0m    \e[106m \e[0m      \e[107m \e[0m  \e[107m \e[0m \n");
  printf("\t\t\e[100m     \e[0m  \e[101m \e[0m   \e[101m \e[0m  \e[102m \e[0m   \e[102m \e[0m  \e[103m     \e[0m     \e[104m     \e[0m    \e[105m \e[0m     \e[106m     \e[0m  \e[107m \e[0m   \e[107m \e[0m\n");
  printf("\n\t\tPara volver al menú pulse enter");
  getchar();
  getchar();
  if(1)
    menu1(lineas);
}
