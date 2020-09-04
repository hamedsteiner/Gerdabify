
#ifndef LIBRARY_H
#define LIBRARY_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "place.h"


using namespace std;

//typedef vector<string> List;
class Database;

class Library: public Place
{
public:

Library();
Place* goToHome();



List list();
List listMusics();
List listAlbums();
List listArtists();

string getName();
string getCompleteName();

void set_db(Database* database);
	 
private:
	
	Database* pointed_db;

	


};









#endif // LIBRARY_H