include(../../cmake/testing_utils.cmake)

SETUP_UNITTEST_ENV()

if(GTest_FOUND)

  set( UNITTEST_DIR unittests )
  set( UNITTESTS
    predefined_string_match_unittests
    )

  ADD_UNITTESTS(dte3603::${PROJECT_NAME} ${UNITTEST_DIR} UNITTESTS
    dte3603::predef_shared)

endif(GTest_FOUND)
