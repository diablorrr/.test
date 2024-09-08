#include "TextQuery.h"
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;



// class TreeNode {
//     public:
//         TreeNode(): value(string()), count(1), left(nullptr), right(nullptr) { }
//         TreeNode(const TreeNode &t): value(t.value), count(t.count) {
//             TreeNode *tmp_left = new TreeNode(*t.left);
//             TreeNode *tmp_right = new TreeNode(*t.right);
//             delete left;
//             delete right;
//             left = tmp_left;
//             right = tmp_right;
//             count = t.count;
//             value = t.value;
//         }
//         TreeNode& operator=(const TreeNode &t) {
//             TreeNode *tmp_left = new TreeNode(*t.left);
//             TreeNode *tmp_right = new TreeNode(*t.right);
//             delete left;
//             delete right;
//             left = tmp_left;
//             right = tmp_right;
//             count = t.count;
//             value = t.value;
//             return *this;
//         }
//         ~TreeNode() {
//             delete left;
//             delete right;
//         }
//     private:
//         string value;
//         int count;
//         TreeNode *left;
//         TreeNode *right;
// };

// class BinStrTree {
//     private:
//         TreeNode *root;
// };

#include "String.h"

void foo(String x)
{
	std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.c_str() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	svec.reserve(8);
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(s5);
	svec.push_back(baz());
	svec.push_back("good job");

	for (const auto &s : svec)
	{
		std::cout << s.c_str() << std::endl;
	}
}
