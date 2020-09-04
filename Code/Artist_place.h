
#ifndef ARTISTPLACE_H
#define ARTISTPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "place.h"
#include "static_declare.h"
#include "Artist.h"


//class Artistt;

using namespace std;

class Artistplace: public Place
{
public:

Artistplace();
//Albumplace

void set_artist(User* _pointed_artist){pointed_artist=_pointed_artist;}
void set_user(UserData _current_user){ current_user=_current_user;}
User* get_artist(){return pointed_artist;}

Place* goToHome();
//Place* goToAlbum();


List list();
List listMusics();
List listAlbums();

//void play();
//void addTo(string music_thing);
//void remove(string music_name);
void rate(int rate);

//string getArtist();
//string getAlbum();
string getName();
string getCompleteName();
int getRate();
int getUserRate();
int getCriticRate();


void validate();




	 
private:
	User* pointed_artist;
	UserData current_user;

	


};









#endif // ARTISTPLACE_H