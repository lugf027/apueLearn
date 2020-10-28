cmake_minimum_required(VERSION 3.17)
project(unixLearn C)

set(CMAKE_C_STANDARD 11)

add_executable(unixLearn main.c)

add_executable(1_3_ls src/ch1/1_3_ls/ls.c)
add_executable(1_4_cp src/ch1/1_4_cp/cp.c)
add_executable(1_5_cp src/ch1/1_5_cp_std_io/cpStdio.c)
add_executable(1_6_processIdPrint src/ch1/1_6_processIdPrint/processIdPrint.c)
add_executable(1_7_simpleShell src/ch1/1_7_simpleShell/simpleShell.c)
add_executable(1_8_errno src/ch1/1_8_errno/errno.c)
add_executable(1_9_userId src/ch1/1_9_userId/userId.c)
add_executable(1_10_signalShell src/ch1/1_10_signalShell/signalShell.c)

add_executable(2_14_conf src/ch2/2_14_conf/conf.c)
add_executable(2_16_dymPath src/ch2/2_16_dymPath/dymPath.c)
add_executable(2_17_fileOpenNum src/ch2/2_17_fileOpenNum/fileOpenNum.c)
