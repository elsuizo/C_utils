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

#include "vendor/unity.h"
#include "../inc/lists.h"

void test_test() {
   int number_test = 37;
   TEST_ASSERT_EQUAL_INT(37, number_test);
}

int main(void)
{
   UnityBegin("test_lists.c");

   RUN_TEST(test_test);
   return 0;
}
