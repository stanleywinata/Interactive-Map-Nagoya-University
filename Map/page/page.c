#include "item.h"
#include <stdio.h>
#include <stdlib.h>


#define RESULT_PAGE "result.html"


/* a function to generate HTML file that contains query results */
void print_page_sample(Item *result[], int size)
{
	FILE *f;
	int i,j,k;

	if( (f = fopen(RESULT_PAGE, "w")) == NULL) {
		printf("cannot open file %s.", RESULT_PAGE);
		return;
	}

	/* printing HTML header */
	fprintf(f, "<html>\n");
	fprintf(f, "<head>\n");
	fprintf(f, "<title>result page</title>\n");
	fprintf(f, "<style type=\"text/css\">\n");
	fprintf(f, "table { background-image: url(\"nagoya.gif\"); }\n");
	fprintf(f, "td { padding: 0px; border: 1px; width: 16px; height: 14px; font-size: 10px; text-aligh: center; color: #ff00ff; } \n");
	fprintf(f, "</style>\n");
	fprintf(f, "</head>\n");
	fprintf(f, "<body>\n");

	/* printing HTML table */
	fprintf(f, "<table>\n");
	for(i = 0; i < MAX_X_COORDINATE; i++){

		/* printing table row */
		fprintf(f, "<tr>\n");
		for(j = 0; j < MAX_Y_COORDINATE; j++){

			/* printing table column */
			fprintf(f,"<td>");

			/* printing item label corresponding to X=j, Y=i */

				/* PLEASE REPLACE HERE */
				if(j == 1 && i == 1)
					fprintf(f, "%d", 1); /* item label1 on X=1,Y=1 */
				if(j == 2 && i == 5)
					fprintf(f, "%d", 2); /* item label2 on X=2,Y=5 */
				if(j == 5 && i == 3)
					fprintf(f, "%d", 3); /* item label3 on X=5,Y=3 */
				/* PLEASE REPLACE HERE */

			fprintf(f,"</td>\n");
		}
		fprintf(f, "</tr>\n");
	}
	fprintf(f, "</table>\n");

	/* printing HTML list */
	fprintf(f, "<ul>\n");

	/* printing list items */

		/* PLEASE REPLACE HERE */
		fprintf(f, "<li>%d : %s</li>\n", 1, "Shop A"); /* item1 */
		fprintf(f, "<li>%d : %s</li>\n", 2, "Shop B"); /* item2 */
		fprintf(f, "<li>%d : %s</li>\n", 3, "Shop C"); /* item3 */
		/* PLEASE REPLACE HERE */

	fprintf(f, "</ul>\n");


	fprintf(f, "</body>\n");
	fprintf(f, "</html>\n");

	fclose(f);

	printf("Search result is written to the file %s.\n", RESULT_PAGE);
	return;
}


/* sample main function */
int main(void)
{
	/* In this sample, we use dummy query result (no items) */
	Item *result[100];
	int num_result = 0;


	print_page_sample(result, num_result);

	return 0;
}

