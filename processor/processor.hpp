#ifndef PROCESSOR

#define PROCESSOR

#include "../plogger/log.hpp"
#include "colorFuncs.hpp"

#define processorFunc Log(*)(Log)
#define parserFunc std::string(*)(Log)

class Processor{
    std::vector<Log(*)(Log)>processorFuncs;
    std::string (*_parse)(Log log);
public:
    Log process(Log log);
    std::string parse(Log log);

    Processor withProcessorFunc(Log(*f)(Log));
    Processor withParserFunc(std::string(*f)(Log));

    Processor();
};

Processor newProcessor();

//////////////////////GENERIC
std::string genericParseFunc(Log log);

//////////////////////FOR CONSOLE EXPORTER
Log color(Log log);

//////////////////////FOR FILE EXPORTER



#endif