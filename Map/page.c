#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include "page.h"


#define RESULT_PAGE "result.html"


/* a function to generate HTML file that contains query results */
void print_page_sample(Item result[], int size)
{
	FILE *f;
	int i,j,k,l;

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
	fprintf(f, "td { padding: 0px; border: 1px; width: 16px; height: 14px; font-size: 14px; text-aligh: center; color: #ff00ff; } \n");
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
			for(l=0;l<size;l++){
				if(j == result[l].x && i == result[l].y)
					fprintf(f, "%d", l); /* item label1 on X=1,Y=1 */
}
			fprintf(f,"</td>\n");
		}
		fprintf(f, "</tr>\n");
	}
	fprintf(f, "</table>\n");

	/* printing HTML list */
	fprintf(f, "<ul>\n");

	/* printing list items */

		/* PLEASE REPLACE HERE */
	for(l=0;l<size;l++){
		fprintf(f, "<li>%d : %s</li>\n",l, result[l].name); 
	}
	fprintf(f, "</ul>\n");



	fprintf(f, "</body>\n");
	fprintf(f, "</html>\n");

	fclose(f);

	printf("Search result is written to the file %s.\n", RESULT_PAGE);
	return;
}


extern int ori_dis[100];
extern int currentx,currenty;
void print_page_original(Item result[], int size)
{
	FILE *f;
	int i,j,k,l;

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
	fprintf(f, "td { padding: 0px; border: 1px; width: 16px; height: 14px; font-size: 14px; text-aligh: center; color: #ff00ff; } \n");
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
				if(j == currentx && i == currenty)
					fprintf(f, "|*|");

			for(l=0;l<size;l++){
				if(j == result[l].x && i == result[l].y)
					fprintf(f, "%d", l+1); /* item label1 on X=1,Y=1 */
				/* PLEASE REPLACE HERE */
}
			fprintf(f,"</td>\n");
		}
		fprintf(f, "</tr>\n");
	}
	fprintf(f, "</table>\n");

	/* printing HTML list */
	fprintf(f, "<ul>\n");

	/* printing list items */
	fprintf(f,"<b><i>Closest %s near you:</i></b>",result[1].category);
		/* PLEASE REPLACE HERE */
	fprintf(f, "<li>|*| : Your Current Location|Distance:   0 [m]</li>\n"); 
	for(l=0;l<size;l++){
		fprintf(f, "<li>%d : %s|Distance:   %d [m]</li>\n",l+1, result[l].name,ori_dis[l]); 
	}
	fprintf(f, "</ul>\n");



	fprintf(f, "</body>\n");
	fprintf(f, "</html>\n");

	fclose(f);

	printf("Search result is written to the file %s.\n", RESULT_PAGE);
	return;
}