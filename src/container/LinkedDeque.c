#include <CNuke/container/LinkedDeque.h>

#include <stdint.h>

int LinkedDequeError = LinkedDequeOk;

LinkedDeque LinkedDequeInit() {
    LinkedDeque result = DoublyLinkedListInit();
    LinkedDequeError = DoublyLinkedListError;

    return result;
}

void LinkedDequeDone(LinkedDeque* D) {
    DoublyLinkedListDone(D);
    LinkedDequeError = DoublyLinkedListError;
}

void LinkedDequePutEnd(LinkedDeque* D, BaseType E) {
    DoublyLinkedListEndPtr(D);
    DoublyLinkedListPutAfter(D, E);
    LinkedDequeError = DoublyLinkedListError;
}

void LinkedDequePutBegin(LinkedDeque* D, BaseType E) {
    DoublyLinkedListBeginPtr(D);
    DoublyLinkedListPutBefore(D, E);
    LinkedDequeError = DoublyLinkedListError;
}

BaseType LinkedDequeGetBegin(LinkedDeque* D) {
    DoublyLinkedListBeginPtr(D);
    DoublyLinkedListMoveR(D);
    BaseType result = DoublyLinkedListGetBefore(D);
    LinkedDequeError = DoublyLinkedListError;

    return result;
}

BaseType LinkedDequeGetEnd(LinkedDeque* D) {
    DoublyLinkedListEndPtr(D);
    DoublyLinkedListMoveL(D);
    BaseType result = DoublyLinkedListGetAfter(D);
    LinkedDequeError = DoublyLinkedListError;

    return result;
}

bool LinkedDequeIsEmpty(LinkedDeque* D) {
    LinkedDequeError = LinkedDequeOk;
    return D->Begin == NULL;
}