#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Prototipos funcs. ppales.
void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);
void ver_prestamos_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);
void consultar_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5]);
void estadisticas(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5]);
void mostrar_ranking_utilizacion(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5]);

//Prototipos funcs. auxiliares.
bool repetido(char codigo[8], char Codigos_kits[][8]);
bool es_numerico(char string[]);
void ordenar_mayor_menor(int arreglo_determinante[], char segundo_criterio[][8], int arreglo_determinado[],int tamano_arreglo);

	//Funcion para DEBUG. Creada por IA. https://share.gemini.google/GieD2gmICYnd
	void cargar_datos_debug(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);

//Declaración de variable global recurrente
char dias_semana[5][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};

int main ()
{
	//Opción menú ppal.
	int op;

	// Datos Kits
	char Nombres_kits[10][30]= {NULL};
	char Codigos_kits[10][8]= {NULL};
	int Unidades_kits[10]= {NULL};
	int Prestados_kits[10][5]= {NULL};
	
	cargar_datos_debug(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
	
	while (op != 5)
	{
		printf("\n----------------------------------------------\n");
		printf("Elija que desea hacer:\n1-Cargar datos\n2-Ver prestamos y disponibilidad\n3-Ver disponibilidad de un kit\n4-Ver estadisticas\n5-Ver Ranking Utilizacion\n");

		scanf("%d", &op);
		
		

		switch(op)
		{
			case 1: //Carga de datos
			
				printf("\n----------------CARGA DE DATOS----------------\n");
				
				printf("\n-DEBUG: CASE 1\n");
			
				cargar_datos(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
			
				break;
			
			case 2: //Ver prestamos y disponibilidad
				
				printf("\n-----------PRESTAMOS-DISPONIBILIDAD-----------\n");
			
				ver_prestamos_disponibilidad(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
				
				break;
			
			case 3: //Ver disponibilidad de un kit
				
				printf("\n----------CONSULTA DE DISPONIBILIDAD----------\n");
				
				consultar_disponibilidad(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
				
				break;
			
			case 4: //Ver estadísticas
				
				printf("\n-----------------ESTADISTICAS-----------------\n");
			
				estadisticas(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
				
				break;
				
			case 5: //Salir del programa
				printf("\n--------------RANKING UTILIZACION--------------\n");
			
				mostrar_ranking_utilizacion(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
				
			break;
				
			case 6: //Salir del programa
				
				break;
		
		}
	}	 
		
	return 0;
}

void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char nombre_auxiliar[30];
	
	//Variables intermediarias que permiten "arrepentirse" se hacer una carga de datos y conservar el vlaor anterior.
	char codigo_intermedio[8];
	char nombre_intermedio[30];
	int unidades_intermedio;
	int prestados_intermedio;
	
	char op;
	
	printf("\n-DEBUG: CARGAR_DATOS\n");
	
	printf("Ingrese los datos que se le soliciten. Presione enter si prefiere no modificar un dato");
	
	for(int i=0; i<10; i++)
	{
		if(Codigos_kits[i] == NULL);
		
		int num_kit = i+1;
		
		printf("\n--------------------KIT %d--------------------\n", num_kit);
		
		//Ingreso CÓDIGO
		printf("\nIngrese el codigo del kit %d (Max. 8 digitos numericos): ", num_kit);
		scanf("%s", codigo_intermedio);
		
		while (strlen(codigo_intermedio)>8 || es_numerico(codigo_intermedio)==false || repetido(codigo_intermedio, Codigos_kits)==true)
		{
			printf("ERROR: Ingrese un codigo valido de entre 1 y 8 digitos numéricos sin repetirse con otro kit: ");
			scanf("%s", codigo_intermedio);
		}

		//Verificar si hay valores anteriores y guardar (o no)
		if(Codigos_kits[i][0] == '\0')
		{
			strcpy(Codigos_kits[i], codigo_intermedio);
		}
		else if(Codigos_kits[i][0] != '\0')
		{
			printf("ADVERTENCIA: El kit %d ya tiene un código asignado (%s), desea sobre escribirlo? s/n ", num_kit, Codigos_kits[i]);
			
			do
			{
				scanf("%c", &op);
			}
			while(op != 's' && op != 'n');
			
			if(op=='s')
			{
				strcpy(Codigos_kits[i], codigo_intermedio);
			}
		}
		printf("-DEBUG: EL NÚMERO INGRESADO ES %s", Codigos_kits[i]);//DEBUG
		
		
		//Ingreso NOMBRE
		printf("\nIngrese el nombre del kit %d: ", num_kit);
		scanf("%c", &nombre_auxiliar);
		gets(nombre_intermedio);
		strncat(nombre_auxiliar, nombre_intermedio, 30);

		while (strlen(Nombres_kits[i])>30)
		{
			printf("ERROR: Ingrese un nombre valido de entre 1 y 30 caracteres alfanumericos: ");
			scanf("%c", &nombre_auxiliar);
			gets(nombre_intermedio);
			strncat(nombre_auxiliar, nombre_intermedio, 30);	
		}
		
		//Verificar si hay valores anteriores y guardar (o no)
		if(Nombres_kits[i][0] == '\0')
		{
			strcpy(Nombres_kits[i], nombre_intermedio);
		}
		else if(Nombres_kits[i][0] != '\0')
		{
			printf("ADVERTENCIA: El kit %d ya tiene un código asignado (%s), desea sobre escribirlo? s/n ", num_kit, Nombres_kits[i]);
			
			do
			{
				scanf("%c", &op);
			}
			while(op != 's' && op != 'n');
			
			if(op=='s')
			{
				strcpy(Nombres_kits[i], nombre_intermedio);
			}
		}
		printf("\n-DEBUG: NOMBRE INGRESADO ES %s", Nombres_kits[i]);//DEBUG
		
		
		//ingreso UNIDADES
		printf("\nIngrese las unidades totales del kit %d: ", num_kit);
		scanf("%d", &unidades_intermedio);
		
		while(unidades_intermedio<1||unidades_intermedio>20)
		{
			printf("ERROR: Ingrese una valor de unidades valida de entre 1 y 20: ");
			scanf("%d", &unidades_intermedio);
		}
		
		//Verificar si hay valores anteriores y guardar (o no)
		if(Unidades_kits[0] == '\0')
		{
			Unidades_kits[i] = unidades_intermedio;;
		}
		else if(Unidades_kits[0] != '\0')
		{
			printf("ADVERTENCIA: El kit %d ya tiene unidades asignadas (%d), desea sobre escribirlo? s/n ", num_kit, Unidades_kits[i]);
			
			do
			{
				scanf("%c", &op);
			}
			while(op != 's' && op != 'n');
			
			if(op=='s')
			{
				Unidades_kits[i] = unidades_intermedio;
			}
		}		
		printf("\n-DEBUG: UNIDADES INGRESADAS ES %d", Unidades_kits[i]);//DEBUG
		
		
		//Ingreso PRESTAMOS
		printf("\nA continuacion, ingresara las unidades prestadas del kit %d para cada dia de la semana", num_kit);
		
		for(int j=0; j<5; j++)
		{
			printf("\n%s: ", dias_semana[j]);
			scanf("%d", &prestados_intermedio);
			
			while (prestados_intermedio>prestados_intermedio)
			{
				printf("ERROR: Ingrese una valor de unidades prestadas valida de entre 1 y %d: ", Unidades_kits[i]);
				scanf("%d", &prestados_intermedio);
			}
			
			//Verificar si hay valores anteriores y guardar (o no)
			if(Prestados_kits[i][j] == '\0')
			{
				Prestados_kits[i][j] = prestados_intermedio;;
			}
			else if(Prestados_kits[i][j] != '\0')
			{
				printf("ADVERTENCIA: El kit %d ya tiene prestamos asignados para el día %s (%d), desea sobre escribirlo? s/n ", num_kit, dias_semana[j], Prestados_kits[i][j]);
				
				do
				{
					scanf("%c", &op);
				}
				while(op != 's' && op != 'n');
				
				if(op=='s')
				{
					Prestados_kits[i][j] = prestados_intermedio;
				}
			}					
			printf("\n-DEBUG: UNIDADES PRESTADAS INGRESADAS %s ES %d", dias_semana[j], Prestados_kits[i][j]);//DEBUG
			
			
		}
		
	}
	

}

void ver_prestamos_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	
	for(int i=0; i<10; i++)
	{
		int num_kit = i+1;
		printf("\n--------------------KIT %d--------------------\n", num_kit);
		printf("Nombre: %s    Codigo: %s \n\n",Nombres_kits[i], Codigos_kits[i]);
		printf("Disponibilidad:\n\n");
		printf("Unidades totales: %d\n\n", Unidades_kits[i]);
		for(int j=0;j<5;j++)
		{
			printf("%s:  Prestamos: %d    Disponibilidad: %d\n", dias_semana[j], Prestados_kits[i][j], (Unidades_kits[i]-Prestados_kits[i][j]));
		}
	}
}

void consultar_disponibilidad(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char codigo[8];
	int dia;
	
	bool encontrado = false;
	int ubicacion;
	
	
	printf("Ingrese el codigo del kit que desea consultar: ");
	scanf("%s", &codigo);
	

	for(int i=0;i<10;i++)
	{		
		if(strcmp(Codigos_kits[i], codigo)==0)
		{
			ubicacion=i;
			i=10;
			encontrado=true;
		}
	}
	if(encontrado==false)
	{
		printf("No se encontró un kit con ese codigo, asegurese de que sea correcto.\n");
	}
	
	printf("Ingrese el día de la semana que quiere consultar:\n1-Lunes\n2-Martes\n3-Miercoles\n4-Jueves\n5-Viernes\n");
	scanf("%d", &dia);
	dia==dia-1;
	
	printf("\nNombre: %s    Codigo: %s \n\n",Nombres_kits[ubicacion], Codigos_kits[ubicacion]);
	printf("Unidades totales: %d\n\n", Unidades_kits[ubicacion]);
	printf("Prestamos: %d    Disponibilidad: %d\n", Prestados_kits[ubicacion][dia], (Unidades_kits[ubicacion]-Prestados_kits[ubicacion][dia]));
	
	printf("\n-DEBUG: ubicacion= %d\n", ubicacion);printf("\n-DEBUG: dia= %d\n", dia);
	
	
}

void estadisticas(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	int Prestamo_semanal[10];
	int Utilizacion_semanal[10];
	int Prestamos_mayor_menor[10][5];
	int Prestamo_diario[5];
	int Prestamos_diario_registro_cambio_orden[5]={0,1,2,3,4};
	

	//Preparación de variables/cálcullo de estadísitcas.
	for(int i=0;i<10;i++)
	{
		Prestamo_semanal[i]=Prestados_kits[i][0]+Prestados_kits[i][1]+Prestados_kits[i][2]+Prestados_kits[i][3]+Prestados_kits[i][4];
	}
	for(int i=0;i<10;i++)
	{
		Utilizacion_semanal[i]=(Prestamo_semanal[i]*100)/(Unidades_kits[i]*5);
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0; j<10; j++)
		{
			Prestamos_mayor_menor[i][j] = Prestados_kits[i][j];
		}
	}
	for(int i=0;i<5;i++)
	{
		Prestamo_diario[i]=Prestados_kits[0][i]+Prestados_kits[1][i]+Prestados_kits[2][i]+Prestados_kits[3][i]+Prestados_kits[4][i];
	}
	for(int i=0;i<5;i++)
	{
		ordenar_mayor_menor(Prestamo_diario, NULL, Prestamos_diario_registro_cambio_orden, 5);
	}
	for(int i=0;i<10;i++)
	{
		ordenar_mayor_menor(Prestamos_mayor_menor[i], NULL, NULL, 10);
	}
		
	
	printf("\n----------------------------------------------\n");
	
	printf("\n-----------Total Prestamos Semanales-----------\n");
	for(int i=0;i<10;i++)
	{
		printf("Cod: %s, Nombre: %s     Prestamos semanales: %d\n", Codigos_kits[i], Nombres_kits[i], Prestamo_semanal[i]);
	}
	
	printf("\n--------------Utilizacion Semanal--------------\n");
	for(int i=0;i<10;i++)
	{
		printf("Cod: %s, Nombre: %s     Utilizacion: %d%\n", Codigos_kits[i], Nombres_kits[i], Utilizacion_semanal[i]);
	}
	
	printf("\n---------------Mayor uso Semanal---------------\n");
	for(int i=0;i<10;i++)
	{
		printf("Cod: %s, Nombre: %s     Mayor uso: %d\n", Codigos_kits[i], Nombres_kits[i], Prestamos_mayor_menor[i][0]);
	}
	
	printf("\n---------------Menor uso Semanal---------------\n");
	for(int i=0;i<10;i++)
	{
		printf("Cod: %s, Nombre: %s     Menor uso: %d\n", Codigos_kits[i], Nombres_kits[i], Prestamos_mayor_menor[i][4]);
	}
	
	printf("\n---------Dias con mas prestamos totales---------\n");
	
		printf("1- %s: %d\n", dias_semana[Prestamos_diario_registro_cambio_orden[0]], Prestamo_diario[Prestamos_diario_registro_cambio_orden[0]]);
		printf("2- %s: %d\n", dias_semana[Prestamos_diario_registro_cambio_orden[1]], Prestamo_diario[Prestamos_diario_registro_cambio_orden[1]]);
		printf("3- %s: %d\n", dias_semana[Prestamos_diario_registro_cambio_orden[2]], Prestamo_diario[Prestamos_diario_registro_cambio_orden[2]]);
}

void mostrar_ranking_utilizacion(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	int Prestamo_semanal[10];
	int Utilizacion_semanal[10];
	int registro_de_cambio[10]={0,1,2,3,4,5,6,7,8,9};
	
	//Preparación de variables/cálcullo de estadísitcas.
	for(int i=0;i<10;i++)
	{
		Prestamo_semanal[i]=Prestados_kits[i][0]+Prestados_kits[i][1]+Prestados_kits[i][2]+Prestados_kits[i][3]+Prestados_kits[i][4];
	}
	for(int i=0;i<10;i++)
	{
		Utilizacion_semanal[i]=(Prestamo_semanal[i]*100)/(Unidades_kits[i]*5);
	}
	for(int i=0;i<10;i++)
	{
		ordenar_mayor_menor(Utilizacion_semanal, Codigos_kits, registro_de_cambio,10);
	}	
	
	for(int i=0;i<10;i++)
	{
		printf("Cod: %s, Nombre: %s     Total prestamos: %d  Porcentaje de utilizacion: %d%\n", Codigos_kits[registro_de_cambio[i]], Nombres_kits[registro_de_cambio[i]], Prestamo_semanal[registro_de_cambio[i]], Utilizacion_semanal[i]);
	}
}

//-----------FUNCIONES AUXILIARES--------------------------------
bool repetido(char codigo[8], char Codigos_kits[][8])
{
	bool result=false;
	
	for(int i=0;i<10;i++)
	{
		if(strcmp(Codigos_kits[i], codigo)==0)
		{
			result = true;
		}
	}
	
	return result;
}
	

bool es_numerico(char string[8])
{
	int verificados = 0;
	bool veredicto;
	
	for (int i=0; i<strlen(string);i++)
	{
		if (isdigit(string[i]))
		{
			verificados++;
		}
	}
	if(verificados==strlen(string))
	{
		veredicto=true;
	}
	else
	{
		veredicto=false;
	}
	
	return veredicto;
}

void ordenar_mayor_menor(int arreglo_determinante[], char segundo_criterio[][8], int arreglo_determinado[],int tamano_arreglo)
{
	
	int a;
	int b;
	
	char c[8];
	char d[8];
	
	bool existe_arreglo_determinado=false;
	bool existe_segundo_criterio=false;
	
	bool terminado;
	
	if (arreglo_determinado!=NULL)
	{
		existe_arreglo_determinado=true;
	}
	if(segundo_criterio!=NULL)
	{
		existe_segundo_criterio=true;
	}
	
	do
	{
		terminado = true;
		
		for(int i=0; i<tamano_arreglo-1;i++)
		{
			
			if (arreglo_determinante[i]<arreglo_determinante[i+1])
			{
				a = arreglo_determinante[i];
				b = arreglo_determinante[i+1];
				arreglo_determinante[i+1] = a;
				arreglo_determinante[i] = b;
				
				terminado = false;
				
				if (existe_arreglo_determinado)
				{
					a = arreglo_determinado[i];
					b = arreglo_determinado[i+1];
					arreglo_determinado[i+1] = a;
					arreglo_determinado[i] = b;
				}
			}
			else if(existe_segundo_criterio && arreglo_determinante[i]==arreglo_determinante[i+1])
			{
				if(strcmp(segundo_criterio[i], segundo_criterio[i+1])>0)
				{
					strcpy(c, segundo_criterio[i]);
					strcpy(d, segundo_criterio[i+1]);
					strcpy(segundo_criterio[i+1], c);
					strcpy(segundo_criterio[i], d);
					
					terminado = false;
					
					if (existe_arreglo_determinado)
					{
						a = arreglo_determinado[i];
						b = arreglo_determinado[i+1];
						arreglo_determinado[i+1] = a;
						arreglo_determinado[i] = b;
					}
				}
			}
		}
	}
	while(terminado == false);
}
//FUNCION PARA CARGAR DATOS DE PRUEBA A PARTIR DE UN .TX. CREADA POR IA SEGÚN SE INDICA EN EL INFORME.
// https://share.gemini.google/Cnf5ArymnMCT
void cargar_datos_debug(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5])
{
	FILE *archivo = fopen("variables_debug.txt", "r");
	
	if (archivo == NULL)
	{
		printf("\n-ERROR DEBUG: No se pudo abrir 'variables_debug.txt'.\n");
		return;
	}
	
	int i = 0;
	while (i < 10 && fscanf(archivo, " %7[^;];%29[^;];%d;%d;%d;%d;%d;%d",
							Codigos_kits[i],
							Nombres_kits[i],
							&Unidades_kits[i],
							&Prestados_kits[i][0],
								&Prestados_kits[i][1],
									&Prestados_kits[i][2],
										&Prestados_kits[i][3],
											&Prestados_kits[i][4]) == 8)
	{
		i++;
	}
	
	fclose(archivo);
	printf("\n-DEBUG: Se cargaron %d kits desde 'variables_debug.txt'.\n", i);
}



