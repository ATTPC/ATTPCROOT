# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/GETDecoder/GETDecoder.hh"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/GETDecoder/GETFrame.hh"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/GETDecoder/GETMath.hh"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/GETDecoder/GETPlot.hh"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/ATDecoder/ATCore.hh"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/reco/ATDecoder/ATPad.hh"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libATTPCReco.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libATTPCReco.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libATTPCReco.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libATTPCReco.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libATTPCReco.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libATTPCReco.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libATTPCReco.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libATTPCReco.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libAtTpcMap.0.so" "libAtTpcMap.0.so"
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

