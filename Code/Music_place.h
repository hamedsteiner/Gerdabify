
#ifndef MUSICPLACE_H
#define MUSICPLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "music.h"
#include "place.h"
using namespace std;


//class Music;

class Musicplace: public Place
{
public:

Musicplace();


void set_music(Music* _pointed_music){ pointed_music=_pointed_music;}
void set_user(UserData _current_user){ current_user=_current_user;}
Music* get_music(){return pointed_music;}

Place* goToHome();
Place* goToAlbum();
Place* goToArtist();



//void play();
//void addTo(string music_thing);
//void remove(string music_name);
void rate(int rate);

string getArtist();
string getAlbum();
string getName();
string getCompleteName();
int getRate();
int getUserRate();
int getCriticRate();

void validate();





	 
private:
	Music* pointed_music;
	UserData current_user;

	


};









#endif // MUSICPLACE_H