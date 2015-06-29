set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES *.cpp)
SET(LARANK_SOURCES linear_larank/LaRank.cpp linear_larank/vectors.cpp)

find_package(Eigen REQUIRED)
find_package(Config REQUIRED)

include_directories("linear_larank")
include_directories("${EIGEN_INCLUDE_DIRS}")
include_directories("${CONFIG_INCLUDE_DIR}")

SET(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} ${EIGEN_DEFINITIONS}")

add_library(omclboost STATIC ${SOURCES} ${LARANK_SOURCES})
add_executable(runomclboost ${SOURCES} ${LARANK_SOURCES})

target_link_libraries(
    omclboost
    ${CONFIG_LIBRARIES}
)


#install(TARGETS omclboost
#    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#)
