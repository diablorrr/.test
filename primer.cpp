#include "Person.h"
#include "TextQuery.h"
#include <fstream>
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

class PrintString {
	public:
		PrintString(istream &i = cin): is(i) {}
		string operator()() const {
			string str;
			getline(is, str);
			return is ? str : string();
		}
	private:
		istream &is;
};

class check {
	public:
		check(int v) : val(v) {}
	bool operator()(int a) {return a == val;}

	int val;
};



int main()
{
	vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};

	std::replace_if(vec.begin(), vec.end(), check(3), 5);
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
}
