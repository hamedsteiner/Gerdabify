#include <vector>
#include <string>
#include <iostream>
using namespace std;


enum UserType {Admin, Artist, Editor, Normal};

struct UserData
{
    string firstname;
    string lastname;
    string username;
    UserType userType;
};

int main()
{

	UserData a;
	a.firstname="ali";
	a.lastname="gholi";
	a.username="jafar";
	a.userType=Editor;

	if(a.userType==Normal)
		cout<<"NARID \n";
	else
		cout<<"RID\n";

	/*if(a==b)
	cout<<"EQ";*/



	return 0;
}