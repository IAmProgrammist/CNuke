// Структура данных двусвязный линейный список

#pragma once

#include <stdbool.h>

// Операция выполнена успешно.
#define DoublyLinkedListOk 0
// Лист пуст.
#define DoublyLinkedListEmpty 1
// Не удалось выделить память для нового элемента.
#define DoublyLinkedListNotMem 2
// Рабочий указатель находится в конце списка
#define DoublyLinkedListEnd 3
// Рабочий указатель находится в начале списка
#define DoublyLinkedListBegin 4

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int DoublyLinkedListError;

#include <CNuke/Common.h>

typedef struct DoublyLinkedListElement {
    BaseType Value;
    struct DoublyLinkedListElement* Next;
    struct DoublyLinkedListElement* Prev;
} DoublyLinkedListElement;

typedef DoublyLinkedListElement* DoublyLinkedListElementPtr;

typedef struct {
    DoublyLinkedListElementPtr Begin;
    DoublyLinkedListElementPtr End;
    DoublyLinkedListElementPtr Ptr;
} DoublyLinkedList;

// Инициализирует пустой двусвязный линейный список и возвращает его.
DoublyLinkedList DoublyLinkedListInit();

// Включает в двусвязный линейный список L элемент E до рабочего указателя.
void DoublyLinkedListPutBefore(DoublyLinkedList* L, BaseType E);

// Включает в двусвязный линейный список L элемент E после рабочего указателя.
void DoublyLinkedListPutAfter(DoublyLinkedList* L, BaseType E);

// Возвращает значение элемента идущего до рабочего указателя и удаляет его из списка L.
BaseType DoublyLinkedListGetBefore(DoublyLinkedList *L);

// Возвращает значение элемента идущего после рабочего указателя и удаляет его из списка L.
BaseType DoublyLinkedListGetAfter(DoublyLinkedList *L);

// Передвигает рабочий указатель на предыдущий элемент в списке L.
void DoublyLinkedListMoveL(DoublyLinkedList *L);

// Передвигает рабочий указатель на следующий элемент в списке L.
void DoublyLinkedListMoveR(DoublyLinkedList *L);

// Освобождает память, занятую двусвязным линейным списком L.
void DoublyLinkedListDone(DoublyLinkedList *L);

// Перемещает рабочий указатель L в начало
void DoublyLinkedListBeginPtr(DoublyLinkedList *L);

// Перемещает рабочий указатель L в конец.
void DoublyLinkedListEndPtr(DoublyLinkedList *L);