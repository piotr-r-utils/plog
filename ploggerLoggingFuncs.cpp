#include "plogger.hpp"

std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void Plogger::log(std::string message){
    if(ALL < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, message, nullptr, ALL};
    exporter->exportLog(log);
}

void Plogger::logInfo(std::string message){
    if(INFO < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, message, nullptr, INFO};
    exporter->exportLog(log);
}

void Plogger::logError(std::string errorMsg, std::runtime_error error){
    if(ERROR < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, &error, ERROR};
    exporter->exportLog(log);
}

void Plogger::logError(std::string errorMsg){
    if(ERROR < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, nullptr, ERROR};
    exporter->exportLog(log);
}

void Plogger::fatal(std::string errorMsg, std::runtime_error error){
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, &error, FATAL};
    exporter->exportLog(log);
    exit(0);
}

void Plogger::fatal(std::string errorMsg){
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, nullptr, FATAL};
    exporter->exportLog(log);
    exit(0);
}


void Plogger::log(std::string message, std::vector<attrib>attrs){
    if(ALL < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, message, nullptr, ALL, attrs};
    exporter->exportLog(log);
}

void Plogger::logInfo(std::string message, std::vector<attrib>attrs){
    if(INFO < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, message, nullptr, INFO, attrs};
    exporter->exportLog(log);
}

void Plogger::logError(std::string errorMsg, std::runtime_error error, std::vector<attrib>attrs){
    if(ERROR < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, &error, ERROR, attrs};
    exporter->exportLog(log);
}

void Plogger::logError(std::string errorMsg, std::vector<attrib>attrs){
    if(ERROR < importance){
        return;
    }
    
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, nullptr, ERROR, attrs};
    exporter->exportLog(log);
}

void Plogger::fatal(std::string errorMsg, std::runtime_error error, std::vector<attrib>attrs){
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, &error, FATAL, attrs};
    exporter->exportLog(log);
    exit(0);
}

void Plogger::fatal(std::string errorMsg, std::vector<attrib>attrs){
    std::string timestamp = currentDateTime();
    Log log{index, timestamp, errorMsg, nullptr, FATAL, attrs};
    exporter->exportLog(log);
    exit(0);
}