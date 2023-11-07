// Структура данных таблица

#pragma once

#include <stdbool.h>

// Максимальное количество элементов таблицы.
#define TableBufferSize 100

// Операция выполнена успешно.
#define TableOk 0
// Таблица пуста.
#define TableEmpty 1
// Таблица заполнена.
#define TableFull 2
// Ключ в таблице не найден
#define TableNoKey 3

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int TableError;

#include <CNuke/Common.h>

// Элемент таблицы, содержит ключ Key и значение Value 
typedef struct {
    int Key;
    BaseType Value;
} TableElement;

typedef struct {
    TableElement Buf[TableBufferSize];
    size_t End;
} Table;

// Инициализирует пустую таблицу и возвращает её.
Table TableInit();

// Если в таблице T есть элемент с ключом E.Key, то обновляет его значение
// Если в таблице T нет элемента с таким ключом и T не переполнена, включает элемент
void TablePut(Table *T, TableElement E);

// Если в таблице T есть элемент с ключом E.Key, возвращает его и удаляет из таблицы
TableElement TableGet(Table T, int key);

// Возвращает true, если очередь T пуста, иначе - false.
bool TableIsEmpty(Table Q);

// Возвращает true, если очередь T заполнена, иначе - false.
bool TableIsFull(Table Q);