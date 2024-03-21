# CMake generated Testfile for 
# Source directory: D:/Codefield/DS/DSExercise/Tests
# Build directory: D:/Codefield/DS/build/Tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(complex_AssignComplex_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "0" "0")
set_tests_properties(complex_AssignComplex_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;14;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_002 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "1.2" "0")
set_tests_properties(complex_AssignComplex_002 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;15;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_003 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "-1.2" "0")
set_tests_properties(complex_AssignComplex_003 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;16;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_004 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "0" "2.3")
set_tests_properties(complex_AssignComplex_004 PROPERTIES  PASS_REGULAR_EXPRESSION "^2[.]30i" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;17;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_005 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "0" "-2.3")
set_tests_properties(complex_AssignComplex_005 PROPERTIES  PASS_REGULAR_EXPRESSION "^-2[.]30i" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;18;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_006 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "1.2" "2.3")
set_tests_properties(complex_AssignComplex_006 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20 [+] 2[.]30i[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;19;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_007 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "-1.2" "2.3")
set_tests_properties(complex_AssignComplex_007 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20 [+] 2[.]30i" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;20;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_008 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "1.2" "-2.3")
set_tests_properties(complex_AssignComplex_008 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20 - 2[.]30i" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;21;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AssignComplex_009 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AssignComplex" "-1.2" "-2.3")
set_tests_properties(complex_AssignComplex_009 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20 - 2[.]30i" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;22;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_CreateComplex_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "CreateComplex")
set_tests_properties(complex_CreateComplex_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;45;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;25;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_DestroyComplex_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "DestroyComplex")
set_tests_properties(complex_DestroyComplex_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0x0000000000000000[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;45;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;28;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "0" "0")
set_tests_properties(complex_GetReal_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;31;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_002 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "1.2" "0")
set_tests_properties(complex_GetReal_002 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;32;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_003 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "-1.2" "0")
set_tests_properties(complex_GetReal_003 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;33;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_004 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "0" "2.3")
set_tests_properties(complex_GetReal_004 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;34;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_005 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "0" "-2.3")
set_tests_properties(complex_GetReal_005 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;35;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_006 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "1.2" "2.3")
set_tests_properties(complex_GetReal_006 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;36;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_007 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "-1.2" "2.3")
set_tests_properties(complex_GetReal_007 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;37;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_008 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "1.2" "-2.3")
set_tests_properties(complex_GetReal_008 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;38;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetReal_009 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetReal" "-1.2" "-2.3")
set_tests_properties(complex_GetReal_009 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;39;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "0" "0")
set_tests_properties(complex_GetImage_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;42;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_002 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "1.2" "0")
set_tests_properties(complex_GetImage_002 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;43;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_003 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "-1.2" "0")
set_tests_properties(complex_GetImage_003 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;44;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_004 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "0" "2.3")
set_tests_properties(complex_GetImage_004 PROPERTIES  PASS_REGULAR_EXPRESSION "^2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;45;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_005 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "0" "-2.3")
set_tests_properties(complex_GetImage_005 PROPERTIES  PASS_REGULAR_EXPRESSION "^-2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;46;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_006 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "1.2" "2.3")
set_tests_properties(complex_GetImage_006 PROPERTIES  PASS_REGULAR_EXPRESSION "^2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;47;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_007 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "-1.2" "2.3")
set_tests_properties(complex_GetImage_007 PROPERTIES  PASS_REGULAR_EXPRESSION "^2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;48;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_008 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "1.2" "-2.3")
set_tests_properties(complex_GetImage_008 PROPERTIES  PASS_REGULAR_EXPRESSION "^-2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;49;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_GetImage_009 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "GetImage" "-1.2" "-2.3")
set_tests_properties(complex_GetImage_009 PROPERTIES  PASS_REGULAR_EXPRESSION "^-2[.]30[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;33;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;50;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_001 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "0" "0" "0" "0")
set_tests_properties(complex_AddComplex_001 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;53;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_002 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "1.2" "2.3" "-1.2" "-2.3")
set_tests_properties(complex_AddComplex_002 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;54;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_003 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "1.2" "-2.3" "-1.2" "2.3")
set_tests_properties(complex_AddComplex_003 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;55;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_004 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "-1.2" "2.3" "1.2" "-2.3")
set_tests_properties(complex_AddComplex_004 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;56;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_005 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "-1.2" "-2.3" "1.2" "2.3")
set_tests_properties(complex_AddComplex_005 PROPERTIES  PASS_REGULAR_EXPRESSION "^0[.]00[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;57;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_006 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "1.2" "2.3" "0" "-2.3")
set_tests_properties(complex_AddComplex_006 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;58;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_007 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "1.2" "0.6" "-1.2" "1.7")
set_tests_properties(complex_AddComplex_007 PROPERTIES  PASS_REGULAR_EXPRESSION "^2[.]30i[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;59;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_008 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "0.4" "0.6" "0.8" "1.7")
set_tests_properties(complex_AddComplex_008 PROPERTIES  PASS_REGULAR_EXPRESSION "^1[.]20 [+] 2[.]30i[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;60;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
add_test(complex_AddComplex_009 "D:/Codefield/DS/build/Tests/DSExerciseTest.exe" "complex" "AddComplex" "-0.4" "-0.6" "-0.8" "-1.7")
set_tests_properties(complex_AddComplex_009 PROPERTIES  PASS_REGULAR_EXPRESSION "^-1[.]20 - 2[.]30i[
]" _BACKTRACE_TRIPLES "D:/Codefield/DS/DSExercise/CMakeLists.txt;41;add_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;61;do_test;D:/Codefield/DS/DSExercise/Tests/CMakeLists.txt;0;")
