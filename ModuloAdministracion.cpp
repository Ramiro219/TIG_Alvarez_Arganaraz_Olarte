#include"estructuras.h"

void registrarprof(FILE *archProfesional, profesional reg);
void registrarRecep(FILE *archRecepcionista, usuarioRecepcionista reg2);
void histori(FILE *historial, historialTra reg3);
void bono(FILE *archProfesional, profesional reg);

main(){
	int opcion;
	profesional reg;
	usuarioRecepcionista reg2;
	historialTra reg3;
	
	FILE *archProfesional;
	FILE *archRecepcionista;
	FILE *historial;
		
	do{
		system("cls");

		printf("    Modulos Administracion\n");
		printf("===============================\n");
		printf("1.- Registrar Profesional\n");
		printf("2.- Registrar Usuario Recepcionista\n");
		printf("3.- Atenciones por Profesional\n");
		printf("4.- Ranking de Profesionales por Atenciones\n");
		printf("5.- Cerrar aplicacion\n\n");
		
		printf("Ingrese una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:{
				system("cls");
				archProfesional = fopen("Profesionales.dat","a+b");
	            if(archProfesional==NULL){
		            system("cls");
	                printf("Ocurrio un error en la apertura del archivo");
		            return 1;
	            }
				
				registrarprof(archProfesional,reg);
				
				system("pause");		
				break;
			}
			case 2:{
				system("cls");
				archRecepcionista = fopen("Recepcionistas.dat","w+b");
	            if(archRecepcionista==NULL){
		            system("cls");
		            printf("Ocurrio un error en la apertura del archivo");
		            return 1;
                }
	
				registrarRecep(archRecepcionista,reg2);
				
				system("pause");				
				break;
			}
			case 3:{
				system("cls");
				
				histori(historial,reg3);
				
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				
				bono(archProfesional,reg);
				
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

void registrarprof(FILE *archProfesional, profesional reg){
	char usu[10],usu1[10],contra[32],contra1[32], continuar;
	int mayus=0,numero=0,largo=0,signo=0,i,min=0,consecutivo=0, digitos=0;
	
	archProfesional=fopen("Profesionales.dat","a+b");
	
	do
	{
		mayus=0;
		numero=0;
		largo=0;
		signo=0;
		min=0;
		consecutivo=0; 
		digitos=0;
		system("cls");
		printf("Ingrese el nombre de usuario: ");
		_flushall();
		gets(reg.us.usuario);
		
		
		largo=strlen(reg.us.usuario);
		
		strcpy(usu1,reg.us.usuario);
		strcpy(usu,reg.us.usuario);
		strupr(usu);
		
		for(i=0; i<largo; i++){
		   if(usu1[i]== usu[i]){
			mayus++;					
		}
		  if(usu1[i] == ' ' || usu1[i] ==',' || usu1[i]==';'|| usu1[i] =='.'|| usu1[i]==':'|| usu1[i]=='!'|| usu1[i]=='¡'|| usu1[i]=='¿'|| usu1[i]=='?'){
			signo++;
		  }			
		  	  
		  if(isdigit(usu1[i])){
			numero++;
		  }
	    }
	    digitos=signo+numero;
	    mayus=mayus-numero-signo;
					
		if(usu1[0]==usu[0] || mayus<2 || digitos>3 || largo<6 || largo>10){			
			while(usu1[0]==usu[0] || mayus<2 || digitos>3 || largo<6 || largo>10){
				printf("Usuario incorrecto\n");
				mayus=0;
				numero=0;
				printf("Ingrese el nombre de usuario: ");
		        _flushall();
		        gets(reg.us.usuario);
		
		
		        largo=strlen(reg.us.usuario);
		
		        strcpy(usu1,reg.us.usuario);
		        strcpy(usu,reg.us.usuario);
		        strupr(usu);
		
		        for(i=0; i<largo; i++){
		            if(usu1[i]== usu[i]){
			            mayus++;					
		            }
		            if(usu1[i] == ' ' || usu1[i] ==',' || usu1[i]==';'|| usu1[i] =='.'|| usu1[i]==':'|| usu1[i]=='!'|| usu1[i]=='¡'|| usu1[i]=='¿'|| usu1[i]=='?'){
			            signo++;
		            }	
		            
		            if(isdigit(usu1[i])){
			           numero++;
		            }
	            }  
				mayus=mayus-numero-signo; 				  	
			}
		}
	    
	    system("pause");
		system("cls");
	    
		printf("Ingrese la contrasenia: ");
		_flushall();
		gets(reg.us.contrasenia);
		
		mayus=0;
		numero=0;
		largo=0;
		signo=0;
		min=0;
		consecutivo=0; 
		digitos=0;
		
		largo=strlen(reg.us.contrasenia);
		
		strcpy(contra1,reg.us.contrasenia);
		strcpy(contra,reg.us.contrasenia);
		strupr(contra);
		
		for(i=0; i<largo; i++){
		    if(contra1[i]== contra[i]){
			    mayus++;					
		    }
		    if(contra1[i] == ' ' || contra1[i] ==',' || contra1[i]==';'|| contra1[i] =='.'|| contra1[i]==':'|| contra1[i]=='!'|| contra1[i]=='¡'|| contra1[i]=='¿'|| contra1[i]=='?'){
			    signo++;
		    }
			if(isdigit(contra1[i])){
			    numero++;
		    }
			if(contra1[i] == contra1[i+1] and contra1[i+1] == contra1[i+2]){
				consecutivo++;
			}	
				 		
		}
		min=largo-mayus;
		mayus=mayus-numero-signo;
		
		if(mayus<1 || min<1 || numero<1 || signo>0 || largo<6 || largo>32 || consecutivo>3){			
			while(mayus<1 || min<1 || numero<1 || signo>0 || largo<6 || largo>32 || consecutivo>3){
				printf("Contrasenia incorrecta\n");
				mayus=0;
				numero=0;
				printf("Ingrese la contrasenia: ");
		        _flushall();
		        gets(reg.us.contrasenia);
		
		        largo=strlen(reg.us.contrasenia);
		
		        strcpy(contra1,reg.us.contrasenia);
		        strcpy(contra,reg.us.contrasenia);
		        strupr(contra);
		
		        for(i=0; i<largo; i++){
		            if(contra1[i]== contra[i]){
			            mayus++;					
		            }
		            if(contra1[i] == ' ' || contra1[i] ==',' || contra1[i]==';'|| contra1[i] =='.'|| contra1[i]==':'|| contra1[i]=='!'|| contra1[i]=='¡'|| contra1[i]=='¿'|| contra1[i]=='?'){
			            signo++;
		            }
			        if(isdigit(contra1[i])){
			            numero++;
		            }
					if(contra1[i] == isdigit(contra1[i+1])){
						if(contra1[i+1] == isdigit(contra1[i+2]))
						consecutivo++;
					}	
		        }
	            min=largo-mayus;
				mayus=mayus-numero-signo; 
				printf("\nCONSE %d\n",consecutivo);
			}
			
		}
		
		system("pause");
		system("cls");
		
		printf("\nREGISTRO DE PROFESIONALES\n");
		printf("\n=========================\n");
		printf("\n\t Nombre de usuario: ");
		_flushall();
		puts(reg.us.usuario);
		printf("\n\t Contrasenia: ");
		_flushall();
		puts(reg.us.contrasenia);
		printf("\n\t Ingrese el ID del profesional: ");
		scanf("%d",&reg.idprofesional);
		printf("\n\t Ingrese el Apellido y nombre del profecional: ");
		_flushall();
		gets(reg.apenom);
		printf("\n\t Ingrese el DNI del profesional: ");
		scanf("%d",&reg.dni);
		printf("\n\t Ingrese el Telefono del profesional: ");
		_flushall();
		gets(reg.telefono);
				
		fwrite(&reg,sizeof(profesional),1,archProfesional);
		
		printf("\n\n¿Quiere continuar ingresando profesionales? (S/N): ");
		_flushall();
		scanf("%c",&continuar);
				
	}while(continuar == 's' || continuar == 'S');
	
	fclose(archProfesional);
}

void registrarRecep(FILE *archRecepcionista, usuarioRecepcionista reg2){
	char usu[10],usu1[10],contra[32],contra1[32], continuar;
	int mayus=0,numero=0,largo=0,signo=0,i,min=0,consecutivo=0, digitos=0;
	
	archRecepcionista=fopen("Recepcionistas.dat","a+b");
	
	do
	{
		mayus=0;
		numero=0;
		largo=0;
		signo=0;
		min=0;
		consecutivo=0; 
		digitos=0;
		system("cls");
		printf("Ingrese el nombre de usuario: ");
		_flushall();
		gets(reg2.usuario2);
		
		
		largo=strlen(reg2.usuario2);
		
		strcpy(usu1,reg2.usuario2);
		strcpy(usu,reg2.usuario2);
		strupr(usu);
		
		for(i=0; i<largo; i++){
		   if(usu1[i]== usu[i]){
			mayus++;					
		}
		  if(usu1[i] == ' ' || usu1[i] ==',' || usu1[i]==';'|| usu1[i] =='.'|| usu1[i]==':'|| usu1[i]=='!'|| usu1[i]=='¡'|| usu1[i]=='¿'|| usu1[i]=='?'){
			signo++;
		  }			
		  	  
		  if(isdigit(usu1[i])){
			numero++;
		  }
	    }
	    digitos=signo+numero;
	    mayus=mayus-numero-signo;
					
		if(usu1[0]==usu[0] || mayus<2 || digitos>3 || largo<6 || largo>10){			
			while(usu1[0]==usu[0] || mayus<2 || digitos>3 || largo<6 || largo>10){
				printf("Usuario incorrecto\n");
				mayus=0;
				numero=0;
				printf("Ingrese el nombre de usuario: ");
		        _flushall();
		        gets(reg2.usuario2);
		
		
		        largo=strlen(reg2.usuario2);
		
		        strcpy(usu1,reg2.usuario2);
		        strcpy(usu,reg2.usuario2);
		        strupr(usu);
		
		        for(i=0; i<largo; i++){
		            if(usu1[i]== usu[i]){
			            mayus++;					
		            }
		            if(usu1[i] == ' ' || usu1[i] ==',' || usu1[i]==';'|| usu1[i] =='.'|| usu1[i]==':'|| usu1[i]=='!'|| usu1[i]=='¡'|| usu1[i]=='¿'|| usu1[i]=='?'){
			            signo++;
		            }	
		            
		            if(isdigit(usu1[i])){
			           numero++;
		            }
	            }  
				mayus=mayus-numero-signo; 				  	
			}
		}
	    
	    system("pause");
		system("cls");
	    
		printf("Ingrese la contrasenia: ");
		_flushall();
		gets(reg2.contrasenia2);
		
		mayus=0;
		numero=0;
		largo=0;
		signo=0;
		min=0;
		consecutivo=0; 
		digitos=0;
		
		largo=strlen(reg2.contrasenia2);
		
		strcpy(contra1,reg2.contrasenia2);
		strcpy(contra,reg2.contrasenia2);
		strupr(contra);
		
		for(i=0; i<largo; i++){
		    if(contra1[i]== contra[i]){
			    mayus++;					
		    }
		    if(contra1[i] == ' ' || contra1[i] ==',' || contra1[i]==';'|| contra1[i] =='.'|| contra1[i]==':'|| contra1[i]=='!'|| contra1[i]=='¡'|| contra1[i]=='¿'|| contra1[i]=='?'){
			    signo++;
		    }
			if(isdigit(contra1[i])){
			    numero++;
		    }
			if(contra1[i] == contra1[i+1] and contra1[i+1] == contra1[i+2]){
				consecutivo++;
			}	
				 		
		}
		min=largo-mayus;
		mayus=mayus-numero-signo;
		
		if(mayus<1 || min<1 || numero<1 || signo>0 || largo<6 || largo>32 || consecutivo>3){			
			while(mayus<1 || min<1 || numero<1 || signo>0 || largo<6 || largo>32 || consecutivo>3){
				printf("Contrasenia incorrecta\n");
				mayus=0;
				numero=0;
				printf("Ingrese la contrasenia: ");
		        _flushall();
		        gets(reg2.contrasenia2);
		
		        largo=strlen(reg2.contrasenia2);
		
		        strcpy(contra1,reg2.contrasenia2);
		        strcpy(contra,reg2.contrasenia2);
		        strupr(contra);
		
		        for(i=0; i<largo; i++){
		            if(contra1[i]== contra[i]){
			            mayus++;					
		            }
		            if(contra1[i] == ' ' || contra1[i] ==',' || contra1[i]==';'|| contra1[i] =='.'|| contra1[i]==':'|| contra1[i]=='!'|| contra1[i]=='¡'|| contra1[i]=='¿'|| contra1[i]=='?'){
			            signo++;
		            }
			        if(isdigit(contra1[i])){
			            numero++;
		            }
					if(contra1[i] == isdigit(contra1[i+1])){
						if(contra1[i+1] == isdigit(contra1[i+2]))
						consecutivo++;
					}	
		        }
	            min=largo-mayus;
				mayus=mayus-numero-signo; 
				printf("\nCONSE %d\n",consecutivo);
			}
			
		}
		
		system("pause");
		system("cls");
		printf("\n\t Nombre de usuario: ");
		_flushall();
		puts(reg2.usuario2);
		printf("\n\t Contrasenia: ");
		_flushall();
		puts(reg2.contrasenia2);
		
		fwrite(&reg2,sizeof(usuarioRecepcionista),1,archRecepcionista);
				
		printf("\n\n¿Quiere continuar ingresando Recepcionista? (S/N): ");
		_flushall();
		scanf("%c",&continuar);
				
	}while(continuar == 's' || continuar == 'S');
	
	fclose(archRecepcionista);
}

void histori(FILE *historial, historialTra reg3){
	historial=fopen("historialTratamiento.dat","rb");
		
	fread(&reg3,sizeof(historialTra),1,historial);
		
	while(!feof(historial)){
		printf("Nombre del profesional: ");
		_flushall();
		puts(reg3.apeyNom);
		
		printf("DNI del profesional: %d\n",reg3.dniPro);
			
		printf("Nombre del cliente: ");
		_flushall();
		puts(reg3.paciente);
			
		printf("DNI del cliente: %d\n",reg3.dniCli);	
			
		printf("---------------\n");
		printf("FECHA DE ATENCION\n");
		printf("---------------\n\n");
			
		printf("%d/%d/%d\n",reg3.fec.dia,reg3.fec.mes,reg3.fec.anio);
			
		printf("Devolucion: ");
		_flushall();
		puts(reg3.atencion);
			
		printf("_________________________________\n");
			
		fread(&reg3,sizeof(historialTra),1,historial);
	}
				
		
}

void bono(FILE *archProfesional, profesional reg){
	int mayor=0;
	char nom[50];
	archProfesional=fopen("profesionales.dat","rb");
	
	fread(&reg,sizeof(profesional),1,archProfesional);
	
	while(!feof(archProfesional)){
		if(reg.contador > mayor){
			mayor=reg.contador;
			strcpy(nom,reg.apenom);
		}
		fread(&reg,sizeof(profesional),1,archProfesional);
	}
	
	fclose(archProfesional);
	
	printf("-----------------------------------------------\n");
	printf("El profesional que debe recibir el bono es: ");
	_flushall();
	puts(nom);
	printf("-----------------------------------------------\n");
	
}
