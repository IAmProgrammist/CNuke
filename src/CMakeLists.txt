set(CNukeSources 
Table.c
File.c

container/ArrayQueue.c
container/ArrayStack.c
container/LinkedStack.c
container/LinkedQueue.c
container/LinkedDeque.c

list/SinglyLinkedList.c
list/SinglyLinkedArrayList.c
list/DoubleLinkedStackList.c
list/DoublyLinkedList.c)

add_library(CNuke STATIC ${CNukeSources})