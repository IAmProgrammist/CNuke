set(CNukeSources 
Table.c
File.c

container/ArrayQueue.c
container/ArrayStack.c
container/LinkedStack.c
container/LinkedQueue.c

list/SinglyLinkedList.c
list/SinglyLinkedArrayList.c
list/DoubleLinkedStackList.c
)

add_library(CNuke STATIC ${CNukeSources})