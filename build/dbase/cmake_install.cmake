# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogBFormat.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbReader.tpl")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbWriter.tpl")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInput/db_detector_def.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dbInput" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInput/prepare_db.sql")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/Experiment.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/FairDbDetector.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/DataType.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/ValCondition.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/ValInterval.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbValidation/ValTimeStamp.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDb.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConnection.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbBufferFile.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbCache.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConfig.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConfigNotice.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConfigurable.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConfigData.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbFieldType.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbTableMetaData.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConnectionPool.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbOutTableBuffer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbProxy.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbResult.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbRollbackTimes.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbTableBuffer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbStatement.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbString.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbTableInterface.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbTableInterfaceStore.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbObjTableMap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbStopWatch.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbStopWatchManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbValRecord.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbValRecordFactory.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairRegistry.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairRegistryElement.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairRegistryElementGeneric.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairUtilStream.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbLogEntry.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConfigBuffer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbConnectionManager.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbExtSqlContent.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbSqlValidityData.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbException.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbExceptionLog.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbUtils.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbValRecordMap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbDataTypeUnion.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbStreamer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairTSQLObject.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLog.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogFormat.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogOSStream.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogService.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogStat.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbUtils/FairDbLogStream.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbReader.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/dbase/dbInterface/FairDbWriter.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.rootmap")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairDB.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairDB.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libFairDB.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/dbase/dbMQ/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

