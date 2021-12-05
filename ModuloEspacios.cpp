#include"estructuras.h"

void altas(FILE *arch,profesional reg1,bool &bol);
void listar(FILE *turno,turnos reg4, bool bol);
void atencion(FILE *arch,FILE *cliente,FILE *aux,FILE *aux1,FILE *historial,FILE *turnos1,clientes reg3,historialTra reg2,profesional reg1,bool bol,turnos reg4);
void contarAtenciones(FILE *historial, historialTra reg2,FILE *arch, profesional reg1);

main(){
	int opcion;
	historialTra reg2;
	profesional reg1;
	FILE *arch,*historial,*aux,*aux1,*cliente,*turno;
	clientes reg3;
	turnos reg4;
	bool bol=false;
	
	do{
		system("cls");

		printf("    Modulos Espacios\n");
		printf("============================\n");
		printf("1.- Iniciar Sesion\n");
		printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
		printf("3.- Registrar Evolucion del tratamiento\n");
		printf("4.- Cerrar la aplicacion.\n\n");
		
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
				
				listar(turno,reg4,bol);
				
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				
				atencion(arch,cliente,aux,aux1,historial,turno,reg3,reg2,reg1,bol,reg4);
				
				system("pause");
				break;
			}
			case 4:{
				printf("\nAPLICACION CERRADA");
				break;
			}
			default:{
				printf("\nOpcion incoreccta\n");
				break;
			}
			
		}
		
	}while(opcion != 4);
		
	printf("\n\n");
	system("pause");
}

void altas(FILE *arch,profesional reg1, bool &bol){
	bol=false;
	char usuario[10],contrasena[32];
			
	printf("Ingrese el nombre de usuario: ");
	_flushall();
	gets(usuario);
			
	printf("Ingrese la contrasena: ");
	_flushall();
	gets(contrasena);
		
	arch=fopen("Profesionales.dat","rb");
	fread(&reg1,sizeof(profesional),1,arch);
				
	while(!feof(arch)){
		if(strcmp(usuario,reg1.us.usuario) == 0 and strcmp(contrasena,reg1.us.contrasenia) == 0){
			bol = true;
		}	
		
		fread(&reg1,sizeof(profesional),1,arch);
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

void listar(FILE *turno,turnos reg4, bool bol){
	int edad=0;
	turno=fopen("Turnos.dat","rb");		
	if(bol == true){
		
		printf("  ------------------------------\n");
	    printf("    LISTA DE ESPERA DE TURNOS\n");
	    printf("  ------------------------------\n\n");
	
	    fread(&reg4,sizeof(turnos),1,turno);
				
		while(!feof(turno)){
			
		    printf("Apellido y nombre del cliente: %s\n",reg4.nombrecli);
		    printf("Numero de DNI del cliente: %d\n",reg4.dni);
		    printf("Domicilio del cliente: %s\n",reg4.domicilio);
		    printf("---------------------\n");
		    printf("FECHA DEL TURNO\n");
		    printf(".....................\n\n");
		    printf("%d/%d/%d\n\n",reg4.fec.dia,reg4.fec.mes,reg4.fec.anio);
		    printf("Detalles de la atencion: ");
		    _flushall();
		    puts(reg4.detalles);
		
		    printf("\n________________________________________\n\n");
		
		    fread(&reg4,sizeof(turnos),1,turno);
	    }
		fclose(turno);		
	}else{
		printf("----------------------------------------------------\n");
		printf("SE DEBE INICIAR SESION PARA VER LA LISTA DE TURNOS\n");
		printf("----------------------------------------------------\n");
	}	
	
}


void atencion(FILE *arch,FILE *cliente,FILE *aux,FILE *aux1,FILE *historial,FILE *turno,clientes reg3,historialTra reg2,profesional reg1,bool bol,turnos reg4){
	char apeNom[30];
	int b=0,band=0,edad;
	
	if(bol == true){
		printf("Ingrese el Apellido y Nombre del paciente a atender: ");
	    _flushall();
	    gets(apeNom);
	
	    cliente=fopen("clientes.dat","rb");
	
	    fread(&reg3,sizeof(clientes),1,cliente);
	
	    while(!feof(cliente)){
		    if(strcmp(apeNom,reg3.apeyNom) == 0){
			    printf("\nApellido y nombre del cliente: %s\n",reg3.apeyNom);
		        printf("Domicilio: %s",reg3.domicilio);
		        printf("\nNumero de DNI: %d",reg3.dni);
		        printf("\nPeso: %.2f",reg3.peso);
		        edad = 2021 - reg3.fec.anio;
		        printf("\nEdad: %d",edad);
		
		        printf("\n___________________________\n\n");		    
		    }
		    fread(&reg3,sizeof(clientes),1,cliente);
	    }
	    fclose(cliente);
	    turno=fopen("Turnos.dat","rb");
	    aux=fopen("secundario.dat","wb");	
	    cliente=fopen("clientes.dat","rb");
	    aux1=fopen("secundario1.dat","wb");
	
	    fread(&reg4,sizeof(turnos),1,turno);
	    fread(&reg3,sizeof(clientes),1,cliente);
	    
	    while(!feof(turno) and !feof(cliente)){
		    if(strcmp(apeNom,reg4.nombrecli) != 0){
			    fwrite(&reg4,sizeof(turnos),1,aux);	
				fwrite(&reg3,sizeof(clientes),1,aux1);			
		    }else{
			    b=1;			
		    }		
		    fread(&reg4,sizeof(turnos),1,turno);
			fread(&reg3,sizeof(clientes),1,cliente);		
	    }
	    fclose(turno);
	    fclose(aux);
	    fclose(cliente);
	    fclose(aux1);
			    	
	    historial=fopen("historialTratamiento.dat","a+b");
		arch=fopen("Profesionales.dat","rb");
			
	    printf("Nombre del profesional que atendio al cliente: ");
        _flushall();
	    gets(reg2.apeyNom);
	    
	    fread(&reg1,sizeof(profesional),1,arch);
		while(!feof(arch)){
			if(strcmp(reg2.apeyNom,reg1.apenom) == 0){
				printf("Numero de ID: %d\n",reg1.idprofesional);
	            printf("Numero de DNI: %d\n",reg1.dni);
	            reg2.dniCli=reg3.dni;
	            reg2.dniPro=reg1.dni;
			}
			fread(&reg1,sizeof(profesional),1,arch);		
		}
	    
	    printf("\nNombre del paciente: ");
	    _flushall();
	    puts(apeNom);
	    	    
	    strcpy(reg2.paciente,apeNom);
	        
	    printf("Ingrese la fecha de atencion:\n");
	    printf("DIA: ");
	    scanf("%d",&reg2.fec.dia);
	    printf("MES: ");
	    scanf("%d",&reg2.fec.mes);
	    printf("ANIO: ");
	    scanf("%d",&reg2.fec.anio);
	        
	    printf("Ingrese la evolucion del tratamiento: ");
	    _flushall();
	    gets(reg2.atencion);
	        
	    fwrite(&reg2,sizeof(historialTra),1,historial);
	
	    fclose(historial);
		fclose(arch);	
		
	    if(b==1){
		    printf("Cliente atendido\n");
		    remove("Turnos.dat");
		    rename("secundario.dat","Turnos.dat");
			remove("Clientes.dat");
		    rename("secundario1.dat","Clientes.dat");	    
	    }else{
	    	printf("Cliente no encontrado");
	    }
	}else{
		printf("--------------------------------------------------------------------\n");
		printf("SE DEBE INICIAR SESION PARA REGISTRAR LA DEVOLUCION DE TRATAMIENTO\n");
		printf("---------------------------------------------------------------------\n");
	}
	
}


void contarAtenciones(FILE *historial, historialTra reg2,FILE *arch, profesional reg1){	
	arch=fopen("Profesionales.dat","rb");
	historial=fopen("historialTratamiento.dat","rb");
	
	fread(&reg2,sizeof(historialTra),1,historial);
	fread(&reg1,sizeof(profesional),1,arch);
	
	reg1.contador=0;
	
	while(!feof(arch) and !feof(historial)){
		if(strcmp(reg2.apeyNom,reg1.apenom) == 0){
			reg1.contador++;
		}
		
		fread(&reg2,sizeof(historialTra),1,historial);
	   fread(&reg1,sizeof(profesional),1,arch);
			
	}
	
	fclose(arch);
	fclose(historial);
		
}