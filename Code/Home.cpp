#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "Home.h"
#include "exception.h"
#include "Playlist_place.h"

using namespace std;
class Library;

//typedef vector<string> List;

// default constructor


Home::Home()
{
	type="Home";
}

Place* Home::goToHome()
{

	Place* temp;
	temp = new Home;
	//cout<<temp->get_type()<<endl;
	return temp;
}

Place* Home::goToPlayLists()
{
	Place* temp;
	temp = new Playlistplace;
	return temp;
}




Place* Home::goToLibrary()
{
	Place* temp;
	temp = new Library;
	return temp;
}

/*
Place* Home::goToAlbum()
{
	throw MethodNotAvailable();
}

Place* Home::goToArtist()
{
	throw MethodNotAvailable();
}*/



List Home::list()
{
	List output;
	output.push_back("playlists");
	output.push_back("library");
	return output;
}



string Home::getCompleteName()
{
	string out="Home";
	return out;
}


string Home::getName()
{
	string out="Home";
	return out;
}