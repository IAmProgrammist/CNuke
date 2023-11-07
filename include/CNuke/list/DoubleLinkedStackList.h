// Структура данных двусвязный линейный список на двух очередях

#pragma once

#include <stdbool.h>

// Операция выполнена успешно.
#define DoublyLinkedStackListOk 0
// Лист пуст.
#define DoublyLinkedStackListEmpty 1
// Не удалось выделить память для нового элемента.
#define DoublyLinkedStackListNotMem 2
// Рабочий указатель находится в конце списка
#define DoublyLinkedStackListEnd 3
// Рабочий указатель находится в начале списка
#define DoublyLinkedStackListBegin 4

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int DoublyLinkedStackListError;

#include <CNuke/Common.h>
#include <CNuke/container/LinkedStack.h>

typedef struct {
    LinkedStack Left;
    LinkedStack Right;
} DoublyLinkedStackList;

// Инициализирует пустой двусвязный линейный список и возвращает его.
DoublyLinkedStackList DoublyLinkedStackListInit();

// Включает в двусвязный линейный список L элемент E до текущего элемента.
void DoublyLinkedStackListPutBefore(DoublyLinkedStackList* L, BaseType E);

// Включает в двусвязный линейный список L элемент E после текущего элемента.
void DoublyLinkedStackListPutAfter(DoublyLinkedStackList* L, BaseType E);

// Возвращает значение элемента идущего до текущего элемента и удаляет его из списка L.
BaseType DoublyLinkedStackListGetBefore(DoublyLinkedStackList *L);

// Возвращает значение элемента идущего после текущего элемента и удаляет его из списка L.
BaseType DoublyLinkedStackListGetAfter(DoublyLinkedStackList *L);

// Передвигает текущий элемент на следующий в списке L.
void DoublyLinkedStackListMoveL(DoublyLinkedStackList *L);

// Передвигает текущий элемент на предыдущий в списке L.
void DoublyLinkedStackListMoveR(DoublyLinkedStackList *L);

// Освобождает память, занятую двусвязным линейным списком L.
void DoublyLinkedStackListDone(DoublyLinkedStackList *L);

// Перемещает текущий элемент в L в начало
void DoublyLinkedStackListBeginPtr(DoublyLinkedStackList *L);

// Перемещает текущий элемент в L в конец.
void DoublyLinkedStackListEndPtr(DoublyLinkedStackList *L);