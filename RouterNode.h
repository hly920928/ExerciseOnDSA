#pragma once
struct _IP {
	unsigned char ip1;
	unsigned char ip2;
	unsigned char ip3;
	unsigned char ip4;
};
struct _LinkData {
	_IP ID;
	_IP IP;
};
struct _NetData {
	_IP prefix;
	unsigned int mask;
};
union _ArcDate {
	_LinkData LinkData;
	_NetData NetData;
};
struct ArcNode {
	char type;//type='L' Link type='N' Net
	unsigned int metric;
	_ArcDate  ArcDate;
	ArcNode* nextArc;//Next ArcNode
};
struct RouterNode {
	_IP RouterID;
	ArcNode* arc;
	RouterNode* next;
};