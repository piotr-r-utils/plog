#ifndef COLORFUNCS

#define COLORFUNCS

#define DEFAULT "\033[0m"

#define INDEX "\033[33;49m"

#define TIMESTAMP "\033[37;40;1m"

#define MESSAGE DEFAULT

#define MSG_INFO "\033[35;40;1m"

#define ERR "\033[31;40;1;4m"

#define ERR_MSG "\033[31;49;1m"

#define ATTRIB_KEY "\033[33;40;1m"

#define FATAL_MSG "\033[31;40m"

#define FATAL_ERR "\033[37;41m"

#define ATTRIB_VAL DEFAULT

#include <iostream>
#include <string>
#include <stdexcept>
#include "../plogger/log.hpp"

std::string indexColor(std::string index);

std::string timeStampColor(std::string time);

std::string messageColor(std::string msg);

std::string infoColor(std::string msg);

std::string errMsgColor(std::string msg);

std::string errorColor(std::runtime_error* err);

attrib attribColor(attrib att);

std::string fatalMsgColor(std::string msg);

std::string fatalColor(std::runtime_error* err);


#endif