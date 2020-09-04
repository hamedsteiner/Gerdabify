

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
#include "editor.h"



using namespace std;



	Editorr::Editorr()
	{
		cout<<"";
	}

	 string Editorr::get_name()
	 {
	 	return (this_person.firstname + this_person.lastname);
	 }