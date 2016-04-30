set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES *.cpp)
SET(LARANK_SOURCES linear_larank/LaRank.cpp linear_larank/vectors.cpp)

find_package(Eigen REQUIRED)

include_directories("linear_larank")
include_directories("${EIGEN_INCLUDE_DIRS}")

SET(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} ${EIGEN_DEFINITIONS}")

add_library(omclboost STATIC ${SOURCES} ${LARANK_SOURCES})
#add_executable(omclboost ${SOURCES} ${LARANK_SOURCES})

target_link_libraries(
    omclboost
)


#install(TARGETS omclboost
#    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#)
