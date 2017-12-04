/*
 * page.h : A header file to share function prototypes for page viewing
 */
#ifndef PAGE_H
#define PAGE_H

/* this file depends on item.h */
#include "item.h"


/*
 * Macro definitions related to page viewing
 */


/*
 * Function prototypes related to page viewing
 */

/* function prototype to show query result pages */
extern int ori_dis[100];
extern int currentx, currenty;
void print_page_original(Item result[], int size);






#endif
