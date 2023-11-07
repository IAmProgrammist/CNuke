// Очередь как отображение на статический массив

#pragma once

#include <stdbool.h>
#include <stdint.h>

// Максимальное количество элементов очереди на массиве.
#define ArrayQueueBufferSize 100

// Операция выполнена успешно.
#define ArrayQueueOk 0
// Очередь пуста.
#define ArrayQueueEmpty 1
// Очередь заполнена.
#define ArrayQueueFull 2

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int ArrayQueueError;

#include <CNuke/Common.h>

typedef struct {
    BaseType Buf[ArrayQueueBufferSize];
    size_t Begin;
    size_t End;
    size_t Size;
} ArrayQueue;

// Инициализирует пустую очередь и возвращает её.
ArrayQueue ArrayQueueInit();

// Если очереь Q не переполнена, добавляет наверх в неё элемент E.
void ArrayQueuePut(ArrayQueue *Q, BaseType E);

// Если очередь Q не пуста, исключает нижний элемент и возвращает его.
BaseType ArrayQueueGet(ArrayQueue *Q);

// Возвращает true, если очередь Q пуста, иначе - false.
bool ArrayQueueIsEmpty(ArrayQueue Q);

// Возвращает true, если очередь Q заполнена, иначе - false.
bool ArrayQueueIsFull(ArrayQueue Q);