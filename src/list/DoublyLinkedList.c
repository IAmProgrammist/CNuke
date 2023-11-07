#include <CNuke/list/DoublyLinkedList.h>

#include <stdlib.h>

int DoublyLinkedListError = DoublyLinkedListOk;

DoublyLinkedList DoublyLinkedListInit() {
    DoublyLinkedListError = DoublyLinkedListOk;

    return (DoublyLinkedList) {NULL, NULL, NULL};
}

void DoublyLinkedListPutBefore(DoublyLinkedList* L, BaseType E) {
    DoublyLinkedListError = DoublyLinkedListOk;
    DoublyLinkedListElementPtr newElement = (DoublyLinkedListElementPtr) malloc(sizeof(DoublyLinkedListElement));
    if (newElement == NULL) {
        DoublyLinkedListError = DoublyLinkedListNotMem;
        return;
    }

    newElement->Value = E;

    if (L->Begin == NULL) {
        L->Begin = newElement;
        L->End = newElement;
        L->Ptr = newElement;
        newElement->Next = NULL;
        newElement->Prev = NULL;

        return;
    }

    DoublyLinkedListElementPtr oldPrev = L->Ptr->Prev;
    L->Ptr->Prev = newElement;
    newElement->Prev = oldPrev;

    if (oldPrev == NULL) {
        L->Begin = newElement;
    }
}

void DoublyLinkedListPutAfter(DoublyLinkedList* L, BaseType E) {
    DoublyLinkedListError = DoublyLinkedListOk;
    DoublyLinkedListElementPtr newElement = (DoublyLinkedListElementPtr) malloc(sizeof(DoublyLinkedListElement));
    if (newElement == NULL) {
        DoublyLinkedListError = DoublyLinkedListNotMem;
        return;
    }

    newElement->Value = E;

    if (L->Begin == NULL) {
        L->Begin = newElement;
        L->End = newElement;
        L->Ptr = newElement;
        newElement->Next = NULL;
        newElement->Prev = NULL;

        return;
    }

    DoublyLinkedListElementPtr oldNext = L->Ptr->Next;
    L->Ptr->Next = newElement;
    newElement->Next = oldNext;

    if (oldNext == NULL) {
        L->End = newElement;
    }
}

BaseType DoublyLinkedListGetBefore(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    if (L->Begin == L->End && L->Begin != NULL) {
        BaseType result = L->Begin->Value;

        free(L->Begin);
        L->Begin = NULL;
        L->End = NULL;
        L->Ptr = NULL;

        return result;
    }

    if (L->Ptr == NULL || L->Ptr->Prev == NULL) {
        DoublyLinkedListError = DoublyLinkedListBegin;
        return;
    }

    DoublyLinkedListElementPtr prevElement = L->Ptr->Prev;
    DoublyLinkedListElementPtr prevPrevElement = prevElement->Prev;

    BaseType result = prevElement->Value;

    free(prevElement);
    L->Ptr->Prev = prevPrevElement;

    if (prevPrevElement == NULL) {
        L->Begin = L->Ptr;
    }

    return result;
}

BaseType DoublyLinkedListGetAfter(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    if (L->Begin == L->End && L->Begin != NULL) {
        BaseType result = L->Begin->Value;

        free(L->Begin);
        L->Begin = NULL;
        L->End = NULL;
        L->Ptr = NULL;

        return result;
    }

    if (L->Ptr == NULL || L->Ptr->Next == NULL) {
        DoublyLinkedListError = DoublyLinkedListEnd;
        return;
    }

    DoublyLinkedListElementPtr nextElement = L->Ptr->Next;
    DoublyLinkedListElementPtr nextNextElement = nextElement->Next;

    BaseType result = nextElement->Value;

    free(nextElement);
    L->Ptr->Next = nextNextElement;

    if (nextNextElement == NULL) {
        L->End = L->Ptr;
    }

    return result;
}

void DoublyLinkedListMoveL(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    if (L->Ptr == NULL || L->Ptr->Prev == NULL) {
        DoublyLinkedListError = DoublyLinkedListBegin;
        return;
    }

    L->Ptr = L->Ptr->Prev;
}

void DoublyLinkedListMoveR(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    if (L->Ptr == NULL || L->Ptr->Next == NULL) {
        DoublyLinkedListError = DoublyLinkedListEnd;
        return;
    }

    L->Ptr = L->Ptr->Next;
}

void DoublyLinkedListDone(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    DoublyLinkedListElementPtr currentElement = L->Begin;
    while (currentElement != NULL) {
        DoublyLinkedListElementPtr next = currentElement->Next;
        free(currentElement);
        currentElement = next;
    }
    
}

void DoublyLinkedListBeginPtr(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    L->Ptr = L->Begin;
}

void DoublyLinkedListEndPtr(DoublyLinkedList *L) {
    DoublyLinkedListError = DoublyLinkedListOk;
    L->Ptr = L->End;
}