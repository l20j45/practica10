#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

class registros {
   public:

      char NumeroEquipo[10],PotenciaActiva[10],CorrienteNominal[10],Eficiencia[10];
      char codigo_caracteres[10];
      int codigo;
   public:

	void Modificar(int opcion);
	void Capturar_Nuevo();
	void Mostrar_Todo();
	void Mostrar();
	void eliminar();
	int Regresar_codigo();
	};


	void registros::eliminar()
{
    int a2,b2,c2,d2,e2;
	int a,b,c,d,e;
    char nom2[10];
    ifstream Lectura("inventario.txt");
	ofstream respaldo("respaldo.txt",ios::app);
    cout<<"NumeroEquipo que deseas eliminar: "<<endl;
    fflush(stdin);
    cin.getline(nom2,10);

    if(!Lectura.good())
        cout<<"No existe el archivo";
    else{
			while(!Lectura.eof())
			{

				Lectura.read((char*)&e,sizeof(int));
				Lectura.read((char*)&codigo_caracteres,e);
				codigo_caracteres[e]='\0';

				Lectura.read((char*)&a,sizeof(int));
				Lectura.read((char*)&NumeroEquipo,a);
				NumeroEquipo[a]='\0';

				Lectura.read((char*)&b,sizeof(int));
				Lectura.read((char*)&PotenciaActiva,b);
				PotenciaActiva[b]='\0';

				Lectura.read((char*)&c,sizeof(int));
				Lectura.read((char*)&CorrienteNominal,c);
				CorrienteNominal[c]='\0';

				Lectura.read((char*)&d,sizeof(int));
				Lectura.read((char*)&Eficiencia,d);
				Eficiencia[d]='\0';



				if(Lectura.eof())
					break;

				if((strcmp(nom2,NumeroEquipo))!=0)
					{
						a2=10;
						b2=10;
						c2=10;
						d2=10;
						e2=10;
						respaldo.write((char*)&e2,sizeof(int));
						respaldo.write((char*)&codigo_caracteres,e2);
						respaldo.write((char*)&a2,sizeof(int));
						respaldo.write((char*)&NumeroEquipo,a2);
						respaldo.write((char*)&b2,sizeof(int));
						respaldo.write((char*)&PotenciaActiva,b2);
						respaldo.write((char*)&c2,sizeof(int));
						respaldo.write((char*)&CorrienteNominal,c2);
						respaldo.write((char*)&d2,sizeof(int));
						respaldo.write((char*)&Eficiencia,d2);
					}
			}
        }
        Lectura.close();
		respaldo.close();
}




		void registros::Mostrar_Todo(){
    int a,b,c,d,e;
    ifstream Lectura("inventario.txt");

    if(!Lectura.good())
        cout<<"No existe el arcLecturaivo";
    else{
			while(!Lectura.eof())
			{
				Lectura.read((char*)&e,sizeof(int));
				Lectura.read((char*)&codigo_caracteres,e);
				codigo_caracteres[e]='\0';

				Lectura.read((char*)&a,sizeof(int));
				Lectura.read((char*)&NumeroEquipo,a);
				NumeroEquipo[a]='\0';

				Lectura.read((char*)&b,sizeof(int));
				Lectura.read((char*)&PotenciaActiva,b);
				PotenciaActiva[b]='\0';

				Lectura.read((char*)&c,sizeof(int));
				Lectura.read((char*)&CorrienteNominal,c);
				CorrienteNominal[c]='\0';

				Lectura.read((char*)&d,sizeof(int));
				Lectura.read((char*)&Eficiencia,d);
				Eficiencia[d]='\0';



				if(Lectura.eof())
					break;

				cout<<endl<<"codigo del equipo: "<<codigo_caracteres<<endl;
				cout<<endl<<"Numero del Equipo: "<<NumeroEquipo<<endl;
				cout<<"potencia activa nominal: "<<PotenciaActiva<<endl;
				cout<<"Corriente Nominal del equipo: "<<CorrienteNominal<<endl;
				cout<<"eficiencia: "<<Eficiencia<<endl;
			}
        }
        Lectura.close();
	}


	void registros::Capturar_Nuevo(){
	int a,b,c,d,e,i;
	codigo=Regresar_codigo();
    codigo++;
    itoa(i,codigo_caracteres,10);
    cout<<"Numero del Equipo: "<<endl;
    fflush(stdin);
    cin.getline(NumeroEquipo,10);
    cout<<"potencia activa nominal : "<<endl;
    cin.getline(PotenciaActiva,10);
    cout<<"Corriente Nominal del equipo: "<<endl;
    cin.getline(CorrienteNominal,10);
	cout<<"eficiencia: "<<endl;
    cin.getline(Eficiencia,10);
    a=10;
	b=10;
	c=10;
	d=10;
	e=10;
	ofstream respaldo("inventario.txt",ios::app);
	respaldo.write((char*)&e,sizeof(int));
	respaldo.write((char*)&codigo_caracteres,e);
    respaldo.write((char*)&a,sizeof(int));
	respaldo.write((char*)&NumeroEquipo,a);
	respaldo.write((char*)&b,sizeof(int));
	respaldo.write((char*)&PotenciaActiva,b);
	respaldo.write((char*)&c,sizeof(int));
	respaldo.write((char*)&CorrienteNominal,c);
	respaldo.write((char*)&d,sizeof(int));
	respaldo.write((char*)&Eficiencia,d);
    respaldo.close();
	}

    void registros::Mostrar(){
    int a,b,c,d,e;
    char nom2[10];
    ifstream Lectura("inventario.txt");
	cout<<"Numero del Equipo a mostrar: "<<endl;
    fflush(stdin);
    cin.getline(nom2,10);

    if(!Lectura.good())
        cout<<"No existe el archivo";
    else{
			while(!Lectura.eof())
			{
				Lectura.read((char*)&e,sizeof(int));
				Lectura.read((char*)&codigo_caracteres,e);
				codigo_caracteres[e]='\0';

				Lectura.read((char*)&a,sizeof(int));
				Lectura.read((char*)&NumeroEquipo,a);
				NumeroEquipo[a]='\0';

				Lectura.read((char*)&b,sizeof(int));
				Lectura.read((char*)&PotenciaActiva,b);
				PotenciaActiva[b]='\0';

				Lectura.read((char*)&c,sizeof(int));
				Lectura.read((char*)&CorrienteNominal,c);
				CorrienteNominal[c]='\0';

				Lectura.read((char*)&d,sizeof(int));
				Lectura.read((char*)&Eficiencia,d);
				Eficiencia[d]='\0';

				if(Lectura.eof())
					break;
					if((strcmp(nom2,NumeroEquipo))==0){
				cout<<endl<<"codigo del equipo: "<<codigo_caracteres<<endl;
				cout<<endl<<"Numero del Equipo: "<<NumeroEquipo<<endl;
				cout<<"potencia activa nominal: "<<PotenciaActiva<<endl;
				cout<<"Corriente Nominal del equipo: "<<CorrienteNominal<<endl;
				cout<<"eficiencia: "<<Eficiencia<<endl;}
			}
        }
        Lectura.close();
		}

      void registros::Modificar(int parametro)
{
	char Letrero[50];
	char modif[10];
	char name2[10];
	int a2,b2,c2,d2,e2;
	int a,b,c,d,e;
	strcpy(Letrero,"");
	cout<<"ingresa el Numero del Equipo quieres modificar";
	fflush(stdin);
    cin.getline(name2,50);
	ifstream Lectura("inventario.txt");
	ofstream respaldo("respaldo.txt",ios::app);
	switch (parametro){
	case 1: strcpy(Letrero,"Numero del Equipo"); break;
	case 2: strcpy(Letrero,"valor de potencia activa nominal"); break;
	case 3: strcpy(Letrero,"valor de la Corriente Nominal"); break;
	case 4: strcpy(Letrero,"valor de la eficiencia"); break;
	}
	cout<<"ingresa el nuevo "<<Letrero<<endl;
    fflush(stdin);
    cin.getline(modif,10);
    if(!Lectura.good())
        cout<<"No existe el arcLecturaivo";
    else{
			while(!Lectura.eof())
			{

				Lectura.read((char*)&e,sizeof(int));
				Lectura.read((char*)&codigo_caracteres,e);
				codigo_caracteres[e]='\0';

				Lectura.read((char*)&a,sizeof(int));
				Lectura.read((char*)&NumeroEquipo,a);
				NumeroEquipo[a]='\0';

				Lectura.read((char*)&b,sizeof(int));
				Lectura.read((char*)&PotenciaActiva,b);
				PotenciaActiva[b]='\0';

				Lectura.read((char*)&c,sizeof(int));
				Lectura.read((char*)&CorrienteNominal,c);
				CorrienteNominal[c]='\0';

				Lectura.read((char*)&d,sizeof(int));
				Lectura.read((char*)&Eficiencia,d);
				Eficiencia[d]='\0';

				if(Lectura.eof())
					break;
				switch(parametro){
				case 1: if((strcmp(name2,NumeroEquipo))==0){
							a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&modif,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
						}
						else{
							a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
							}
						break;
				case 2:if((strcmp(name2,NumeroEquipo))==0){
						a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&modif,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
						}
						else{
						a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
							}break;
				case 3:if((strcmp(name2,NumeroEquipo))==0){
						a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&modif,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
						}
						else{
						a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
							}break;
				case 4:if((strcmp(name2,NumeroEquipo))==0){
						a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&modif,d2);
						}
						else{
					a2=10;
							b2=10;
							c2=10;
							d2=10;
							e2=10;
							respaldo.write((char*)&e2,sizeof(int));
							respaldo.write((char*)&codigo_caracteres,e2);
							respaldo.write((char*)&a2,sizeof(int));
							respaldo.write((char*)&NumeroEquipo,a2);
							respaldo.write((char*)&b2,sizeof(int));
							respaldo.write((char*)&PotenciaActiva,b2);
							respaldo.write((char*)&c2,sizeof(int));
							respaldo.write((char*)&CorrienteNominal,c);
							respaldo.write((char*)&d2,sizeof(int));
							respaldo.write((char*)&Eficiencia,d2);
							}break;
				}
			}
        }

        Lectura.close();
		respaldo.close();
        }

    int registros::Regresar_codigo(){
    int a,b,c,d,e;
    ifstream Lectura("inventario.txt");
    codigo=0;
    if(!Lectura.good())
    {
        cout<<"No existe el arcLecturaivo";
        ofstream respaldo("inventario.txt",ios::app);
        codigo=0;
	}
    else{
			while(!Lectura.eof())
			{

				Lectura.read((char*)&e,sizeof(int));
				Lectura.read((char*)&codigo_caracteres,e);
				codigo_caracteres[e]='\0';

				Lectura.read((char*)&a,sizeof(int));
				Lectura.read((char*)&NumeroEquipo,a);
				NumeroEquipo[a]='\0';

				Lectura.read((char*)&b,sizeof(int));
				Lectura.read((char*)&PotenciaActiva,b);
				PotenciaActiva[b]='\0';

				Lectura.read((char*)&c,sizeof(int));
				Lectura.read((char*)&CorrienteNominal,c);
				CorrienteNominal[c]='\0';

				Lectura.read((char*)&d,sizeof(int));
				Lectura.read((char*)&Eficiencia,d);
				Eficiencia[d]='\0';

				if(Lectura.eof())
					break;
				cout<<codigo_caracteres;
				codigo=atoi(codigo_caracteres);
			}
        }
        Lectura.close();
        cout<<codigo;
        return codigo;
	}

class principal{
    public:
        registros contactos;

    public:
	void Menu_Modificar();
	void Remover();
	void menu();
	void restaurar();
	void Remover1();

};

	void principal::Remover(){
	 remove( "respaldo.txt" );
	}

	void principal::Remover1(){
	 remove( "inventario.txt" );
	}
	void principal::restaurar(){
	string linea;
	ifstream entrada ( "respaldo.txt" );
    ofstream salNumeroEquipoa ("inventario.txt");

    if (salNumeroEquipoa.is_open()) {
        if (entrada.is_open()){
            while (getline (entrada,linea)) {
                salNumeroEquipoa << linea << endl;
            }
            entrada.close(); // No necesario, se cerrara al salir del bloque
        }
        salNumeroEquipoa.close(); // No necesario, se cerrara al salir del bloque
    }
	}


    void principal::Menu_Modificar(){
		int opc;
		cout <<"1.- modificar el Numero del Equipo"<<endl;
		cout <<"2.- modificar la potencia activa nominal"<<endl;
		cout <<"3.- modificar la Corriente Nominal"<<endl;
		cout <<"4.- modificar eficiencia"<<endl;
		cin>>opc;
		getchar();

		switch(opc){
		case 1: contactos.Modificar(1);break;
		case 2: contactos.Modificar(2);break;
		case 3: contactos.Modificar(3);break;
		case 4: contactos.Modificar(4);break;
		}
    }



void principal::menu(){
    int opc=0;
    int bandera=0;
    int calificaciones;
    while(opc!=6){
    cout<<"1.- capturar contactos"<<endl;
    cout<<"2.- mostrar informacion"<<endl;
    cout<<"3.- Buscar"<<endl;
    cout<<"4.- modificar"<<endl;
    cout<<"5.- eliminar"<<endl;
    cout<<"6.- salir"<<endl;
    cin >>opc;
    getchar();
    switch(opc){
    case 1:
    contactos.Capturar_Nuevo();
    break;
    case 2: contactos.Mostrar_Todo();
            break;
    case 3:
			contactos.Mostrar();
            break;
    case 4:
    Menu_Modificar();
	Remover1();
	restaurar();
	Remover();
	opc=0;
	break;
    case 5:
			contactos.eliminar();
			Remover1();
			restaurar();
			Remover();
	break;
    }
    }
}

int main(){
principal p;

p.menu();
return 0;
}
