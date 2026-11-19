#include <stdio.h>
#include <string.h>

//Prototipos
void cargar_datos(int Codigos_kits[], char Nombres_kits[][30], int Unidades_kits[], int Prestados_kits[][5]);

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
	int Codigos_kits[10];
	int Unidades_kits[10];
	int Prestados_kits[10][5];
	
	while (op != 5)
	{
		printf("Elija que desea hacer:\n1-Cargar datos\n2-Ver prestamos y disponibilidad\n3-Ver disponibilidad de un kit\n4-Ver estadisticas\n");
		
		scanf("%d", &op);

		switch(op)
		{
			case 1: //Carga de datos
				
				printf("\nDEBUG: CASE 1\n");
			
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

void cargar_datos(int Codigos_kits[], char Nombres_kits[][30],int Unidades_kits[], int Prestados_kits[][5])
{
	char dias_semana[5][10]={"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};
	
	printf("\nDEBUG: CARGAR_DATOS\n");
	
	for(int i=0; i<9; i++)
	{
		int num_kit = i+1;
		printf("\n--------------------KIT %d--------------------\n", i+1);
		
		printf("\nIngrese el codigo del kit %d: ", num_kit);
		scanf("%d", &Codigos_kits[i]);
		
		printf("\nIngrese el nombre del kit %d: ", num_kit);
		scanf("%c", Nombres_kits[i]);
		gets(Nombres_kits[i]);
			
		printf("\nIngrese las unidades totales del kit %d: ", num_kit);
		scanf("%d", &Unidades_kits[i]);
			
		printf("\nA continuacion, ingresara las unidades prestadas del kit %d para cada dia de la semana", num_kit);
		
		for(int j=0; j<4; j++)
		{
			printf("\n%s: ", dias_semana[j]);
			scanf("%d", &Prestados_kits[i][j]);
		}
		
	}
	

}


