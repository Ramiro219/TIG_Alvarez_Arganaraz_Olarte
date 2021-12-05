#include"estructuras.h"

void altas(FILE *arch,usuarioRecepcionista reg1, bool &bol);
void registrar(FILE *regis,clientes reg2,bool bol);
void tur(FILE *turno,FILE *regis,clientes reg2,turnos reg3, bool bol);
void histori(FILE *historial, historialTra reg4,bool bol);

main(){
	int opcion;
	bool bol=false;
	FILE *arch,*regis,*turno, *historial;
	usuarioRecepcionista reg1;
	clientes reg2;
	turnos reg3;
	historialTra reg4;
	
	do{
		system("cls");

		printf("    Modulos del recepcionista\n");
		printf("=================================\n");
		printf("1.- Iniciar Sesion\n");
		printf("2.- Registrar Cliente\n");
		printf("3.- Registrar Turno\n");
		printf("4.- Listado de Atenciones por Profesional y Fecha\n");
		printf("5.- Cerrar aplicacion\n\n");
		
		printf("Ingrese una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:{
				system("cls");
				
				altas(arch,reg1,bol);
					
				system("pause");						
				break;
			}
			case 2:{
				system("cls");
				
				registrar(regis,reg2,bol);
				
				system("pause");				
				break;
			}
			case 3:{
				system("cls");
				
				tur(turno,regis,reg2,reg3,bol);
				
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				
				histori(historial,reg4,bol);
				
				system("pause");
				break;
			}
			case 5:{
				printf("\nAPLICACION CERRADA");
				break;
			}
			default:{
				printf("\nOpcion incoreccta\n");
				break;
			}			
		}
		
	}while(opcion != 5);
	
		
	printf("\n\n");
	system("pause");
}

void altas(FILE *arch,usuarioRecepcionista reg1, bool &bol){
	bol=false;
	char usuario[10],contrasena[32];
			
	printf("Ingrese el nombre de usuario: ");
	_flushall();
	gets(usuario);
			
	printf("Ingrese la contrasena: ");
	_flushall();
	gets(contrasena);
		
	arch=fopen("Recepcionistas.dat","rb");
	fread(&reg1,sizeof(usuarioRecepcionista),1,arch);
				
	while(!feof(arch)){
		if(strcmp(usuario,reg1.usuario2) == 0 and strcmp(contrasena,reg1.contrasenia2) == 0){
			bol = true;
		}	
		
		fread(&reg1,sizeof(usuarioRecepcionista),1,arch);
	}
	   	
	fclose(arch);
	
	if(bol == true){
		printf("\n  -------------------\n");
		printf("    SESION INICIADA\n");
		printf("  -------------------\n\n");
	}else{
		printf("\nEL NOMBRE DE USUARIO O CONTRASEÑA NO ESTAN REGISTRADOS\n\n");
	}
		
}

void registrar(FILE *regis,clientes reg2,bool bol){
	
	if(bol == true){
		regis=fopen("clientes.dat","ab");
	
	    printf("Nombre del cliente: ");
	    _flushall();
	    gets(reg2.apeyNom);
		
	    printf("Domicilio: ");
	    _flushall();
	    gets(reg2.domicilio);
		
	    printf("Numero de DNI: ");
	    scanf("%d",&reg2.dni);
		
	    printf("Peso: ");
	    scanf("%f",&reg2.peso);
		
	    printf("Fecha de nacimiento:\n");
		
	    printf("DIA: ");
	    scanf("%d",&reg2.fec.dia);
	    printf("MES: ");
	    scanf("%d",&reg2.fec.mes);
	    printf("ANIO: ");
	    scanf("%d",&reg2.fec.anio);
		
	    fwrite(&reg2,sizeof(clientes),1,regis);
				
	    fclose(regis);
	
	}else{
		printf("----------------------------------------------------\n");
		printf("SE DEBE INICIAR SESION PARA REGISTRAR UN CLIENTE\n");
		printf("----------------------------------------------------\n");
	}
	
}

void tur(FILE *turno,FILE *regis,clientes reg2,turnos reg3, bool bol){
	if(bol == true){	
	    turno=fopen("Turnos.dat","ab");
	    regis=fopen("clientes.dat","rb");
		
		printf("Nombre del cliente: ");
	    _flushall();
	    gets(reg3.nombrecli);
		
		fread(&reg2,sizeof(clientes),1,regis);
		while(!feof(regis)){
			if(strcmp(reg3.nombrecli,reg2.apeyNom) == 0){
				printf("-------------------------------------\n");
				printf("Numero de DNI del cliente: %d\n",reg2.dni);
		        reg3.dni =reg2.dni;
		        printf("Domicilio del cliente: ");
		        _flushall();
		        puts(reg2.domicilio);		        
		        strcpy(reg3.domicilio,reg2.domicilio);
		        printf("Peso del cliente: %2.f\n",reg2.peso);
		        printf("---------------------------------------\n");
			}
			fread(&reg2,sizeof(clientes),1,regis);		
		}
	   		
	    printf("Detalles de la atencion: ");
	    _flushall();
	    gets(reg3.detalles);
	    
		
	    printf("\nFecha de turno:\n");
		
	    printf("DIA: ");
	    scanf("%d",&reg3.fec.dia);
	    printf("MES: ");
	    scanf("%d",&reg3.fec.mes);
	    printf("ANIO: ");
	    scanf("%d",&reg3.fec.anio);
		
	    fwrite(&reg3,sizeof(turnos),1,turno);
		fclose(turno);						
	}else{
		printf("----------------------------------------------------\n");
		printf("SE DEBE INICIAR SESION PARA REGISTRAR UN TURNO\n");
		printf("----------------------------------------------------\n");
	}
	
}

void histori(FILE *historial, historialTra reg4,bool bol){
	if(bol == true){
		historial=fopen("historialTratamiento.dat","rb");
		
		fread(&reg4,sizeof(historialTra),1,historial);
		
		while(!feof(historial)){
			printf("Nombre del profesional: ");
			_flushall();
			puts(reg4.apeyNom);
			
			printf("Nombre del cliente: ");
			_flushall();
			puts(reg4.paciente);
			
			printf("---------------\n");
			printf("FECHA DE ATENCION\n");
			printf("---------------\n\n");
			
			printf("%d/%d/%d\n",reg4.fec.dia,reg4.fec.mes,reg4.fec.anio);
			
			printf("Devolucion: ");
			_flushall();
			puts(reg4.atencion);
			
			printf("________________________________________\n");
			
			fread(&reg4,sizeof(historialTra),1,historial);
		}
				
	}else{
		printf("----------------------------------------------------\n");
		printf("SE DEBE INICIAR SESION PARA VER EL LISTADO POR ATENCION\n");
		printf("----------------------------------------------------\n");
	}
		
}