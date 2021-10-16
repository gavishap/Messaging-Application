#pragma once
#include <map>
#include <string>
#include "BusinessUser.h"
using namespace std;

class USocial
{
private:
	map<unsigned long, User* > users;

public:
	User* registerUser(string, bool = false);//adds a new user to the user list
	void removeUser(User*);//removes a user to the user list
	User* getUserById(unsigned long);//returns a user by searching for his id


};
