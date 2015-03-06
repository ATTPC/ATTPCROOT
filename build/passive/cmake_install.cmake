# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive/AtCave.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive/AtPipe.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive/AtGeoCave.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive/AtMagnet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/passive/AtPassiveContFact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libPassive.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libPassive.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libPassive.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libPassive.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPassive.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPassive.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPassive.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libPassive.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libBase.0.so" "libBase.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.0.so" "libFairDB.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairTools.0.so" "libFairTools.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libGeoBase.0.so" "libGeoBase.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libMbsAPI.0.so" "libMbsAPI.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libParBase.0.so" "libParBase.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

