#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct fecha{
	int dia,mes,anio;
};

struct turnos{
	fecha fec;
	int dni;
	char detalles[380],nombrecli[30],domicilio[50];
};

struct usuario{
	char usuario[10];
	char contrasenia[32];
};


struct historialTra{
	char atencion[25],apeyNom[30],paciente[30];
	int dniCli,dniPro;
	fecha fec;
};

struct clientes{
	char domicilio[50],apeyNom[30];
	int dni;
	float peso;
	fecha fec;
};

struct profesional{
	char apenom[60];
	int idprofesional;
	int dni;
	char telefono[25];
	usuario us;
	int contador;
};

struct usuarioRecepcionista{
	char usuario2[10];
	char contrasenia2[10];
};