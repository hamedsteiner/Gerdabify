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
#include "exception.h"
//#include "User.h"

using namespace std;



Place* Place::goToHome()
{
	throw MethodNotAvailable();
}

Place* Place::goToPlayLists()
{
	throw MethodNotAvailable();
}

Place* Place::goToLibrary()
{
	throw MethodNotAvailable();
}

Place* Place::goToAlbum()
{
	throw MethodNotAvailable();
}

Place* Place::goToArtist()
{
	throw MethodNotAvailable();
}



List Place::list()
{
	throw MethodNotAvailable();
}

List Place::listMusics()
{
	throw MethodNotAvailable();
}

List Place::listAlbums()
{
	throw MethodNotAvailable();
}

List Place::listPlaylists()
{
	throw MethodNotAvailable();
}

List Place::listArtists()
{
	throw MethodNotAvailable();
}


/*void Place::play()
{
	throw MethodNotAvailable();
}*/


void Place::orderItem(string music_name, int order)
{
	throw MethodNotAvailable();
}



void Place::addTo(string music_thing)
{
	throw MethodNotAvailable();
}

void Place::remove(string music_name)
{
	throw MethodNotAvailable();
}

void Place::rate(int rate)
{
	throw MethodNotAvailable();
}


string Place::getArtist()
{
	throw MethodNotAvailable();
}

string Place::getAlbum()
{
	throw MethodNotAvailable();
}



string Place::getName()
{
	throw MethodNotAvailable();
}

string Place::getCompleteName()
{
	throw MethodNotAvailable();
}

int Place::getRate()
{
	throw MethodNotAvailable();
}

int Place::getUserRate()
{
	throw MethodNotAvailable();
}

int Place::getCriticRate()
{
	throw MethodNotAvailable();
}


void Place::set_type(string _type)
{
	type=_type;
}

void Place::validate()
{
	throw MethodNotAvailable();
}



string Place::get_type()
{
	return type;
}