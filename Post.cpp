#include "Post.h"

std::string Post::getText()
{
    return text;
}

Media* Post::getMedia()
{
    return media;
}

void Post::display()
{
    cout << text << endl;
    if (media != nullptr)
        media->display();
}

Post::~Post()
{
}
