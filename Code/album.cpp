


#include "Artist.h"


#include "album.h"

using namespace std;
/*
Album::Album(Artistt* creator,string _name)
{
	author=creator;
	name=_name;
}
*/


Album::Album()
{
	validated=false;

}

void Album::set_name(string _name)
{
	name=_name;
}

void Album::set_author(Artistt* artist)
{
	author=artist;
}




void Album::add_music(Music* new_music)
{
	musics.push_back(new_music);
}

void Album::add_album(Album* new_album)
{
	vector<Music*> temp=new_album->get_musics();
	for(int i=0;i<temp.size();i++)
		musics.push_back(temp[i]);

}




string Album::get_name()
{
	return name;
}
void Album::get_validate()
{
	validated=true;

}
Artistt* Album::get_author()
{
	return author; 
}
vector<Music*> Album::get_musics()
{
	return musics;
}


void Album::remove(string music_name)
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