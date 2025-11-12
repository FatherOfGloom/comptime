@echo off

@REM TODO: generate lib folder + run cmake + copy to lib

set TARGET_NAME=comptime.exe
set SRC_FILENAMES=main.c 
set ROOT_FOLDER=D:\Users\aauhabin1\dev\c\comptime\
set CFLAGS=-Wall -Wextra -pedantic -ggdb -fanalyzer -std=c11 -O1 
set LINK_LIBRARIES=tree-sitter tree-sitter-c

setlocal enabledelayedexpansion

set SRC_PATHS=

for %%i in (%SRC_FILENAMES%) do (set SRC_PATHS=!SRC_PATHS! %ROOT_FOLDER%src\%%i)

set LINK_FLAGS=

for %%i in (%LINK_LIBRARIES%) do (set LINK_FLAGS=!LINK_FLAGS! -l%%i)

echo %SRC_PATHS%
echo %LINK_FLAGS%

pushd %ROOT_FOLDER%

if not exist bin mkdir bin

@echo on
gcc  %SRC_PATHS% -Ilib -Llib %LINK_FLAGS% -o bin/%TARGET_NAME% %CFLAGS%
@echo off

if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

echo build success.

endlocal