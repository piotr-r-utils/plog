#include "processor.hpp"

std::string genericParseFunc(Log log) {
    auto errKey = (log.importance == ERROR ? "ERROR: " : "FATAL: ");
    auto index = (log.index != "defaultIndex" ? "[" + log.index + "]" : "");

    auto time = (log.timeStamp != "-" ? "[" + log.timeStamp + "]\t" : "");

    auto mess = log.message + "\t";

    auto err = (log.errorStr != "" ? errKey + log.errorStr : "") + "\n";

    std::string res = "";

    res += index + time + mess +err;
    for(int i = 0; i <log.attributes.size(); i++){
        res += "\t" + std::to_string(i) + ": "  + log.attributes[i].key + " : " + log.attributes[i].val + "\n";
    }

    return res;
}