cmake_minimum_required(VERSION 3.0.0)
project(DSExercise VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DSExercise
    DSExercise.c
    MathComplex/MathComplex.c
    MathComplex/Complex.c
    MathComplex/Complex.h
    DataStructures/LinkedList.c
    DataStructures/LinkedList.h
    Polynomial/Polynomial.c
    Polynomial/Polynomial.h
    Polynomial/Lab2.c
    Expression/Expression.c
    Expression/Expression.h
    Expression/Stack.c
    Expression/Stack.h
    DynamicString/DynamicString.c
    DynamicString/DynamicString.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_compile_options(-Wall -Wextra -pedantic)

## 自动测试函数
# do_test: 测试用函数
# $<TARGET_FILE:DSExerciseTest>：指执行编译输出的DSExercise.exe进行测试
# testname: 所测试的数据结构名称
# testfunc：所测试的数据机构的操作方法
# result：预期的输出，用于正则式结果匹配，如果匹配成功，则测试通过，否则测试失败
# ${ARGC}：调用do_test测试函数时传入的参数个数
# ${ARGV4} - ${ARGV7}：调用do_test测试函数时的第4到第7个参数
function(do_test testname testfunc testnum result)
    if(${ARGC} EQUAL 5)
        add_test(NAME ${testname}_${testfunc}_${testnum}
            COMMAND $<TARGET_FILE:DSExerciseTest>
                ${testname} ${testfunc} ${ARGV4})
    elseif(${ARGC} EQUAL 6)
        add_test(NAME ${testname}_${testfunc}_${testnum}
                COMMAND $<TARGET_FILE:DSExerciseTest>
                    ${testname} ${testfunc} ${ARGV4} ${ARGV5})
    elseif(${ARGC} EQUAL 7)
        add_test(NAME ${testname}_${testfunc}_${testnum}
                COMMAND $<TARGET_FILE:DSExerciseTest>
                    ${testname} ${testfunc} ${ARGV4} ${ARGV5} ${ARGV6})
    elseif(${ARGC} EQUAL 8)
        add_test(NAME ${testname}_${testfunc}_${testnum}
                COMMAND $<TARGET_FILE:DSExerciseTest>
                    ${testname} ${testfunc} ${ARGV4} ${ARGV5} ${ARGV6} ${ARGV7})
    else()
        add_test(NAME ${testname}_${testfunc}_${testnum}
                COMMAND $<TARGET_FILE:DSExerciseTest>
                    ${testname} ${testfunc})
    endif()    

    set_tests_properties(${testname}_${testfunc}_${testnum} 
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

# 增加对Tests目录的编译
add_subdirectory(Tests)