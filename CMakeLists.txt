cmake_minimum_required(VERSION 3.16)
project(CNuke VERSION 1.0.0 DESCRIPTION "Basic data structures written in C")

set(CMAKE_C_STANDARD 23)

add_subdirectory(src)

set_target_properties(CNuke PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(CNuke PROPERTIES PUBLIC_HEADER 
include/CNuke/CNuke.h
include/CNuke/Common.h
include/CNuke/File.h
include/CNuke/Table.h

include/CNuke/list/DoubleLinkedStackList.h
include/CNuke/list/DoublyLinkedList.h
include/CNuke/list/SinglyLinkedArrayList.h
include/CNuke/list/SinglyLinkedList.h

include/CNuke/container/ArrayQueue.h
include/CNuke/container/LinkedQueue.h
include/CNuke/container/ArrayStack.h
include/CNuke/container/LinkedStack.h
include/CNuke/container/LinkedDeque.h)

target_include_directories(CNuke PRIVATE include/)
target_include_directories(CNuke PRIVATE src/)

install(TARGETS CNuke 
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})