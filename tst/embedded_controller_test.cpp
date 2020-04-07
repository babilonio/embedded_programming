/**
 * @file embedded_controller_test.cpp
 *
 * @brief Unit tests for Embedded Controller
 *
 * @author Sergio Boatella Ojeda
 * Contact: sergioboatella@gmail.com
 *
 */
#include <gtest/gtest.h>
#include "embedded_controller.hpp"


// Test covering base case for getResultingAddress()
TEST(EmbeddedControllerTest, GetResultingAddress) {
	
	uint32_t dataOffsett = 10;
	
	DataContainment data_test;
	data_test.baseAddress = 20;
	
	uint32_t expectedAddress = 30;
	
	
    ASSERT_EQ(expectedAddress, getResultingAddress(dataOffsett, data_test));
}


// Test covering error control for getResultingAddress()
TEST(EmbeddedControllerTest, MemoryOutOfRangeError)
{
    uint32_t dataOffsett = 1;
	
	DataContainment data_test;
	data_test.baseAddress = MAX_MEMORY_RANGE_ADDRESS;
	
	// Easy way to assert whether expected exception is thrown
	// ASSERT_THROW(getResultingAddress(dataOffsett, data_test), MemoryOutOfRangeError);
	
	// This way, both "no exception" and "different exception" cases are checked
    try {
        getResultingAddress(dataOffsett, data_test);
        FAIL() << "No exception thrown, expected MemoryOutOfRangeError";
    }
    catch(MemoryOutOfRangeError const & err) {
        EXPECT_EQ(err.what(),std::string("MemoryOutOfRangeError Exception"));
    }
    catch(...) {
        FAIL() << "Expected MemoryOutOfRangeError";
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}