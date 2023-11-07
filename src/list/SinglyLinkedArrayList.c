#include <CNuke/list/SinglyLinkedArrayList.h>

#include <stdint.h>

int SinglyLinkedArrayListError = SinglyLinkedArrayListOk;

SinglyLinkedArrayList SinglyLinkedArrayListInit() {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    return (SinglyLinkedArrayList) {{0}, {true, false}, 0, 0};
}

void SinglyLinkedArrayListPut(SinglyLinkedArrayList *L, BaseType E) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    SinglyLinkedArrayListElementPtr newElement = 0;
    for (size_t i = 0; i < SinglyLinkedArrayListBufferSize && newElement == 0; i++) {
        if (!L->Taken[i])
            newElement = i;
    }

    if (newElement == 0) {
        SinglyLinkedArrayListError = SinglyLinkedArrayListFull;
        return;
    }

    L->Taken[newElement] = true;

    SinglyLinkedArrayListElementPtr oldElement = L->Buf[L->Ptr].Next;
    L->Buf[L->Ptr].Next = newElement;
    L->Buf[newElement] = (SinglyLinkedArrayListElement) {E, oldElement};
}

BaseType SinglyLinkedArrayListGet(SinglyLinkedArrayList *L) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    if (L->Buf[L->Ptr].Next == 0) {
        SinglyLinkedArrayListError = SinglyLinkedArrayListEnd;
        return;
    }

    SinglyLinkedArrayListElementPtr readElement = L->Buf[L->Ptr].Next;

    BaseType result = L->Buf[readElement];
    L->Buf[L->Ptr].Next = L->Buf[readElement].Next;

    L->Taken[readElement] = false;

    return result;
}

void SinglyLinkedArrayListMovePtr(SinglyLinkedArrayList *L) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    if (L->Buf[L->Ptr].Next == 0) {
        SinglyLinkedArrayListError = SinglyLinkedArrayListEnd;
        return;
    }

    L->Ptr = L->Buf[L->Ptr].Next;
}

bool SinglyLinkedArrayListIsEmpty(SinglyLinkedArrayList L) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    return L.Buf[L.Begin].Next == 0;
}

void SinglyLinkedArrayListBeginPtr(SinglyLinkedArrayList *L) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    L->Ptr = L->Begin;
}

void SinglyLinkedArrayListEndPtr(SinglyLinkedArrayList *L) {
    SinglyLinkedArrayListError = SinglyLinkedArrayListOk;
    while (L->Buf[L->Ptr].Next != 0) {
        L->Ptr = L->Buf[L->Ptr].Next;
    }
}