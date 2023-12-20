// Структура данных односвязный линейный список

#pragma once

#include <stdbool.h>

// Операция выполнена успешно.
#define SinglyLinkedListCycledOk 0
// Лист пуст.
#define SinglyLinkedListCycledEmpty 1
// Память для нового элемента выделить не удалось.
#define SinglyLinkedListCycledNotMem 2
// Рабочий указатель стоит на последнем элементе списка.
#define SinglyLinkedListCycledEnd 3

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int SinglyLinkedListCycledCycledError;

#include <CNuke/Common.h>

typedef struct SinglyLinkedListCycledElement {
    BaseType Value;
    struct SinglyLinkedListCycledElement* Next;
} SinglyLinkedListCycledElement;

typedef SinglyLinkedListCycledElement* SinglyLinkedListCycledElementPtr;

typedef struct {
    SinglyLinkedListCycledElementPtr Begin;
    SinglyLinkedListCycledElementPtr Ptr;
} SinglyLinkedListCycled;

// Инициализирует пустой односвязный линейный список и возвращает его.
SinglyLinkedListCycled SinglyLinkedListCycledInit();

// Включает в односвязный линейный список элемент после рабочего указателя.
void SinglyLinkedListCycledPut(SinglyLinkedListCycled *L, BaseType E);

// Возвращает значение элемента идущего после рабочего указателя и удаляет его из списка L.
BaseType SinglyLinkedListCycledGet(SinglyLinkedListCycled *L);

// Передвигает рабочий указатель на следующий элемент в списке L.
void SinglyLinkedListCycledMovePtr(SinglyLinkedListCycled *L);

// Возвращает true, если односвязный линейный список L пуст, иначе - false.
bool SinglyLinkedListCycledIsEmpty(SinglyLinkedListCycled L);

// Освобождает память, занятую односвязным линейным списком L.
void SinglyLinkedListCycledDone(SinglyLinkedListCycled *L);

// Перемещает рабочий указатель L в начало
void SinglyLinkedListCycledBeginPtr(SinglyLinkedListCycled *L);

// Перемещает рабочий указатель L в конец.
void SinglyLinkedListCycledEndPtr(SinglyLinkedListCycled *L);