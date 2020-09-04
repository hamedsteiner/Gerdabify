#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "api.hpp"
#include "Gerdabify_logic.h"
#include "exception.h"



using namespace std;




int main()
{

	//Gerdabify_logic r;
	GerdabifyAPI r;
	string b;
	vector<string>ggg;
	b="hamed123";
	UserData a,c,d,e;
	a.firstname="hamed";
	a.lastname="rahmani";
	a.username="steiner";
	a.userType=Artist;

	c.firstname="sheri";
	c.lastname="killer";
	c.username="shalil";
	c.userType=Admin;


	r.signup(a,b);
	r.login(a.username,b);


	//cout<<"SAKHT1";

	r.addAlbum("brad","pitt");

	//cout<<"SAKHT1";
	List out;

	r.addMusic("SL","ferisheri.wav");
	
	r.createPlaylist("SLlist");

	r.enterBrowserMode();
	//r.enterPlayMode();
	r.goToHome();
	//r.goToPlayLists();
	//r.goToLibrary();

	//out=r.listMusics();
	//out=r.listAlbums();
	//out=r.listArtists();
	//out=r.search("SH");
	r.addMusic("dokhtare","beat.wav");



	r.createPlaylist("list");
	r.select("SL");
	//cout<<r.getName();
	r.addTo("list");
	r.select("dokhtare");
	r.addTo("list");
	r.select("list");
	//out=r.listAlbums();
	
	/*for(int i=0;i<out.size();i++)
		cout<<out[i]<<endl;*/

	r.play();
	r.shuffle();















	/*r.signup(c,b);
	r.login(c.username,b);
	
	r.select("SL");
	r.validate();*/






	//r.select("SHOMBOLlist");//error
	

	
	//r.select("SHOMBOL");
	



	//r.select("pitt");
	//r.select("hamedrahmani");
	//r.rate(3);
	//r.play();




	//r.addTo("SHOMBOLlist");
	//r.select("dokhtare");


	
	//r.addTo("SHOMBOLlist");



	//r.select("SHOMBOLlist");

	//r.clearPlaylist("SHOMBOLlist");
	//r.remove("dokhtare");
	//r.goTo("SHOMBOLlist");
	//r.orderItem("SHOMBOL",1);


	//r.play();
	//r.next();

	//r.rate(3);
	//cout<<r.getRate();
	//cout<<r.getCriticRate();


	//r.remove("SHOMBOL");
	//r.goToAlbum();
	//r.addTo()
	//r.goToArtist();
	//r.goToAlbum();
	//r.goTo("SHOMBOL2");



	
	











	/*out=r.list();
	for(int i=0;i<out.size();i++)
		cout<<ggg[i]<<endl;*/


	//cout<<r.getCompleteName();
	//cout<<r.getName();
	//cout<<r.getCompleteName();
	//r.goToAlbum();



	/*
	r.enterPlayMode();
	r.enterPlayMode();
	r.enterPlayMode();
	r.enterPlayMode();


	//r.createPlaylist("AN o GOH");
	//cout<<"2"<<endl;
	
	r.addMusic("pesare shasho","khone nanash");
	




	//cout<<"3"<<endl;
	//ggg=r.get_artists_name();
	//cout<<ggg[0]<<endl;
	b="steiner";
	ggg=r.get_albums_name(b);
	//ggg=r.get_musics_name("steiner");

	//ggg=r.get_playlists_name("steiner");
	



	//cout<<"4"<<endl;


	for(int i=0;i<ggg.size();i++)
		cout<<ggg[i]<<endl;*/

	//cout<<"5"<<endl;
	return 0 ;
		
	
}