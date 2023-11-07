// Структура данных односвязный линейный список на статическом массиве

#pragma once

#include <stdbool.h>

// Максимальное количество элементов в списке
#define SinglyLinkedArrayListBufferSize 100

// Операция выполнена успешно.
#define SinglyLinkedArrayListOk 0
// Лист пуст.
#define SinglyLinkedArrayListEmpty 1
// Память для нового элемента выделить не удалось.
#define SinglyLinkedArrayListFull 2
// Рабочий указатель стоит на последнем элементе списка.
#define SinglyLinkedArrayListEnd 3

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int SinglyLinkedArrayListError;

#include <CNuke/Common.h>

typedef size_t SinglyLinkedArrayListElementPtr;

typedef struct {
    BaseType Value;
    SinglyLinkedArrayListElementPtr Next;
} SinglyLinkedArrayListElement;

typedef struct {
    SinglyLinkedArrayListElement Buf[SinglyLinkedArrayListBufferSize];
    bool Taken[SinglyLinkedArrayListBufferSize];
    SinglyLinkedArrayListElementPtr Begin;
    SinglyLinkedArrayListElementPtr Ptr;
} SinglyLinkedArrayList;

// Инициализирует пустой односвязный линейный список и возвращает его.
SinglyLinkedArrayList SinglyLinkedArrayListInit();

// Включает в односвязный линейный список элемент после рабочего указателя.
void SinglyLinkedArrayListPut(SinglyLinkedArrayList *L, BaseType E);

// Возвращает значение элемента идущего после рабочего указателя.
BaseType SinglyLinkedArrayListGet(SinglyLinkedArrayList *L);

// Передвигает рабочий указатель на следующий элемент.
void SinglyLinkedArrayListMovePtr(SinglyLinkedArrayList *L);

// Возвращает true, если односвязный линейный список L пуст, иначе - false.
bool SinglyLinkedArrayListIsEmpty(SinglyLinkedArrayList L);

// Перемещает рабочий указатель L в начало
void SinglyLinkedArrayListBeginPtr(SinglyLinkedArrayList *L);

// Перемещает рабочий указатель L в конец.
void SinglyLinkedArrayListEndPtr(SinglyLinkedArrayList *L);