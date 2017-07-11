/* -------------------------------------------------------------------------
@file test_lists.c

@date 07/10/17 13:35:56
@author Martin Noblia
@email martin.noblia@openmailbox.org

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
   TEST_ASSERT_EQUAL_UINT8(expected->size, slist_out->size); /* size */
   TEST_ASSERT_EQUAL_PTR(expected->head, slist_out->head); /* head */
   TEST_ASSERT_EQUAL_PTR(expected->tail, slist_out->tail); /* tail */
   TEST_ASSERT_EQUAL_PTR(expected->current, slist_out->current); /* current */

}

void test_single_lists_init() {
   struct SingleLinked test_list;
   lists_single_linked_init(&test_list);
   assert_equal_SingleLinked(&test_list, &empty_list);
}

void test_single_lists_add_head_list_empty() {
   struct SingleLinked test_list;
   int data_test = 37;
   int result = lists_single_linked_add_head(&test_list, &data_test);
   TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
   UnityBegin("test_lists.c");

   RUN_TEST(test_single_lists_init);
   RUN_TEST(test_single_lists_add_head_list_empty);
   UnityEnd();
   return 0;
}
