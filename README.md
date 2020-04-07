
# Exercise Embedded Programming

#### Author: Sergio Boatella
## Description
C++ project  created to solve the "Embedded Programming" exercise.
In addition to the implementation of the “getResultingAddress” method, some extra features have been included that were not explicitely requested:

- Solution created as a CMake project.
- Added a simple logger class.
- Unit test (Google Test) covering “getResultingAddress” use cases.

## Building and executing instructions
### Requirements
- CMake 3.10
- GCC 4.9

#### Download
Clone the project from repository:
```console
$ git clone https://github.com/babilonio/embedded_programming
```
NOTE: Google test library is included in project files (lib/googletest)

#### Build
The first time it takes longer to build as the Google test library also needs to be built.
```console
$ cd embedded_programming && mkdir build && cd build
$ cmake ..
$ make all
```
- To activate Debug mode

```console
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
```
- To run all unit test:
```console
$ make test
```
#### Run
```console
$ ./src/EmbeddedProgramming_run
```
 #### Run unit tests
```console
$ ./tst/EmbeddedProgramming_tst
```

## Example output

#### Basic usage
```console
~/embedded_programming/build$ ./src/EmbeddedProgramming_run
2020-04-07 16:43:02.189323::INFO::Starting...
2020-04-07 16:43:02.196762::INFO::Resulting address: 0x1000
2020-04-07 16:43:02.203101::INFO::Exiting...
Execution log saved in log.txt
```
#### Debug mode
```console
~/embedded_programming/build$ ./src/EmbeddedProgramming_run
2020-04-07 17:14:15.695642::INFO::Starting...
2020-04-07 17:14:15.702080::DEBUG::dataOffsett: 0xff
2020-04-07 17:14:15.708530::DEBUG::baseAddress: 0xf01
2020-04-07 17:14:15.714588::INFO::Resulting address: 0x1000
2020-04-07 17:14:15.719421::INFO::Exiting...
Execution log saved in log.txt
```
#### Test run
```console
~/embedded_programming/build$ ./tst/EmbeddedProgramming_tst
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from EmbeddedControllerTest
[ RUN      ] EmbeddedControllerTest.GetResultingAddress
[       OK ] EmbeddedControllerTest.GetResultingAddress (0 ms)
[ RUN      ] EmbeddedControllerTest.MemoryOutOfRangeError
[       OK ] EmbeddedControllerTest.MemoryOutOfRangeError (0 ms)
[----------] 2 tests from EmbeddedControllerTest (2 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (6 ms total)
[  PASSED  ] 2 tests.
```

## Solution
### getResultingAddress() implementation

```c++
#include "embedded_controller.hpp"

/** Calculates the resulting address of the given base address 
 *  stored in the struct and an offset,
 *  by a simpleaddition of those two values.
 * 
 *  @param offset The name of the algorithm required
 *  @param data_containmet Data structure containing base address
 *  @return Resulting memory address
 * 
 *  @throw MemoryOutOfRangeError Thrown if resulting address is out of memory range
 */
uint32_t getResultingAddress(uint32_t offset, const DataContainment& data_containmet)
{	
	if( offset > MAX_MEMORY_RANGE_ADDRESS - data_containmet.baseAddress) 
	{
		throw MemoryOutOfRangeError();
	}

	return offset + data_containmet.baseAddress;
}
```
File: https://github.com/babilonio/embedded_programming/blob/master/src/embedded_controller.cpp

### Header file
```c++
#ifndef EMBEDDED_CONTROLLER_H
#define EMBEDDED_CONTROLLER_H

#include <cinttypes>
#include <exception>


const uint32_t MAX_MEMORY_RANGE_ADDRESS = UINT32_MAX; // Maximum memory range definition

/** Data structure for storing base address
 * 
 *  @member baseAddress Base memory address
 */
typedef struct DataContainment_t
{
	uint32_t baseAddress;
} DataContainment;


// Calculates the resulting address of the given base address stored in the struct and an offset
uint32_t getResultingAddress(uint32_t offset, const DataContainment& data_containmet);


// Define exception for out of range memory accesses
struct MemoryOutOfRangeError : public std::exception {
	
    const char * what () const noexcept {
        return "MemoryOutOfRangeError Exception";
    }
};


#endif // EMBEDDED_CONTROLLER_H
```
File: https://github.com/babilonio/embedded_programming/blob/master/src/embedded_controller.hpp
