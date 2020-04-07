/**
 * @file embedded_controller.hpp
 *
 * @brief Embedded controller definitions
 *
 * @author Sergio Boatella Ojeda
 * Contact: sergioboatella@gmail.com
 *
 */  
    
#ifndef EMBEDDED_CONTROLLER_H
#define EMBEDDED_CONTROLLER_H
    
#include <cinttypes>
#include <exception>

 
const uint32_t MAX_MEMORY_RANGE_ADDRESS = UINT32_MAX;        // Maximum memory range definition

/** Data structure for storing base address
 * 
 *  @member baseAddress Base memory address
 */ 
typedef struct DataContainment_t 
{
     uint32_t baseAddress;
} DataContainment;

 
// Calculates the resulting address of the given base address stored in the struct and an offset
uint32_t getResultingAddress(uint32_t offset, const DataContainment & data_containmet);

 
// Define exception for out of range memory accesses
struct MemoryOutOfRangeError:public std::exception {
    const char *what() const noexcept {
        return "MemoryOutOfRangeError Exception";
    }
};
 
 
#endif // EMBEDDED_CONTROLLER_H
