#include "processor.hpp"

Log color(Log log){
    log.index = indexColor(log.index);
    log.timeStamp = timeStampColor(log.timeStamp);
    switch(log.importance){
        case ALL: 
        log.message = messageColor(log.message);
        break;
        case INFO: 
        log.message = infoColor(log.message);
        break;
        case ERROR:
        log.message = errMsgColor(log.message);
        log.errorStr = errorColor(log.error);
        break;
        case FATAL:
        log.message = fatalMsgColor(log.message);
        log.errorStr = fatalColor(log.error);
    }
    
    for (auto& a : log.attributes){
        a = attribColor(a);
    }
    return log;
}