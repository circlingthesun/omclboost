project(OMCLBoost)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../../cmake")
find_package(Eigen REQUIRED)
include_directories("${EIGEN_INCLUDE_DIRS}")

SET(TOOLS LaRank.cpp vectors.cpp)
SET(TOOLSINCL LaRank.h vectors.h wrapper.h)
SET(LARANKSRC LaRankLearn.cpp)
SET(LARANKTESTSRC LaRankClassify.cpp)

add_library(la_rank_learn STATIC ${LARANKSRC})
#add_library(la_rank_classify STATIC ${LARANKTESTSRC})
