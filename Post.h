#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Media.h"
class Post
{
private:
	string text;
	Media* media;
public:
	string getText();//returns the text from a post
	Media* getMedia();//returns the media
	void display();
	Post(const string str) : text(str), media(nullptr) {};
	Post(const string str, Media* media) : text(str), media(media) {};
	~Post();
};