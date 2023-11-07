#include <CNuke/container/ArrayQueue.h>

ArrayQueue ArrayQueueInit() {
    ArrayQueueError = ArrayQueueOk;
    return (ArrayQueue) {{0}, 0, 0, 0};
}

void ArrayQueuePut(ArrayQueue *Q, BaseType E) {
    ArrayQueueError = ArrayQueueOk;
    if (ArrayQueueIsFull(*Q)) {
        ArrayQueueError = ArrayQueueFull;
        return;
    }

    Q->Buf[Q->End] = E;
    Q->End = (Q->End + 1) % ArrayQueueBufferSize;
    Q->Size++; 
}

BaseType ArrayQueueGet(ArrayQueue *Q) {
    ArrayQueueError = ArrayQueueOk;
    if (ArrayQueueIsEmpty(*Q)) {
        ArrayQueueError = ArrayQueueEmpty;
        return 0;
    }

    BaseType result = Q->Buf[Q->Begin];
    Q->Begin = (Q->Begin + 1) % ArrayQueueBufferSize;
    Q->Size--;

    return result; 
}

bool ArrayQueueIsEmpty(ArrayQueue Q) {
    return Q.Size == 0;
}

bool ArrayQueueIsFull(ArrayQueue Q) {
    return Q.Size == ArrayQueueBufferSize;
}