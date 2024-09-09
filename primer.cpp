#include "Person.h"
#include "TextQuery.h"
#include <fstream>
#include <functional>
#include <ostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;



//#include "String.h"



class StrLenBetween {
	private:
		int minLen_;
		int maxLen_;
	public:
		StrLenBetween(int minLne, int maxLen)
			: minLen_(minLne), maxLen_(maxLen) {}
		bool operator()(const string &str) {
			return str.length() >= minLen_ && str.length() <= maxLen_;
		}
};

class biggies {
	public:
		biggies(vector<string>::size_type s) : sz(s) {}
		bool operator()(const string &a) {return a.size() >= sz;}
	private:
		vector<string>::size_type sz;
};

int add(int i, int j) {return i + j;}
auto mod = [](int i, int j) {return i % j;};
struct divide {
	int operator()(int i, int j) {
		return i / j;
	}
};


struct LongDouble {
	LongDouble(double = 0.0);
	operator double();
	operator float();
};


int main(int argc, char *argv[])
{


}
