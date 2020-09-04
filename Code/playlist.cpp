#include "playlist.h"


#include "album.h"

using namespace std;



/*
Playlist::Playlist(string _name)
{
	name=_name;
}*/


void Playlist::set_name(string _name)
{
	name=_name;
}
void Playlist::set_owner(string _owner)
{
	owner=_owner;
}


string Playlist::get_owner()
{
	return owner;
}

string Playlist::get_name()
{
	return name;
}


vector<Music*> Playlist::get_musics()
{
	return musics;
}


void Playlist::set_music(Music* new_music)
{
	musics.push_back(new_music);
}
void Playlist::set_album(Album* new_album)
{
	vector<Music*>added= new_album->get_musics();
	for(int i=0;i<added.size();i++)
		musics.push_back(added[i]);
	album_names.push_back(new_album->get_name());

}

vector<string>Playlist::get_albums()
{
	return album_names;
}



void Playlist::clear()
{
	for (int i=musics.size() ;i>0;i--)
	{
		musics.erase(musics.begin()+i-1);
	}
}




void Playlist::remove(string music_name) //remove a musci from a playlist
{
	int location=-1;
	for(int i=0;i<musics.size();i++)
	{
		if(musics[i]->get_name()==music_name)
		{
			location=i;
			break;
		}
	}

	if(location==-1)
		throw ItemDoesNotExists();
	else
		musics.erase(musics.begin()+location);
}



void Playlist:: orderItem(string music_name, int order)
{
	int location=-1;
	for(int i=0;i<musics.size();i++)
	{
		if(musics[i]->get_name()==music_name)
		{
			location=i;
			break;
		}
	}
	if(location==-1)
		throw ItemDoesNotExists();
	else if ( order <1 || order>musics.size() )
		throw InvalidArguments();
	else // we must take care that we are 0 base !!!!!!!!!!!
	{
		Music* temp=musics[location];
		musics[location]=musics[order-1];
		musics[order-1]=temp;
		//cout<<"NEW ORDER "<<location+1<<" to "<<order<<endl;
	}
}

