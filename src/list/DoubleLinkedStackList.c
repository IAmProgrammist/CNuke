#include <CNuke/list/DoubleLinkedStackList.h>

int DoublyLinkedStackListError = DoublyLinkedStackListOk;

DoublyLinkedStackList DoublyLinkedStackListInit() {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    return (DoublyLinkedStackList) {LinkedStackInit(), LinkedStackInit()};
}

void DoublyLinkedStackListPutBefore(DoublyLinkedStackList* L, BaseType E) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    LinkedStackPut(&L->Left, E);
    
    if (LinkedStackError == LinkedStackNotMem) 
        DoublyLinkedStackListError = DoublyLinkedStackListNotMem;
}

void DoublyLinkedStackListPutAfter(DoublyLinkedStackList* L, BaseType E) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    LinkedStackPut(&L->Right, E);
    
    if (LinkedStackError == LinkedStackNotMem) 
        DoublyLinkedStackListError = DoublyLinkedStackListNotMem;
}

BaseType DoublyLinkedStackListGetBefore(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType result = LinkedStackGet(&L->Left);

    if (LinkedStackError == LinkedStackEmpty)
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

    return result;
}

BaseType DoublyLinkedStackListGetAfter(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType result = LinkedStackGet(&L->Right);

    if (LinkedStackError == LinkedStackEmpty)
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

    return result;
}

void DoublyLinkedStackListMoveL(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType element = DoublyLinkedStackListGetBefore(L);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    DoubleLinkedStackListPutAfter(L, element);
}

void DoublyLinkedStackListMoveR(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType element = DoublyLinkedStackListGetAfter(L);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    DoubleLinkedStackListPutBefore(L, element);
}

void DoublyLinkedStackListDone(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    LinkedStackDone(&L->Left);
    LinkedStackDone(&L->Right);
}

void DoublyLinkedStackListBeginPtr(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    while (!LinkedStackIsEmpty(L->Left) && DoublyLinkedStackListError == DoublyLinkedStackListOk) {
        DoublyLinkedStackListMoveL(L);
    }
}

void DoublyLinkedStackListEndPtr(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    while (!LinkedStackIsEmpty(L->Right) && DoublyLinkedStackListError == DoublyLinkedStackListOk) {
        DoublyLinkedStackListMoveR(L);
    }
}