# Week 1
## Array
* Contiguous area of memory 
* Consisting of equal size elements
* Indexed by contiguous integer
* Constant time (O(1)) access to any particular element in array for read and write because of simple airthmatic requirement to find the address of element. 
* Expensive for adition or removal of element except from end
* Times for common operations:
  |          | Add  | Remove |
  | -------- | ---- | ------ |
  | Begining | O(n) | O(n)   |
  | Middle   | O(n) | O(n)   |
  | End      | O(1) | O(1)   |


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
   | Singly-Linked list   | no tail | with tail | Description          |
   | -------------------- | ------- | --------- | -------------------- |
   | PushFront(key)       | O(1)    | O(1)      | Add to front         |
   | Key TopFront         | O(1)    | O(1)      | Return fron item     |
   | PopFront()           | O(1)    | O(1)      | Remove front item    |
   | PushBack(key)        | O(n)    | O(1)      | Add to back          |
   | Key TopBack          | O(n)    | O(1)      | Return back item     |
   | PopBack              | O(n)    | O(n)      | Remove back time     |
   | Boolean Find(key)    | O(n)    | O(n)      | Is key in list       |
   | Erase(key)           | O(n)    | O(n)      | Remove key from list |
   | Boolean Empty()      | O(1)    | O(1)      | Empty list?          |
   | AddBefore(node, key) | O(n)    | O(n)      | Add key before node  |
   | AddAfter(node, key)  | O(1)    | O(1)      | Add key afer node    |

### Doubly-Linked Lists
* Each node contains key and  two pointers, one pointing to the  next elelment and other to the previous element
* With doubly-linked list PopBack() (with tail) and AddBefore(node, key) becomes O(1) operation
* Hence, doubly-linked list with tail is cheap to add or remove element from anywhere in the list. 
* Accessing elements from front (always) and back (given that it has tail) of the linked list is cheap whereas accessing elements from middle is expensive.


## Stacks
* Abstract data type with following operations:
  * Push(key): adds key to the collection 
  * Key Top(): returns most recently added key
  * Key Pop(): return and remove most recently added key
  * Boolean Empty(): is there any elements?
* Also known as LIFO queues which means Last In First Out
* Can be implemented either using array or linked list with both having its own pros and cons
* All operations wil be O(1)

## Queues
* Abstract data type with following operations:
  * Enqueue(key): add key to the collection
  * Key Dequeue(): remove and returns least recently-added key
  * Boolean Empty(): are there any elements?
* Also known as FIFO queues which means First In First Out
* It could also be implemented using array or linked list (with tail pointer) with each having its own pros and cons
* All operations wil be O(1) if implemented optimally


## Trees
* A tree is nodes connected by edges
* A node contains:
  * Key
  * Children: list of children nodes
  * Parent (optional)
* Root: Top most node
* Parent: Any node except the root node has one edge upward to a node called parent
* Child: The node below a given node connected by its edge downward is called its child node 
* Ancestor: Parent, parent's parent and so on
* Decendants: Child, child's child and so on
* Siblings: Two nodes sharing same parent
* Leaf: Node with no children
* Interior node: All nodes which is non-leaf
* Level: 1 + number of edges between root and node
* Height: Maximum depth of subtree node and farthest leaf. Note that the leafs height are one
* Forest: Collection of trees
### Binary Search Trees
* At most two childrens at each node
* Value of node should greater than or equal to the left child and lesser than right child
* Node contains:
  * Key
  * Left child
  * Right child
  * Parent (optional)
### Traversing Tree:
  *  Order of visting nodes of tree:
     * Depth-first Search (DFS): 
       * Completely traverse one subtree before exploring other
       * Type of traversal:
         * In-order: Travel the left subtree, visit the root, travel the right subtree
         * Pre-order: Visit the root, travel the left subtree, travel the right subtree 
         * Post-order: Travel the left subtree, travel the right subtree, visit the root
       * Use stack 
     * Breadth-first Search (BFS): 
       * Use queue
       * Traverse all nodes at one level before progressing to the next level
         * Start with root in queue
         * Push all children of the front element in the queue and then remove the from elelment from queue till queue becomes empty

## Additional notes:
* Programming assignmnet 5 is worth rivisiting.

## Reading Resources
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. Introduction to Algorithms (3rd Edition). MIT Press and McGraw-Hill. 2009.
  * chapter 10.1: Stack and queue
  * Chapter 10.2: Array and linked list
  * Chapter 10.4: Trees

# Week 2
## Dynamic Arrays
* Provides possibility to change size of array during runtime
* Idea: Store a pointer to a dinamically allocated array, and replace it with a newly allocated array as needed.
* In C++ vector and in python list are dynamic arrays.
* Common operation's runtime:
  | Operation | Runtime                                                                    |
  | --------- | -------------------------------------------------------------------------- |
  | Get(i)    | O(1)                                                                       |
  | Set(i)    | O(1)                                                                       |
  | PushBack  | O(1) but in worst case (allocated array is full) O(n); Amortized cost O(1) |
  | Remove(i) | O(n)                                                                       |
  | Size()    | O(1)                                                                       |
* Con: Some space is wasted 

## Amortized Analysis
* Looking at the worst-case run time per operation, rather than per algorithm, can be too pessimistic. The amortized analysis considers both the costly and less costly operations together over the whole series of operations of the algorithm.
* Amortized cost = Cost(n Operations)/n
### Aggregated Method
* Aggregate analysis determines the upper bound T(n) on the total cost of a sequence of n operations, then calculates the amortized cost to be T(n) / n [[wiki](https://en.wikipedia.org/wiki/Amortized_analysis)].
### Banker's Method
* It is a form of aggregate analysis which assigns to each operation an amortized cost which may differ from its actual cost. Early operations have an amortized cost higher than their actual cost, which accumulates a saved "credit" that pays for later operations having an amortized cost lower than their actual cost. Because the credit begins at zero, the actual cost of a sequence of operations equals the amortized cost minus the accumulated credit. Because the credit is required to be non-negative, the amortized cost is an upper bound on the actual cost. Usually, many short-running operations accumulate such credit in small increments, while rare long-running operations decrease it drastically [[wiki](https://en.wikipedia.org/wiki/Amortized_analysis)].
### Physicist's Method
* The potential method is a form of the accounting method where the saved credit is computed as a function (the "potential") of the state of the data structure. The amortized cost is the immediate cost plus the change in potential [[wiki](https://en.wikipedia.org/wiki/Amortized_analysis)].

## Reading Resources
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. Introduction to Algorithms (3rd Edition). MIT Press and McGraw-Hill. 2009.
  * chapter 17

# Week 3
## Priority Queues
* A generalization of queue where each element is assigned a priority and elements come out in order by priority.
* Naive approach:
  | Data Structure      | Insert | ExtractMax |
  | ------------------- | ------ | ---------- |
  | Unsorted array/list | O(1)   | O(n)       |
  | Sorted array/lsit   | O(n)   | O(1)       |
### Binary Max-heap
* One of the method to implement priority queue
* A binary tree with value of parent is at least equal to value of the child.
* Here we define tree height to be equal to the number of edges on the longest path from the root to a leaf.
* GetMax: Return the value at root of the tree. Running time O(1)
* Insert: Attach new node to any leaf and then swap it with parent till binary max-heap property is satisfied. Running time O(tree height)
* ExtractMax: Replace root with any leaf and keep swaping it with largest child till binary max-heap property is satisfied. Running time O(tree height)
* Change priority: Assign new priority to node and keep swaping element with parent or largest child till binary max-heap property is satisfied. Running time O(tree height)
* Remove: Change prioirty(element to be removed to infinity) + ExtractMax
* Seeing runtime of all the operation above, we definetily want tree to be shallow and hence we need complete binary tree (all level filled except the last one which is filled from left to right)
  * A complete binary tree with n nodes has height at max O(log n)
  * Complete binary tree could be stored as array because of following relation it holds for node i in 0-based array:
    * Parent(i) = floor((i-1)/2)
    * Leftchild(i) = 2i + 1
    * RightChild(i) = 2i + 2
  * Insert and ExtractMax (also remove by calling ExtractMax) affects the completeness of tree
  * To keep tree complete while iserting, insert it as a leaf in the leftmost vacant position in the last level and let it sift up
  * To keep tree complete while extracting max value, repalce the root by the last leafand let it sift down.
* Pros of priority queueusing binary max-heap:
  * Fast: all operations work in time O(log n) (GetMax even work in O(1))
  * Space efficient: we store an array of priorities, parent child connection are not stored but computed on the fly
* Binay heap could be generalized in *d*-ary heap in such a way that nodes on all levels except for possibly the last one have exactly *d* children. In such case height of tree will log<sub>*d*</sub>(n) and runnning time of sift will be *O*(log<sub>*d*</sub>(n)) whereas running time of SiftDown operation will be *O*(d log<sub>*d*</sub>(n)) because at each level we find the largest among the d children.
### Heap sort
* Comparison based sorting algorithm which isimilar to selection sort where we find maelement and then place it to the end of array anrepeat same till sequence is sorted.
* Steps:
  * Build array based max-heap
  * Swap root element to last element of arrayreduce size of heap by 1 and shitDown to makit complete binary tree
  * Do above step iteratively till heap size is 1
* Runtime: *O*(n log(n))
  * Runtime for building heap: *O*(n)
  * Runtime for sorting: *O*(n log(n))
* No extra space required, in place sorting
* Note that for quick sort on average runtime is n log(n) whereas for heap sort worst case rutime is nlog(n)
### Disjoint Sets
* x
## Reading Resources
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. Introduction to Algorithms (3rd Edition). MIT Press and McGraw-Hill. 2009
  * Chapter 6: Heap
  * chapter 6.4: Heap-sort