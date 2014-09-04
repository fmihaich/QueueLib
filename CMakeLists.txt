#------------------------------------------------------------------------------
# CMake to create a makefile for compiling QueueLib Library
#   run: 
#          $cmake .
#------------------------------------------------------------------------------

# CMake compatibility issues: don't modify this, please!
CMAKE_MINIMUM_REQUIRED( VERSION 2.8.0 )
MARK_AS_ADVANCED(CMAKE_BACKWARDS_COMPATIBILITY)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
SET(MAIN_ARTIFACT "Queue")
SET(TEST_EXECUTABLE1 "QueueTest")
SET(TEST_EXECUTABLE2 "VectorTest")

# add directorio de libFrame 
ADD_SUBDIRECTORY( ./src ./bin)

# external testing dependencies
SET (CppUnit_FIND_REQUIRED true)
FIND_PACKAGE(CppUnit)

# add directorio de compilacion de test
ADD_SUBDIRECTORY( ./test/test_queue ./test/test_queue/bin )
ADD_SUBDIRECTORY( ./test/test_vector ./test/test_vector/bin )

ENABLE_TESTING()
ADD_TEST(${TEST_EXECUTABLE1} ./test/test_queue/bin/${TEST_EXECUTABLE1})
ADD_TEST(${TEST_EXECUTABLE2} ./test/test_vector/bin/${TEST_EXECUTABLE2})
#------------------------------------------------------------------------------
