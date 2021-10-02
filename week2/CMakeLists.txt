project(week2)

# Add library target
add_library(${PROJECT_NAME} INTERFACE )

# Headers
target_include_directories( ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include> )

# Make ${PROJECT_NAME} available as a direct linkable target
add_library(dte3603::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Unit tests
option(BUILD_UNITTESTS_WEEK2 "Build unittests Week 2" OFF)
if(BUILD_UNITTESTS_WEEK2)
  add_subdirectory(testing)
endif(BUILD_UNITTESTS_WEEK2)

# Benchmarking
option(BUILD_BENCHMARKS_WEEK2 "Build benchmarks Week 2" OFF)
if(BUILD_BENCHMARKS_WEEK2)
  add_subdirectory(benchmarking)
endif(BUILD_BENCHMARKS_WEEK2)
