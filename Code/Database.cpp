
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "exception.h"
#include "Database.h"

#include "User.h"
#include "Artist.h"

using namespace std;

	List Database::search_all(string name)
	{
		List output;
		string artist_name;
		string album_name;
		for(int i =0;i<artists.size();i++)
		{
			if(dynamic_cast<Artistt*>(artists[i])->get_name()==name && dynamic_cast<Artistt*>(artists[i])->get_validation()==true)
				output.push_back(name);
		}

		for(int i =0;i<albums.size();i++)
		{
			if(albums[i]->get_name()==name && albums[i]->get_validation()==true)
			{
				artist_name=(albums[i]->get_author()->getUserDetails().firstname +" "+ albums[i]->get_author()->getUserDetails().lastname );
				output.push_back(" < " + artist_name+ " > " + " - "+ " < " + name + " > ");
			}
				
		}

		for(int i =0;i<musics.size();i++)
		{
			if(musics[i]->get_name()==name && musics[i]->get_validation()==true)
			{
				if(musics[i]->get_album() == NULL)
                    output.push_back(" < "+(musics[i]->get_author()->getUserDetails().firstname + " "+musics[i]->get_author()->getUserDetails().lastname )+" > " +   " - " + " < No Album assigned > " + " - "  +     " < "+musics[i]->get_name()+" > ");
                else
                    output.push_back(" < " +(musics[i]->get_author()->getUserDetails().firstname +" "+musics[i]->get_author()->getUserDetails().lastname )+ " > "+ " - " + " < "+musics[i]->get_album()->get_name()+" > " + " - "  + " < "+musics[i]->get_name()+" > ");




				/*artist_name=(musics[i]->get_author()->getUserDetails().firstname + musics[i]->get_author()->getUserDetails().lastname );
				album_name=musics[i]->get_album()->get_name();

				output.push_back(artist_name+" - "+album_name+name);*/



			}
		}
		
		return output;


	}

	vector<User*> Database::get_artists()
	{
		return artists;
	}
	vector<Music*> Database::get_musics()
	{
		return musics;
	}
	vector<Album*> Database::get_albums()
	{
		return albums;
	}

	User* Database::get_artist(int location)
	{
		return artists[location];
	}
	Music* Database::get_music(int location)
	{
		return musics[location];
	}
	Album* Database::get_album(int location)
	{
		return albums[location];
	}


	void Database::add_artist(User* new_artist)
	{
		artists.push_back(new_artist);
	}

	void Database::add_music(Music* new_music)
	{
		musics.push_back(new_music);
	}
	void Database::add_album(Album* new_album)
	{
		albums.push_back(new_album);
	}