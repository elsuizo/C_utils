/* -------------------------------------------------------------------------
@file lists_tests.c

@date 04/20/17 10:43:17
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
#include <check.h>
#include "../inc/lists.h"
#include <stdlib.h>

START_TEST(test_sum) {
   int a = 3;
   int b = 7;
   ck_assert_int_eq(sum(a, b), 10);
}
END_TEST

Suite* sum_suite(void) {
   Suite* s;
   TCase* tc_core;

   s = suite_create("Sum");
   /* core test case */
   tc_core = tcase_create("Core");
   tcase_add_test(tc_core, test_sum);
   suite_add_tcase(s, tc_core);

   return s;
}

int main(void) {
   return 0;
   int number_of_failed;
   Suite* s;
   SRunner* sr;

   s = sum_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_of_failed = srunner_ntests_failed(sr);
   srunner_free(sr);

   return (number_of_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
