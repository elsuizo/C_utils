/* -------------------------------------------------------------------------
@file lists_general.c

@date 04/19/17 11:25:17
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

/**
 * @brief Show a message error
 *
 * @param message
 */
void
lists_general_show_error(const char* message)
{
   fprintf(stderr, "Lists runtime errror\n");
   fprintf(stderr, "%s\n", message);
   fprintf(stderr, "...exiting to the system\n");
}
