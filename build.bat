@echo off
setlocal
chcp 65001 > nul

set "PATH=C:\msys64\mingw64\bin;%PATH%"

echo.
echo ===== СБОРКА: SmartAssistantBot (Windows) =====
echo.

cd /d "%~dp0"

if exist build (
    echo Удаление папки build...
    rmdir /s /q build
)

mkdir build
cd build

echo --- Генерация CMake ---
cmake .. -G "MinGW Makefiles" ^
  -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe ^
  -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe

if errorlevel 1 (
    echo [X] Ошибка генерации CMake!
    pause
    exit /b 1
)

echo --- Сборка ---
mingw32-make

if errorlevel 1 (
    echo [X] Ошибка сборки!
    pause
    exit /b 1
)

echo --- Запуск ---
SmartAssistantBot.exe

pause