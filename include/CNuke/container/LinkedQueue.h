// Очередь как отображение на односвязный линейный список

#pragma once

#include <CNuke/list/SinglyLinkedList.h>

// Операция выполнена успешно.
#define LinkedQueueOk SinglyLinkedListOk
// Очередь пуста.
#define LinkedQueueEmpty SinglyLinkedListEmpty
// Недостаточно памяти для нового элемента.
#define LinkedQueueNotMem SinglyLinkedListNotMem

// Код ошибки, обновляется каждый раз после выполнения операции над стеком.
extern int LinkedQueueError;

#include <stdint.h>

#include <CNuke/Common.h>

typedef SinglyLinkedList LinkedQueue;

// Инициализирует пустую очередь и возвращает её.
LinkedQueue LinkedQueueInit();

// Добавляет в очередь Q элемент E, если это возможно.
void LinkedQueuePut(LinkedQueue *Q, BaseType E);

// Если очередь Q не пуста, исключает элемент и возвращает его.
BaseType LinkedQueueGet(LinkedQueue *Q);

// Возвращает true, если очередь Q пуста, иначе - false.
bool LinkedQueueIsEmpty(LinkedQueue Q);

// Освобождает память, занятую очередью Q
void LinkedQueueDone(LinkedQueue *Q);