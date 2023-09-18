#include "plogger/plogger.hpp"
#include <stdexcept>
#include <iostream>


int main(){
    Plogger plog0 = newPlogger();
    Plogger plog1 = newPlogger()
                    .withConsoleExporter(defaultConsoleExporter());
    Plogger plog2 = newPlogger()
                    .withConsoleExporter(colorfullConsoleExporter());
    Plogger plog3 = newPlogger()
                    .withConsoleExporter(colorfullConsoleExporter()).withIndex("testIndex");

    plog0.log("A to jest log na golym ploggerze");
    plog0.logError("A to jest blad na golym ploggerze", std::runtime_error("jakis tam blad"));

    std::cout<<"\n\n";

    plog1.log("przykladowy log");
    plog1.log("przykladowy log", {{"atrybut1", "jakas tam wartosc"}, {"chuj", "cipa"}});

    std::cout<<"\n\n";

    plog2.logInfo("przykladowe info");
    plog2.logError("przykladowy error");

    std::cout<<"\n\n";

    plog3.logError("przykladowy error z runtime bledem", std::runtime_error("jakis tam blad"));
    plog3.fatal("no i sie wyjebal, i to z bledem", std::runtime_error("powazny blad"));

    std::cout<<"\n\n";

    return 0;
}