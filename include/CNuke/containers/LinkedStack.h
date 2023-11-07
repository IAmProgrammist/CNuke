// Стек как отображение на односвязный линейный список

#pragma once

#include <CNuke/list/SinglyLinkedList.h>

// Операция выполнена успешно.
#define LinkedStackOk SinglyLinkedListOk
// Стек пуст.
#define LinkedStackEmpty SinglyLinkedListEmpty
// Недостаточно памяти для нового элемента.
#define LinkedStackNotMem SinglyLinkedListNotMem

// Код ошибки, обновляется каждый раз после выполнения операции над стеком.
extern int LinkedStackError;

#include <stdint.h>

#include <CNuke/Common.h>

typedef SinglyLinkedList LinkedStack;

// Инициализирует пустой стек и возвращает его.
LinkedStack LinkedStackInit();

// Добавляет в стек S элемент E, если это возможно.
void LinkedStackPut(LinkedStack *S, BaseType E);

// Если стек S не пуст, исключает элемент и возвращает его.
BaseType LinkedStackGet(LinkedStack *S);

// Возвращает true, если стек S пуст, иначе - false.
bool LinkedStackIsEmpty(LinkedStack S);

// Освобождает память, занятую стеком S
void LinkedStackDone(LinkedStack *S);