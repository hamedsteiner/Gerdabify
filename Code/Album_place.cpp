#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Album_place.h"
#include "music.h"

#include "Home.h"

#include "Artist_place.h"


Place* Albumplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}




Place* Albumplace::goToArtist()
{
	Place* temp;
	temp = new Artistplace();
	dynamic_cast<Artistplace*>(temp)->set_artist(pointed_album->get_author());
	dynamic_cast<Artistplace*>(temp)->set_user(current_user);
	
	return temp;
}


void Albumplace::validate()
{
	pointed_album->get_validate();
	
}





Albumplace::Albumplace()
{
	type="album";

}

void Albumplace::remove(string music_name)
{

	pointed_album->remove(music_name);
}

List Albumplace::list()
{
	if(pointed_album->get_validation()==true)
	{
		vector<Music*> temp;
		List output;
		temp=pointed_album->get_musics();
		for(int i=0;i<temp.size();i++)
			output.push_back(temp[i]->get_name());
		return output;
	}
	else
		throw NotAuthorized();

}
List Albumplace::listMusics()
{
	if(pointed_album->get_validation()==true)
	{
		vector<Music*> temp;
		List output;
		temp=pointed_album->get_musics();
		for(int i=0;i<temp.size();i++)
			output.push_back(temp[i]->get_name());
		return output;
	}
	else
		throw NotAuthorized();
}





void Albumplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
	{
		pointed_album->rate(rate,current_user); /// esme USER ham mohem
	}
}


string Albumplace::getArtist()
{
	if(pointed_album->get_validation()==true)
		return (pointed_album->get_author()->getUserDetails().firstname + pointed_album->get_author()->getUserDetails().lastname );
	else
		throw NotAuthorized();
}


string Albumplace::getName()
{	
	if(pointed_album->get_validation()==true)
		return (pointed_album->get_name());
	else
		throw NotAuthorized();
}

string Albumplace::getCompleteName()
{
	if(pointed_album->get_validation()==true)
	{
		string artist_name,album_name,space,complete_name;
		artist_name=(pointed_album->get_author()->getUserDetails().firstname + pointed_album->get_author()->getUserDetails().lastname );
		album_name=pointed_album->get_name();
		space=" - ";
		complete_name=artist_name+space+album_name;
		return complete_name;
	}
	else
		throw NotAuthorized();



}

int Albumplace::getRate()
{
	return ( pointed_album->getRate(current_user) );
}

int Albumplace::getUserRate()
{
	return ( pointed_album->getUserRate() );
}

int Albumplace::getCriticRate()
{
	return ( pointed_album->getCriticRate() );
}
