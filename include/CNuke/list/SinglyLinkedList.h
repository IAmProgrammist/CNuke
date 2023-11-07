// Структура данных односвязный линейный список

#pragma once

#include <stdbool.h>

// Операция выполнена успешно.
#define SinglyLinkedListOk 0
// Лист пуст.
#define SinglyLinkedListEmpty 1
// Память для нового элемента выделить не удалось.
#define SinglyLinkedListNotMem 2
// Рабочий указатель стоит на последнем элементе списка.
#define SinglyLinkedListEnd 3

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int SinglyLinkedListError;

#include <CNuke/Common.h>

typedef struct SinglyLinkedListElement {
    BaseType Value;
    struct SinglyLinkedListElement* Next;
} SinglyLinkedListElement;

typedef SinglyLinkedListElement* SinglyLinkedListElementPtr;

typedef struct {
    SinglyLinkedListElementPtr Begin;
    SinglyLinkedListElementPtr Ptr;
} SinglyLinkedList;

// Инициализирует пустой односвязный линейный список и возвращает его.
SinglyLinkedList SinglyLinkedListInit();

// Включает в односвязный линейный список элемент после рабочего указателя.
void SinglyLinkedListPut(SinglyLinkedList *L, BaseType E);

// Возвращает значение элемента идущего после рабочего указателя и удаляет его из списка L.
BaseType SinglyLinkedListGet(SinglyLinkedList *L);

// Передвигает рабочий указатель на следующий элемент в списке L.
void SinglyLinkedListMovePtr(SinglyLinkedList *L);

// Возвращает true, если односвязный линейный список L пуст, иначе - false.
bool SinglyLinkedListIsEmpty(SinglyLinkedList L);

// Освобождает память, занятую односвязным линейным списком L.
void SinglyLinkedListDone(SinglyLinkedList *L);

// Перемещает рабочий указатель L в начало
void SinglyLinkedListBeginPtr(SinglyLinkedList *L);

// Перемещает рабочий указатель L в конец.
void SinglyLinkedListEndPtr(SinglyLinkedList *L);