
set(SOURCES
    filepath.cpp
    directories.cpp
)

add_library(osutils ${SOURCES})
target_include_directories(osutils PUBLIC ${PROJECT_ROOT}/include)
