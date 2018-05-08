INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DIP dip)

FIND_PATH(
    DIP_INCLUDE_DIRS
    NAMES dip/api.h
    HINTS $ENV{DIP_DIR}/include
        ${PC_DIP_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DIP_LIBRARIES
    NAMES gnuradio-dip
    HINTS $ENV{DIP_DIR}/lib
        ${PC_DIP_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DIP DEFAULT_MSG DIP_LIBRARIES DIP_INCLUDE_DIRS)
MARK_AS_ADVANCED(DIP_LIBRARIES DIP_INCLUDE_DIRS)

