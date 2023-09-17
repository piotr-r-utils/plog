#ifndef EXPORTER

#define EXPORTER

#include "log.hpp"
#include "processor.hpp"

#include <fstream>
#include <iostream>

class Exporter{
    Processor processor;
public:
    void exportLog(Log);
    Exporter();

    Exporter withProcessor(Processor p);
};

Exporter newExporter();



class ConsoleExporter : public Exporter{
public:
    Exporter withNewConsole(std::string childConsolePath);
};

class FileExporter : public Exporter{
    std::fstream filestream;
public:
    Exporter withEndFile(std::string filePath);
};

#endif