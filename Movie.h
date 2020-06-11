//
// Created by Victor Ponce on 5/31/2020.
//

#ifndef FINALPROYECTV1_MOVIE_H
#define FINALPROYECTV1_MOVIE_H

using namespace std;

#include "Video.h"

class Movie: public Video{
    private:
    //string genre;

    public:
    Movie();
    Movie(int id, string name, string duration,double rating,string genre);
    int getId();
    string getName();
    string getDuration();
    string getGenre();
    double getRating();

    void operator = (double rating);
    bool operator == (int id);
    bool operator == (string genre);

};
Movie::Movie(int id, string name,string duration, double rating, string genre):Video(id,name,duration,rating,'M'){
    this->genre = genre;
}

int Movie::getId() {
    return id;
}

string Movie::getName() {
    return name;
}

string Movie::getDuration() {
    return duration;
}

string Movie::getGenre() {
    return genre;
}

double Movie::getRating() {
    return rating;
}

void Movie::operator=(double rating){
    this->rating = rating;
}

bool Movie::operator==(int id){
    return this->id == id;
}

bool Movie::operator==(string genre) {
    return this->genre == genre;
}


ostream& operator <<(ostream& os, Movie movie){
    os <<movie.getName()<<" "<<movie.getDuration()<<" "<< movie.getGenre()<<""<<movie.getRating()<< endl;
    return os;
}






#endif //FINALPROYECTV1_MOVIE_H
