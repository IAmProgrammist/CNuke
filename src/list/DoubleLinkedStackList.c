#include <CNuke/list/DoubleLinkedStackList.h>

DoublyLinkedStackList DoublyLinkedStackListInit() {
    
}

void DoublyLinkedStackListPutBefore(DoublyLinkedStackList* L, BaseType E);

void DoublyLinkedStackListPutAfter(DoublyLinkedStackList* L, BaseType E);

BaseType DoublyLinkedStackListGetBefore(DoublyLinkedStackList *L);

BaseType DoublyLinkedStackListGetAfter(DoublyLinkedStackList *L);

void DoublyLinkedStackListMoveL(DoublyLinkedStackList *L);

void DoublyLinkedStackListMoveR(DoublyLinkedStackList *L);

void DoublyLinkedStackListDone(DoublyLinkedStackList *L);

void DoublyLinkedStackListBeginPtr(DoublyLinkedStackList *L);

void DoublyLinkedStackListEndPtr(DoublyLinkedStackList *L);