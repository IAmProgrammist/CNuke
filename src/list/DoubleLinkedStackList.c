#include <CNuke/list/DoubleLinkedStackList.h>

int DoublyLinkedStackListError = DoublyLinkedStackListOk;

DoublyLinkedStackList DoublyLinkedStackListInit() {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    DoublyLinkedStackList result;
    result.Left = LinkedStackInit();
    result.Right = LinkedStackInit();
    result.Size = 0;
    
    return result;
}

void DoublyLinkedStackListPutBefore(DoublyLinkedStackList* L, BaseType E) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    if (L->Size == 0) {
        L->Size++;
        L->Current = E;

        return;
    }

    LinkedStackPut(&L->Left, E);
    L->Size++;
    
    if (LinkedStackError == LinkedStackNotMem) 
        DoublyLinkedStackListError = DoublyLinkedStackListNotMem;
}

void DoublyLinkedStackListPutAfter(DoublyLinkedStackList* L, BaseType E) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    if (L->Size == 0) {
        L->Size++;
        L->Current = E;

        return;
    }

    LinkedStackPut(&L->Right, E);
    L->Size++;
    
    if (LinkedStackError == LinkedStackNotMem) 
        DoublyLinkedStackListError = DoublyLinkedStackListNotMem;
}

BaseType DoublyLinkedStackListGetBefore(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    if (L->Size == 1) {
        L->Size--;

        return L->Current;
    }

    BaseType result;
    if (L->Size == 0) {
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

        return result;
    }

    result = LinkedStackGet(&L->Left);
    L->Size--;

    if (LinkedStackError == LinkedStackEmpty)
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

    return result;
}

BaseType DoublyLinkedStackListGetAfter(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;

    if (L->Size == 1) {
        L->Size--;

        return L->Current;
    }

    BaseType result;
    if (L->Size == 0) {
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

        return result;
    }

    result = LinkedStackGet(&L->Right);
    L->Size--;

    if (LinkedStackError == LinkedStackEmpty)
        DoublyLinkedStackListError = DoublyLinkedStackListBegin;

    return result;
}

void DoublyLinkedStackListMoveL(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType element = DoublyLinkedStackListGetBefore(L);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    DoublyLinkedStackListPutAfter(L, L->Current);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    L->Current = element;
}

void DoublyLinkedStackListMoveR(DoublyLinkedStackList *L) {
    DoublyLinkedStackListError = DoublyLinkedStackListOk;
    BaseType element = DoublyLinkedStackListGetAfter(L);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    DoublyLinkedStackListPutBefore(L, L->Current);
    if (DoublyLinkedStackListError != DoublyLinkedStackListOk) 
        return;

    L->Current = element;
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