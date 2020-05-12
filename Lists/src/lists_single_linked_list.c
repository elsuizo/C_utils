/* -------------------------------------------------------------------------
@file lists_single_linked_list.c

@date 04/18/17 23:35:59
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
#include "../inc/lists.h"

/*-------------------------------------------------------------------------
 *                        implementations
 -------------------------------------------------------------------------*/
/**
 * @brief Initialize a single linked list
 *
 * @param slist
 */
extern void
lists_single_linked_init(struct SingleLinked* slist) {
   slist->head = NULL;
   slist->tail = NULL;
   slist->current = NULL;
   slist->size = 0;
}

/**
 * @brief Add a node in the head of the single linked list
 *
 * @param slist
 * @param data
 *
 * @return
 */
extern int
lists_single_linked_add_head(struct SingleLinked* slist, const void* data) {
   struct Node* node;
   /* check for memory */
   if((node = (struct Node*)malloc(sizeof(struct Node))) == NULL) {
      printf("Failed to allocate the memoty\n");
      return LISTS_STATUS_ERROR;
   }
   node->data = (void*)data;
   /* the list is empty */
   if(slist->head == NULL) {
      slist->tail = node;
      slist->current = node;
      node->next = NULL;
   } else {
      node->next = slist->head;
   }
   slist->head = node;
   slist->size++;

   return LISTS_STATUS_OK;
}

/**
 * @brief Add a node in the tail of the single linked list
 *
 * @param slist
 * @param data
 *
 * @return
 */
extern int
lists_single_linked_add_tail(struct SingleLinked* slist, const void* data) {
   struct Node* node;
   if ((node = (struct Node*)malloc(sizeof(struct Node))) == NULL) {
      printf("Failed to allocate the memoty\n");
      return LISTS_STATUS_ERROR;
   }
   node->data = (void*)data;
   node->next = NULL; /* tail point to NULL */
   /* list is empty */
   if(slist->head == NULL) {
      slist->head = node;
   } else {
      slist->tail->next = node;
   }
   slist->tail = node;
   slist->size++;

   return LISTS_STATUS_OK;
}

/**
 * @brief Delete a especific node in a single linked list
 *
 * @param slist
 * @param node
 *
 * @return
 */
extern int
lists_single_linked_delete_Node(struct SingleLinked* slist,
                                             struct Node* node)
{
   /* check is empty */
   if (LISTS_SIZE(slist) == 0) {
      printf("ERROR the list is empty\n");
      return LISTS_STATUS_ERROR;
   }
   if (node == slist->head) {
      /* the list become empty */
      if (slist->head->next == NULL) {
         slist->head = slist->tail = NULL;
      }
      else {
         slist->head = slist->head->next;
      }
   } else {
      struct Node* tmp = slist->head;
      while (tmp != NULL && tmp->next != node) {
         tmp = tmp->next;
      }
      if (tmp != NULL) {
         tmp->next = node->next;
      }
   }
   free(node);
   slist->size--;

   return LISTS_STATUS_OK;

}

/**
 * @brief Get the node wich hold a especific data
 *
 * @param slist
 * @param compare_func
 * @param
 * @param compare_func
 * @param data
 *
 * @return
 */
extern struct Node*
lists_single_linked_get_Node(struct SingleLinked* slist, LISTS_SINGLE_COMPARE compare_func, const void* data)
{
   struct Node* node = slist->head;
   while (node != NULL) {
      if (compare_func(node->data, (void*)data) == 0) {
         return node;
      }
   }
   return NULL;
}

/**
 * @brief
 *
 * @param head
 * @param data
 *
 * @return
 */
extern struct Node*
lists_single_linked_get_Node_Linus(struct Node** head, const void* data)
{
   struct Node** node2 = head;
   /* while node2 != NULL and != data */
   while (*node2 && (**node2).data != data) {
      node2 = &(*node2)->next;
   }
   if(*node2 == NULL) {
      return NULL;
   }
   struct Node* delete_Node = *node2;
   *node2 = delete_Node->next;
   delete_Node->next = NULL;

   return delete_Node;
}

/**
 * @brief
 *
 * @param slist
 * @param display_func
 * @param
 * @param display_func
 * @param name
 */
extern void
lists_single_linked_display(struct SingleLinked* slist, LISTS_SINGLE_DISPLAY display_func, const char* name)
{
   printf("=======%s=======\n", name);
   struct Node* current = slist->head;
   while (current != NULL) {
      display_func(current->data);
      current = current->next;
   }
}
