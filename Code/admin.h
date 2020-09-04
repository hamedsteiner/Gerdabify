
#ifndef ADMIN_H
#define ADMIN_H
// i intemtionaly didnt initiate validate at first casue it would be too hard to use and actuall if admin can not be admin, then who would verify?

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
#include "rated_object.h"




using namespace std;
//class DataBase;


//class Rated_object
class Adminn : public User
{
public:
	Adminn();
	void validate();

	string get_name();
private:
	
	


};


#endif // ADMIN_H