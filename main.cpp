#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "Movie.h"
#include "Serie.h"

void loadFile(vector<Serie*> &series,vector<Episode*> &episode, vector<Video*> &videos, vector<Movie*> &movies){
    string error = "";
    string line, type, name, genre, duration,episodeId;
    int id,season;
    double rating;
    char delim = ',';

    ifstream moviesFromFile("ProyectoIntegrador-Peliculas-1.csv");
    if(moviesFromFile.is_open()){
        getline(moviesFromFile,line);
        while (getline(moviesFromFile, line)) {
            stringstream ss(line);
            getline(ss, type, delim);
            id = stoi(type);
            getline(ss, type, delim);
            name = type;
            getline(ss, type, delim);
            duration = type;
            getline(ss, type, delim);
            genre = type;
            getline(ss, type, delim);
            rating = stod(type);
            movies.push_back(new Movie(id,name,duration,rating,genre));

        }

    }else{
        error = error+ "Files for movies doesn't exist";
    }

    if(error!= ""){
        throw(invalid_argument(error));
    }
    error = "";

    ifstream episodesFromFile("ProyectoIntegrador-Episodios-1.csv");
    if(episodesFromFile.is_open()){
        getline(episodesFromFile, line);
        while (getline(episodesFromFile, line)) {
            stringstream ss(line);
            getline(ss, type, delim);
            id = stoi(type);
            getline(ss, type, delim);
            episodeId = type;
            getline(ss, type, delim);
            name = type;
            getline(ss, type, delim);
            duration = type;
            getline(ss, type, delim);
            rating = stod(type);
            getline(ss, type, delim);
            season = stoi(type);
            episode.push_back(new Episode(id,name,duration,rating,episodeId,season));
        }
    } else{
        error = error+"Files for Episodes doesn't exist";
    }
    if(error != ""){
        throw(invalid_argument(error));
    }
    error = "";

    ifstream seriesFromFile("ProyectoIntegrador-Series-1.csv");
    if(seriesFromFile.is_open()){
        getline(seriesFromFile, line);
        while (getline(seriesFromFile, line)) {
            stringstream ss(line);
            getline(ss, type, delim);
            id = stoi(type);
            getline(ss, type, delim);
            name = type;
            getline(ss, type, delim);
            genre = type;
            getline(ss, type, delim);
            season = stoi(type);

            vector<Episode> episodeVector;
            for(auto i: episode){
                if(*i == id){
                    *i = genre;
                    episodeVector.push_back(*i);

                }
            }
            series.push_back(new Serie(episodeVector,id,name,genre,season));
            episodeVector.clear();
        }
    }else{
        error = error+ "Files for Series doesn't exist";
    }
    if(error != ""){
        throw(invalid_argument(error));
    }
}
void changeRating(vector<Serie*> &series, vector<Video*>&videos,vector<Episode*> &episodes){
    int option;
    int seasonOption = 1;
    int episodeOption = 1;
    bool check = false;
    bool good = false;
    int copySeason;
    int copyEpisode;
    int optionCopy;
    double newRating;

//TODO: not going back when pressing 0;
    while(!check) {
        bool checkSeason = false;
        bool checkEpisode = false;
        int index = 1;
        for (auto i:series) {
            cout << "Option: " << index << " " << *i << endl;
            index++;
        }
        cout << "press 0 to leave" << endl;
        cout << "what serie do you want to choose? ";
        cin >> option;
        if (option == 0) {
            check = true;
            checkSeason = true;
            checkEpisode = true;
        }
        else {
            while(!checkSeason){
                int num = 1;
                cout <<"Press 0 to go back"<<endl;
                cout <<"What season do you want to choose?";
                cin >> seasonOption;
                while(series[option-1]->getNumberOfSeasons()<seasonOption){
                    cout<<"This serie only has: "<<series[option-1]->getNumberOfSeasons()<<" seasons."<<endl;
                    cout <<"What season do you want to choose?";
                    cin >> seasonOption;
                }
                copySeason = seasonOption;
                if(seasonOption == 0){
                    checkSeason = true;
                    checkEpisode = true;
                    check = false;
                }
                else{
                    checkEpisode = false;
                    for(auto j:episodes){
                        if (*j == series[option-1]->getId()&& j->getSeason() == seasonOption) {
                            cout<<"Episode " << num<<" " << *j << endl;
                            num++;
                        }
                    }
                    num = 0;
                    cout << endl;
                    while(!checkEpisode){
                        cout <<"Press 0 to go back"<<endl;
                        cout <<"What episode do you want to choose: ";
                        cin >> episodeOption;
                        copyEpisode = episodeOption;
                        cout << endl;
                        if(episodeOption == 0){
                            checkEpisode =true;
                        }
                        else{
                            int count = 0;
                            for(auto j: videos){
                                for(auto i:episodes){
                                    if(*series[option-1] == j->getId() && j->getName() == i->getName()&& i->getSeason() == seasonOption) {
                                        if(count == episodeOption-1){
                                            cout << "You choose: ";
                                            cout << *i << endl;
                                        }
                                        count++;
                                }
                                }
                            }
                            checkEpisode = true;
                            checkSeason = true;
                            good = true;
                            copyEpisode = episodeOption;
                            episodeOption = 0;
                        }
                    }
                }
            }
        }
        if(checkSeason & checkEpisode & good){
            int index =0;
            for(auto j: videos) {
                for(auto i: episodes){
                    if(*series[option-1] == j->getId() && j->getName() == i->getName()&& i->getSeason() == seasonOption) {
                        if(index == copyEpisode-1){
                            cout << "new score: ";
                            cin >> newRating;
                            *i = newRating;
                            *j = newRating;
                            cout << "heres your new score" << endl;
                            cout << *i << endl;
                        }
                        index++;
                    }
                }
            }
            check = true;
        }
    }
}

void chooseSeries(vector<Serie*> &series, vector<Video*>&videos,vector<Episode*> &episodes){
    int option;
    int seasonOption = 1;
    int episodeOption = 1;
    bool check = false;
    while(!check) {
        bool checkSeason = false;
        bool checkEpisode = false;
        int index = 1;
        for (auto i:series) {
            cout << "Option: " << index << " " << *i << endl;
            index++;
        }
        cout << "press 0 to leave" << endl;
        cout << "what serie do you want to choose? ";
        cin >> option;
        if (option == 0) {
            check = true;
        }
        else {
            while(!checkSeason){
                int num = 1;
                cout <<"Press 0 to go back"<<endl;
                cout <<"What season do you want to choose?";
                cin >> seasonOption;
                while(series[option-1]->getNumberOfSeasons()<seasonOption){
                    cout<<"This serie only has: "<<series[option-1]->getNumberOfSeasons()<<" seasons."<<endl;
                    cout <<"What season do you want to choose?";
                    cin >> seasonOption;
                }
                if(seasonOption == 0){
                    checkSeason = true;
                    checkEpisode = true;
                    check = false;
                }
                else{
                    checkEpisode = false;
                    for(auto j:episodes){
                        if (*j == series[option-1]->getId()&& j->getSeason() == seasonOption) {
                            cout<<"Episode " << num<<" " << *j << endl;
                            num++;
                        }
                    }
                    num = 0;
                    cout << endl;
                    while(!checkEpisode){
                        cout <<"Press 0 to go back"<<endl;
                        cout <<"press any number to exit: ";
                        cin >> episodeOption;
                        cout << endl;
                        if(episodeOption == 0){
                            checkEpisode =true;
                        }
                        else{
                            checkEpisode = true;
                            checkSeason = true;
                            check = true;
                            episodeOption = 0;
                        }
                    }
                }
            }
        }
    }
}


int main() {
    vector<Movie*> movies;
    vector<Episode*> episodes;
    vector<Serie*> series;
    vector<Video*> videos;

    bool loaded = false;
    bool end = false;
    int select;
    while (!end) {
        string category;
        string nameOfSeries;
        string name;
        char Name;
        double newRating;
        int count = 0;
        cout<<endl;
        cout <<"Option 1: Load files"<<endl;
        cout <<"Option 2: See movies"<<endl;
        cout <<"Option 3: See TV series"<<endl;
        cout <<"Option 4: See videos from a certain rating and a genre"<<endl;
        cout <<"Option 5: See videos from a certain genre"<<endl;
        cout <<"Option 6: See episodes with certain ratings"<<endl;
        cout <<"Option 7: Look up series by Name"<<endl;
        cout <<"Option 8: Find movies with a certain rating"<<endl;
        cout <<"Option 9: Change rating of the episode of a series"<<endl;
        cout <<"Option 10: Change rating of a movie"<<endl;
        cout <<"Option 11: Exit"<<endl;
        cout << endl;
        cin >> select;
        switch (select){
            //Load the files
            case 1:
                if(!loaded){
                    try {
                        loadFile(series,episodes,videos,movies);
                        loaded = true;
                        cout<<"Files have loaded correctly"<<endl;
                        for(auto i: movies){
                            videos.push_back(i);
                        }
                        for(auto i: episodes){
                            videos.push_back(i);
                        }
                    } catch (invalid_argument& e) {
                        cout<<e.what()<<endl;
                        loaded = false;
                    }
                } else{
                    cout<<"You already loaded the files"<<endl;
                }
                break;

            //see all of the movies
            case 2:
                if(loaded) {
                    for (auto i:movies) {
                        cout << *i;
                    }
                }
                else{
                    cout <<"You need to load the files"<<endl;
                }
                break;
                //see all of the videos
            case 3:
                if(loaded){
                    chooseSeries(series,videos,episodes);
                }
                else{
                    cout <<"You need to load the files"<<endl;
                }
                break;
                //choose the category and rating of videos that you want to see
            case 4:
                if(loaded){
                    int overRating;
                    int underRating;
                    cout << "what category are you looking for";
                    cin >> category;
                    cout << "what is the lowest rated video that you want to see?:  ";
                    cin >> underRating;
                    cout << "what is the highest rated video that you want to see?:  ";
                    cin >> overRating;
                    for (auto i:videos) {
                        if (*i == category && *i <=overRating && *i >=underRating) {
                            cout << *i << endl;
                        }
                    }
                }
                else{
                    cout <<"You need to load the files"<<endl;
                }

                break;
                //search for a video with a certain category
            case 5:
                if(loaded){
                    int overRating;
                    int underRating;
                    cout << "what category are you looking for";
                    cin >> category;
                    for (auto i:videos) {
                        if (*i == category) {
                            cout << *i << endl;
                        }
                    }
                }
                cout <<"You need to load the files"<<endl;
                break;
                //searches episodes with a rating higher to
            case 6:
                if(loaded){
                    int overRating;
                    int underRating;
                    int index =1;
                    cout << "what is the lowest rated video that you want to see?:  ";
                    cin >> underRating;
                    cout << "what is the highest rated video that you want to see?:  ";
                    cin >> overRating;
                    for (auto i:series) {
                        for (auto j:videos) {
                            if (*i == j->getId() && *j <=overRating && *j >=underRating) {
                                if (index == 1) {
                                    cout << endl;
                                    cout << *i;
                                    index++;
                                }
                                cout << *j;
                            }
                        }
                        index = 1;
                    }
                }
                cout <<"You need to load the files"<<endl;
                break;
            case 7:
                //Searches the series that you want to look by name
                if(loaded){
                    for (auto i:videos) {
                        cout << "Name of the series you want to look at: ";
                        cin >> nameOfSeries;
                        for (auto j:series) {
                            if (*j == i->getId() && *j == nameOfSeries) {
                                cout << *i;
                            }
                        }
                    }
                }
                cout <<"You need to load the files"<<endl;

                break;
                //
            case 8:
                if(loaded){
                    int overRating;
                    int underRating;
                    cout << "what is movie do you want to see with a higher rating than: ";
                    cin >> overRating;
                    for (auto j:videos) {
                        for (auto i:series) {
                            if (*i != j->getId() && *j > overRating && *j == 'M' && count == 0) {
                                cout << *j << endl;
                                count++;
                            }
                        }
                        if (count == 1) count = 0;
                    }
                }
                cout <<"You need to load the files"<<endl;
                break;
            case 9:
                if(loaded){
                    changeRating(series, videos, episodes);
                }
                cout <<"You need to load the files"<<endl;
                break;

            case 10:
                if(loaded){
                    for (auto i:movies) {
                        cout << *i << endl;
                    }
                    cout << "What Movie do you want to change?: ";
                    cin.ignore();
                    getline(cin,name);

                    for (auto i:videos) {
                        if (i->getName() == name) {
                            cout << *i << endl;
                            cout << "what rating do you want to give the video? ";
                            cin >> newRating;
                            *i = newRating;
                            for (auto j:movies) {
                                if (*j == i->getId()) {
                                    *j = newRating;
                                }
                            }
                            cout << *i;
                        }
                    }
                }
                cout<<"You need to load the files first"<<endl;
                break;
            case 11:
                end = true;
                break;
        }
    }
    return 0;
}
