INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FILTERS filters)

FIND_PATH(
    FILTERS_INCLUDE_DIRS
    NAMES filters/api.h
    HINTS $ENV{FILTERS_DIR}/include
        ${PC_FILTERS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FILTERS_LIBRARIES
    NAMES gnuradio-filters
    HINTS $ENV{FILTERS_DIR}/lib
        ${PC_FILTERS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FILTERS DEFAULT_MSG FILTERS_LIBRARIES FILTERS_INCLUDE_DIRS)
MARK_AS_ADVANCED(FILTERS_LIBRARIES FILTERS_INCLUDE_DIRS)

