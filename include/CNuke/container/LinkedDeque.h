// Дек как отображение на двусвязный линейный список

#pragma once

#include <CNuke/list/DoublyLinkedList.h>

// Операция выполнена успешно.
#define LinkedDequeOk DoublyLinkedListOk
// Не удалось выделить память для нового элемента.
#define LinkedDequeNotMem DoublyLinkedListNotMem
// Дек пуст
#define LinkedDequeEmpty DoublyLinkedListEmpty

// Код ошибки, обновляется каждый раз после выполнения операции над очередью.
extern int LinkedDequeError;

typedef DoublyLinkedList LinkedDeque;

// Инициализирует пустой дек и возвращает его.
LinkedDeque LinkedDequeInit();

// Освобождает память, занятую деком D.
void LinkedDequeDone(LinkedDeque* D);

// Включает в дек D элемент E в конец списка.
void LinkedDequePutEnd(LinkedDeque* D, BaseType E);

// Включает в дек D элемент E в начало списка.
void LinkedDequePutBegin(LinkedDeque* D, BaseType E);

// Возвращает значение элемента в начале и удаляет его из дека D.
BaseType LinkedDequeGetBegin(LinkedDeque* D);

// Возвращает значение элемента в конце и удаляет его из дека D.
BaseType LinkedDequeGetEnd(LinkedDeque* D);

// Возвращает true, если дек D пуст, иначе - false.
bool LinkedDequeIsEmpty(LinkedDeque* D);