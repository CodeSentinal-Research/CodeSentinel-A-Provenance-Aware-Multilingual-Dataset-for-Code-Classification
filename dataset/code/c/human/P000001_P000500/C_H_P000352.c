#pragma once

// SINGULAR LINKED LIST
#define for_each(type, var)                                                    \
  for (type *_iter = var; _iter != NULL; _iter = _iter->p_next)

#define LL_NODE_DEFINE(type)                                                   \
  typedef struct type##LLNode {                                                \
    type item;                                                                 \
    struct type##LLNode *p_next;                                               \
  } type##LLNode;                                                              \
                                                                               \
  void type##ll_push_front(type##LLNode **root, type value) {                  \
    type##LLNode *new_node = (type##LLNode *)malloc(sizeof(type##LLNode));     \
    new_node->item = value, new_node->p_next = *root, *(root) = new_node;      \
  };                                                                           \
                                                                               \
  void type##ll_push_back(type##LLNode **root, type value) {                   \
    type##LLNode *new_node = (type##LLNode *)malloc(sizeof(type##LLNode));     \
    new_node->item = value;                                                    \
    (*root == NULL) ? (*root = new_node) : ({                                  \
      type##LLNode *temp = *root;                                              \
      while (temp->p_next != NULL)                                             \
        temp = temp->p_next;                                                   \
      temp->p_next = new_node;                                                 \
    });                                                                        \
  };                                                                           \
                                                                               \
  type##LLNode *type##ll_find_ref(type##LLNode *root, type value) {            \
    for (; root != NULL; root = root->p_next)                                  \
      if (root->item == value)                                                 \
        return root;                                                           \
    return NULL;                                                               \
  };

#define DEFINE_ARRAY(type)                                                     \
  typedef struct type##_array {                                                \
    size_t size;                                                               \
    size_t capacity;                                                           \
    type items[];                                                              \
  } type##_array;                                                              \
  type type##_array_get(type##_array **this, size_t index) {                 \
    assert((*this)->size > index);                                                \
    return (*this)->items[index];                                                 \
  };                                                                           \
  type* type##_array_get_ref(type##_array **this, size_t index) {                 \
    assert((*this)->size > index);                                                \
    return &(*this)->items[index];                                                 \
  };                                                                           \
  type##_array *type##_array_create_empty_array() {                            \
    type##_array *this =                                                       \
        (type##_array *)malloc(sizeof(type##_array) + 20 * sizeof(type));      \
    this->size = 0;                                                            \
    this->capacity = 20;                                                       \
    return this;                                                               \
  };                                                                           \
  type##_array *type##_array_create_array(size_t size, type item) {       \
    type##_array *this =                                                       \
        (type##_array *)malloc(sizeof(type##_array) + size * 1.5 * sizeof(type));    \
    this->size = size;                                                         \
    this->capacity = 1.5 * size;                                               \
    for (int i = 0; i < size; ++i)                                             \
      (*this).items[i] = item;                                                 \
    return this;                                                               \
  };\
  void type##_array_push_back(type##_array **this, type item) {\
    if ((*this)->size >= (*this)->capacity) { \
      *this = realloc(*this, sizeof(type##_array) + (*this)->capacity * 1.5 * sizeof(type));\
      (*this)->capacity *= 1.5; \
      (*this)->items[(*this)->size++] = item;\
    } else {\
      (*this)->items[(*this)->size++] = item;\
    };\
  };\



/*
Constructor/Initialization
Create a new dynamic array with initial capacity
Create an empty dynamic array


Add/Insert Operations
append(element) - Add an element to the end
insert(index, element) - Insert an element at a specific position


Access Operations
get(index) - Return the element at the specified index
set(index, element) - Replace the element at the specified index


Remove Operations
remove(index) - Remove an element at a specific index
pop() - Remove and return the last element


Utility Operations
size() - Return the number of elements
isEmpty() - Check if the array is empty
clear() - Remove all elements


Capacity Management
resize(newCapacity) - Change the underlying array capacity
capacity() - Return the current capacity
trimToSize() - Trim the capacity to match the size


Search Operations
indexOf(element) - Find first occurrence of an element
contains(element) - Check if element exists
*/




/*
 *
Singly-linked	Doubly-linked	Circular, doubly-linked
LL_PREPEND(head,add)              ;        DL_PREPEND(head,add)                                ; CDL_PREPEND(head,add)              ;
LL_PREPEND_ELEM(head,ref,add)     ;        DL_PREPEND_ELEM(head,ref,add)                       ; CDL_PREPEND_ELEM(head,ref,add)     ;
LL_APPEND_ELEM(head,ref,add)      ;        DL_APPEND_ELEM(head,ref,add)                        ; CDL_APPEND_ELEM(head,ref,add)      ;
LL_REPLACE_ELEM(head,del,add)     ;        DL_REPLACE_ELEM(head,del,add)                       ; CDL_REPLACE_ELEM(head,del,add)     ;
LL_APPEND(head,add)               ;        DL_APPEND(head,add)                                 ; CDL_APPEND(head,add)               ;
LL_INSERT_INORDER(head,add,cmp)   ;        DL_INSERT_INORDER(head,add,cmp)                     ; CDL_INSERT_INORDER(head,add,cmp)   ;
LL_CONCAT(head1,head2)            ;        DL_CONCAT(head1,head2)                              ;
LL_DELETE(head,del)               ;        DL_DELETE(head,del)                                 ; CDL_DELETE(head,del)               ;
LL_SORT(head,cmp)                 ;        DL_SORT(head,cmp)                                   ; CDL_SORT(head,cmp)                 ; 
LL_FOREACH(head,elt) {…}          ;        DL_FOREACH(head,elt) {…}                            ; CDL_FOREACH(head,elt) {…}          ;
LL_FOREACH_SAFE(head,elt,tmp) {…} ;        DL_FOREACH_SAFE(head,elt,tmp) {…}                   ; CDL_FOREACH_SAFE(head,elt,tmp1,tmp2) {…}
LL_SEARCH_SCALAR(head,elt,mbr,val);        DL_SEARCH_SCALAR(head,elt,mbr,val)                  ; CDL_SEARCH_SCALAR(head,elt,mbr,val);
LL_SEARCH(head,elt,like,cmp)      ;        DL_SEARCH(head,elt,like,cmp)                        ; CDL_SEARCH(head,elt,like,cmp)      ;
LL_LOWER_BOUND(head,elt,like,cmp) ;        DL_LOWER_BOUND(head,elt,like,cmp)                   ; CDL_LOWER_BOUND(head,elt,like,cmp) ;
LL_COUNT(head,elt,count)          ;        DL_COUNT(head,elt,count)                            ; CDL_COUNT(head,elt,count)          ; 
*
*/

