#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>




#include "Artist_place.h"
#include "Home.h"
#include "music.h"
#include "album.h"

using namespace std;
class Artistt;
//class Home;

Place* Artistplace::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}



/////////////////////////////////////////////////////////
/*

void Artistplace::play()
{
	throw MethodNotAvailable();
}
void Artistplace::addTo(string music_thing)
{
	throw MethodNotAvailable();
}

*/
///////////////////////////////////////////////////////////

Artistplace::Artistplace(/*Artistt* _pointed_artist, UserData username */)
{
	type="artist";
	/*pointed_artist=_pointed_artist;
	current_user=username;*/
}


void Artistplace::validate()
{
	dynamic_cast<Artistt*>(pointed_artist)->get_validate();
	
}



List Artistplace::list()
{
	if(dynamic_cast<Artistt*>(pointed_artist)->get_validation()==true)
	{
		vector<Album*> temp;
		List output;
		temp=dynamic_cast<Artistt*>(pointed_artist)->get_albums();
		for(int i=0;i<temp.size();i++)
			output.push_back(temp[i]->get_name());
		return output;
	}
	else
		throw NotAuthorized();

}
List Artistplace::listMusics()/// az album ham misshe add kard
{
	if(dynamic_cast<Artistt*>(pointed_artist)->get_validation()==true)
	{
		vector<Music*> temp;
		List output;
		temp=dynamic_cast<Artistt*>(pointed_artist)->get_musics();
		for(int i=0;i<temp.size();i++)
			output.push_back(temp[i]->get_name());
		return output;
	}
	else
		throw NotAuthorized();
}

List Artistplace::listAlbums()
{
	if(dynamic_cast<Artistt*>(pointed_artist)->get_validation()==true)
	{
		vector<Album*> temp;
		List output;
		temp=dynamic_cast<Artistt*>(pointed_artist)->get_albums();
		for(int i=0;i<temp.size();i++)
			output.push_back(temp[i]->get_name());
		return output;
	}
	else
		throw NotAuthorized();

}



void Artistplace::rate(int rate)
{
	if(rate>10 || rate<0)
		throw InvalidArguments();
	else
		dynamic_cast<Artistt*>(pointed_artist)->rate(rate,current_user); /// esme USER ham mohem

}


string Artistplace::getName()
{
	if(dynamic_cast<Artistt*>(pointed_artist)->get_validation()==true)
		return (dynamic_cast<Artistt*>(pointed_artist)->get_name());
	else
		throw NotAuthorized();
}

string Artistplace::getCompleteName()
{
	if(dynamic_cast<Artistt*>(pointed_artist)->get_validation()==true)
		return (dynamic_cast<Artistt*>(pointed_artist)->get_name());
	else
		throw NotAuthorized();
}

int Artistplace::getRate()
{
	return ( dynamic_cast<Artistt*>(pointed_artist)->getRate(current_user) );
}

int Artistplace::getUserRate()
{
	return (dynamic_cast<Artistt*> (pointed_artist)->getUserRate() );
}

int Artistplace::getCriticRate()
{
	return ( dynamic_cast<Artistt*>(pointed_artist)->getCriticRate() );
}
