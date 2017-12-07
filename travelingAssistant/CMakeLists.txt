cmake_minimum_required(VERSION 3.1)

project(travelingAssistant)

include_directories(.)

set(link_list
	TravelWay.cpp
)
add_library(${PROJECT_NAME}_lib STATIC ${link_list})

set(source_list
	main.cpp
)
add_executable(${PROJECT_NAME} ${source_list})

add_subdirectory(test)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)