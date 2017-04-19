/* -------------------------------------------------------------------------
@file double_linked_list.c

@date 04/19/17 11:09:14
@author Martin Noblia
@email martin.noblia@openmailbox.org

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
/* include headers */
#include "../inc/lists.h"
/*-------------------------------------------------------------------------
 *                        implementations
 -------------------------------------------------------------------------*/
/**
 * @brief Initialize the double linked list
 *
 * @param dlist:
 */
extern void
list_double_linked_init(struct DoubleLinked* dlist)
{
   dlist->head = NULL;
   dlist->tail = NULL;
   dlist->current = NULL;
   dlist->size = 0;
}

/**
 * @brief Add a node to the head of the double linked list
 *
 * @param dlist
 * @param data
 *
 * @return -1:error, 0:other case
 */
extern int
list_double_linked_add_head(struct DoubleLinked* dlist, const void* data)
{
   struct NodeDouble* dnode;
   /* check for memory */
   dnode = (struct NodeDouble*)malloc(sizeof(struct NodeDouble));
   if (dnode == NULL) {
      lists_general_show_error("allocation error");
      return LISTS_STATUS_ERROR;
   }
   dnode->data = (void*)data;
   /* the list is empty */
   if (dlist->head == NULL) {
      dlist->tail = dnode;
      dnode->next = NULL;
      dnode->previous = NULL;
   } else {
      dnode->next = dlist->head;
      dnode->previous = NULL;
   }
   dlist->head = dnode;
   dlist->size++;

   return LISTS_STATUS_OK;

}


/**
 * @brief Add a node in the tail of the double linked list
 *
 * @param dlist
 * @param data
 *
 * @return -1:error, 0:other case
 */
extern int
lists_double_linked_add_tail(struct DoubleLinked* dlist, const void* data)
{
   struct NodeDouble* dnode;
   /* check for memory */
   dnode = (struct NodeDouble*)malloc(sizeof(struct NodeDouble));
   if (dnode == NULL) {
      lists_general_show_error("allocation error");
      return LISTS_STATUS_ERROR;
   }
   dnode->data = (void*)data;
   dnode->next = NULL; /* is the tail */
   if (dlist->head == NULL) {
      dlist->head = dnode;
      dnode->next = NULL;
      dnode->previous = NULL;
   } else {
      dlist->tail->next = dnode;
   }
   dlist->tail = dnode;
   dlist->size++;

   return LISTS_STATUS_OK;

}

/**
 * @brief Delete a specific node of the double linked list
 *
 * @param dlist
 * @param dnode
 *
 * @return -1:error, 0:other case
 */
extern int
lists_double_linked_delete_NodeDouble(struct DoubleLinked* dlist, struct NodeDouble* dnode)
{
   /* check if the list is empty */
   if (!LISTS_SIZE(dlist)) {
      lists_general_show_error("The list is empty!!!");
      return LISTS_STATUS_ERROR;
   }
   if (dnode == dlist->head) {
     /* the list becomes empty */
      if (dlist->head->next == NULL) {
         dlist->head = dlist->tail = NULL;
      } else {
         dlist->head = dlist->head->next;
      }
   } else {
      struct NodeDouble* tmp = dlist->head;
      /* iterate over the nodes */
      while (tmp != NULL && tmp->next != dnode) {
         tmp = tmp->next;
      }
      if (tmp != NULL) {
         tmp->next = dnode->next;
      }
   }
   free(dnode);
   dlist->size--;

   return LISTS_STATUS_ERROR;
}

/**
 * @brief Get the node with contain a espefic data from the double linked list, the search begin in a head of the list.
 *
 * @param dlist
 * @param compare_func
 * @param 
 * @param compare_func
 * @param data
 *
 * @return -1:error, 0:other case
 */
extern struct NodeDouble*
list_double_linked_get_NodeDouble(struct DoubleLinked* dlist, LISTS_SINGLE_COMPARE compare_func, const void* data)
{
   struct NodeDouble* noded = dlist->head; /* point to the head of the list */
   while (noded != NULL) {
      if (compare_func(noded->data, (void*)data) == 0) {
         return noded;
      }
   }
   return NULL;
}
