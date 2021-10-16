
#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"
User* USocial::registerUser(string userName, bool isBusiness)
{
	User* user;
	if (isBusiness)
	{
		user = new BusinessUser(userName, this);
	}
	else
	{
		user = new User(userName, this);
	}
	users[user->getId()] = user;
	return user;
}

void USocial::removeUser(User* user)
{
	users.erase(user->getId());
}

User* USocial::getUserById(unsigned long id)
{
	return users[id];
}
