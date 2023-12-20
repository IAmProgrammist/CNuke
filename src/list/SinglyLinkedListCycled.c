#include <CNuke/list/SinglyLinkedListCycled.h>

#include <malloc.h>

int SinglyLinkedListCycledError = SinglyLinkedListCycledOk;

SinglyLinkedListCycled SinglyLinkedListCycledInit() {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    SinglyLinkedListCycledElementPtr newElement = (SinglyLinkedListCycledElementPtr) malloc(sizeof(SinglyLinkedListCycledElement));
    if (newElement == NULL) {
        SinglyLinkedListCycledError = SinglyLinkedListCycledNotMem;
        return;
    }
    newElement->Next = newElement;

    return (SinglyLinkedListCycled) {newElement, newElement};
}

void SinglyLinkedListCycledPut(SinglyLinkedListCycled *L, BaseType E) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    SinglyLinkedListCycledElementPtr newElement = (SinglyLinkedListCycledElementPtr) malloc(sizeof(SinglyLinkedListCycledElement));
    if (newElement == NULL) {
        SinglyLinkedListCycledError = SinglyLinkedListCycledNotMem;
        return;
    }

    newElement->Value = E;
    newElement->Next = NULL;

    SinglyLinkedListCycledElementPtr currentElement = L->Ptr;
    SinglyLinkedListCycledElementPtr nextElement = currentElement->Next;
    currentElement->Next = newElement;
    newElement->Next = nextElement;
}

BaseType SinglyLinkedListCycledGet(SinglyLinkedListCycled *L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    if (SinglyLinkedListCycledIsEmpty(*L)) {
        SinglyLinkedListCycledError = SinglyLinkedListCycledEmpty;
        return;
    }

    if (L->Ptr->Next == NULL) {
        SinglyLinkedListCycledError = SinglyLinkedListCycledEnd;
        return;
    }

    SinglyLinkedListCycledElementPtr currentElement = L->Ptr;
    BaseType result = currentElement->Next->Value;

    SinglyLinkedListCycledElementPtr nextNextElement = currentElement->Next->Next;
    free(currentElement->Next);
    currentElement->Next = nextNextElement;

    return result;
}

void SinglyLinkedListCycledMovePtr(SinglyLinkedListCycled *L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    if (L->Ptr->Next == L->Begin) {
        SinglyLinkedListCycledError = SinglyLinkedListCycledEnd;
        return;
    }

    L->Ptr = L->Ptr->Next;
}

bool SinglyLinkedListCycledIsEmpty(SinglyLinkedListCycled L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    return L.Begin->Next == L->Begin;
}

void SinglyLinkedListCycledDone(SinglyLinkedListCycled *L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    SinglyLinkedListCycledBeginPtr(L);

    do  {
        free(L->Ptr);
        L->Ptr = L->Ptr->Next;
    } while (L->Ptr != L->Begin);

    *L = (SinglyLinkedListCycled){NULL, NULL};
}

void SinglyLinkedListCycledBeginPtr(SinglyLinkedListCycled *L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    L->Ptr = L->Begin;
}

void SinglyLinkedListCycledEndPtr(SinglyLinkedListCycled *L) {
    SinglyLinkedListCycledError = SinglyLinkedListCycledOk;
    while (L->Ptr->Next != L->Begin) {
        L->Ptr = L->Ptr->Next;
    }
}