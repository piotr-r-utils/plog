#include "processor.hpp"

Log defaultProcessorFunc(Log log){
    return log;
}

std::string defaultParserFunc(Log log){
    std::string error = "";
    if(log.error != nullptr){
        error = log.error->what();
        error = " : " + error;
    }

    return "[" + log.timeStamp + "]\t" + log.message + error + "\n";
}

Processor newProcessor(){
    return Processor();
}

Processor::Processor(){
    processorFuncs = std::vector<Log(*)(Log)>();
    processorFuncs.push_back(&defaultProcessorFunc);

    _parse = &defaultParserFunc;
}

Processor Processor::withProcessorFunc(Log(*f)(Log)){
    processorFuncs.push_back(f);
    return *this;
}

Processor Processor::withParserFunc(std::string(*f)(Log)){
    _parse = f;
    return *this;
}

Log Processor::process(Log log){
    for (auto f : processorFuncs){
        log = f(log);
    }

    return log;
}

std::string Processor::parse(Log log){
    return _parse(log);
}

