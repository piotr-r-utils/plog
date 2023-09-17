#include "plogger.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

Plogger::Plogger(){
    exporter = new Exporter();
    index = "defaultIndex";
    importance = ALL;
}

Plogger newPlogger(){
    return Plogger();
}

Plogger Plogger::withImportance(Importance i){
    importance = i;
    return *this;
}

Plogger Plogger::withIndex(std::string index){
    index = index;
    return *this;
}

Plogger Plogger::withExporter(Exporter exp){
    exporter = new Exporter();
    *exporter = exp;
    return *this;
}



void Plogger::log(std::string message){
    if(ALL < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, message, nullptr, ALL};
    exporter->exportLog(log);
}

void Plogger::logInfo(std::string){}
void Plogger::logError(std::string, std::runtime_error){}
void Plogger::logError(std::string){}
void Plogger::fatal(std::string, std::runtime_error){}
void Plogger::fatal(std::string){}