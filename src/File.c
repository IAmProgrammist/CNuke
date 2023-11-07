#include <CNuke/File.h>

int FileError = FileOk;

File FileInit() {
    FileError = FileOk;
    return (File) {ArrayQueueInit(), ArrayQueueInit()};
}

BaseType FileRead(File *F) {
    FileError = FileOk;
    BaseType element = ArrayQueueGet(&F->Buf);

    if (ArrayQueueError != ArrayQueueOk) {
        FileError = FileEnd;
        return element;
    }

    ArrayQueuePut(&F->Read, element);
    if (ArrayQueueError != ArrayQueueOk) {
        FileError = FileNotMem;
        return element;
    }

    return element;
}

void FilePut(File* F, BaseType E) {
    FileError = FileOk;
    ArrayQueuePut(&F->Buf, E);
    if (ArrayQueueError != ArrayQueueOk) {
        FileError = FileNotMem;
    }
}

void FileBeginPtr(File* F) {
    FileError = FileOk;
    while (!ArrayQueueIsEmpty(F->Buf)) {
        ArrayQueuePut(&F->Read, ArrayQueueGet(&F->Buf));

        if (ArrayQueueError != ArrayQueueOk) {
            FileError = FileNotMem;
            return;
        }
    }

    ArrayQueue T = F->Buf;
    F->Buf = F->Read;
    F->Read = T;
}