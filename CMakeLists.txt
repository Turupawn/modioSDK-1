cmake_minimum_required(VERSION 3.5)
project(modio)
set (CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# set BUILD_SHARED_LIBs to OFF to compile statically, for example:
# cmake -D BUILD_SHARED_LIBS=OFF .
option(BUILD_SHARED_LIBS "Build Shared Libraries" ON)

# MSVC: set the crtmode flag to 'static' to include the Visual C++
# runtime statically. Requires libcurl to be built with /MT as well.
# cmake -D crtmode=static .

include_directories(include additional_dependencies include/dependencies/miniz)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_library(modio ${SOURCES})
if( BUILD_SHARED_LIBS )
  message("Building mod.io SDK dynamically")
  add_definitions(-DMODIO_DYNAMICLIB -DCURL_STATICLIB)
else()
  message("Building mod.io SDK statically")
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  add_definitions(-DMODIO_STATICLIB -DCURL_STATICLIB)
endif()

IF (APPLE)
  find_package(CURL REQUIRED)
  target_link_libraries(modio ${CURL_LIBRARIES})
ENDIF()

IF (UNIX AND NOT APPLE)
  add_definitions(-D_LARGEFILE64_SOURCE)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
  target_link_libraries (modio curl)
ENDIF ()

IF (MINGW)
  target_link_libraries(modio
    ${CMAKE_SOURCE_DIR}/lib/MinGW/libcurl.a
    ${CMAKE_SOURCE_DIR}/lib/MinGW/libcrypto.dll.a
    ${CMAKE_SOURCE_DIR}/lib/MinGW/libeay32.dll
    ${CMAKE_SOURCE_DIR}/lib/MinGW/libssl.dll.a
    wldap32 ws2_32)
ENDIF()

IF (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS -DUNICODE -D_UNICODE)
  target_link_libraries(modio ws2_32.lib wldap32.lib advapi32.lib kernel32.lib comdlg32.lib crypt32.lib normaliz.lib )

  IF (crtmode AND crtmode STREQUAL "static")
    set(CompilerFlags
      CMAKE_CXX_FLAGS
      CMAKE_CXX_FLAGS_DEBUG
      CMAKE_CXX_FLAGS_RELEASE
      CMAKE_C_FLAGS
      CMAKE_C_FLAGS_DEBUG
      CMAKE_C_FLAGS_RELEASE
    )

    foreach(CompilerFlag ${CompilerFlags})
      string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      target_link_libraries(modio ${CMAKE_SOURCE_DIR}/lib/MSVC/x64/static/libcurl_a.lib)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
      target_link_libraries(modio ${CMAKE_SOURCE_DIR}/lib/MSVC/x86/static/libcurl_a.lib)
    endif()

  ELSE()

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      target_link_libraries(modio ${CMAKE_SOURCE_DIR}/lib/MSVC/x64/libcurl_a.lib)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
      target_link_libraries(modio ${CMAKE_SOURCE_DIR}/lib/MSVC/x86/libcurl_a.lib)
    endif()

  ENDIF()

ENDIF()

IF( test AND test STREQUAL "on" )
  message("Testing enabled")
  file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
  add_subdirectory(ext/googletest-master)
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests ${TEST_SRC_FILES})
  target_link_libraries(runUnitTests gtest gtest_main modio)
  add_test(UnitTests runUnitTests)
ENDIF()
