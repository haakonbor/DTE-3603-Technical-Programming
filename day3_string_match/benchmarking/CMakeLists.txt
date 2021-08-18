include(../../cmake/testing_utils.cmake)

SETUP_BENCHMARK_ENV()

if(benchmark_FOUND)

  set( BENCHMARKS_DIR benchmarks )
  set( BENCHMARKS
    predefined_string_match_bechmarks
    )

  ADD_BENCHMARKS(dte3603::${PROJECT_NAME} ${BENCHMARKS_DIR} BENCHMARKS
    dte3603::predef_shared)

endif(benchmark_FOUND)
