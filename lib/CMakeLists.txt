#configure variables
set (LIB_NAME "${PROJECT_NAME}")
set (LIB_CONFIG "${LIB_NAME}LibConfig")

#configure directories
set (LIBRARY_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib")
set (LIBRARY_SRC_PATH  "${LIBRARY_MODULE_PATH}/src" )
set (LIBRARY_INCLUDE_PATH  "${LIBRARY_MODULE_PATH}/include")

#set includes
include_directories (${LIBRARY_INCLUDE_PATH} ${THIRD_PARTY_INCLUDE_PATH}) 

#set sources
file (GLOB LIB_HEADER_FILES "${LIBRARY_INCLUDE_PATH}/*.hpp")
file (GLOB LIB_SOURCE_FILES "${LIBRARY_SRC_PATH}/*.cpp")

#set library
add_library(${LIB_NAME} STATIC ${LIB_SOURCE_FILES} ${LIB_HEADER_FILES})

target_include_directories(${LIB_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>  
    PRIVATE src)

#export vars
set (LIBRARY_INCLUDE_PATH  ${LIBRARY_INCLUDE_PATH} PARENT_SCOPE)
set (LIB_NAME ${LIB_NAME} PARENT_SCOPE)

message(${LIB_NAME}  " " ${LIB_CONFIG} " " ${CMAKE_INSTALL_LIBDIR})
# install(TARGETS ${LIB_NAME} EXPORT ${LIB_CONFIG}
    # ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT library
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT library
    # RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT library
# )

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIB_NAME})
#install(EXPORT ${LIB_CONFIG} DESTINATION cmake)

# this makes the project importable from the build directory.
# export(TARGETS ${LIB_NAME} FILE "${LIB_CONFIG}.cmake")

#test
enable_testing ()

