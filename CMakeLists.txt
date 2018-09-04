cmake_minimum_required(VERSION 3.1)

project(TicTacToe LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
find_package(Qt5 COMPONENTS Core Quick Test REQUIRED)

# create static GameLogic library
# we try to avoid recompilation for tests and for application
# and organize things nicely
set(game_logic_sources
    include/gamecontroller.h
    include/gameboard.h
    include/boarditerator.h
    include/gamestatealgorithm.h
    include/gamestateenum.h

    src/gamecontroller.cpp
    src/gameboard.cpp
    src/boarditerator.cpp
    src/gamestatealgorithm.cpp
    src/gamestateenum.cpp
)
ADD_LIBRARY(GameLogicLib STATIC ${game_logic_sources})
target_link_libraries(GameLogicLib PRIVATE Qt5::Core Qt5::Quick)


# create application
add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick GameLogicLib)


# set up the testing project
enable_testing()
set(test_sources
    test/BoardIteratorTest.cpp
)
set(PROJECT_TEST_NAME "Tests")

add_executable(${PROJECT_TEST_NAME} ${test_sources})
add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})
target_link_libraries(${PROJECT_TEST_NAME} PRIVATE Qt5::Test GameLogicLib)

