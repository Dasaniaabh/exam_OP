#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Структура для представления данных
typedef struct {
    int value;
    char *name;
} Data;

// Функция для обработки структуры
void processData(Data *data) {
    if (data == NULL) {
        // Обработка ошибки: структура пуста
        fprintf(stderr, "Ошибка: Структура пуста. Файл: %s, Строка: %d\n", FILE, LINE);
        perror("processData: "); // Вывод системной ошибки
        return;
    }

    printf("Значение: %d\n", data->value);
    printf("Название: %s\n", data->name);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Создание структуры
    Data *data = malloc(sizeof(Data));
    Data *new_data = NULL;

    if (data == NULL) {
        // Обработка ошибки: ошибка выделения памяти
        fprintf(stderr, "Ошибка: Не удалось выделить память. Файл: %s, Строка: %d\n", FILE, LINE);
        perror("main: "); // Вывод системной ошибки
        return 1;
    }

    // Инициализация структуры
    data->value = 10;
    data->name = "Пример";

    // Вызов функции обработки 1 случая
    processData(data);

    // Вызов функции обработки 2 случая (не инициализируем new_data)
    processData(new_data);  // Здесь new_data не инициализирован, поэтому вызовет ошибку

    // Освобождение памяти
    free(data);

    return 0;
}