# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

project( Classification_Tests )


cmake_minimum_required(VERSION 2.8.11)

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()

# include helper file
include( ${CGAL_USE_FILE} )


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()  
endif()

find_package( Boost OPTIONAL_COMPONENTS serialization iostreams)

if( WIN32 )
# to avoid a warning with old cmake 
  set(_Boost_BZIP2_HEADERS             "boost/iostreams/filter/bzip2.hpp")
  set(_Boost_ZLIB_HEADERS              "boost/iostreams/filter/zlib.hpp")
  find_package( Boost OPTIONAL_COMPONENTS zlib)
endif()

# Use Eigen
find_package(Eigen3 3.1.0) #(requires 3.1.0 or greater)
if (EIGEN3_FOUND)
  include( ${EIGEN3_USE_FILE} )
endif()

find_package( TBB )

# include for local directory
include_directories( BEFORE include )

# include for local package
include_directories( BEFORE ../../include )


# Creating entries for all C++ files with "main" routine
# ##########################################################

include( CGAL_CreateSingleSourceCGALProgram )

#add_definitions("-DCGAL_DO_NOT_USE_BOYKOV_KOLMOGOROV_MAXFLOW_SOFTWARE")

# Classification requires some C++11 features
set(needed_cxx_features cxx_rvalue_references cxx_variadic_templates)

# Libraries and flags
set(classification_linked_libraries)

if (Boost_SERIALIZATION_FOUND AND Boost_IOSTREAMS_FOUND)
  set(classification_linked_libraries ${classification_linked_libraries}
    ${Boost_SERIALIZATION_LIBRARY}
    ${Boost_IOSTREAMS_LIBRARY})
else()
  message(STATUS "NOTICE: Boost Serialization or IO Streams not found, no test will be compiled.")
  return()
endif()

if( WIN32 )
  if (Boost_ZLIB_FOUND)
    set(classification_linked_libraries ${classification_linked_libraries}
      ${Boost_ZLIB_LIBRARY})
  else()
    message(STATUS "NOTICE: Boost ZLIB not found, no example will be compiled.")
    return()
  endif()
endif()

create_single_source_cgal_program( "test_classification_point_set.cpp" CXX_FEATURES ${needed_cxx_features} )

if(TARGET test_classification_point_set)
  target_link_libraries(test_classification_point_set PUBLIC ${classification_linked_libraries})
  if (TBB_FOUND)
    CGAL_target_use_TBB( test_classification_point_set )
  endif()
endif()
