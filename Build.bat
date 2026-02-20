@echo off

if exist "Bin" (
	rmdir /s /q "Bin"
)

echo CONFIGURING
cmake -S . -B Build -G Ninja

echo BUILDING
cmake --build Build

echo INSTALLING
cmake --install Build
