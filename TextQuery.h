#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include "StrVec.h"


class QueryResult;

class TextQuery
{
    friend void runQueries(std::ifstream &infile);
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};




class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    using line_no = std::string::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<StrVec> f):
        sought(s), lines(p), file(f) {};


private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrVec> file;
};


void runQueries(std::ifstream &infile);
#endif
