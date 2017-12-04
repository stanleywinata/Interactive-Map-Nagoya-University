/*
 * main_menu.c : A Source file of main function
 */
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "database.h"

	
/* main function */
int main(void){
	char code;
    printf("This is a skelton of the spatial database.\n");
  
        for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')  /* skips to end of line */
            ;
        switch(code) {
            case 'i': insert_item();
            		break;
            case 'p': print_all_items();
            		break;
            case 'q': return 0;
            		break;
            case 'l': load_items();
            		break;
            case 's': save_items();
            		break;
            case 'c': find_items_by_category();
                    break;
            case 'f': find_items_by_name();
                    break;
            case 'r': find_items_by_range();
                    break;
            case 'n': find_nearest_neighbor();
                    break;
            case 'o': original_function();
                    break;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
 return 0;
}


