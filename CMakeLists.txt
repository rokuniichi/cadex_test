cmake_minimum_required (VERSION 3.4)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (cadex_test)

# CMake 3.4 feature that enables us to automatically generate module definition information
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

add_subdirectory(curves_lib)
add_executable (cadex_test  "main.cpp")
# Link the library to the project's executable
target_link_libraries (cadex_test curves_lib)

# Copy the library .dll to the project's executable location
add_custom_command(TARGET cadex_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE_DIR:curves_lib>/curves_lib.dll
        $<TARGET_FILE_DIR:cadex_test>)

# Using C++11 standard
set_property(TARGET cadex_test PROPERTY CXX_STANDARD 11)