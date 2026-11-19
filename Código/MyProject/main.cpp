#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Prototipos
void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);
bool es_numerico(char string[]);

int main ()
{
	//Opción menú ppal.
	int op;
	
//	//Códigos kits
//	
//	int Cod_kit_1;
//	int Cod_kit_2;
//	int Cod_kit_3;	
//	int Cod_kit_4;
//	int Cod_kit_5;	
//	int Cod_kit_6;	
//	int Cod_kit_7;	
//	int Cod_kit_8;	
//	int Cod_kit_9;
//	int Cod_kit_10;
	
	
	
//	//Unidades kits
//	
//	int Unit_kit_1[];
//	int Unit_kit_2[20];
//	int Unit_kit_3[20];	
//	int Unit_kit_4[20];
//	int Unit_kit_5[20];	
//	int Unit_kit_6[20];	
//	int Unit_kit_7[20];	
//	int Unit_kit_8[20];	
//	int Unit_kit_9[20];
//	int Unit_kit_10[20];

	
	
//	//Unidades prestadas cada día de la semana.
//	
//	int Prest_kit_1[5];
//	int Prest_kit_2[5];
//	int Prest_kit_3[5];	
//	int Prest_kit_4[5];
//	int Prest_kit_5[5];	
//	int Prest_kit_6[5];	
//	int Prest_kit_7[5];	
//	int Prest_kit_8[5];	
//	int Prest_kit_9[5];
//	int Prest_kit_10[5];	
	
	
	// Datos Kits
	char Nombres_kits[10][30];
	char Codigos_kits[10][8];
	int Unidades_kits[10];
	int Prestados_kits[10][5];
	
	while (op != 5)
	{
		printf("Elija que desea hacer:\n1-Cargar datos\n2-Ver prestamos y disponibilidad\n3-Ver disponibilidad de un kit\n4-Ver estadisticas\n");
		
		scanf("%d", &op);

		switch(op)
		{
			case 1: //Carga de datos
				
				printf("\n-DEBUG: CASE 1\n");
			
				cargar_datos(Codigos_kits, Nombres_kits, Unidades_kits, Prestados_kits);
			
				break;
			
			case 2: //Ver prestamos y disponibilidad
			
				break;
			
			case 3: //Ver disponibilidad de un kit
			
				break;
			
			case 4: //Ver estadísticas
			
				break;
				
			case 5: //Salir
				
				break;
		
		}
	}	 
		
	return 0;
}

void cargar_datos(char Codigos_kits[][8], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char dias_semana[5][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};
	char nombre_auxiliar[30];
	
	printf("\n-DEBUG: CARGAR_DATOS\n");
	
	printf("Ingrese los datos que se le soliciten. Presione enter si prefiere no modificar un dato");
	
	for(int i=0; i<9; i++)
	{
		int num_kit = i+1;
		printf("\n--------------------KIT %d--------------------\n", i+1);
		
		//Ingreso CÓDIGO
		printf("\nIngrese el codigo del kit %d (Max. 8 digitos numericos): ", num_kit);
		scanf("%s", Codigos_kits[i]);
		
		while (strlen(Codigos_kits[i])>8 || es_numerico(Codigos_kits[i])==false)
		{
			printf("ERROR: Ingrese un codigo valido de entre 1 y 8 digitos numéricos: ");
			scanf("%s", Codigos_kits[i]);
		}
		printf("-DEBUG: EL NÚMERO INGRESADO ES %s", Codigos_kits[i]);//DEBUG
		
		
		//Ingreso NOMBRE
		printf("\nIngrese el nombre del kit %d: ", num_kit);
		scanf("%c", &nombre_auxiliar);
		gets(Nombres_kits[i]);
		strncat(nombre_auxiliar, Nombres_kits[i], 30);

		while (strlen(Nombres_kits[i])>30)
		{
			printf("ERROR: Ingrese un nombre valido de entre 1 y 30 caracteres alfanumericos: ");
			scanf("%c", &nombre_auxiliar);
			gets(Nombres_kits[i]);
			strncat(nombre_auxiliar, Nombres_kits[i], 30);	
		}
		printf("\n-DEBUG: NOMBRE INGRESADO ES %s", Nombres_kits[i]);//DEBUG
		
		
		//ingreso UNIDADES
		printf("\nIngrese las unidades totales del kit %d: ", num_kit);
		scanf("%d", &Unidades_kits[i]);
		
		while(Unidades_kits[i]<1||Unidades_kits[i]>20)
		{
			printf("ERROR: Ingrese una valor de unidades valida de entre 1 y 20: ");
			scanf("%d", &Unidades_kits[i]);
		}
		printf("\n-DEBUG: UNIDADES INGRESADAS ES %d", Unidades_kits[i]);//DEBUG
		
		
		//Ingreso PRESTAMOS
		printf("\nA continuacion, ingresara las unidades prestadas del kit %d para cada dia de la semana", num_kit);
		
		for(int j=0; j<4; j++)
		{
			printf("\n%s: ", dias_semana[j]);
			scanf("%d", &Prestados_kits[i][j]);
			
			while (Prestados_kits[i][j]>Unidades_kits[i])
			{
				printf("ERROR: Ingrese una valor de unidades prestadas valida de entre 1 y %d: ", Unidades_kits[i]);
				scanf("%d", &Prestados_kits[i][j]);
			}
			printf("\n-DEBUG: UNIDADES PRESTADAS INGRESADAS %s ES %d", dias_semana[j], Prestados_kits[i][j]);//DEBUG
		}
		
	}
	

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


