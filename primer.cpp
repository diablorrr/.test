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

#include "Quote.hpp"


int main(int argc, char *argv[])
{
	Quote q("qbook", 100);
	Bulk_quote bq("bqbook", 200, 150, 0.5);
	print_total(cout, q, 10);
	print_total(cout, bq, 10);

}
