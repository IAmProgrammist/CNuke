#include <CNuke/container/LinkedStack.h>

int LinkedStackError = LinkedStackOk;

LinkedStack LinkedStackInit() {
    LinkedStack stack = SinglyLinkedListInit();
    LinkedStackError = SinglyLinkedListError;
    
    return stack;
}

void LinkedStackPut(LinkedStack *S, BaseType E) {
    SinglyLinkedListPut(S, E);
    LinkedStackError = SinglyLinkedListError;
}

BaseType LinkedStackGet(LinkedStack *S) {
    BaseType result = SinglyLinkedListGet(S);
    LinkedStackError = SinglyLinkedListError;

    return result;
}

bool LinkedStackIsEmpty(LinkedStack S) {
    bool result = SinglyLinkedListIsEmpty(S);
    LinkedStackError = SinglyLinkedListError;

    return result;
}

void LinkedStackDone(LinkedStack *S) {
    SinglyLinkedListDone(S);
    LinkedStackError = SinglyLinkedListError;
}