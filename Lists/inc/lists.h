/* -------------------------------------------------------------------------
@file lists.h

@date 04/18/17 21:38:23
@author Martin Noblia
@email mnoblia@disroot.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#ifndef LISTS_H
#define LISTS_H
/* includes */
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
/*=========================================================================
 *                        General
 ===========================================================================*/

/*-------------------------------------------------------------------------
 *                        defines
 -------------------------------------------------------------------------*/
#define LISTS_STATUS_OK       0
#define LISTS_STATUS_ERROR   -1

/*-------------------------------------------------------------------------
 *                        macros
 -------------------------------------------------------------------------*/
#define LISTS_SIZE(list) ((list)->size)
#define LISTS_HEAD(list) ((list)->head)
#define LISTS_TAIL(list) ((list)->tail)
#define LISTS_SINGLE_IS_HEAD(SingleLinked, Node)((node)->next == NULL ? true : false)
#define LISTS_GET_DATA(node)((node)->data)
#define LISTS_GET_NEXT(node)((node)->next)
/*-------------------------------------------------------------------------
 *                        prototypes general functions
 -------------------------------------------------------------------------*/
extern void
lists_general_show_error(const char* message);

/*=========================================================================
 *                        Single linked lists
 ===========================================================================*/
/* TODO(elsuizo:2017-04-18):put here a definition of this data structure */



/*-------------------------------------------------------------------------
 *                        custom data types
 -------------------------------------------------------------------------*/
struct Node {
   void* data;
   struct Node* next;
};

struct SingleLinked {
   struct Node* head;
   struct Node* tail;
   struct Node* current;
   uint8_t size;
};
/* function pointers to functions for display the single linked lists */
typedef void (*LISTS_SINGLE_DISPLAY)(void*); /* return void take void* */
/* function pointers to functions for compare two lists */
typedef int(*LISTS_SINGLE_COMPARE)(void*, void*);/* return uint8_t take two void* */
/*-------------------------------------------------------------------------
 *                        prototypes
 -------------------------------------------------------------------------*/
extern void
lists_single_linked_init(struct SingleLinked* slist);

extern int
lists_single_linked_add_head(struct SingleLinked* slist, const void* data);

extern int
lists_single_linked_add_tail(struct SingleLinked* slist, const void* data);

extern int
lists_single_linked_delete_Node(struct SingleLinked* slist, struct Node* node);

extern struct Node*
lists_single_linked_list_get_Node(struct SingleLinked* slist, LISTS_SINGLE_COMPARE compare_func, const void* data);

extern struct Node*
lists_single_linked_list_get_Node_Linus(struct Node** head, const void* data);

extern void
lists_single_linked_list_display(struct SingleLinked* slist, LISTS_SINGLE_DISPLAY display_func, const char* name);

/*=========================================================================
 *                        Double linked lists
 ===========================================================================*/
/* TODO(elsuizo:2017-04-19):add the definition of this data structure here */

/*-------------------------------------------------------------------------
 *                        custom data structures
 -------------------------------------------------------------------------*/
struct NodeDouble {
   void* data;
   struct NodeDouble* next;
   struct NodeDouble* previous;
};

struct DoubleLinked {
   struct NodeDouble* head;
   struct NodeDouble* tail;
   struct NodeDouble* current;
   uint8_t size;
};

/*-------------------------------------------------------------------------
 *                        prototypes
 -------------------------------------------------------------------------*/
extern void
list_double_linked_init(struct DoubleLinked* dlist);

extern int
lists_double_linked_add_head(struct DoubleLinked* dlist, const void* data);

extern int
lists_double_linked_add_tail(struct DoubleLinked* dlist, const void* data);

extern int
lists_double_linked_delete_NodeDouble(struct DoubleLinked* dlist, struct NodeDouble* dnode);

extern struct NodeDouble*
lists_double_linked_get_NodeDouble(struct DoubleLinked* dlist, LISTS_SINGLE_COMPARE compare_func, const void* data);

extern int
lists_double_linked_insert_next(struct DoubleLinked* dlist, struct NodeDouble* dnode, const void* data);

extern int
lists_double_linked_insert_previous(struct DoubleLinked* dlist, struct NodeDouble* dnode, const void* data);

extern void
list_double_linked_display(struct DoubleLinked* dlist, LISTS_SINGLE_DISPLAY display_func, const char* name);

#endif /* end Lists */
