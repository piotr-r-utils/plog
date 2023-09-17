#ifndef PLOGGER

#define PLOGGER

#include <string>
#include <stdexcept>

#include "exporter.hpp"

class Plogger{
    Exporter* exporter;
public:
    std::string index;
    Importance importance;

    void log(std::string);
    void logInfo(std::string);
    void logError(std::string, std::runtime_error);
    void logError(std::string);
    void fatal(std::string, std::runtime_error);
    void fatal(std::string);

    Plogger withIndex(std::string i);
    Plogger withImportance(Importance importance);
    Plogger withExporter(Exporter exp);

    Plogger();
};



Plogger newPlogger();


#endif