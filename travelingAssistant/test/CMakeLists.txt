cmake_minimum_required(VERSION 3.1)

project(ta_test)

set(source_list
	TravelingAssistantTest.cpp
)
add_executable(${PROJECT_NAME} ${source_list})

target_link_libraries(${PROJECT_NAME} travelingAssistant_lib gtest)