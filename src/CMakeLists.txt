#------------------------------------------------------------------------------
# CMake to create a makefile for compiling QueueLib
# -- this is a sub-CMakeFile
#------------------------------------------------------------------------------

set(CMAKE_INSTALL_RPATH "./lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# include dependenies headers (internal / external)
SET(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES(${INCLUDE_DIR})

# list sources 
FILE(GLOB SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" AND "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# final library file
ADD_LIBRARY(${MAIN_ARTIFACT} SHARED ${SRCS} )
#SET_TARGET_PROPERTIES(${MAIN_ARTIFACT} PROPERTIES 
#	VERSION ${MAIN_ARTIFACT_VERSION}
#	SOVERSION ${MAIN_ARTIFACT_VERSION}
#)

# link libraries (internal / external)
TARGET_LINK_LIBRARIES(${MAIN_ARTIFACT} 
#    ${LIBRARY_PATHS}
)

# define macro for testing
ADD_DEFINITIONS(-DTESTMETHODS)
