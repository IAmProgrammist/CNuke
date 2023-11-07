#include <CNuke/Table.h>

int TableError = TableOk;

Table TableInit() {
    TableError = TableOk;
    return (Table) {{0}, 0};
}

void TablePut(Table *T, TableElement E) {
    TableError = TableOk;
    for (int i = 0; i < T->End; i++) {
        if (E.Key == T->Buf[i].Key) {
            T->Buf[i].Value = E.Value;

            return;
        }
    }

    if (TableIsFull(*T))  {
        TableError = TableFull;
        return;
    }

    T->Buf[T->End++] = E;
}

TableElement TableGet(Table *T, int key) {
    if (TableIsEmpty(*T)) {
        TableError = TableEmpty;

        return (TableElement){0};
    }

    TableError = TableOk;
    for (int i = 0; i < T->End; i++) {
        if (key == T->Buf[i].Key) {
            TableElement result = T->Buf[i];
            T->Buf[i] = T->Buf[--T->End];
            
            return result;
        }
    }

    TableError = TableNoKey;
    return (TableElement){0};
}

bool TableIsEmpty(Table T) {
    return T.End == 0;
}

bool TableIsFull(Table T) {
    return T.End >= TableBufferSize;
}