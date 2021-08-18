include(../../cmake/testing_utils.cmake)

SETUP_UNITTEST_ENV()

if(GTest_FOUND)

  set( UNITTEST_DIR unittests )
  set( UNITTESTS
    predefined_dijkstra_sp_unittests
    predefined_astar_sp_unittests
    )

  ADD_UNITTESTS(dte3603::${PROJECT_NAME} ${UNITTEST_DIR} UNITTESTS
    dte3603::predef_shared Boost::graph)

endif(GTest_FOUND)
