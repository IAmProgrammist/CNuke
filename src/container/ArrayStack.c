#include <CNuke/container/ArrayStack.h>

int ArrayStackError = ArrayStackOk;

ArrayStack ArrayStackInit() {
    ArrayStackError = ArrayStackOk;
    return (ArrayStack) {{0}, 0};
}

void ArrayStackPut(ArrayStack *S, BaseType E) {
    ArrayStackError = ArrayStackOk;
    if (ArrayStackIsFull(*S)) {
        ArrayStackError = ArrayStackFull;
        return;
    }

    S->Buf[S->End++] = E;
}

BaseType ArrayStackGet(ArrayStack *S) {
    ArrayStackError = ArrayStackOk;
    if (ArrayStackIsEmpty(*S)) {
        ArrayStackError = ArrayStackFull;
        return;
    }

    return S->Buf[--S->End];
}

bool ArrayStackIsEmpty(ArrayStack S) {
    return S.End == 0;
}

bool ArrayStackIsFull(ArrayStack S) {
    return S.End == ArrayStackBufferSize;
}