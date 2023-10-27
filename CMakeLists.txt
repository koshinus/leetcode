# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.19)

project ("ProblemsSolving")
#target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")
endif(MSVC)

#set(3RDPARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../mailbox-license-service/3rdparty)
#set(EXPECTED_PATH ${3RDPARTY_PATH}/expected)
#set(EXPECTED_BUILD_PACKAGE OFF)
#add_subdirectory(${EXPECTED_PATH} Expected)

# Включите подпроекты.
#add_subdirectory(${PROJECT_NAME})
#add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/Test/funcs.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/Test/Test.cpp")
#add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/Test/main.cpp")
add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC problems)

#message(${EXPECTED_PATH}/include)
#target_include_directories(${PROJECT_NAME} PUBLIC
#	${EXPECTED_PATH}/include
#)