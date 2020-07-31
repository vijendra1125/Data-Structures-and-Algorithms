# Week 1
## Array
* *contiguous* area of memory 
* consisting of *equal* size elements
* indexed by *contiguous* integer
* *Constant* time ($O(1)$) access to any particular element in array for read and write because of simple airthmatic requirement to find the address of element. An example to find element address in one-dimensional array could be given by:
  
  > *element_address = array_address + element_size * (element_index - first_index)*
  
  Simillar way for two dimensional array:
  > *elelment_address = array_address + element_size * ((row_index - total_column)+(column_index - 1))*
* Times for common operations:
  |          | Add    | Remove |
  | -------- | ------ | ------ |
  | Begining | $O(n)$ | $O(n)$ |
  | Middle   | $O(n)$ | $O(n)$ |
  | End      | $O(1)$ | $O(1)$ |
  Hence, cheap for addition or removal of element from end whereas as costly for beginning and middle

## Linked Lists
### Singly-Linked Lists
* It is made of head and nodes
* Head contains pointer to first node
* Each node contains key (value) and pointer to next node
* Time complexity on operations on Singly-Linked List:
   | Singly-Linked list   | no tail | with tail |
   | -------------------- | ------- | --------- |
   | PushFront(key)       | $O(1)$  | $O(1)$    |
   | Key TopFront         | $O(1)$  | $O(1)$    |
   | PopFront()           | $O(1)$  | $O(1)$    |
   | PushBack(key)        | $O(n)$  | $O(1)$    |
   | Key TopBack          | $O(n)$  | $O(1)$    |
   | PopBack              | $O(n)$  | $O(n)$    |
   | Boolean Find(key)    | $O(n)$  | $O(n)$    |
   | Erase(key)           | $O(n)$  | $O(n)$    |
   | Boolean Empty()      | $O(1)$  | $O(1)$    |
   | AddBefore(node, key) | $O(n)$  | $O(n)$    |
   | AddAfter(node, key)  | $O(1)$  | $O(1)$    |

### Doubly-Linked Lists
* Similar to Singly liknked list but each node will have two pointers, one pointing to the  next elelment and other to the previous element
* With doubly linked list PopBack() with tail and Addbefore(node, key) becomes $O(1)$ operation
* Hence, double-linked list with tail is cheap to add or remove element from anywhere in the list and read or write element from front or back of the list whereas reading or writing element from middle is expensive.
