
#include "cartelera.hpp"

using namespace std;


struct TPelicula // Definiere den Typ Pelicula
{
    int year;
    int duracion;
    char titulo[32];
    char categoria[16];
    string sipnosis;
    string director;
    string actor_principal;
};  // Hier vergisst man leicht das Semikolon!



vector<vector<string> > getNextLineAndSplitIntoTokens(istream& str){
    vector< vector<string> >result;
    vector<string> row;
    string line;
    string cell;
    while(getline(str,line)){
    stringstream lineStream(line);
    row.clear();
        while(getline(lineStream,cell,';')){
            //    cout << cell << endl;
            row.push_back(cell);

        }
    if( !row.empty() )
    result.push_back( row );
    }

    return result;
}


void cargar_peliculas() {
/// http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/

    int counter = 0;
    ifstream file("peliculas.cvs");

    vector<vector<string> > peliculas=getNextLineAndSplitIntoTokens( file);

    file.close();
    for(int i = 0; i < peliculas.size(); ++i){
         for( int j=0; j<peliculas[i].size(); ++j)
             cout << peliculas[i][j] << endl;
        cout<<"\n"<<endl;
    }

}
