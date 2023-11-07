// Структура данных файл

#pragma once

#include <CNuke/container/ArrayQueue.h>

// Операция выполнена успешно.
#define FileOk 0
// Достигнут конец файла.
#define FileEnd 1
// Недостаточно памяти для нового элемента.
#define FileNotMem 2

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int FileError;

typedef struct {
    // Прочитанные данные
    ArrayQueue Read;
    // Непрочитанные данные
    ArrayQueue Buf;
} File;


// Инициализирует файл и возвращает его.
File FileInit();

// Прочитывает элемент из F и возвращает его, если можно выполнить это действие. 
BaseType FileRead(File *F);

// Включает в файл F элемент E.
void FilePut(File* F, BaseType E);

// Устанавливает указатель в начало.
void FileBeginPtr(File* F);