//
// Created by Victor Ponce on 5/31/2020.
//

#ifndef FINALPROYECTV1_EPISODE_H
#define FINALPROYECTV1_EPISODE_H

using namespace std;

#include "../FinalProyectV1/Video.h"
//TODO print the episode id
class Episode: public Video{
    protected:
    string episodeId;
    int season;
    public:
    Episode();
    Episode(int id, string name,string duration,double rating,string episodeId,int seasons);
    int getId();
    int getSeason();
    string getEpisodeId();
    void operator = (string genre);
    bool operator ==(int id);
    bool operator ==(Episode episode);
    bool operator ==(string episodeID);
    void operator = (double rating);
};

Episode::Episode():Video(){
    episodeId ="place holder";
    season = 0;
    genre = "place holder";
}

Episode::Episode(int id, string name, string duration, double rating, string episodeId, int season):Video(id,name,duration,rating,'E'){
    this->episodeId = episodeId;
    this->season = season;
    this->genre = "placeholder";
}

void Episode::operator=(string genre) {
    this->genre = genre;
}

int Episode::getId() {
    return id;
}
int Episode::getSeason() {
    return season;
}

string Episode::getEpisodeId(){
    return episodeId;
}

void Episode::operator=(double rating ){
    this->rating = rating;
}


bool Episode::operator==(int id) {
    return this->id == id;
}
bool Episode::operator==(Episode episode){
    return this->episodeId == episode.getEpisodeId();
}

bool Episode::operator==(string episodeID) {
    return this->episodeId==episodeID;
}
#endif //FINALPROYECTV1_EPISODE_H
