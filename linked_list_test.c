#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>




void main(){

	struct cu_data{
		
	char status[3] ;
	char name[20] ;
	char lname[20] ;
	char hire_date[10] ;
	char id[10] ;
	char tel[12] ;
	char email[100] ;
	
	struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));
	d = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;



	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	rewind(staff_data);

	while(1 > 0){
		
		fscanf(staff_data , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->hire_date , q->id , q->tel , q->email );
		
		q->node = d ;
		q = d ;
		d->node = NULL;
		if(feof(staff_data) != 0){
			break;
		}
	}

	fclose(staff_data);


	while(t != NULL){
	
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , t->status , t->name ,  t->lname , t->hire_date , t->id , t->tel , t->email );
		
		t = t->node ;

	}
}



