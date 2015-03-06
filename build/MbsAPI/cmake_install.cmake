# Install script for directory: /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI

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
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/fLmd.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_evhe.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_evhe_swap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/sMbs.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_ves10_1.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_ves10_1_swap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_ve10_1.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_ve10_1_swap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/f_evt.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/f_ut_utime.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_bufhe.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_bufhe_swap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_filhe.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_filhe_swap.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/portnum_def.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/s_stdint.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/typedefs.h"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/MbsAPI/f_stccomm.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libMbsAPI.0.0.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libMbsAPI.0.so"
    "/Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/lib/libMbsAPI.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMbsAPI.0.0.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMbsAPI.0.so"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMbsAPI.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
        -id "libMbsAPI.0.so"
        "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

