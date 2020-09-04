
#ifndef HOME_H
#define HOME_H

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
#include "Library.h"

using namespace std;




class Home : public Place
{
public:
	Home();

Place* goToHome();
Place* goToPlayLists();
Place* goToLibrary();

/*Place* goToAlbum();
Place* goToArtist();*/


List list();


string getName();
string getCompleteName();



};









#endif // HOME_H
