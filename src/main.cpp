/**
 * @file main.cpp
 *
 * @brief Main function for embedded programming application
 *
 * @author Sergio Boatella Ojeda
 * Contact: sergioboatella@gmail.com
 *
 */  
#include <iostream>
#include "embedded_controller.hpp"
#include "custom_logger.hpp"
    
using namespace custom_logger;

 
int main(int argc, char *argv[]) 
{    
    uint32_t dataOffsett = 0xFF;    
    uint32_t resultingAddress = 0;    
    DataContainment data1;    
    data1.baseAddress = 0xF01;
    
    Logger & logger = Logger::getInstance();    
    logger.setLogfile("log.txt");
    
    logger.info("Starting...");
    
    logger.debug("dataOffsett: 0x" + to_hex(dataOffsett));
    logger.debug("baseAddress: 0x" + to_hex(data1.baseAddress));   
 
    try {            
        resultingAddress = getResultingAddress(dataOffsett, data1);
        logger.info("Resulting address: 0x" + to_hex(resultingAddress));
    } 
    catch(MemoryOutOfRangeError const &err) {
        logger.error(err.what());
    } 
     
    logger.info("Exiting...");        
    return 0;
}
