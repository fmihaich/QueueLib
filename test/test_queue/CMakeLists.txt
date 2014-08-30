#------------------------------------------------------------------------------
# CMake to FrameLibTest (CPPUnit Test)

SET(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

# include dirs (internals / externals)
INCLUDE_DIRECTORIES( "${PROJECT_DIR}/src" 
    "${PROJECT_DIR}/include"
)

# almacena todos los nombres de archivos "*.cpp" en la variable src
FILE(GLOB TEST_SRCS "${PROJECT_DIR}/test/test_queue/*.cpp" AND "${PROJECT_DIR}/src/*.cpp" )

# nombre del ejecutable final asociado a los sources.
ADD_EXECUTABLE(${TEST_EXECUTABLE1} ${TEST_SRCS} )

# link libraries (internals / externals)
FILE(GLOB LIBRARIES "${PROJECT_DIR}/lib/*.so")
TARGET_LINK_LIBRARIES(${TEST_EXECUTABLE1} ${LIBRARIES} 
    ${LIBRARY_PATHS}
	cppunit
)
#------------------------------------------------------------------------------
