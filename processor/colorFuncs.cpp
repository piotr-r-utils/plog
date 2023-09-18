#include "colorFuncs.hpp"

std::string indexColor(std::string index){
    if (index == "defaultIndex")return index;
    return INDEX + index + DEFAULT;
}

std::string timeStampColor(std::string time){
    if (time == "-") return time;
    return TIMESTAMP + time + DEFAULT;
}

std::string messageColor(std::string msg){
    return MESSAGE + msg + DEFAULT;
}

std::string infoColor(std::string msg) {
    return MSG_INFO + msg + DEFAULT;
}

std::string errMsgColor(std::string msg){
    return ERR_MSG + msg + DEFAULT;
}

std::string errorColor(std::runtime_error* err){
    if(err == nullptr) return "";
    return ERR + std::string(err->what()) + DEFAULT;
}

attrib attribColor(attrib att){
    return {ATTRIB_KEY + att.key + DEFAULT, ATTRIB_VAL + att.val + DEFAULT};
}

std::string fatalMsgColor(std::string msg){
    return FATAL_MSG + msg + DEFAULT;
}

std::string fatalColor(std::runtime_error* err){
    if(err == nullptr) return "";
    return FATAL_ERR + std::string(err->what()) + DEFAULT;
}
