#include "USocial.h"
#include <exception>
#include <iostream>
#include "Audio.h"
#include "Photo.h"
int main()
{
	USocial us;
	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	u1->post("Hello world!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());
	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts
	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewRecievedMessage();
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong tous"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u5->viewRecievedMessage();
	u3->addFriend(u5);
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewRecievedMessage();
	return 0;
}