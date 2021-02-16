@echo off
call vendor\premake\premake5.exe vs2019
echo.
echo Launching Visual Studio...
start Nerthus.sln
timeout 3
EXIT