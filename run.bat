@echo off

set TARGET_NAME=vault-cli.exe
set ROOT_FOLDER=D:\Users\aauhabin1\dev\c\comptime\
set CLI_ARGS=%*

pushd %ROOT_FOLDER%
call ./build.bat

if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%
echo:

pushd bin
%TARGET_NAME% %CLI_ARGS%
popd
popd