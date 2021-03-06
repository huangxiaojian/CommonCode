/**
* $Id: readWords.h
*
* This file implement reading words from file
* it is good for I/O operation
*
*/

#ifndef READ_WORDS_H
#define READ_WORDS_H

#include <istream>
#include <sstream>
#include <vector>
using namespace std;

namespace Util {
    template <class T>
    inline std::string ToString(const T& obj) {
     ostringstream stream;
     stream << obj;
     return stream.str();
    }

    inline std::vector<string> ReadWords(istream &stream, string myspace = "")
    {
        std::string whitespace = myspace+" \n\t\r";
        stream >> noskipws;
    
        char tmp[10000];
        stream.getline(tmp, 9990);
        std::string line(tmp);

        if(line.size() == 0)
            return std::vector<string>();

        while(line[line.size() - 1] == '\\') {
            line[line.size() - 1] = ' ';
            stream.getline(tmp, 9990);
            line = line + std::string(tmp);
        }
        
        //split the line into words
        std::vector<string> words;
        std::string::size_type pos = 0;
        while(pos != std::string::npos) {
            pos = line.find_first_not_of(whitespace, pos);
            if(pos == std::string::npos)
                break;
            std::string::size_type eow = line.find_first_of(whitespace, pos);
            words.push_back(std::string(line, pos, eow - pos));
            pos = eow;
        }
    
        return words;
    }

    inline double StringToFloat(string& str)
    {
        return atof(str.c_str());
    }
    inline int StringToInt(string& str)
    {
        return atoi(str.c_str());
    }

}

#endif //READ_WORDS_H
