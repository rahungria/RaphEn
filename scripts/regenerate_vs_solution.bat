@echo off

pushd ..\
del /s /f /q *.sln
del /s /f /q *.vcxproj
del /s /f /q *.vcxproj.filters
call vendor\premake\bin\premake5.exe vs2019
popd
PAUSE