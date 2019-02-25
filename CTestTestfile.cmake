# CMake generated Testfile for 
# Source directory: C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string
# Build directory: C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(unit_tests "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/Debug/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;51;add_test;C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(unit_tests "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/Release/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;51;add_test;C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(unit_tests "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/MinSizeRel/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;51;add_test;C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(unit_tests "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/RelWithDebInfo/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;51;add_test;C:/Users/Robinzon/Documents/Чики-Брики/lab-01-string/CMakeLists.txt;0;")
else()
  add_test(unit_tests NOT_AVAILABLE)
endif()
