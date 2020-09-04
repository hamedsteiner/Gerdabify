
#ifndef PLACE_H
#define PLACE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "static_declare.h"

using namespace std;

class User;




class Place
{
public:

	virtual Place* goToHome();
	virtual Place* goToPlayLists();
	virtual Place* goToLibrary();
	virtual Place* goToAlbum();
	virtual Place* goToArtist();


	virtual List list();
	virtual List listMusics();
	virtual List listAlbums();
	virtual List listPlaylists();
	virtual List listArtists();

	//void play();


	virtual void orderItem(string music_name, int order);

	virtual void remove(string music_name);

	virtual void rate(int rate);

	virtual string getArtist();
	virtual string getAlbum();
	virtual string getName();
	virtual string getCompleteName();

	virtual int getRate();
	virtual int getUserRate();
	virtual int getCriticRate();




	virtual string get_type();
	virtual void set_type(string _type);
	virtual void addTo(string music_thing);

	virtual void validate();
	 
protected:

string type;
	


};









#endif // PLACE_H