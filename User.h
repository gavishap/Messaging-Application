#pragma once
#include <list>
#include <string>
#include "Post.h"
#include "Media.h"
#include "Message.h"
using namespace std;
class USocial;

class User
{
protected:
	USocial* us;
	unsigned long id;
	string name;
	list<unsigned long> friends;
	list<Message*> recievedMsgs;
	list<Post*> Posts;

	User();//Enables to create objects of user only from user class and inherited class
	~User();

public:
	User(string name, USocial* usocial);

	unsigned long getId();//We get a user and returns an ID number
	string getName();//We get a user and return a name
	void addFriend(User*);//Adds a friend to a user
	void removeFriend(User*);//Removes a friend from a user
	void post(string);//posts a post with only a string
	void post(string, Media*);//posts a post with string and media
	list <Post*> getPosts();//returns all the posts of a certain user
	void viewFriendsPosts();//returns all the posts from all the friends of a user
	void recieveMessage(Message*);//a user recieves a message
	void sendMessage(User*, Message*);//a user sends a message to another user
	void viewRecievedMessage();//prints all the messages recieved
	bool friendExists(User*);//a function to to check if  user exists in another user's friend list

};

