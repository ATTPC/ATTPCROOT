# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairAnaSelector.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRadGridManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRadLenManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRadMapManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRingSorter.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRingSorterTask.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRootManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRun.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRunAna.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRunAnaProof.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRunSim.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairTSBufferFunctional.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairTask.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairTrajFilter.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairWriteoutBuffer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairRunOnline.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/steer/FairLinkManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairBaseContFact.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairBaseParSet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairGeoParSet.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairDetector.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairGeaneApplication.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairGenerator.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairGenericStack.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairIon.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairMCApplication.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairModule.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairParticle.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairPrimaryGenerator.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairRunIdGenerator.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairVolume.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/sim/FairVolumeList.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairEventBuilder.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairEventBuilderManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairEventHeader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairFileHeader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairFileInfo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairHit.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairLink.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairMCEventHeader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairMCPoint.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairMesh.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairMultiLinkedData.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairMultiLinkedData_Interface.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairRadLenPoint.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairRadMapPoint.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairRecoEventHeader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairRunInfo.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairTimeStamp.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/event/FairTrackParam.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/field/FairField.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/field/FairFieldFactory.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/field/FairRKPropagator.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/FairSource.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/FairLmdSource.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/FairRemoteSource.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/FairMbsSource.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/FairUnpack.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/base/source/MRevBuffer.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libBase.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libBase.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libBase.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libBase.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBase.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libBase.0.so"
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

