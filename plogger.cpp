#include "plogger.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

Plogger::Plogger(){
    exporter = new Exporter();
    index = "defaultIndex";
    importance = ALL;
}

Plogger newPlogger(){
    return Plogger();
}

Plogger newPloggerConsole(){
    return newPlogger()
        .withExporter(
            newConsoleExporter()
            .withProcessor(
                newProcessor()
                .withParserFunc(genericParseFunc)
            )
        );
}

Plogger newPloggerConsoleColor(){
    return newPlogger()
        .withExporter(
            newConsoleExporter()
            .withProcessor(
                newProcessor()
                .withParserFunc(genericParseFunc)
                .withProcessorFunc(color)
            )
        );
}

Plogger Plogger::withImportance(Importance i){
    this->importance = i;
    return *this;
}

Plogger Plogger::withIndex(std::string index){
    this->index = index;
    return *this;
}

Plogger Plogger::withExporter(Exporter exp){
    this->exporter = new Exporter();
    *this->exporter = exp;
    return *this;
}

Plogger Plogger::withConsoleExporter(Exporter exp){
    return this->withExporter(exp);
}

Plogger Plogger::withFileExporter(Exporter exp){
    return this->withExporter(exp);
}
