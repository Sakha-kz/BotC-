@echo off
setlocal
chcp 65001 > nul

set "PATH=C:\msys64\mingw64\bin;%PATH%"

echo.
echo ===== СБОРКА ПРОЕКТА BotC =====
echo.

cd /d "%~dp0"

if exist build (
    echo Удаление старой папки build...
    rmdir /s /q build
)

mkdir build
cd build

echo.
echo [1/3] Генерация CMake...
cmake .. -G "MinGW Makefiles" ^
  -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe ^
  -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe
if errorlevel 1 (
    echo Ошибка генерации CMake!
    pause
    exit /b 1
)

echo.
echo [2/3] Сборка проекта...
mingw32-make
if errorlevel 1 (
    echo Ошибка сборки!
    pause
    exit /b 1
)

echo.
echo [3/3] Готова

echo.
pause