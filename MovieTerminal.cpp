// MovieTerminal.cpp
// g++ -o MovieTerminal -std=c++11 MovieTerminal.cpp

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>     // std::string, std::stoi
#include <sstream>

using namespace std;

int alternativa;

struct TPelicula { // Definiere den Typ Pelicula
    string titulo;
    int ano;
    int duracion;
    string categoria;
    string horario;
    string sipnosis;
    string director;
    string actor_principal;
};  // Hier vergisst man leicht das Semikolon!

int counter = 0;
vector<TPelicula> peliculas;

void ReadCVS();
void ClearScreen();
void MenuPrincipal();
void MenuPeliculas();
void MenuPorCategorias();
void ListarTodasPeliculas();
void ListarPorCategoria(string categoria);
void detalles(int i);
void ReservarBoletos(int i); 
void ComprarBoletos(int i); 

int main(int argc, char *argv[]){
	MenuPrincipal();
    //cin.get();
 	return EXIT_SUCCESS;
 }
 
void MenuPrincipal(){
	alternativa=0;
	ClearScreen();
	do {
       	cout <<"-------------------------"<< endl;
        cout <<"----- Movie Terminal -----"<< endl;
        cout <<"-------------------------\n"<< endl;
        cout<<"Estimado Cliente por favor ingrese Ud. una Opción"<<endl;
        cout<<"1. Cartelera"<<endl;
        cout<<"2. Boleteria"<<endl;
        cout<<"3. Confiteria"<<endl;
        cout<<"4. Promociones"<<endl;
        cout<<"5. Para salir\n"<<endl;
        cout<<"Ingresa una Opción: ";
        cin>> alternativa;
        switch(alternativa){
            case 1:
            cout << "Ud. Eligio Cartelera!\n";
            MenuPeliculas();
            break;
            case 2:
            cout << "Ud. Eligio Comprar Boleto!\n";
            break;
            case 3:
            cout << "Confiteria\n";
            break;
            case 4:
            ClearScreen();
            cout << "Ver Promociones!\n";
            break;
            case 5:
            ClearScreen();
            cout<<"Hasta pronto..."<<endl; 
            break;
        }
    }while (alternativa!=5);

}

void ClearScreen(){
	#ifdef WINDOWS
		system("cls");
	#else
		// Assume POSIX
		system ("clear");
	#endif
}
void ReadCVS(){
	string tmp_titulo;
	string tmp_ano;
	string tmp_duracion;
	string tmp_categoria;
	string tmp_horario;
	string tmp_sipnosis;
	string tmp_director;
	string tmp_actor_principal;
	TPelicula tmp_pelicula;
	
	string cell,namefile,line;
    ifstream file;
	//int counter = 0;
    
    namefile="peliculas.csv";
    file.open(namefile.c_str());
	    if( !file.is_open()) {
        cout << "ERROR: File "<< namefile <<" not found." << endl;
		}else{
		//cout << "File found"<<endl;	
		while ( getline( file, line) ) { 
			stringstream lineStream(line);
			if (getline(lineStream, tmp_titulo, ';') &&
			getline(lineStream, tmp_ano, ';') &&
			getline(lineStream, tmp_duracion, ';') &&
			getline(lineStream, tmp_categoria, ';') &&
			getline(lineStream, tmp_horario, ';') &&
			getline(lineStream, tmp_sipnosis, ';') &&
			getline(lineStream, tmp_director, ';') &&        
			getline(lineStream, tmp_actor_principal, ';') ){
			   tmp_pelicula.titulo=tmp_titulo;
			   tmp_pelicula.ano=stoi(tmp_ano);
			   tmp_pelicula.duracion=stoi(tmp_duracion);
			   tmp_pelicula.categoria=tmp_categoria;
			   tmp_pelicula.horario=tmp_horario;
			   tmp_pelicula.sipnosis=tmp_sipnosis;
			   tmp_pelicula.director=tmp_director;
			   tmp_pelicula.actor_principal=tmp_actor_principal;
		}
        peliculas.push_back(tmp_pelicula);
        counter++;
		}
	}
	file.close();
}

void MenuPeliculas() {
	alternativa=0;
	do{ 
		ClearScreen();
		ReadCVS(); 
		cout<<" Cartelera de Peliculas "<<endl; 
		cout<<" **************************"<<endl<<endl; 
		cout<<" 1.- Ver la cartelera Completa"<<endl; 
		cout<<" 2.- Ver los Extrenos"<<endl; 
		cout<<" 3.- Ver por Categoria"<<endl; 
		//cout<<" 4.- Siguientes"<<endl; 
		cout<<" 4.- Menu Principal"<<endl<<endl; 
		cout<<" Ingrese Opcion: ";
		cin>>alternativa; 
	}while(alternativa<1 || alternativa>5);
		switch(alternativa){ 
		case 1:
		ClearScreen(); 
		ListarTodasPeliculas(); 
		break; 
		case 2:
		ClearScreen();  
		//ListarExtrenos(); 
		break; 
		case 3:
		ClearScreen();  
		MenuPorCategorias(); 
		break; 
		case 4:
		ClearScreen();  
		MenuPrincipal(); 
		break; 
		case 5: 
		ClearScreen(); 
		break; 
		default:
		ClearScreen();
		break; 
	}  
	
/// http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/

    ifstream file("peliculas.csv");
    file.close();


}
void ListarTodasPeliculas(){
	ClearScreen();	
	int i=0;
	alternativa=0;
	for (auto p : peliculas){
		i++;
		cout << "************************"<<endl;
		cout <<"Pelicula Numero: "<<i<<endl;
		cout <<"Titulo: "<< p.titulo << ' '<<endl;
		cout <<"Año: "<< p.ano <<endl;
		cout <<"Categoria: "<< p.categoria <<endl;
		cout <<"Horario: "<< p.horario <<endl;
	    if(i%3==0){
			cout << "************************"<<endl;
			do{
			cout << "Precione el numero de Pelicula para selecionarla o la tecla 0 para continuar: ";
			cin >>alternativa;
			}while (alternativa<0 || alternativa>counter);
			switch(alternativa){ 
			case 0:
			ClearScreen(); 
			break;
			default:
			detalles(alternativa);
			break;
			} 	
		}
	}
	//cout << "************************"<<endl;
}
void ListarPorCategoria(string categoria){
	ClearScreen();
	cout << "Listado Por Categoria :"<< categoria<<endl;
	int i=0;
	alternativa=0;
	for (auto p : peliculas){
		i++;
		if(p.categoria==categoria){
		cout << "************************"<<endl;
		cout <<"Pelicula Numero: "<<i<<endl;
		cout <<"Titulo: "<< p.titulo << ' '<<endl;
		cout <<"Año: "<< p.ano <<endl;
		cout <<"Categoria: "<< p.categoria <<endl;
		cout <<"Horario: "<< p.horario <<endl;
		}
	}
		cout << "************************"<<endl;
		do{
		cout << "Precione el numero de Pelicula para selecionarla o la tecla 0 para cancelar: ";
		cin >>alternativa;
		}while (alternativa<0 ||alternativa>counter);
		switch(alternativa){ 
		case 0: 
		MenuPeliculas(); 
		break;
		default:
		detalles(alternativa);
		break;
		} 	

}
void detalles(int i){
		ClearScreen();
		alternativa=0;
		cout << "************************"<<endl;
		cout <<"Pelicula Numero: "<<i<<endl;
		cout <<"\nTitulo: "<< peliculas[i].titulo << ' '<<endl;
		cout <<"Año: "<< peliculas[i].ano <<endl;
		cout <<"Categoria: "<< peliculas[i].categoria <<endl;
		cout <<"\nHorario: "<< peliculas[i].horario <<endl;
		cout <<"\nSipnosis: "<< peliculas[i].sipnosis <<endl;
		cout <<"Director: "<< peliculas[i].director <<endl;
		cout <<"Actor Principal: "<< peliculas[i].actor_principal <<endl;
		do{
		cout <<"\n Desea (1) Reservar o (2)Comprar los Boletos, (3) Cancelar : ";
		cin>>alternativa;
		}while(alternativa<1 ||alternativa>3);
		switch(alternativa){ 
		case 1: 
		ReservarBoletos(i); 
		break; 
		case 2: 
		ComprarBoletos(i); 
		break; 
		case 3: 
		MenuPeliculas(); 
		break; 
		//default:
		//ClearScreen();
		//break;
		} 
}

void ReservarBoletos(int i){
	ClearScreen();
	cout<<" Reservar Boletos "<<endl;
	
	}; 
void ComprarBoletos(int i){
	ClearScreen();
	cout<<" Comprar Boletos "<<endl;
	}; 

void MenuPorCategorias(){
	ClearScreen();
	alternativa=0;
	do{
	cout<<" Cartelera de Peliculas "<<endl; 
	cout<<" **************************"<<endl<<endl;
	cout<<" Categoria de Peliculas "<<endl; 
	cout<<" 1.- Todas"<<endl;
	cout<<" 2.- Accion"<<endl;
	cout<<" 3.- Drama"<<endl;
	cout<<" 4.- Infantil"<<endl;
	cout<<" 5.- Terror"<<endl;
	cout<<"Filtar Peliculas por: ";
	cin>>alternativa;
	}while(alternativa<1 || alternativa>5);
	switch(alternativa){ 
		case 1:
		ListarTodasPeliculas();
		break;
		case 2:
		ListarPorCategoria("Accion");
		break;
		case 3:
		ListarPorCategoria("Drama");
		break;
		case 4:
		ListarPorCategoria("Infantil");
		break;
		case 5:
		ListarPorCategoria("Terror");
		break;
		default:
		ClearScreen();
		break; 
	}	   
}
