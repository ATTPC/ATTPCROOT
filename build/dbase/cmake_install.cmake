# Install script for directory: /home/daq/fair_install_2015/ATTPCROOT_Feb/dbase

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogBFormat.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbReader.tpl")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbWriter.tpl")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInput/db_detector_def.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dbInput" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInput/prepare_db.sql")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/Experiment.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/FairDbDetector.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/DataType.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/ValCondition.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/ValInterval.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbValidation/ValTimeStamp.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDb.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConnection.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbBufferFile.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbCache.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConfig.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConfigNotice.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConfigurable.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConfigData.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbFieldType.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbTableMetaData.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConnectionPool.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbOutTableBuffer.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbProxy.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbResult.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbRollbackTimes.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbTableBuffer.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbStatement.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbString.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbTableInterface.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbTableInterfaceStore.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbObjTableMap.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbStopWatch.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbStopWatchManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbValRecord.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbValRecordFactory.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairRegistry.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairRegistryElement.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairRegistryElementGeneric.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairUtilStream.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbLogEntry.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConfigBuffer.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbConnectionManager.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbExtSqlContent.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbSqlValidityData.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbException.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbExceptionLog.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbUtils.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbValRecordMap.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbDataTypeUnion.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbStreamer.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairTSQLObject.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLog.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogFormat.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogOSStream.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogService.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogStat.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbUtils/FairDbLogStream.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbReader.h"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/dbase/dbInterface/FairDbWriter.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/daq/fair_install_2015/ATTPCROOT_Feb/build/lib/libFairDB.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/build/lib/libFairDB.so.0.0.0"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/build/lib/libFairDB.so.0"
    "/home/daq/fair_install_2015/ATTPCROOT_Feb/build/lib/libFairDB.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so.0.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so"
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

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/daq/fair_install_2015/ATTPCROOT_Feb/build/dbase/dbMQ/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

