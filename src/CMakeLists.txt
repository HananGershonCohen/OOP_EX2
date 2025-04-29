file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Butten.h" "Butten.cpp" "../include/Constants.h" "../include/SfmlMan.h" "../include/Date.h" "Date.cpp" "../include/Validator.h"  "../include/Field.h" "Field.cpp")
