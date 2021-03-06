/**
 * @file embedded_controller.cpp
 *
 * @brief getResultingAddress() function implementation
 *
 * @author Sergio Boatella Ojeda
 * Contact: sergioboatella@gmail.com
 *
 */

#include "embedded_controller.hpp"

/** Calculates the resulting address of the given base address stored in the struct and an offset,
 *  by a simpleaddition of those two values.
 * 
 *  @param offset The name of the algorithm required
 *  @param data_containmet Data structure containing base address
 *  @return Resulting memory address
 * 
 *  @throw MemoryOutOfRangeError Thrown if resulting address is out of memory range
 */
uint32_t getResultingAddress(uint32_t offset, const DataContainment & data_containmet)
{
    if (offset > MAX_MEMORY_RANGE_ADDRESS - data_containmet.baseAddress) {
        throw MemoryOutOfRangeError();
    }

    return offset + data_containmet.baseAddress;
}
