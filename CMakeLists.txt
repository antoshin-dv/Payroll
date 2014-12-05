project(Payroll)
cmake_minimum_required(VERSION 2.8)

if("${CMAKE_COMPILER_ID}" MATCHES "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	set(GCC_LIKE_COMPILER ON)
endif()

if(NOT MSVC AND NOT GCC_LIKE_COMPILER)
	message(FATAL_ERROR "Support only gcc, clang or msvc compilers")
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
if(MSVC)
	set(MSVC_RUNTIME static)
endif()

if(MSVC)
	add_definitions(-DflagMSC)
	add_definitions(-D_WIN32_WINNT=0x0501)
	include(MSVCRuntime.cmake)
    configure_msvc_runtime()
endif()

if(GCC_LIKE_COMPILER)
	add_definitions(-std=c++11)
	if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
		add_definitions(-stdlib=lib++)
	endif()
endif()

enable_testing()

set(PAYROLL_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)
add_subdirectory(tests)