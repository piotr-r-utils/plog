#include "plogger.hpp"
#include <stdexcept>

Log test(Log log){
    log.error = new std::runtime_error("testowyError");
    log.message = "testowaWiadomosc";
    return log;
}

int main(){
    Plogger plog1 = newPlogger();

    plog1.log("aaaaa");

    Plogger plog2 = newPlogger()
        .withExporter(
            newExporter()
            .withProcessor(
                newProcessor()
                .withProcessorFunc(test)
            )
        );

    plog2.log("aaaaa");

    return 0;
}