#include "exporter.hpp"

FileExporter newFileExporter(){
    return FileExporter();
}

FileExporter FileExporter::withFile(std::string filePath){
    filePath = filePath;
    return *this;
}
