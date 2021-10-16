#include "User.h"
#include <stdexcept>
#include <sstream>
#include"USocial.h"
User::User()
{
	static unsigned int current_id = 0;
	current_id++;
	id = current_id;
}

User::~User()
{
}

User::User(string name, USocial* usocial)
{
	static unsigned int current_id = 0;
	current_id++;
	id = current_id;
	this->name = name;
	this->us = usocial;
}

unsigned long User::getId()
{
	return id;
}

string User::getName()
{
	return name;
}

void User::addFriend(User* user)
{
	/* Check if the user alreday exists in friends list, if not add to the list */
	if (!friendExists(user))
		friends.push_back(user->id);
}

void User::removeFriend(User*user)
{
	
	if (!friendExists(user)) {
		std::stringstream message;
		message << "User with id " << user->getId() << " is not your friend.";
		throw std::invalid_argument(message.str());
	}
	friends.remove(user->id);
}

void User::post(string text)
{
	Posts.push_back(new Post (text));
}

void User::post(string text, Media* media)
{
	Posts.push_back(new Post(text,media));
}

list<Post*> User::getPosts()
{
	return Posts;
}

void User::viewFriendsPosts()
{
	for (unsigned int id : friends)
	{
		User* user = us->getUserById(id);
		list<Post*> posts = user->getPosts();

		for (Post* post : posts)
		{
			post->display();
		}
	}
}

void User::recieveMessage(Message* message)
{
	recievedMsgs.push_back(message);
}

void User::sendMessage(User* user, Message* message)
{
	std::cout << "we got to send message" << std::endl;
	std::cout << "Message: " << message->getText() << std::endl;
	/*if (!friendExists(user)) {
		std::stringstream errorMessage;
		errorMessage << "User " << user->getId() << " is not your friend. Message unable to send.";
		throw std::invalid_argument(errorMessage.str());
	}i tried to use this to check if there doesnt exist a friend that they want to send a message to but it made it crash*/
	user->recieveMessage(message);
}

void User::viewRecievedMessage()
{
	for (const auto& message : recievedMsgs) {
		std::cout << "Message: " << message->getText() << std::endl;
	}
}

bool User::friendExists(User* user) {
	for (const auto& friendId : friends) {
		if (user->getId() == friendId) {
			return true;
		}
	}
	return false;
}
