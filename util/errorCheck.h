#pragma once
class errorCheck{
public:
    static bool checkErrors(std::string line);
    static bool checkBrackets(std::string line);
private:
    static int countMatchInRegex(std::string s,std::string re);
};