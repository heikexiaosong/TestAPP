CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (TestAPP)

MESSAGE( STATUS "PROJECT_NAME: " ${PROJECT_NAME} )

include_directories(src)
include_directories(src/math)

###############################################################################
#
# compiler and linker
#
###############################################################################

set(LIBRARY_TYPE SHARED)
if (STATIC)
    set(LIBRARY_TYPE)
endif()



########################################
# LIBRARY test
########################################

file(GLOB test_src
#        src/arch/*.cpp
#        src/ccmain/*.cpp
#        src/ccstruct/*.cpp
#        src/ccutil/*.cpp
#        src/classify/*.cpp
#        src/cutil/*.cpp
#        src/dict/*.cpp
#        src/lstm/*.cpp
#        src/opencl/*.cpp
#        src/textord/*.cpp
#        src/viewer/*.cpp
#        src/wordrec/*.cpp
        )
file(GLOB test_hdr
        src/math/*.h
        )


set(test_src ${test_src}
        src/math/math.cpp
        )



add_library                     (libtest ${LIBRARY_TYPE} ${test_src} ${test_hdr}
        ${tesseract_rsc}
        )


set(testmain_src src/main.cpp)

add_executable                  (test ${testmain_src} ${tesseractmain_rsc})
target_link_libraries           (test libtest)