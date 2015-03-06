# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoAssembly.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoCone.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoCons.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoEltu.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoBuilder.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoInterface.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoLoader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoMatrix.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoMedia.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoMedium.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoNode.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoOldAsciiIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoPcon.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoPgon.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoRootBuilder.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoRotation.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoSet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoShapes.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoSphe.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTransform.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTrap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTrd1.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTube.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTubs.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoTorus.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoVector.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoVolume.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoCompositeVolume.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoAsciiIo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoBrik.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/geobase/FairGeoBasicShape.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libGeoBase.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libGeoBase.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libGeoBase.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libGeoBase.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libGeoBase.0.so"
        -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairTools.0.so" "libFairTools.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

