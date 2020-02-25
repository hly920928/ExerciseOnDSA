//468. Validate IP Address
#include "mainHeader.h"
using namespace std;
bool checkSingleV4(char c) {
	if (c >= '0' && c <= '9')return true;
	return false;
}
bool checkSingleV6(char c) {
	if (c >= '0' && c <= '9')return true;
	if (c >= 'a' && c <= 'f')return true;
	if (c >= 'A' && c <= 'F')return true;
	return  false;
}

bool checkUnitV4(string& s) {
	if (s == "0")return true;
	if (s.size() >= 4 ||s.size() == 0)return false;
	if (s[0] == '0')return false;
	int num = stoll(s);
	if( num>=0&&num<=255)return true;
	return false;
}

bool checkUnitV6(string& s) {
	if (s == "0")return true;
	if (s.size() <=4&& s.size() >0)return true;
	return false;
}


bool checkV4(string& IP) {
	int len = IP.size();
	if (len > 15)return false;
	if (len <7)return false;
	if (!checkSingleV4(IP[len-1]))return false;
	string now = ""; int count = 0;
	for (int i = 0; i < len; i++) {
		if (IP[i]!='.') {
			if (!checkSingleV4(IP[i]))return false;
			now.push_back(IP[i]);
		}
		if (IP[i] == '.' || i == len - 1) {
			if (!checkUnitV4(now))return false;
			now = "";
			count++;
		}
	}
	if(count==4)return true;
	return false;
}
bool checkV6(string& IP) {
	int len = IP.size();
	if (len > 39)return false;
	if (len < 15)return false;
	string now = ""; int count = 0;
	if (!checkSingleV6(IP[len - 1]))return false;
	for (int i = 0; i < len; i++) {
		if (IP[i] != ':') {
			if (!checkSingleV6(IP[i]))return false;
			now.push_back(IP[i]);
		}
		if (IP[i] == ':' || i == len - 1) {
			if (!checkUnitV6(now))return false;
			now = "";
			count++;
		}
	}
	if (count == 8)return true;
	return false;

}

string validIPAddress(string IP) {
	if (IP.find('.') != string::npos) {
		if (checkV4(IP))return "IPv4";
	}else if (IP.find(':') != string::npos) {
		if (checkV6(IP))return "IPv6";
	}
	return "Neither";

}