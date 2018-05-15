# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

# Armadillo
include_directories(${ARMADILLO_INCLUDE_DIR})
link_directories(${ARMADILLO_LIBRARY_DIRS})
list(APPEND filters_sources
    gaussian_impl.cc )

set(filters_sources "${filters_sources}" PARENT_SCOPE)
if(NOT filters_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT filters_sources)

add_library(gnuradio-filters SHARED ${filters_sources})
target_link_libraries(gnuradio-filters
  ${OpenCV_LIBS} # added by me
  ${Boost_LIBRARIES}
  ${GNURADIO_ALL_LIBRARIES}
  )
set_target_properties(gnuradio-filters PROPERTIES DEFINE_SYMBOL "gnuradio_filters_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-filters PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-filters RUNTIME_COMPONENT "filters_runtime" DEVEL_COMPONENT "filters_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_filters_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_filters.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_filters.cc
)

add_executable(test-filters ${test_filters_sources})

target_link_libraries(
  test-filters
  ${OpenCV_LIBS} # added by me
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${GNURADIO_BLOCKS_LIBRARIES} # added by me
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  ${ARMADILLO_LIBRARIES}
  gnuradio-filters
)

GR_ADD_TEST(test_filters test-filters)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")
