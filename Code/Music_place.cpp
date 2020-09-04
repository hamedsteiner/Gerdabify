#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Music_place.h"
#include "User.h"
#include "Home.h"

#include "Album_place.h"


Musicplace::Musicplace()
{
	type="music";
}






Place* Musicplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}


Place* Musicplace::goToAlbum()
{
	Place* temp;
	temp=new Albumplace;
	if(pointed_music->get_album()==NULL)
		throw ItemDoesNotExists();
	else
	    dynamic_cast<Albumplace*>(temp)->set_album(pointed_music->get_album());
	dynamic_cast<Albumplace*>(temp)->set_user(current_user);
	return temp;
}

Place* Musicplace::goToArtist()
{
	Place* temp;
	temp = new Artistplace;
	dynamic_cast<Artistplace*>(temp)->set_artist(pointed_music->get_author());
	dynamic_cast<Artistplace*>(temp)->set_user(current_user);
	return temp;
}


/////////////////////////////////////////////////////////
/*

void Musicplace::play()
{
	throw MethodNotAvailable();
}
void Musicplace::addTo(string music_thing)
{
	throw MethodNotAvailable();
}

*/
///////////////////////////////////////////////////////////

void Musicplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
	{
		pointed_music->rate(rate,current_user); /// esme USER ham mohem
	}
}


string Musicplace::getArtist()
{
	if(pointed_music->get_validation()==true)
		return (pointed_music->get_author()->getUserDetails().firstname + pointed_music->get_author()->getUserDetails().lastname );
	else
		throw NotAuthorized();
}

string Musicplace::getAlbum()
{
	if(pointed_music->get_validation()==true)
		return ( pointed_music->get_album()->get_name() );
	else
		throw NotAuthorized();
}

string Musicplace::getName()
{
	if(pointed_music->get_validation()==true)
		return (pointed_music->get_name());
	else
		throw NotAuthorized();
}

string Musicplace::getCompleteName()
{
	if(pointed_music->get_validation()==true)
	{
		string artist_name,album_name,space,complete_name;
		artist_name=(pointed_music->get_author()->getUserDetails().firstname + pointed_music->get_author()->getUserDetails().lastname );
		album_name=pointed_music->get_album()->get_name();
		space=" - ";
		complete_name=artist_name+space+album_name+space+( pointed_music->get_name() );
		return complete_name;
	}
	else
		throw NotAuthorized();
}

int Musicplace::getRate()
{
	//cout<<"begir \n";
	return ( pointed_music->getRate(current_user) );
}

int Musicplace::getUserRate()
{
	return ( pointed_music->getUserRate() );
}

int Musicplace::getCriticRate()
{
	return ( pointed_music->getCriticRate() );
}


void Musicplace::validate()
{
	pointed_music->get_validate();
	
}