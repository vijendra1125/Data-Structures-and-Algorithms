# Week 1
## Array
* *contiguous* area of memory 
* consisting of *equal* size elements
* indexed by *contiguous* integer
* *Constant* time ($O(1)$) access to any particular element in array for read and write because of simple airthmatic requirement to find the address of element. 
* Expensive for adition or removal of element except from end
* Times for common operations:

  |          | Add    | Remove |
  | -------- | ------ | ------ |
  | Begining | $O(n)$ | $O(n)$ |
  | Middle   | $O(n)$ | $O(n)$ |
  | End      | $O(1)$ | $O(1)$ |


## Linked Lists
* Linked-lists are made of a head and nodes and optionally a tail
* Head contains the pointer to first node
*  Tail contains the pointer to last node
*  Nodes contins key and pointer(s)
* Head, tail and nodes need not be contiguous
* Below are Linked-list's type based on the type of node it consist
  
### Singly-Linked Lists
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
* Each node contains key and  two pointers, one pointing to the  next elelment and other to the previous element
* With doubly linked list PopBack() with tail and Addbefore(node, key) becomes $O(1)$ operation
* Hence, double-linked list with tail is cheap to add or remove element from anywhere in the list. Accessing elements from front (always) and back (given that it has tail) of the linked list is cheap whereas accessing elements from middle is expensive.


## Reading Resources:
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. Introduction to Algorithms (3rd Edition). MIT Press and McGraw-Hill. 2009.
  * Chapter 10.2
