#include <CNuke/list/SinglyLinkedList.h>

#include <malloc.h>

int SinglyLinkedListError = SinglyLinkedListOk;

SinglyLinkedList SinglyLinkedListInit() {
    SinglyLinkedListError = SinglyLinkedListOk;
    SinglyLinkedListElementPtr newElement = (SinglyLinkedListElementPtr) malloc(sizeof(SinglyLinkedListElement));
    if (newElement == NULL) {
        SinglyLinkedListError = SinglyLinkedListNotMem;
        return;
    }
    newElement->Next = NULL;

    return (SinglyLinkedList) {newElement, newElement};
}

void SinglyLinkedListPut(SinglyLinkedList *L, BaseType E) {
    SinglyLinkedListError = SinglyLinkedListOk;
    SinglyLinkedListElementPtr newElement = (SinglyLinkedListElementPtr) malloc(sizeof(SinglyLinkedListElement));
    if (newElement == NULL) {
        SinglyLinkedListError = SinglyLinkedListNotMem;
        return;
    }

    newElement->Value = E;
    newElement->Next = NULL;

    SinglyLinkedListElementPtr currentElement = L->Ptr;
    SinglyLinkedListElementPtr nextElement = currentElement->Next;
    currentElement->Next = newElement;
    newElement->Next = nextElement;
}

BaseType SinglyLinkedListGet(SinglyLinkedList *L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    if (SinglyLinkedListIsEmpty(*L)) {
        SinglyLinkedListError = SinglyLinkedListEmpty;
        return;
    }

    if (L->Ptr->Next == NULL) {
        SinglyLinkedListError = SinglyLinkedListEnd;
        return;
    }

    SinglyLinkedListElementPtr currentElement = L->Ptr;
    BaseType result = currentElement->Next->Value;

    SinglyLinkedListElementPtr nextNextElement = currentElement->Next->Next;
    free(currentElement->Next);
    currentElement->Next = nextNextElement;

    return result;
}

void SinglyLinkedListMovePtr(SinglyLinkedList *L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    if (L->Ptr->Next == NULL) {
        SinglyLinkedListError = SinglyLinkedListEnd;
        return;
    }

    L->Ptr = L->Ptr->Next;
}

bool SinglyLinkedListIsEmpty(SinglyLinkedList L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    return L.Begin->Next == NULL;
}

void SinglyLinkedListFreeElement(SinglyLinkedListElementPtr element) {
    if (element == NULL)
        return;
    
    SinglyLinkedListFreeElement(element->Next);
    free(element);
}

void SinglyLinkedListDone(SinglyLinkedList *L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    SinglyLinkedListFreeElement(L->Begin);
    *L = (SinglyLinkedList){NULL, NULL};
}

void SinglyLinkedListBeginPtr(SinglyLinkedList *L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    L->Ptr = L->Begin;
}

void SinglyLinkedListEndPtr(SinglyLinkedList *L) {
    SinglyLinkedListError = SinglyLinkedListOk;
    while (L->Ptr->Next != NULL) {
        L->Ptr = L->Ptr->Next;
    }
}