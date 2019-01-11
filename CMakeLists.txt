CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (TestAPP)

MESSAGE( STATUS "PROJECT_NAME: " ${PROJECT_NAME} )

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
file(GLOB test_hdr src/api/*.h)

set(test_src ${test_src} src/api/test.cpp)

add_library                     (libtest ${LIBRARY_TYPE} ${test_src} ${test_hdr} ${tesseract_rsc})


if (NOT STATIC)
target_compile_definitions      (libtest PRIVATE -DTESS_EXPORTS INTERFACE -DTESS_IMPORTS)
set_target_properties           (libtest PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS True)
endif()

set_target_properties           (libtest PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set_target_properties           (libtest PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

if (WIN32)
set_target_properties           (libtest PROPERTIES OUTPUT_NAME test${VERSION_MAJOR}${VERSION_MINOR})
set_target_properties           (libtest PROPERTIES DEBUG_OUTPUT_NAME test${VERSION_MAJOR}${VERSION_MINOR}d)
else()
set_target_properties           (libtest PROPERTIES OUTPUT_NAME test)
endif()


########################################
# EXECUTABLE test
########################################

set(testmain_src src/main.cpp)

add_executable                  (test ${testmain_src} ${tesseractmain_rsc})
target_link_libraries           (test libtest)