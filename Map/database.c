/*
 * database.h : A header file to share function prototype for database accesses
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "database.h"
#include "page.h"

/*To Read Lines*/
int read_line(char str[], int n)
{
    int ch, i = 0;

    while(isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF) {
        if(i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

/*
 * the definition of array variable to store items
 */
Item store[MAX_ITEM_SIZE];
Item result[MAX_ITEM_SIZE];
Item neighbor;

/*
 * Integer variable to store the number of stored items
 */

int num_stored=0;

/*
 * Functions
 */

	int ori_dis[MAX_ITEM_SIZE];
	int currentx,currenty;
/* Original function to find closest item within specified category*/
void original_function(){
	int i,j,k,min,temp_dis;
	int num_result=0;
	char catofitem[MAX_CATEGORY_LENGTH];


	Item temp;

	printf("What type of store are you looking for: ");
	read_line(catofitem,MAX_CATEGORY_LENGTH);
	printf("What is your X-Coordinate: ");
	scanf("%d",&currentx);
	printf("What is your Y-coordinate: ");
	scanf("%d",&currenty);

	for(i=0;i<num_stored;i++){
		if(strcmp(catofitem,store[i].category)==0){
		strcpy(result[num_result].name,store[i].name);
		strcpy(result[num_result].category,store[i].category); 
		result[num_result].x=store[i].x;
		result[num_result].y=store[i].y;
		ori_dis[num_result]=sqrt(pow((result[num_result].x-currentx),2)+pow((result[num_result].y-currenty),2))*40;
		num_result++;
	}
}

for(j=0;j<num_result;j++){
	for(k=j+1;k<num_result;k++){
		if(ori_dis[k]<ori_dis[j]){

			temp=result[j];
			result[j]=result[k];
			result[k]=temp;

			temp_dis=ori_dis[j];
			ori_dis[j]=ori_dis[k];
			ori_dis[k]=temp_dis;
		}
	}
}
print_page_original(result,num_result);
}
/* function for nearest neighbor items */
void find_nearest_neighbor(){
	int i,j,x,y;
	int dis[num_stored];

	printf("Enter your X-Coordinate: ");
	scanf("%d",&x);
	printf("Enter your Y-coordinate: ");
	scanf("%d",&y);

	int min=0;
	for(i=0;i<num_stored;i++){
		dis[i]=sqrt(pow((store[i].x-x),2)+pow((store[i].y-y),2));
		if(dis[i]<dis[min]){
			min=i;
		}

	}		neighbor.x=store[min].x;
		neighbor.y=store[min].y;
		print_page_sample(neighbor,1);
}

/* function for finding items based on range */
void find_items_by_range(){
	int i,x,y,range,dis,test;
	int num_result=0;
	printf("Enter your X-Coordinate: ");
	scanf("%d",&x);
	printf("Enter your Y-ccordinate: ");
	scanf("%d",&y);
	printf("Enter distance threshold (m): ");
	scanf("%d",&range);
	printf("%d",x^3);

	for(i=0;i<num_stored;i++){
		dis=sqrt(pow((store[i].x-x),2)+pow((store[i].y-y),2))*40;
		if(range>dis){
		strcpy(result[num_result].name,store[i].name); 
		strcpy(result[num_result].category,store[i].category); 
		result[num_result].x=store[i].x;
		result[num_result].y=store[i].y;
		num_result++;
		}
	}
print_page_sample(result,num_result);
}
/* function for finding items based on category */
void find_items_by_category(){
	int num_result=0;
	int i,j,k,l;
	char catofitem[MAX_CATEGORY_LENGTH];


	printf("Enter the category of store: ");
	read_line(catofitem, MAX_CATEGORY_LENGTH);

	for(i=0;i<num_stored;i++){

		if(strcmp(catofitem,store[i].category)==0){
		strcpy(result[num_result].name,store[i].name); 
		strcpy(result[num_result].category,store[i].category); 
		result[num_result].x=store[i].x;
		result[num_result].y=store[i].y;
		num_result++;
	}
}
print_page_sample(result,num_result);
}

/* function for finding items based on name */

void find_items_by_name(){
	int num_result=0;
	int i,j,k,l;
	char nameofitem[MAX_NAME_LENGTH];

	printf("Enter the name of store: ");
	read_line(nameofitem, MAX_NAME_LENGTH);

	for(i=0;i<num_stored;i++){
		if(strcmp(nameofitem,store[i].name)==0){
		strcpy(result[num_result].name,store[i].name); 
		strcpy(result[num_result].category,store[i].category); 
		result[num_result].x=store[i].x;
		result[num_result].y=store[i].y;
		num_result++;
	}
}
print_page_sample(result,num_result);
}
/* function for loading items from a file */

void load_items(){
	FILE *fp;
	char filename[20];
	
	printf("Enter filename: ");
	scanf("%s",&filename);

	if((fp=fopen(filename,"r"))==NULL){
		printf("Cannot Open File %s\n",filename);
		return;
	}

while(fscanf(fp,"%[^,],%[^,],%d,%d\n",&store[num_stored].name,
		&store[num_stored].category,&store[num_stored].x,&store[num_stored].y)==4){
	
	num_stored++;
}
fclose(fp);
}

/* function for saving items into a file */
	void save_items(){
		FILE *fp;
		char filename[20];
		int i;

		printf("Enter filename: ");
		scanf("%s",&filename);

		fp=fopen(filename,"a");
		
		for(i=0;i<num_stored;i++){
				fprintf(fp,"%s,%s,%d,%d\n",store[i].name,
					store[i].category,store[i].x,store[i].y);
				}
fclose(fp);
}
/* function for insertion of a new data item */
void insert_item(){
	int shop_number=num_stored;

	if(num_stored==MAX_ITEM_SIZE){
		printf("OOPS ! database is full");
		return;
	}
	printf("Enter Name of Store: ");
	read_line(store[shop_number].name, MAX_NAME_LENGTH);
	printf("Enter Cateogry of Item: ");
	read_line(store[shop_number].category, MAX_CATEGORY_LENGTH);
	printf("Enter the X-Coordinate: ");
	scanf("%d",&store[shop_number].x);
	printf("Enter Y-ccordinate: ");
	scanf("%d",&store[shop_number].y);
	num_stored++;
}
/* function for printing all data items */
void print_all_items(){
	int i,j,k,l,m;
	k=10+16+9+9+11+6;
	char fir[20],sec[20],thir[20];
	strcpy(fir,"Storename");
	strcpy(sec,"Category");

	/*printf("|Store name 		       |Category 	    |Position |\n");*/
	printf("|%-30s|%-20s|Position   |\n",fir,sec);
	printf("+");
	for(j=0;j<30;j++)
		printf("-");
	printf("+");
	for(k=0;k<20;k++)
		printf("-");
	printf("+");
	for(l=0;l<11;l++)
		printf("-");
	printf("+");
	printf("\n");

	for(i=0;i<num_stored;i++){
		printf("|%-30s|%-20s|( %3d, %3d)|\n",store[i].name, store[i].category, store[i].x, store[i].y);
	}
	printf("+");
	for(j=0;j<30;j++)
		printf("-");
	printf("+");
	for(k=0;k<20;k++)
		printf("-");
	printf("+");
	for(l=0;l<11;l++)
		printf("-");
	printf("+");
	printf("\n");
	
}




