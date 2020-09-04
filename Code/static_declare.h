
#ifndef STATICDECLARE_H
#define STATICDECLARE_H




enum UserType {Admin, Artist, Editor, Normal};

typedef std::vector<std::string> List;

struct UserData
{
    std::string firstname;
    std::string lastname;
    std::string username;
    UserType userType;
};







#endif // EXCEPTION_H

