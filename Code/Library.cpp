#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Library.h"
#include "Database.h"
#include "Artist.h"
#include "Home.h"

using namespace std;


Library::Library()
{
	type="library";
}



Place* Library::goToHome()
{
	Place* temp;
	temp = new Home;
	return temp;
}


List Library::list()
{
	/// artist -> get name !
	List output;
	string name;
	for(int i=0 ;i< pointed_db->get_artists().size();i++)
	{
		name=pointed_db->get_artists()[i]->getUserDetails().firstname + pointed_db->get_artists()[i]->getUserDetails().lastname;
		output.push_back(name);
	}
	return output;


}

List Library::listMusics()
{
	List output;
	for(int i=0 ;i< pointed_db->get_musics().size();i++)
		output.push_back(pointed_db->get_musics()[i]->get_name());
	return output;

}


List Library::listAlbums()
{
	List output;
	for(int i=0 ;i< pointed_db->get_albums().size();i++)
		output.push_back(pointed_db->get_albums()[i]->get_name());
	return output;
}


List Library::listArtists()
{
	List output;
	string name;
	for(int i=0 ;i< pointed_db->get_artists().size();i++)
	{
		name=pointed_db->get_artists()[i]->getUserDetails().firstname + pointed_db->get_artists()[i]->getUserDetails().lastname;
		output.push_back(name);
	}
	return output;
}






string Library::getCompleteName()
{
	string out="Library";
	return out;
}


string Library::getName()
{
	string out="Library";
	return out;
}



void Library::set_db(Database* database)
{
	pointed_db=database;
}