// Write a recursive function to print alternate nodes of a single linked list
// Copyright (C) 2018  Julius Alphonso

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#define NULL 0

struct Linked_List
{
    int data;
    struct Linked_List * next;
};

void printll(struct Linked_List * ll)
{
    if(ll == NULL)
        return;
    // end if

    printf("%d ", ll->data);

    // Check if
    // next node is NULL
    // next node is last node
    if (ll->next == NULL)
        return;
    else if (ll->next->next == NULL);
        return;
    // end if

    printll(ll->next->next);
}