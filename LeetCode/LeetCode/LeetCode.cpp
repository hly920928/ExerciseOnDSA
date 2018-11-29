// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myHeader.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	Twitter twitter;
	twitter.postTweet(1, 5);
	auto v1= twitter.getNewsFeed(1);
	twitter.follow(1, 2);
	twitter.postTweet(2, 6);
	auto v2 = twitter.getNewsFeed(1);
	twitter.unfollow(1, 2);
	auto v3= twitter.getNewsFeed(1);
    return 0;
}

