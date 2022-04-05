# -Linked-Lists-
This programming assignment will require the usage of dynamic memory, pointers and linked 
lists.  It will also require the usage of File IO and templates.   Also, required is a good 
understanding of overloading assignment and copy constructors.   Learnings from previous 
assignments, especially operator overloading will also be required. 
 
Problem: The List. 
 
 build a class for a fully ordered list.  The list class, called List342, will be templatized so 
that different types of objects can be stored in it. 
 
 List342<string> some_strings; 
 List342<int> list_of_integers; 
 List342<Child> children; 
 List342<MyRandomObj> ordered_list_random_objs; 
 
The following member functions should be created for the List342 class.  Please make sure the 
signatures are exact or points will be deducted as the test programs will not compile.   
 


 
 bool   BuildList(string file_name) : Given a string which represents a file, open the file, 
read the objects from file, and build an ordered list.  Note that BuildList puts the responsibility 
on the Object class to know how to read from a file.  That is, do not have object specific logic in 
the implementation.  You can insert each item into the list as you read it from the file.  If a list 
already has an item do not add it to the list; only add the new items to the list. 
 
 Assume that the text in the file is well-formed for the object being read into. 
  
bool   Insert( T* obj ) :  Insert an object in the list in the correct place.  Return true or 
false depending on whether the insert was successful.   Duplicates of an object are not allowed 
and should return false.  Note that a pointer to the object is passed in but the Insert should 
create a copy of the object to keep in the list. 
 
bool   Remove(T target, T& result):  Remove the target item from the list.  Return the 
item using a second parameter that is passed in by reference.  If the item was found and 
removed return true, else return false.   
bool   Peek(T target, T& result) const:   The same as Remove except the item is not 
removed from the list.  Again, the second item is returned by reference. 
 
bool   isEmpty() const:  Is the list empty? 
 
 void   DeleteList():  Remove all items from the list.  Deallocate all memory appropriately.  
This includes not only the nodes in the list but the items being pointed to by the nodes.  
 
 bool   Merge(List342& list1):  Takes a sorted list and merges into the calling sorted list 
(no new memory should be allocated). At termination of function, the list passed in (list1) 
should be empty (unless it is the calling list).  No duplicates are allowed. 
 
The following operators should be overloaded for the List342<>.  Please make sure signatures 
are correct on overloads. 
 
 +, += :  This should add two lists together.  The lists are assumed to be sorted and the 
returned list must also be sorted.  Use an efficient sort algorithm and avoid unnecessary data 
allocations.  Duplicates are not allowed and expected.  
 
 << :  Display the list and only the List object, no extra blanks, no tabs, no endl.  Display 
the items on the list in increasing order.  See examples below. 
 
 == and != :  check for equality or inequality. 
 
 =  :  Assignment.  Make a deep copy of all new memory.   
 
 
