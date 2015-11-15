# Locate Box2D library
# This module defines
# BOX2D_LIBRARY, the name of the library to link against
# BOX2D_FOUND, if false, do not try to link to Box2D
# BOX2D_INCLUDE_DIR, where to find Box2D headers
#
# Created by iZastic. Based on multiple examples

IF (BOX2D_INCLUDE_DIR)
    # Already in cache, be silent
    SET(BOX2D_FIND_QUIETLY TRUE)
ENDIF (BOX2D_INCLUDE_DIR)

# define the list of search paths for headers and libraries

set(FIND_BOX2D_PATHS
        ${BOX2D_ROOT}
        $ENV{BOX2D_ROOT}
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        /opt)

# find the BOX2D include directory
find_path(BOX2D_INCLUDE_DIR Box2D/Box2D.h
        PATH_SUFFIXES include Include
        PATHS ${FIND_BOX2D_PATHS})

# find the BOX2D release library
FIND_LIBRARY(BOX2D_RELEASE_LIBRARY
        NAMES box2d Box2d BOX2D Box2D
        PATH_SUFFIXES lib64 lib lib/release Library
        PATHS ${FIND_BOX2D_PATHS})

# find the BOX2D debug library
FIND_LIBRARY(BOX2D_DEBUG_LIBRARY
        NAMES box2dd box2d_d Box2d_d BOX2D_d Box2D_d
        PATH_SUFFIXES lib64 lib lib/debug Library
        PATHS ${FIND_BOX2D_PATHS})

IF (BOX2D_RELEASE_LIBRARY OR BOX2D_DEBUG_LIBRARY)
    IF (BOX2D_DEBUG_LIBRARY)
        SET(BOX2D_LIBRARY optimized "${BOX2D_RELEASE_LIBRARY}" debug "${BOX2D_DEBUG_LIBRARY}")
    ELSE ()
        SET(BOX2D_LIBRARY "${BOX2D_RELEASE_LIBRARY}")
    ENDIF ()
ENDIF ()

IF (BOX2D_INCLUDE_DIR AND BOX2D_LIBRARY)
    SET(BOX2D_FOUND TRUE)
ENDIF ()

MARK_AS_ADVANCED(BOX2D_LIBRARY BOX2D_RELEASE_LIBRARY BOX2D_DEBUG_LIBRARY BOX2D_INCLUDE_DIR)

# Per-recommendation
SET(BOX2D_INCLUDE_DIRS "${BOX2D_INCLUDE_DIR}")
SET(BOX2D_LIBRARIES "${BOX2D_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set BOX2D_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Box2D DEFAULT_MSG BOX2D_LIBRARY BOX2D_INCLUDE_DIR)