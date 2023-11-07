#include <CNuke/container/LinkedQueue.h>

int LinkedQueueError = LinkedQueueOk;

LinkedQueue LinkedQueueInit() {
    LinkedQueue stack = SinglyLinkedListInit();
    LinkedQueueError = SinglyLinkedListError;
    
    return stack;
}

void LinkedQueuePut(LinkedQueue *Q, BaseType E) {
    SinglyLinkedListEndPtr(Q);
    SinglyLinkedListPut(Q, E);
    LinkedQueueError = SinglyLinkedListError;
}

BaseType LinkedQueueGet(LinkedQueue *Q) {
    SinglyLinkedListBeginPtr(Q);
    BaseType result = SinglyLinkedListGet(Q);
    LinkedQueueError = SinglyLinkedListError;

    return result;
}

bool LinkedQueueIsEmpty(LinkedQueue Q) {
    bool result = SinglyLinkedListIsEmpty(Q);
    LinkedQueueError = SinglyLinkedListError;

    return result;
}

void LinkedQueueDone(LinkedQueue *Q) {
    SinglyLinkedListDone(Q);
    LinkedQueueError = SinglyLinkedListError;
}