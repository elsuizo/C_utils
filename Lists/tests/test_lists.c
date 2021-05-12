/* -------------------------------------------------------------------------
@file test_lists.c

@date 07/10/17 13:35:56
@author Martin Noblia
@email mnoblia@disroot.org

@brief
Unit test for the list library
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
#include <stdlib.h>
#include <stdio.h>
#include "../inc/lists.h"
#include "vendor/unity.h"

static struct SingleLinked empty_list = {
   NULL,
   NULL,
   NULL,
   0,
};

static void
assert_equal_SingleLinked(struct SingleLinked* slist_out,
                          struct SingleLinked* expected)
{
   TEST_ASSERT_EQUAL_UINT8(expected->size, slist_out->size);      /* size */
   TEST_ASSERT_EQUAL_PTR(expected->head, slist_out->head);        /* head */
   TEST_ASSERT_EQUAL_PTR(expected->tail, slist_out->tail);        /* tail */
   TEST_ASSERT_EQUAL_PTR(expected->current, slist_out->current);  /* current */
}

void test_single_lists_init() {
   struct SingleLinked test_list;
   lists_single_linked_init(&test_list);
   assert_equal_SingleLinked(&test_list, &empty_list);
}

/* NOTE(elsuizo:2020-05-11): agrego un elemento a la lista y me tiene que devolver un resultado positivo */
void test_single_lists_add_head_list_empty() {
   struct SingleLinked test_list;
   int data_test = 37;
   int result = lists_single_linked_add_head(&test_list, &data_test);
   TEST_ASSERT_EQUAL_INT(LISTS_STATUS_OK, result);
}

/* FIXME(elsuizo:2020-04-16): si la lista tiene un solo elemento entonces
 * current == head == tail o no??? porque este test solo funciona cuando
 * miramos head */
void test_single_list_data() {
   struct SingleLinked test_list;
   lists_single_linked_init(&test_list);
   int data_test = 37;
   int expected  = 37;
   int _code = lists_single_linked_add_head(&test_list, &data_test);
   /* NOTE(elsuizo:2020-04-16): recordemos que los datos son void* */
   void* current = test_list.current->data;
   void* current_head = test_list.head->data;
   void* current_tail = test_list.tail->data;
   /* los tres deben apuntar a la misma direccion */
   int result = *((int*) current);
   int result2 = *((int*) current_head);
   int result3 = *((int*) current_tail);
   TEST_ASSERT_EQUAL_INT(result, expected);
   TEST_ASSERT_EQUAL_INT(result2, expected);
   TEST_ASSERT_EQUAL_INT(result3, expected);
}

/* NOTE(elsuizo:2020-05-11): hay que inicializar la lista primero sino apunta a cualquier lado!!! */
void test_single_list_size() {
   struct SingleLinked test_list;
   lists_single_linked_init(&test_list);
   char* data_test = "37";
   if (lists_single_linked_add_head(&test_list, &data_test)) {
      int result = test_list.size;
      uint8_t expected = 1;
      TEST_ASSERT_EQUAL_INT(result, expected);
   }
}
int main(void) {
   UnityBegin("test_lists.c");

   RUN_TEST(test_single_lists_init);
   RUN_TEST(test_single_lists_add_head_list_empty);
   RUN_TEST(test_single_list_data);
   RUN_TEST(test_single_list_size);
   UnityEnd();
   return 0;
}
