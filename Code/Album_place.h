
#ifndef ALBUMPLACE_H
#define ALBUMPLACE_H


#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iostream> 

#include "static_declare.h"


#include "place.h"
#include "Artist_place.h"
#include "album.h"

using namespace std;

//typedef vector<string> List;




class Albumplace: public Place
{
public:

Albumplace();
void validate();
void set_album(Album* _pointed_album){pointed_album=_pointed_album;}
void set_user(UserData user){current_user=user;}

Album* get_album(){return pointed_album;}

Place* goToHome();
Place* goToArtist();
void remove(string music_name);


List list();
List listMusics();

//void play();
void rate(int rate);

string getArtist();
string getName();
string getCompleteName();
int getRate();
int getUserRate();
int getCriticRate();







	 
private:
	Album* pointed_album;
	UserData current_user;

	


};









#endif // ALBUMPLACE_H