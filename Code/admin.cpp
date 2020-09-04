

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "User.h"
//#include "album.h"
//#include "music.h"
#include "admin.h"



using namespace std;



	Adminn::Adminn()
	{
		cout<<"";
	}

	 string Adminn::get_name()
	 {
	 	return (this_person.firstname + this_person.lastname);
	 }
	 void Adminn::validate()
	 {
	 	current_place->validate();
	 }
