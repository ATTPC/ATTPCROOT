# Install script for directory: /home/daq/fair_install_2015/ATTPCROOT_09032015/geobase

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

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoAssembly.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoCone.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoCons.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoEltu.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoBuilder.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoInterface.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoIo.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoLoader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoMatrix.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoMedia.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoMedium.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoNode.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoOldAsciiIo.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoPcon.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoPgon.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoRootBuilder.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoRotation.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoSet.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoShapes.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoSphe.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTransform.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTrap.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTrd1.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTube.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTubs.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoTorus.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoVector.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoVolume.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoCompositeVolume.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoAsciiIo.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoBrik.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/geobase/FairGeoBasicShape.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libGeoBase.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libGeoBase.so.0.0.0"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libGeoBase.so.0"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libGeoBase.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGeoBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_REMOVE
           FILE "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

