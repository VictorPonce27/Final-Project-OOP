//
// Created by Victor Ponce on 5/31/2020.
//

#ifndef FINALPROYECTV1_VIDEO_H
#define FINALPROYECTV1_VIDEO_H

#include<string>

using namespace std;

class Video{
protected:
    string duration;
    string name;
    string genre;
    int id;
    double rating;
    char type;
    friend  ostream& operator <<(ostream& os, Video video);
public:
    Video();
    Video(int id, string name, string duration,double rating,char type);
    virtual int getId();
    virtual string getName();
    virtual string getDuration();
    virtual string getGenre();
    virtual double getRating();

    void operator =(string genre);
    virtual void operator =(double rating);
    bool operator <(double rating);
    bool operator >(double rating);
    bool operator <=(double rating);
    bool operator >=(double rating);

    virtual bool operator == (string genre);
    bool operator ==(char type);
    bool operator ==(int id);
    bool operator !=(string genre);
    bool operator !=(char type);

    friend  ostream& operator <<(ostream& os, Video video);
};
Video::Video(){
    duration = "0";
    name = "place holder";
    genre = "place holder";
    id = 0;
    rating = 0.0;

};



Video::Video(int id, string name, string duration, double rating,char type) {
    this-> id = id;
    this-> name = name;
    this-> duration = duration;
    this-> rating = rating;
    this-> type = type;
}

int Video::getId() {
    return id;
}

string Video::getName() {
    return name;
}

string Video::getDuration() {
    return duration;
}

string Video::getGenre() {
    return genre;
}



double Video::getRating() {
    return rating;
}

void Video::operator =(string genre){
    this->genre = genre;
}

void Video::operator=(double rating) {
    this->rating = rating;
}

bool Video::operator==(string genre) {
    return this->genre == genre;
}

bool Video::operator ==(char type){
    return this->type == type;
}

bool Video::operator==(int id) {
    return this->id == id;
}

bool Video::operator!=(string genre) {
    return this->genre != genre;
}

bool Video::operator!=(char type) {
    return this->type != type;
}

bool Video::operator<(double rating) {
    return this->rating < rating;
}

bool Video::operator>(double rating) {
    return this->rating > rating;
}
bool Video::operator<=(double rating) {
    return this->rating <= rating;
}

bool Video::operator>=(double rating) {
    return this->rating >= rating;
}

ostream& operator <<(ostream& os, Video video){
    os <<video.getName() <<" "<<video.getDuration()<<" "<< video.getRating()<< endl;
    return os;
}


#endif //FINALPROYECTV1_VIDEO_H
