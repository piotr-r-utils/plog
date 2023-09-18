#include "exporter.hpp"

ConsoleExporter newConsoleExporter(){
    return ConsoleExporter();
}

ConsoleExporter ConsoleExporter::withNewConsole(std::string childConsolePath){
    return *this;
}

Exporter defaultConsoleExporter(){
    return ConsoleExporter().withProcessor(
                newProcessor()
                .withParserFunc(genericParseFunc)
            );
}

Exporter colorfullConsoleExporter(){
     return ConsoleExporter().withProcessor(
                newProcessor()
                .withParserFunc(genericParseFunc)
                .withProcessorFunc(color)
            );
}

