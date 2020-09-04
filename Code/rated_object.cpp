#include "rated_object.h"


using namespace std;



void Rated_object::rate(int rate,UserData user )
{
	if(rate> 10 || rate <0)
		throw InvalidArguments();
	else
	{
		rates.push_back(rate);
		users.push_back(user);
	}


	//cout<< rate<<" " <<user.username;
}
int Rated_object::getRate(UserData user)
{
	int location=-1;
	for(int i=0;i<users.size();i++)
		if(users[i].username == user.username && 
           users[i].firstname == user.firstname &&
           users[i].lastname == user.lastname
          )
		{
			location=i;
			break;
		}
	if(location!=-1)
		return rates[location];
	else
		throw ItemDoesNotExists();
	
}


int Rated_object::getUserRate()
{
	int sum=0;
	int num=0;
	for(int i=0;i<users.size();i++)
		if(users[i].userType != Admin || users[i].userType != Editor)
		{
			num++;
			sum+=rates[i];
		}

	if(num==0)
		return 0;
	else
		return (sum/num);
}
int Rated_object::getCriticRate()
{
	int sum=0;
	int num=0;
	for(int i=0;i<users.size();i++)
		if(users[i].userType==Editor)
		{
			num++;
			sum+=rates[i];
		}
	if(num==0)
		return 0;
	else
		return (sum/num);
}






