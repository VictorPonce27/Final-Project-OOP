//
// Created by Victor Ponce on 5/31/2020.
//

#ifndef FINALPROYECTV1_SERIE_H
#define FINALPROYECTV1_SERIE_H

using namespace std;

#include "../Episode.h"

class Serie{
    private:
    int numberOfSeasons;
    int id;
    string name;
    string genre;
    vector <Episode> episodes;
    public:
    Serie();
    Serie(vector<Episode> episodes,int id,string name, string genre,int numberOfSeasons);

    int getId();
    int getNumberOfSeasons();
    string getName();
    string getGenre();

    bool operator ==(string name);
    bool operator ==(Episode episode);
    bool operator ==(int id);
    bool operator !=(int id);
    bool operator >=(double rating);
    friend  ostream& operator <<(ostream& os, Serie serie);

};
Serie::Serie(vector <Episode> episodes, int id, string name, string genre, int numberOfSeasons) {
   this-> episodes = episodes;
   this-> name = name;
   this-> id = id;
   this-> numberOfSeasons = numberOfSeasons;
   this-> genre = genre;
}

int Serie::getId() {
    return id;
}

int Serie::getNumberOfSeasons() {
    return numberOfSeasons;
}

string Serie::getName() {
    return name;
}
string Serie::getGenre() {
    return genre;
}


bool Serie::operator==(string name){
    return this->name == name;
}

bool Serie::operator==(Episode episode) {
    return this->id == episode.getId();
}

bool Serie::operator ==(int id){
    return this->id == id;
}

bool Serie::operator!=(int id) {
    return this->id != id;
}


ostream& operator <<(ostream& os, Serie serie){
    os <<serie.getName()<<" "<<serie.getGenre()<<" "<<serie.getNumberOfSeasons() << endl;
    return os;
}

#endif //FINALPROYECTV1_SERIE_H