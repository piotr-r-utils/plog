#ifndef PLOGGER

#define PLOGGER

#include <string>
#include <stdexcept>

#include "../exporter/exporter.hpp"

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

    void log(std::string, std::vector<attrib>attrs);
    void logInfo(std::string, std::vector<attrib>attrs);
    void logError(std::string, std::runtime_error, std::vector<attrib>attrs);
    void logError(std::string, std::vector<attrib>attrs);
    void fatal(std::string, std::runtime_error, std::vector<attrib>attrs);
    void fatal(std::string, std::vector<attrib>attrs);

    Plogger withIndex(std::string i);
    Plogger withImportance(Importance importance);
    Plogger withExporter(Exporter exp);
    Plogger withConsoleExporter(Exporter exp);
    Plogger withFileExporter(Exporter exp);

    Plogger();
};



Plogger newPlogger();


#endif