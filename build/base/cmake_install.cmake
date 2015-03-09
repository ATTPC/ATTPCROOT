# Install script for directory: /home/daq/fair_install_2015/ATTPCROOT_09032015/base

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
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairAnaSelector.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRadGridManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRadLenManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRadMapManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRingSorter.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRingSorterTask.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRootManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRun.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRunAna.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRunAnaProof.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRunSim.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairTSBufferFunctional.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairTask.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairTrajFilter.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairWriteoutBuffer.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairRunOnline.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/steer/FairLinkManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairBaseContFact.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairBaseParSet.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairGeoParSet.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairDetector.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairGeaneApplication.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairGenerator.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairGenericStack.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairIon.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairMCApplication.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairModule.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairParticle.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairPrimaryGenerator.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairRunIdGenerator.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairVolume.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/sim/FairVolumeList.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairEventBuilder.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairEventBuilderManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairEventHeader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairFileHeader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairFileInfo.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairHit.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairLink.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairMCEventHeader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairMCPoint.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairMesh.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairMultiLinkedData.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairMultiLinkedData_Interface.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairRadLenPoint.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairRadMapPoint.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairRecoEventHeader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairRunInfo.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairTimeStamp.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/event/FairTrackParam.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/field/FairField.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/field/FairFieldFactory.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/field/FairRKPropagator.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/FairSource.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/FairLmdSource.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/FairRemoteSource.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/FairMbsSource.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/FairUnpack.h"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/base/source/MRevBuffer.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libBase.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libBase.so.0.0.0"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libBase.so.0"
    "/home/daq/fair_install_2015/ATTPCROOT_09032015/build/lib/libBase.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so"
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

