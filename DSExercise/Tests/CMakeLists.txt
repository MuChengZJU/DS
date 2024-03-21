# 编译输出DSExerciseTest.exe
add_executable(DSExerciseTest
    DSExerciseTest.c
    ../MathComplex/Complex.c
    ../MathComplex/Complex.h)

## 自动测试用例
# "\^"表示从打印输出的行首开始匹配
# "[.]"表示匹配一个小数点
# "[\n]"表示匹配一个换行符
# "[+]"表示匹配一个加号

# 自动测试AssignComplex方法
do_test(complex AssignComplex 001 "\^0[.]00" 0 0)
do_test(complex AssignComplex 002 "\^1[.]20" 1.2 0)
do_test(complex AssignComplex 003 "\^-1[.]20" -1.2 0)
do_test(complex AssignComplex 004 "\^2[.]30i" 0 2.3)
do_test(complex AssignComplex 005 "\^-2[.]30i" 0 -2.3)
do_test(complex AssignComplex 006 "\^1[.]20 [+] 2[.]30i[\n]" 1.2 2.3)
do_test(complex AssignComplex 007 "\^-1[.]20 [+] 2[.]30i" -1.2 2.3)
do_test(complex AssignComplex 008 "\^1[.]20 - 2[.]30i" 1.2 -2.3)
do_test(complex AssignComplex 009 "\^-1[.]20 - 2[.]30i" -1.2 -2.3)

# 自动测试CreateComplex方法
do_test(complex CreateComplex 001 "\^0[.]00[\n]")

# 自动测试DestroyComplex方法
do_test(complex DestroyComplex 001 "\^0x0000000000000000[\n]")

# 自动测试GetReal方法
do_test(complex GetReal 001 "\^0[.]00[\n]" 0 0)
do_test(complex GetReal 002 "\^1[.]20[\n]" 1.2 0)
do_test(complex GetReal 003 "\^-1[.]20[\n]" -1.2 0)
do_test(complex GetReal 004 "\^0[.]00[\n]" 0 2.3)
do_test(complex GetReal 005 "\^0[.]00[\n]" 0 -2.3)
do_test(complex GetReal 006 "\^1[.]20[\n]" 1.2 2.3)
do_test(complex GetReal 007 "\^-1[.]20[\n]" -1.2 2.3)
do_test(complex GetReal 008 "\^1[.]20[\n]" 1.2 -2.3)
do_test(complex GetReal 009 "\^-1[.]20[\n]" -1.2 -2.3)

# 自动测试GetImage方法
do_test(complex GetImage 001 "\^0[.]00[\n]" 0 0)
do_test(complex GetImage 002 "\^0[.]00[\n]" 1.2 0)
do_test(complex GetImage 003 "\^0[.]00[\n]" -1.2 0)
do_test(complex GetImage 004 "\^2[.]30[\n]" 0 2.3)
do_test(complex GetImage 005 "\^-2[.]30[\n]" 0 -2.3)
do_test(complex GetImage 006 "\^2[.]30[\n]" 1.2 2.3)
do_test(complex GetImage 007 "\^2[.]30[\n]" -1.2 2.3)
do_test(complex GetImage 008 "\^-2[.]30[\n]" 1.2 -2.3)
do_test(complex GetImage 009 "\^-2[.]30[\n]" -1.2 -2.3)

# 自动测试AddComplex方法
do_test(complex AddComplex 001 "\^0[.]00[\n]" 0 0 0 0)
do_test(complex AddComplex 002 "\^0[.]00[\n]" 1.2 2.3 -1.2 -2.3)
do_test(complex AddComplex 003 "\^0[.]00[\n]" 1.2 -2.3 -1.2 2.3)
do_test(complex AddComplex 004 "\^0[.]00[\n]" -1.2 2.3 1.2 -2.3)
do_test(complex AddComplex 005 "\^0[.]00[\n]" -1.2 -2.3 1.2 2.3)
do_test(complex AddComplex 006 "\^1[.]20[\n]" 1.2 2.3 0 -2.3)
do_test(complex AddComplex 007 "\^2[.]30i[\n]" 1.2 0.6 -1.2 1.7)
do_test(complex AddComplex 008 "\^1[.]20 [+] 2[.]30i[\n]" 0.4 0.6 0.8 1.7)
do_test(complex AddComplex 009 "\^-1[.]20 - 2[.]30i[\n]" -0.4 -0.6 -0.8 -1.7)
