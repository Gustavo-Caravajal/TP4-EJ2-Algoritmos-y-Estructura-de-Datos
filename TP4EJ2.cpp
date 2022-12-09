//TP4 : ESQUELETO EJERCICIO 2
#include <iostream>
#include <cstring>
#define topeDato 20
#define topeEmpleados 20
#define meses 12
using namespace std;

struct empleado{
	int dni; 
	char apellido[topeDato];
	char nombre[topeDato];
};

struct costosManoObra{
	float horaFija;
	float horaExtra;
};

struct horasTrabajo{
	float horasFijasTrabajadas;
	float horasExtraTrabajadas;
	float sueldo;
};

void seleccion(char eleccion[]);
void ingresarMes(int& mesAingresar);
costosManoObra costoVacio();
costosManoObra ingresarCosto();
void inicializarCostosManoObra(costosManoObra costoXMeses[]);
void cargarCostosManoObra(costosManoObra costoXMeses[]);
void mostrarEmpleado(empleado empleado);
horasTrabajo horasVacias();
horasTrabajo ingresarHoras();
void inicializarHorasTrabajadas(horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]);
void cargarhorastrabajadas(empleado empleados[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]);
void mostrarHoras(horasTrabajo horas);
void calcularSueldo(horasTrabajo& horas,costosManoObra& costoXMes);
void listadoSueldosEmpleados(empleado empleados[],costosManoObra costoXMeses[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]);
void ingresarDni(int& dni);
void mostrarSueldoEspecifico(empleado empleados[],costosManoObra costoXMeses[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]);

int main()
{
	
	empleado empleados[topeEmpleados]={
	{25400998,"Perez","Natalia"}, 
	{26788100,"Torres","Claudio"},
	{27500123,"Rodriguez","Julieta"},
	{28300656,"Medrano","Juan Carlos"},
	{29700650,"Andrade","Mariana"},
	{30250400,"Gramajo","Joel"},
	{31625800,"Barraza","Macarena"},
	{32600300,"Dominguez","Leonel"},
	{33900433,"Di Santo","Nicole"},
	{34550766,"Alvarez","Nicolas"},
	{35120200,"Lopez","Mauro"},
	{36300554,"Esquivel","Maria Luz"},
	{37900788,"Compagnoni","Gonzalo"},
	{38200450,"Chavez","Maria del Pilar"},
	{39200788,"Juarez","Ignacio"},
	{40400560,"Fresta","Victoria"},
	{41350800,"Caceres","Emiliano"},
	{42880700,"Desimone","Antonella"},
	{43200767,"Bursese","Jonathan"},
	{44800950,"Pardo","Florencia"}
	};
	
	
	costosManoObra costoXMeses[meses];
	horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados];
	char eleccion[5];
	bool salir=false;
	
	inicializarCostosManoObra(costoXMeses);
	inicializarHorasTrabajadas(horasTrabajadasXEmpleados);
	
	do{
		seleccion(eleccion);
		switch(eleccion[0]){
			case 'A':
				cargarCostosManoObra(costoXMeses);
				cin.ignore();
				break;
			case 'B':
				cargarhorastrabajadas(empleados,horasTrabajadasXEmpleados);
				cin.ignore();
				cout<<endl;
				break;
			case 'C':
				listadoSueldosEmpleados(empleados,costoXMeses,horasTrabajadasXEmpleados);
				cout<<endl;
				break;
			case 'D':
				mostrarSueldoEspecifico(empleados,costoXMeses,horasTrabajadasXEmpleados);
				cout<<endl;
				break;
			case 'S':
				salir=true;
				cout<<endl;
				break;
			default:
				cout<<"Elije una opcion correcta."<<endl;
				cout<<endl;
		}
	}
	while (!salir);
	
	
  
return 0;
}



void seleccion(char eleccion[]){
	
	cout<<"Elige una opcion: "<<endl;
	cout<<"A: Para un mes determinado, ingresar los costos de mano de obra. "<<endl;
	cout<<"B: Para un mes determinado, cargar las horas trabajadas de todos los empleados."<<endl;
	cout<<"C: Para un mes determinado, cargar las horas trabajadas de todos los empleados."<<endl;
	cout<<"D: Para un empleado determinado, mostrar el sueldo de un mes espec�fico."<<endl;
	cout<<"S: Salir."<<endl;
	cout<<endl;
	cout<<"Eliges: ";
	cin>>eleccion;
	cin.ignore();
	while (strlen(eleccion)!=1){
		cout<<"La opcion tiene que contener solo una letra: "<<endl;
		cout<<"Elige una opcion: "<<endl;
		cout<<"A: Para un mes determinado, ingresar los costos de mano de obra. "<<endl;
		cout<<"B: Para un mes determinado, cargar las horas trabajadas de todos los empleados."<<endl;
		cout<<"C: Para un mes determinado, cargar las horas trabajadas de todos los empleados."<<endl;
		cout<<"D: Para un empleado determinado, mostrar el sueldo de un mes espec�fico."<<endl;
		cout<<"S: Salir."<<endl;
		cout<<endl;
		cout<<"Eliges: ";
		cin>>eleccion;
		cin.ignore();
	}
	cout<<endl;
}

void ingresarMes(int& mesAingresar){
	
	cout<<"INGRESE EL MES: ";
	cin>>mesAingresar;
	while(mesAingresar<1 || mesAingresar>meses){
		cin.ignore();
		cout<<"MES INGRESADO INVALIDO, INGRESE EL MES NUEVAMENTE: ";

		cin>>mesAingresar;
	}
	
}

costosManoObra costoVacio(){
	costosManoObra costo;
	costo.horaFija=0.0;
	costo.horaExtra=0.0;
	return costo;
}

costosManoObra ingresarCosto(){
	costosManoObra costoIngresado;
	cout<<"INGRESE EL COSTO POR HORA FIJA: ";
	cin>>costoIngresado.horaFija;
	cout<<endl;
	cin.ignore();
	cout<<"INGRESE EL COSTO POR HORA EXTRA: ";
	cin>>costoIngresado.horaExtra;
	cout<<endl;
	cin.ignore();
	return costoIngresado;
}

void inicializarCostosManoObra(costosManoObra costoXMeses[]){
	for (int i=0;i<meses;i++){
		costoXMeses[i]=costoVacio();
	}
	
}

void cargarCostosManoObra(costosManoObra costoXMeses[]){
	int mesAingresar;
	cout<<"CARGAR LOS COSTOS DE MANO DE OBRA DE LOS EMPLEADOS: "<<endl;
	ingresarMes(mesAingresar);
	
	costoXMeses[mesAingresar-1]=ingresarCosto();		
	

	cout<<endl;
}

horasTrabajo horasVacias(){
	horasTrabajo horas;
	horas.horasFijasTrabajadas=0.0;
	horas.horasExtraTrabajadas=0.0;
	horas.sueldo=0.0;
	return horas;
}


horasTrabajo ingresarHoras(){
	horasTrabajo horasIngresadas;
	cout<<"INGRESE LA CANTIDAD DE HORAS FIJAS TRABAJADAS: ";
	cin>>horasIngresadas.horasFijasTrabajadas;
	cout<<endl;
	cin.ignore();
	cout<<"INGRESE LA CANTIDAD DE HORAS EXTRA TRABAJADAS: ";
	cin>>horasIngresadas.horasExtraTrabajadas;
	cout<<endl;
	cin.ignore();
	horasIngresadas.sueldo=0.0;
	return horasIngresadas;
}

void inicializarHorasTrabajadas(horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]){
	for (int i=0;i<meses;i++){
		for (int j=0;j<topeEmpleados;j++){
			horasTrabajadasXEmpleados[i][j]=horasVacias();
		}
	}
	
}
void mostrarEmpleado(empleado empleado){
	cout<<"DNI: "<<empleado.dni<<endl;
	cout<<"Nombre: "<<empleado.apellido<<endl;
	cout<<"Apellido: "<<empleado.nombre<<endl;
}

void cargarhorastrabajadas(empleado empleados[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]){
	int mesAingresar;
	cout<<"CARGAR LAS HORAS TRABAJADAS DE LOS EMPLEADOS: "<<endl;
	ingresarMes(mesAingresar);	
	
	for (int i=0;i<topeEmpleados;i++){
		cout<<"EMPLEADO "<<i+1<<endl;
		mostrarEmpleado(empleados[i]);
		horasTrabajadasXEmpleados[mesAingresar-1][i]=ingresarHoras();
	}
	
}

void mostrarHoras(horasTrabajo horas){
	cout<<"HORAS FIJAS TRABAJADAS: "<<horas.horasFijasTrabajadas<<endl;
	cout<<"HORAS EXTRA TRABAJADAS: "<<horas.horasExtraTrabajadas<<endl;
}

void calcularSueldo(horasTrabajo& horas,costosManoObra& costoXMes){
	horas.sueldo=(horas.horasFijasTrabajadas*costoXMes.horaFija)+(horas.horasExtraTrabajadas*costoXMes.horaExtra);

}

void listadoSueldosEmpleados(empleado empleados[],costosManoObra costoXMeses[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]){
	int mesAingresar;	
	cout<<"LISTADO DE TODOS LOS EMPLEADOS: "<<endl;
	ingresarMes(mesAingresar);
	for (int i=0;i<topeEmpleados;i++){
		cout<<"EMPLEADO "<<i+1<<endl;
		mostrarEmpleado(empleados[i]);
		mostrarHoras(horasTrabajadasXEmpleados[mesAingresar-1][i]);
		calcularSueldo(horasTrabajadasXEmpleados[mesAingresar-1][i],costoXMeses[mesAingresar-1]);
		cout<<"SUELDO MENSUAL: $"<<horasTrabajadasXEmpleados[mesAingresar-1][i].sueldo<<endl;
		cout<<endl;
	}
}

void ingresarDni(int& dni){
	cout<<"INGRESE EL DNI DEL EMPLEADO: ";
	cin>>dni;
	while (dni<10000000){
		cin.ignore();
		cout<<"DNI INVALIDO"<<endl;
		cout<<"INGRESE EL DNI DEL EMPLEADO: ";
		cin>>dni;
	}
}

void mostrarSueldoEspecifico(empleado empleados[],costosManoObra costoXMeses[],horasTrabajo horasTrabajadasXEmpleados[meses][topeEmpleados]){
	int dni;
	int mesAingresar;
	ingresarDni(dni);
	ingresarMes(mesAingresar);	
	
	for (int i=0;i<topeEmpleados;i++){
		if (dni==empleados[i].dni){
			cout<<"EMPLEADO "<<i+1<<endl;
			mostrarEmpleado(empleados[i]);
			mostrarHoras(horasTrabajadasXEmpleados[mesAingresar-1][i]);
			calcularSueldo(horasTrabajadasXEmpleados[mesAingresar-1][i],costoXMeses[mesAingresar-1]);
			cout<<"SUELDO MENSUAL: $"<<horasTrabajadasXEmpleados[mesAingresar-1][i].sueldo<<endl;
			cout<<endl;
		}
	}
}
