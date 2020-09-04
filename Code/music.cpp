





#include "music.h"
#include "Artist.h"
#include "album.h"



using namespace std;

	/*Music::Music(string m_name,string path,Artistt* creator)
	{
		name=m_name;
		path_file=path;
		validated=false;
		author=creator;

	}*/
	Music::Music()
	{

		validated=false;

	}
	void Music::set_path(string path)
	{
		path_file=path;
	}

	void Music::set_name(string _name)
	{
		name=_name;
	}

	void Music::set_author(Artistt* artist)
	{
		author=artist;
	}





	string Music::get_name()
	{
		return name;
	}
	Album* Music::get_album()
	{
		return belonged_album;
	}
	Artistt* Music::get_author()
	{
		return author;
	}
	void Music::get_validate()
	{
		//if(validated==false)
			//cout<<"false bod \n";
		validated=true;
		//if(validated==true)
			//cout<<"true shod \n";
	}