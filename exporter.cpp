#include "exporter.hpp"

Exporter::Exporter(){
    processor = newProcessor();
}

Exporter newExporter(){
    return Exporter();
}

void Exporter::exportLog(Log log){
    log = processor.process(log);
    std::string logString = processor.parse(log);
    std::cout<<logString;
}

Exporter Exporter::withProcessor(Processor p){
    processor = p;
    return *this;
}

