cmake_minimum_required(VERSION 3.1)

project(TicTacToe LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Test REQUIRED)

set(project_sources
   main.cpp
   gamecontroller.cpp
   gamecontroller.h
   gameboard.cpp
   gameboard.h
   boarditerator.h
   boarditerator.cpp
   gamestatealgorithm.h
   gamestatealgorithm.cpp
)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" ${project_sources})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)


# set up the testing project
enable_testing()
set(test_sources
    Test/BoardIteratorTest.cpp
    boarditerator.h
    boarditerator.cpp
)
set(PROJECT_TEST_NAME "Tests")

add_executable(${PROJECT_TEST_NAME} ${test_sources})
add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Qt5::Test)

