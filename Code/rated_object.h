
#ifndef RATED_OBJECT_H
#define RATED_OBJECT_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include <map>
#include "static_declare.h"
#include "exception.h"



using namespace std;

class Rated_object
{
public:


virtual void rate(int rate,UserData user );
virtual int getRate(UserData user);
virtual int getUserRate();
virtual int getCriticRate();



///////////////bayad befahmim har ki cheghad dade 
	 
protected:

	vector<UserData> users;
	vector<int> rates;
	//map<string, int> user_rate;
	//	user_rate.insert(pair <string, int> ("ali", 16));


};





#endif // RATED_OBJECT_H