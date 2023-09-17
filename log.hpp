#ifndef LOG

#define LOG

#include<string>
#include<stdexcept>
#include<vector>

struct attrib {
    std::string key;
    std::string val;
};

enum Importance{ALL, INFO, ERROR};

struct Log {
    std::string index;
    std::string timeStamp;
    std::string message;
    std::runtime_error* error;
    Importance importance;
    
    std::vector<attrib> attributes;

    
    void withAttribs(std::vector<attrib> attribs);
};

#endif