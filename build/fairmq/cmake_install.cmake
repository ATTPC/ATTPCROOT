# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQLogger.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQConfigurable.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQStateMachine.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQTransportFactory.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQMessage.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQSocket.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQDevice.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQBenchmarkSampler.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQSink.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQBuffer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQProxy.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQSplitter.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/devices/FairMQMerger.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/FairMQPoller.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/examples/req-rep/FairMQExampleClient.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/examples/req-rep/FairMQExampleServer.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/zeromq/FairMQTransportFactoryZMQ.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/zeromq/FairMQMessageZMQ.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/zeromq/FairMQSocketZMQ.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/zeromq/FairMQPollerZMQ.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/zeromq/FairMQContextZMQ.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairMQ.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFairMQ.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libFairMQ.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/bsampler")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bsampler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bsampler")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bsampler")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bsampler")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/buffer")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/buffer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/buffer")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/buffer")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/buffer")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/splitter")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/splitter" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/splitter")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/splitter")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/splitter")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/merger")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merger" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merger")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merger")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merger")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/sink")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sink" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sink")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sink")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sink")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/proxy")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/proxy" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/proxy")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/proxy")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/proxy")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/example_client")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_client" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_client")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_client")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_client")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/bin/example_server")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_server" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_server")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -change "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libFairMQ.0.so" "libFairMQ.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_server")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/example_server")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

