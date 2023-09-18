#ifndef EXPORTER

#define EXPORTER

#include "log.hpp"
#include "processor/processor.hpp"

#include <fstream>
#include <iostream>
#include <string>

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
    ConsoleExporter withNewConsole(std::string childConsolePath);
};

ConsoleExporter newConsoleExporter();

Exporter defaultConsoleExporter();
Exporter colorfullConsoleExporter();

class FileExporter : public Exporter{
    std::string filePath;
public:
    FileExporter withFile(std::string filePath);
};

FileExporter newFileExporter();

Exporter defaultFileExporter();

#endif