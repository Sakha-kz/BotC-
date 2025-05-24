#!/bin/bash

echo "===== СБОРКА: SmartAssistantBot (Linux) ====="
echo

cd "$(dirname "$0")" || { echo "Не удалось перейти в директорию"; exit 1; }

if [ -d build ]; then
    echo "[1/4] Удаление build/"
    rm -rf build
fi

echo "[2/4] Создание build/"
mkdir build && cd build || { echo "Не удалось создать build"; exit 1; }

echo "[3/4] Генерация CMake..."
cmake .. 
if [ $? -ne 0 ]; then
    echo "[X] Ошибка CMake!"
    exit 1
fi

echo "[4/4] Сборка проекта..."
make
if [ $? -ne 0 ]; then
    echo "[X] Ошибка сборки!"
    exit 1
fi

echo "--- Запуск бота ---"
./SmartAssistantBot

exit 0