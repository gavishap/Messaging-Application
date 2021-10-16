#pragma once
#include "User.h"
#include "Message.h"
class BusinessUser :public User
{
public:
	void SendMessage(User*, Message*);
	BusinessUser(string name, USocial* usocial) : User(name, us) {}
};

