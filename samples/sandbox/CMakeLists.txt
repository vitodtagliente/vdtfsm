cmake_minimum_required(VERSION 3.2)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

file(GLOB PROJECT_HEADERS "*.h") 
file(GLOB PROJECT_SOURCES "*.cpp")

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_executable(
    ${PROJECT_NAME} 
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES} 
)

target_link_libraries(
    ${PROJECT_NAME} 
    vdtfsm
)

add_subdirectory(../../ vdtfsm)
