# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Debug")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairContFact.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairDetParAsciiFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairDetParIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairDetParRootFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairGenericParAsciiFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairGenericParRootFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParAsciiFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParGenericSet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParRootFileIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParSet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairParamList.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairRtdbRun.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/FairRuntimeDb.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/dbIO/FairParTSQLIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/dbIO/FairDetParTSQLIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/parbase/dbIO/FairGenericParTSQLIo.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libParBase.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libParBase.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libParBase.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libParBase.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libParBase.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libParBase.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libParBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libParBase.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.0.so" "libFairDB.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairTools.0.so" "libFairTools.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

