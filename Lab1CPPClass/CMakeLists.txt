add_executable(Lab1Task1 task1.cpp)
target_include_directories(Lab1Task1 PUBLIC ../LibraryCPPClass)
target_link_libraries(Lab1Task1 LibraryCPPClass)

add_executable(Lab1Task2 task2.cpp)
target_include_directories(Lab1Task2 PUBLIC ../LibraryCPPClass)
target_link_libraries(Lab1Task2 LibraryCPPClass)

add_test(NAME Lab1Task1_Test1
    COMMAND Lab1Task1 "${CMAKE_CURRENT_SOURCE_DIR}/tests/task1_test1.txt")
set_tests_properties(Lab1Task1_Test1 PROPERTIES
    PASS_REGULAR_EXPRESSION "^4[\r\n]*$")

add_test(NAME Lab1Task1_Test2
    COMMAND Lab1Task1 "${CMAKE_CURRENT_SOURCE_DIR}/tests/task1_test2.txt")
set_tests_properties(Lab1Task1_Test2 PROPERTIES
    PASS_REGULAR_EXPRESSION "^0[\r\n]*$")

add_test(NAME Lab1Task2_Test1
    COMMAND Lab1Task2 "${CMAKE_CURRENT_SOURCE_DIR}/tests/task2_test1.txt")
set_tests_properties(Lab1Task2_Test1 PROPERTIES
    PASS_REGULAR_EXPRESSION "^2[\r\n]*$")

add_test(NAME Lab1Task2_Test2
    COMMAND Lab1Task2 "${CMAKE_CURRENT_SOURCE_DIR}/tests/task2_test2.txt")
set_tests_properties(Lab1Task2_Test2 PROPERTIES
    PASS_REGULAR_EXPRESSION "^6[\r\n]*$")