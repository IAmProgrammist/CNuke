// Стек как отображение на статический массив

#pragma once

#include <stdbool.h>

// Максимальное количество элементов стека на массиве.
#define ArrayStackBufferSize 100

// Операция выполнена успешно.
#define ArrayStackOk 0
// Стек пуст.
#define ArrayStackEmpty 1
// Стек заполнен.
#define ArrayStackFull 2

// Код ошибки, обновляется каждый раз после выполнения операции над стеком.
extern int ArrayStackError;

#include <stdint.h>

#include <CNuke/Common.h>

typedef struct {
    BaseType Buf[ArrayStackBufferSize];
    size_t End;
} ArrayStack;

// Инициализирует пустой стек и возвращает его.
ArrayStack ArrayStackInit();

// Если стек S не переполнен, добавляет в него элемент E.
void ArrayStackPut(ArrayStack *S, BaseType E);

// Если стек S не пуст, исключает верхний элемент и возвращает его.
BaseType ArrayStackGet(ArrayStack *S);

// Возвращает true, если стек S пуст, иначе - false.
bool ArrayStackIsEmpty(ArrayStack S);

// Возвращает true, если стек S заполнен, иначе - false.
bool ArrayStackIsFull(ArrayStack S);