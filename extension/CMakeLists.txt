set(PLUGIN_NAME openvdb_extension)

if (UNIX)
    add_definitions(-DLINUX -D_LINUX -pthread)
endif ()
add_definitions(-D_BOOL -DREQUIRE_IOSTREAM)

find_package(Arnold)
find_package(MtoA)
find_package(Maya)

link_directories(${MAYA_LIBRARY_DIR})

set(MAYA_LIBS OpenMaya Foundation OpenMayaAnim OpenMayaFX OpenMayaUI OpenMayaRender)

file(GLOB SRC *.cpp)
if (INCLUDE_HEADERS_IN_BUILD)
    file(GLOB HDR *.hpp *.h ../util/*.hpp ../util/*.h)
    set(SRC ${SRC} ${HDR})
endif ()

add_library(${PLUGIN_NAME} SHARED ${SRC})
set_target_properties(${PLUGIN_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PLUGIN_NAME} ${ARNOLD_LIBRARY} ${MAYA_LIBS} ${MTOA_mtoa_api_LIBRARY})
target_include_directories(${PLUGIN_NAME} PRIVATE ${ARNOLD_INCLUDE_DIR})
target_include_directories(${PLUGIN_NAME} SYSTEM PRIVATE ${MTOA_INCLUDE_DIR})
target_include_directories(${PLUGIN_NAME} PRIVATE ${MAYA_INCLUDE_DIRS})

install(TARGETS ${PLUGIN_NAME}
        DESTINATION extensions)
