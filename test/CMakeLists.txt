
set(SOURCES
    filepath_test.cpp
    directories_test.cpp
    tests.cpp
    
)

add_executable(osutils_test ${SOURCES})
target_link_libraries(osutils_test osutils)

add_test (NAME osutils_test COMMAND osutils_test --home $ENV{HOME})
