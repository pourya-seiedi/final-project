#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// function prototype -------------------
void menu(void);
void ADMIN(void);
void Admin_page(void);
void timer(long long int failed_time);
void timer_sec(int sec);
void Add_Staff(void);
void Staff_list(void);
void delete_staff(void);
void Staff_page(void);
void add_customer(void);
void staff_check(void);
void customer_list(void);
void add_book(void);
void delete_customer(void);
void admin_logs(void);
void fired_staff_list(void);
void book_list(void);
void ava_book_list(void);
void nva_book_list(void);
void active_user(char user[21] , char pass[21]);
void setting(void);
void ch_pass(void);
void ch_email(void);
void ch_tell(void);
void customer_page(void);
void staff_logs(void);
void active_m(void);
void fired_m(void);
void deactive_m(void);
void customer_check(void);



//---------------------------------------








// global variable ----------------------


// admin
char admin_user[] = "1" , admin_password[] = "1" , attempt = 0;



//---------------------------------------








// main body ----------------------------
void main(){
	
	menu();
	
}
//---------------------------------------



// menu body ----------------------------
void menu(void){
	
	int login_part ;


	printf("Welcome to command line library manager\n\n");
	printf("*LOGIN PAGE*\n");
	printf("1 - Admin\n");
	printf("2 - Staff\n");
	printf("3 - members\n");
	printf("4 - EXIT\n\n");
	
	printf("Please Enter Type Of Login : \n");
	scanf("%d" , &login_part);

	switch(login_part){

		case 1 :
			system("clear");
			ADMIN();
			Admin_page();
		
		case 2 :
			system("clear");
			// final form --> staff page will be called in staff_check for username usage
			staff_check();
			//Staff_page();
		
		case 3 :
			system("clear");
			customer_check();
			
			system("clear");
		
		case 4 :
			system("clear");
			exit(0);
		
		default :
			printf("Please Enter Numbers 1 to 4!!!");
			exit(0);
	}

}
//---------------------------------------



// ADMIN -------------------------------------------------------------
void ADMIN(void){
	char user[6] , password[11] ;
	
	printf("Enter User Name : ");
	scanf("%s" , user);
	
	printf("Enter Password : ");
	scanf("%s" , password);

	if(strcmp(admin_user , user) == 0 && strcmp(admin_password , password) == 0 ){
		attempt = 0 ;
		system("clear");
	}
	else{
		system("clear");
		menu();
	}
	
}

void Admin_page(void){
	
	int  page ; 


	
	printf("ADMIN MENU : \n\n");
	printf("1 - Add Staff\n");
	printf("2 - Staff List\n");
	printf("3 - Delete Staff\n");
	printf("4 - Logs\n");
	printf("5 - RETURN\n\n");

	printf("Enter Your Choice : \n");
	scanf("%d" , &page);


	switch(page){
		case 1:
			Add_Staff();
			Admin_page();

		case 2:
			Staff_list();
			Admin_page();

		case 3:
			delete_staff();
			Admin_page();
		case 4:
			admin_logs();
			Admin_page();

		case 5:
			// exit
			system("clear");
			menu();

		default:
			printf("Please Enter Numbers 1 to 5!!!\n");
			exit(0);
	}	
}

void Add_Staff(void){
	
	
	char name[21] , lname[21] , hire_date[11] , id[11];
	char tel[13] , email[101] , user_name[21] ;
	char password[20] ;
	long long int gl_id = time(NULL);


	printf("Name : ");
	scanf("%s" , name);


	printf("Last Name : ");
	scanf("%s" , lname);


	printf("ID : ");
	scanf("%s" , id);


	printf("Telephon Number : ");
	scanf("%s" , tel);
	
	printf("Email : ");
	scanf("%s" , email);
	
	printf("User Name : ");
	scanf("%s" , user_name);
	
	printf("Password : ");
	scanf("%s" , password);
	
	FILE *staff_data , *user_pass ;

	staff_data = fopen("STAFF_DATA.txt" , "a");

	fflush(staff_data);
	fprintf(staff_data , "%-5s" , "ACT");
	fprintf(staff_data , "%-21s" , name);
	fprintf(staff_data , "%-21s" , lname);
	fprintf(staff_data , "%-12s" , id);

	// hire date - PASS
	fprintf(staff_data , "%-12s" , "----" );
	//---------
	
	fprintf(staff_data , "%-12s" , tel );
	fprintf(staff_data , "%-50s" , email);
	fprintf(staff_data , "%-15lld" , gl_id);
	fprintf(staff_data , "\n");


	fclose(staff_data);


	user_pass = fopen("STAFF_PASS.txt" , "a");
	
	fprintf(user_pass , "%-5s%-21s%-21s%-15lld\n" , "ACT" , user_name , password , gl_id);
	
	fclose(user_pass);
	system("clear");
}

void Staff_list(void){
	

	system("clear");
	char input , i = 0;
	
	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");

	rewind(staff_data);

	
	if(staff_data == NULL){
		printf("UNABLE TO LOACATE THE FILE!!!");
	}


	input = fgetc(staff_data);
	while(input != EOF ){
		printf("%c" , input);
		input = fgetc(staff_data);
	}

	fclose(staff_data);
	
}


void delete_staff(void){

	char staff_id[12] , user[21]; 
	
	printf("ID : \n");
	scanf("%s" , staff_id);

	printf("User Name : \n");
	scanf("%s" , user);

	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		char global_id[15] ; 
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	rewind(staff_data);
	fflush(staff_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(staff_data , "%s%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email , q->global_id);
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(staff_data) != 0 ){
			break;
		}

	}

	fclose(staff_data);

	staff_data = fopen("STAFF_DATA.txt" , "w");
	rewind(staff_data);
	fflush(staff_data);


	while(t != NULL){
			
		if(strcmp(t->id , staff_id) == 0){
			strcpy(t->status , "DCT");
		}
		
		if(strcmp(t->status , "ACT") == 0 || strcmp(t->status , "DCT") == 0){
			fprintf(staff_data , "%-5s" , t->status );
			fprintf(staff_data , "%-21s" , t->name );
			fprintf(staff_data , "%-21s" , t->lname );
			fprintf(staff_data , "%-12s" , t->id );
			fprintf(staff_data , "%-11s" , t->hire_date );
			fprintf(staff_data , "%-13s" , t->tel );
			fprintf(staff_data , "%-50s" , t->email);
			fprintf(staff_data , "%-15s" , t->global_id);
			fprintf(staff_data , "\n");
		}

		t = t->node ;
	}

	fclose(staff_data);


	struct users{
		char status[4] ;
		char username[21] ;
		char password[21] ;
		char global_id[15] ;
		struct users *node ; 
	};


	struct users  *l , *g;
	l = malloc(sizeof(struct users));

	struct users *f , *k ;
	f = l ;
	k = f ;

	FILE *staff_pass ;
	staff_pass = fopen("STAFF_PASS.txt" , "r");
	rewind(staff_pass);
	fflush(staff_pass);

	while(1 > 0){
	
		g = malloc(sizeof(struct users));

		if(feof(staff_data) != 0 ){
			break;
		}

		fscanf(staff_data , "%s%s%s%s" , l->status , l->username , l->password , l->global_id );
		
		l->node = g ;
		l = g ;
		g->node = NULL;
	
	}

	fclose(staff_pass);

	staff_pass = fopen("STAFF_PASS.txt" , "w");
	rewind(staff_pass);
	fflush(staff_pass);


	while(k != NULL){
			
		if(strcmp(k->username , user) == 0){
			strcpy(k->status , "DCT");
		}
		
		if(strcmp(k->status , "ACT") == 0 || strcmp(k->status , "DCT") == 0){
			fprintf(staff_pass , "%-5s" , k->status );
			fprintf(staff_pass , "%-21s" , k->username );
			fprintf(staff_pass , "%-21s" , k->password );
			fprintf(staff_pass , "%-15s" , k->global_id );
			fprintf(staff_pass , "\n");
		}

		k = k->node ;
	}

	fclose(staff_pass);



	system("clear");
}



void admin_logs(){

	printf("\n\nLogs Page\n\n");
	printf("1 - Customer List\n");
	printf("2 - Staff List\n");
	printf("3 - Fired Staff List\n");
	printf("4 - Book List\n");
	printf("5 - Available Book List\n");
	printf("6 - Non-Available Book List\n");
	printf("7 - Time-Pass Book List\n");
	printf("8 - Non-Available Book History\n");
	printf("9 - Buy List History\n");
	printf("10 - Staff Abdd Book History\n");
	printf("11 - Entery Logs\n");
	printf("12 - RETURN\n");

	int page ;
	printf("Enter Your Choice : \n");
	scanf("%d" , &page);
	
	system("clear");

	switch(page){
		case 1:
			customer_list();
			admin_logs();

		case 2:
			Staff_list();
			admin_logs();

		case 3:
			fired_staff_list();
			admin_logs();

		case 4:
			book_list();
			admin_logs();

		case 5:
			ava_book_list();
			admin_logs();

		case 6:
			
			nva_book_list();
			admin_logs();

		case 7:
		

		case 8:
		

		case 9:
		

		case 10:
		

		case 11:
		

		case 12:
			system("clear");
			Admin_page();
		

		default :
			printf("enter a number between 1 to 12!!!");
			exit(0);
	}
	system("clear");
}


void fired_staff_list(void){



	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		char gl_id[15] ; 
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	rewind(staff_data);
	fflush(staff_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(staff_data , "%s%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email , q->gl_id);
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(staff_data) != 0 ){
			break;
		}

	}

	fclose(staff_data);
	
	
	while(t != NULL){
		
		if(strcmp(t->status , "DCT") == 0){
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->lname );
			printf("%-10s" , t->id );
			printf("%-10s" , t->hire_date );
			printf("%-15s" , t->tel );
			printf("%-25s" , t->email);
			printf("%-15s" , t->gl_id);
			printf("\n");

		}
		t = t->node;
	}

}





void book_list(void){

	system("clear");
	char input , i = 0;
	
	FILE *book ;
	book = fopen("BOOK_DATA.txt" , "r");

	rewind(book);

	
	if(book == NULL){
		printf("UNABLE TO LOACATE THE FILE!!!");
	}


	input = fgetc(book);
	while(input != EOF ){
		printf("%c" , input);
		input = fgetc(book);
	}

	fclose(book);
	

}


void ava_book_list(void){


	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char publisher[21] ;
		char writer[21] ;
		char publish_date[11] ;
		char date[12] ;
		char bnumber[12] ;
		
		// add book should be fixed
		//char user[21] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *book ;
	book = fopen("BOOK_DATA.txt" , "r");
	rewind(book);
	fflush(book);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(book , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->publisher , q->writer , q->publish_date , q->date , q->bnumber );
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(book) != 0 ){
			break;
		}

	}

	fclose(book);
	
	
	while(t != NULL){

		if(strcmp(t->status , "GGG") == 0){
			
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->publisher );
			printf("%-10s" , t->writer );
			printf("%-10s" , t->publish_date );
			printf("%-15s" , t->date );
			printf("%-25s" , t->bnumber);
			printf("\n");

		}
		t = t->node;

	}

}



void nva_book_list(void){


	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char publisher[21] ;
		char writer[21] ;
		char publish_date[11] ;
		char date[12] ;
		char bnumber[12] ;
		
		// add book should be fixed
		//char user[21] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *book ;
	book = fopen("BOOK_DATA.txt" , "r");
	rewind(book);
	fflush(book);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(book , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->publisher , q->writer , q->publish_date , q->date , q->bnumber );
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(book) != 0 ){
			break;
		}

	}

	fclose(book);
	
	
	while(t != NULL){

		if(strcmp(t->status , "YYY") == 0){
			
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->publisher );
			printf("%-10s" , t->writer );
			printf("%-10s" , t->publish_date );
			printf("%-15s" , t->date );
			printf("%-25s" , t->bnumber);
			printf("\n");

		}
		t = t->node;

	}

}




















//----------------------------------------------------------------------------------



// STAFF----------------------------------------------------------------------------

void staff_check(void){


	struct users{
		char status[4] ;
		char user_name[21] ;
		char password[21] ;
		char id[15] ;
		struct users *node ;
	};


	char user[21] , pass[21];

	printf("Enter User Name : \n");
	scanf("%s" , user);

	printf("Enter Password : \n");
	scanf("%s" , pass);

	struct users  *q , *d;
	q = malloc(sizeof(struct users));

	struct users *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_pass ;
	staff_pass = fopen("STAFF_PASS.txt" , "r");
	rewind(staff_pass);
	fflush(staff_pass);

	while(1 > 0){
	
		d = malloc(sizeof(struct users));
		
		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s" , q->status , q->user_name , q->password , q->id);
		q->node = d ;
		q = d ;
		d->node = NULL;

	}

	fclose(staff_pass);

	
	while(t != NULL){
	
		if(strcmp(t->status , "ACT") == 0 && strcmp(t->user_name , user) == 0 && strcmp(t->password , pass) == 0){
			system("clear");
			active_user(user , pass);
			Staff_page();
		}

		t = t->node ;
	}

	system("clear");
}


void Staff_page(void){
	
	int  page ; 
	
	printf("STAFF MENU : \n\n");
	printf("1 - Add Customer\n");
	printf("2 - Subscription Extend\n");
	printf("3 - Customer List\n");
	printf("4 - Delete Customer\n");
	printf("5 - Add Book\n");
	printf("6 - Logs\n");
	printf("7 - Settings\n");
	printf("8 - RETURN\n\n");

	printf("Enter Your Choice : \n");
	scanf("%d" , &page);


	switch(page){
		case 1 :
			add_customer();
			Staff_page();

		case 2 :

		case 3 :
			customer_list();
			Staff_page();
		
		case 4 :
			delete_customer();
			Staff_page();

		case 5 :
			add_book();
			Staff_page();
			
		case 6 :
			staff_logs();
			Staff_page();
		case 7 :
			setting();
			Staff_page();

		case 8 :
			system("clear");
			menu();

		default :
			printf("Please enter Number 1 to 8!!!");
			exit(0);
	}
}


void add_customer(void){

	char name[21] , lname[21] , sub_date[11] , id[11];
	char tel[13] , email[101] , user_name[21] ;
	char password[21] ;
	long long int gl_id = time(NULL);

	printf("Name : ");
	scanf("%s" , name);


	printf("Last Name : ");
	scanf("%s" , lname);


	printf("ID : ");
	scanf("%s" , id);


	printf("Telephon Number : ");
	scanf("%s" , tel);
	
	printf("Email : ");
	scanf("%s" , email);
	
	printf("User Name : ");
	scanf("%s" , user_name);
	
	printf("Password : ");
	scanf("%s" , password);
	
	FILE *customer_data , *user_pass ;

	customer_data = fopen("CUSTOMER_DATA.txt" , "a");

	fflush(customer_data);
	fprintf(customer_data , "%-5s" , "ACT");
	fprintf(customer_data , "%-20s" , name);
	fprintf(customer_data , "%-20s" , lname);
	fprintf(customer_data , "%-10s" , id);

	// hire date - PASS
	fprintf(customer_data , "%-10s" , "----" );
	//---------
	
	fprintf(customer_data , "%-15s" , tel );
	fprintf(customer_data , "%-25s" , email);
	fprintf(customer_data , "%-15lld" , gl_id);
	fprintf(customer_data , "\n");


	fclose(customer_data);


	user_pass = fopen("CUSTOMER_PASS.txt" , "a");
	
	fprintf(user_pass , "%-5s%-20s%-20s%-15lld\n" , "ACT" , user_name , password , gl_id);
	
	fclose(user_pass);
	system("clear");
}


void customer_list(void){
	
	system("clear");
	char input , i = 0;
	
	FILE *customer_data ;
	customer_data = fopen("CUSTOMER_DATA.txt" , "r");

	rewind(customer_data);

	
	if(customer_data == NULL){
		printf("UNABLE TO LOACATE THE FILE!!!");
	}


	input = fgetc(customer_data);
	while(input != EOF ){
		printf("%c" , input);
		input = fgetc(customer_data);
	}


	fclose(customer_data);

}

void add_book(void){

	// status 3 mode --> GGG - YYY - RRR
	// GGG FREE
	// YYY NOT AVILABLE
	// RRR PASSED LIMIT TIME
	char status[4];
	char name[21] , publisher[21] , writer[21] ;
	char publish_date[11] ;

	printf("Name : ");
	scanf("%s" , name);


	printf("Publisher : ");
	scanf("%s" , publisher);


	printf("Writer : ");
	scanf("%s" , writer);


	printf("Publish Date : ");
	scanf("%s" , publish_date);
	
	
	FILE *book_data ;

	book_data = fopen("BOOK_DATA.txt" , "a");

	fflush(book_data);
	fprintf(book_data , "%-5s" , "GGG");
	fprintf(book_data , "%-20s" , name);
	fprintf(book_data , "%-20s" , publisher);
	fprintf(book_data , "%-10s" , writer);
	fprintf(book_data , "%-10s" , publish_date );
	


		
	fprintf(book_data , "%-10s" , "-----");

	// book number
	fprintf(book_data , "%-10ld" , time(NULL));

	// staff user name
	//fprintf(book_data , "%-10s" , ------ );


	fprintf(book_data , "\n");
	
	fclose(book_data);
	system("clear");

}


void delete_customer(void){

	char cu_id[12]  , user[21]; 
	printf("ID : \n");
	scanf("%s" , cu_id);
	

	printf("User Name : \n");
	scanf("%s" , user);
	

	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		char gl_id[15] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *customer_data ;
	customer_data = fopen("CUSTOMER_DATA.txt" , "r");
	rewind(customer_data);
	fflush(customer_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));
		
		if(feof(customer_data) != 0 ){
			break;
		}

		fscanf(customer_data , "%s%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email , q->gl_id);
		q->node = d ;
		q = d ;
		d->node = NULL;
		

	}

	fclose(customer_data);

	customer_data = fopen("CUSTOMER_DATA.txt" , "w");
	rewind(customer_data);
	fflush(customer_data);


	while(t != NULL){
			
		if(strcmp(t->id , cu_id) == 0){
			strcpy(t->status , "DCT");
		}
		
		if(strcmp(t->status , "ACT") == 0 || strcmp(t->status , "DCT") == 0){
			fprintf(customer_data , "%-5s" , t->status );
			fprintf(customer_data , "%-20s" , t->name );
			fprintf(customer_data , "%-20s" , t->lname );
			fprintf(customer_data , "%-10s" , t->id );
			fprintf(customer_data , "%-10s" , t->hire_date );
			fprintf(customer_data , "%-15s" , t->tel );
			fprintf(customer_data , "%-25s" , t->email);
			fprintf(customer_data , "%-15s" , t->gl_id);
			fprintf(customer_data , "\n");
		}

		t = t->node ;
	}

	fclose(customer_data);



	struct users{
		char status[4] ;
		char username[21] ;
		char password[21] ;
		char global_id[15] ;
		struct users *node ; 
	};


	struct users  *l , *g;
	l = malloc(sizeof(struct users));

	struct users *f , *k ;
	f = l ;
	k = f ;

	FILE *cu_pass ;
	cu_pass = fopen("CUSTOMER_PASS.txt" , "r");
	rewind(cu_pass);
	fflush(cu_pass);

	while(1 > 0){
	
		g = malloc(sizeof(struct users));

		if(feof(cu_pass) != 0 ){
			break;
		}

		fscanf(cu_pass , "%s%s%s%s" , l->status , l->username , l->password , l->global_id );
		
		l->node = g ;
		l = g ;
		g->node = NULL;
	
	}

	fclose(cu_pass);

	cu_pass = fopen("CUSTOMER_PASS.txt" , "w");
	rewind(cu_pass);
	fflush(cu_pass);


	while(k != NULL){
			
		if(strcmp(k->username , user) == 0){
			strcpy(k->status , "DCT");
		}
		
		if(strcmp(k->status , "ACT") == 0 || strcmp(k->status , "DCT") == 0){
			fprintf(cu_pass , "%-5s" , k->status );
			fprintf(cu_pass , "%-21s" , k->username );
			fprintf(cu_pass , "%-21s" , k->password );
			fprintf(cu_pass , "%-15s" , k->global_id );
			fprintf(cu_pass , "\n");
		}

		k = k->node ;
	}

	fclose(cu_pass);


	system("clear");
	



}

void setting(void){

	int page ; 
	
	system("clear");
	printf("SETTINGS\n\n");
	
	printf("1 - Change Password\n");
	printf("2 - Change Email\n");
	printf("3 - Change Telephone Number\n");
	printf("4 - RETURN\n\n");


	printf("Enter Your Choice : \n");
	scanf("%d" , &page);

	switch(page){
		case 1: 
			ch_pass();
			setting();
		
		case 2: 
			ch_email();
			setting();
		
		case 3: 
			ch_tell();
			setting();
		
		case 4: 
			system("clear");
			break;

		default :
			printf("Please Enter A Number Between 1 and 4");
			exit(0);
	}


}

void ch_pass(void){
	
	system("clear");

	char new_pass[21] , pass_check[21];
	
	printf("Enter New Password\n");
	scanf("%s" , new_pass);
	
	printf("Enter New Password Again\n");
	scanf("%s" , pass_check);


	char user[21] , pass[21];
	FILE *user_data ;
	user_data = fopen("cr_user.txt" , "r");
	fscanf(user_data , "%s%s" , user , pass);
	fclose(user_data);


	if(strcmp(new_pass , pass) == 0){
		printf("Please Enter New Password\n");
		timer_sec(3);
		setting();
	}

	if(strcmp(new_pass , pass_check) != 0){
		printf("Wrong Password Confirmation\n");
		timer_sec(3);
		setting();
	}


	struct cu_data{
		
		char status[4] ;
		char user_name[21] ;
		char password[21] ;
		char gl_id[15] ;

		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_pass ;
	staff_pass = fopen("STAFF_PASS.txt" , "r");
	rewind(staff_pass);
	fflush(staff_pass);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s" , q->status , q->user_name ,  q->password , q->gl_id);
		q->node = d ;
		q = d ;
		d->node = NULL;

	}

	fclose(staff_pass);
	
	
	staff_pass = fopen("STAFF_PASS.txt" , "w");
	rewind(staff_pass);
	fflush(staff_pass);


	while(t->node != NULL){
		
		if(strcmp(user , t->user_name) == 0){
			strcpy(t->password , new_pass);
		}	
		if(strcmp(t->status , "ACT") == 0 || strcmp(t->status , "DCT") == 0 ){
		
			fprintf(staff_pass , "%-5s"  , t->status );
			fprintf(staff_pass , "%-20s" , t->user_name);
			fprintf(staff_pass , "%-20s" , t->password);
			fprintf(staff_pass , "%-15s" , t->gl_id);
			fprintf(staff_pass , "\n");
		
		}
		t = t->node;
	}

	fclose(staff_pass);

	printf("Operation Done\n");



	timer_sec(2);
}




void ch_email(void){


	system("clear");

	char new_email[21] , id[15];
	
	printf("Enter New email\n");
	scanf("%s" , new_email);


	char user[21] , pass[21];
	FILE *user_data ;
	user_data = fopen("cr_user.txt" , "r");
	fscanf(user_data , "%s%s" , user , pass);
	fclose(user_data);


	struct cu_data{
		
		char status[4] ;
		char user_name[21] ;
		char password[21] ;
		char gl_id[15] ;

		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_pass ;
	staff_pass = fopen("STAFF_PASS.txt" , "r");
	rewind(staff_pass);
	fflush(staff_pass);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s" , q->status , q->user_name ,  q->password , q->gl_id );
		q->node = d ;
		q = d ;
		d->node = NULL;

	}

	fclose(staff_pass);

	while(t->node != NULL){
		
		if(strcmp(user , t->user_name) == 0){
			strcpy(id, t-> gl_id);
		}
		t = t->node ; 
	}

	
	struct staff_d{
		char status[5] ;
		char name[21] ;
		char lname[21] ;
		char id[12] ;
		char date[12] ;
		char tel[12] ;
		char email[101] ;
		char gl_id[15] ;
		
		struct staff_d *node ;
	};
	

	struct staff_d  *l , *g;
	l = malloc(sizeof(struct staff_d));

	struct staff_d *f , *k ;
	f =  l ;
	k = f ;

	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	rewind(staff_data);
	fflush(staff_data);


	while(1 > 0){
	
		g = malloc(sizeof(struct staff_d));

		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s%s%s%s%s" , l->status , l->name ,  l->lname , l->id , l->date , l->tel , l->email , l->gl_id );
		l->node = g ;
		l = g ;
		g->node = NULL;
	}
	
	fclose(staff_data);
	


	staff_data = fopen("STAFF_DATA.txt" , "w");
	rewind(staff_data);
	fflush(staff_data);


	while(k->node != NULL){


		if(strcmp(id , k->gl_id) == 0){
			strcpy(k->email , new_email);
		}
		
		if(strcmp(k->status , "ACT") == 0 || strcmp(k->status , "DCT") == 0 ){
		
			fprintf(staff_data ,"%-5s" , k->status );
			fprintf(staff_data ,"%-20s" , k->name );
			fprintf(staff_data ,"%-20s" , k->lname );
			fprintf(staff_data ,"%-10s" , k->id );
			fprintf(staff_data ,"%-10s" , k->date );
			fprintf(staff_data ,"%-15s" , k->tel );
			fprintf(staff_data ,"%-25s" , k->email);
			fprintf(staff_data ,"%-15s" , k->gl_id);
			fprintf(staff_data ,"\n");

		}

		k = k->node ; 
	}

	fclose(staff_data);


}
void ch_tell(void){


	system("clear");

	char new_tel[21] , id[15];
	
	printf("Enter New Telphone Number\n");
	scanf("%s" , new_tel);


	char user[21] , pass[21];
	FILE *user_data ;
	user_data = fopen("cr_user.txt" , "r");
	fscanf(user_data , "%s%s" , user , pass);
	fclose(user_data);


	struct cu_data{
		
		char status[4] ;
		char user_name[21] ;
		char password[21] ;
		char gl_id[15] ;

		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *staff_pass ;
	staff_pass = fopen("STAFF_PASS.txt" , "r");
	rewind(staff_pass);
	fflush(staff_pass);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s" , q->status , q->user_name ,  q->password , q->gl_id );
		q->node = d ;
		q = d ;
		d->node = NULL;

	}

	fclose(staff_pass);

	while(t->node != NULL){
		
		if(strcmp(user , t->user_name) == 0){
			strcpy(id, t-> gl_id);
		}
		t = t->node ; 
	}

	
	struct staff_d{
		char status[5] ;
		char name[21] ;
		char lname[21] ;
		char id[12] ;
		char date[12] ;
		char tel[12] ;
		char email[101] ;
		char gl_id[15] ;
		
		struct staff_d *node ;
	};
	

	struct staff_d  *l , *g;
	l = malloc(sizeof(struct staff_d));

	struct staff_d *f , *k ;
	f =  l ;
	k = f ;

	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	rewind(staff_data);
	fflush(staff_data);


	while(1 > 0){
	
		g = malloc(sizeof(struct staff_d));

		if(feof(staff_pass) != 0 ){
			break;
		}

		fscanf(staff_pass , "%s%s%s%s%s%s%s%s" , l->status , l->name ,  l->lname , l->id , l->date , l->tel , l->email , l->gl_id );
		l->node = g ;
		l = g ;
		g->node = NULL;
	}
	
	fclose(staff_data);
	


	staff_data = fopen("STAFF_DATA.txt" , "w");
	rewind(staff_data);
	fflush(staff_data);


	while(k->node != NULL){


		if(strcmp(id , k->gl_id) == 0){
			strcpy(k->tel , new_tel);
		}
		
		if(strcmp(k->status , "ACT") == 0 || strcmp(k->status , "DCT") == 0 ){
		
			fprintf(staff_data ,"%-5s" , k->status );
			fprintf(staff_data ,"%-20s" , k->name );
			fprintf(staff_data ,"%-20s" , k->lname );
			fprintf(staff_data ,"%-10s" , k->id );
			fprintf(staff_data ,"%-10s" , k->date );
			fprintf(staff_data ,"%-15s" , k->tel );
			fprintf(staff_data ,"%-25s" , k->email);
			fprintf(staff_data ,"%-15s" , k->gl_id);
			fprintf(staff_data ,"\n");

		}

		k = k->node ; 
	}

	fclose(staff_data);

}


void staff_logs(void){

	int page ;


	printf("\nStaff Logs\n\n");

	printf("1 - Active Members\n");
	printf("2 - Fired Members\n");
	printf("3 - DeActive Members\n");
	printf("4 - Non-Available Book\n");
	printf("5 - Available Book\n");
	printf("6 - Members Book History\n");
	printf("7 - Members Sign Up History\n");
	printf("8 - Refresh Non-Available Book\n");
	printf("9 - Return\n\n");

	printf("Enter Your Choice\n");
	scanf("%d" , &page);
	
	system("clear");
	
	switch(page){
		case 1:
			active_m();
			staff_logs();
		
		case 2:
			fired_m();
			staff_logs();

		case 3:
			deactive_m();
			staff_logs();

		case 4:
			nva_book_list();
			staff_logs();

		case 5:
			ava_book_list();
			staff_logs();
		
		case 6:
		case 7:
		case 8:
		
		case 9:
			system("clear");
			Staff_page();
		
		default :
			printf("enter a number 1 to 9");
			exit(0);
	}

}


void active_m(void){


	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *m_data ;
	m_data = fopen("CUSTOMER_DATA.txt" , "r");
	rewind(m_data);
	fflush(m_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(m_data , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email );
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(m_data) != 0 ){
			break;
		}

	}

	fclose(m_data);
	
	
	while(t != NULL){
		
		if(strcmp(t->status , "ACT") == 0){
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->lname );
			printf("%-10s" , t->id );
			printf("%-10s" , t->hire_date );
			printf("%-15s" , t->tel );
			printf("%-25s" , t->email);
			printf("\n");

		}
		t = t->node;
	}
}
void fired_m(void){

	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *m_data ;
	m_data = fopen("CUSTOMER_DATA.txt" , "r");
	rewind(m_data);
	fflush(m_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(m_data , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email );
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(m_data) != 0 ){
			break;
		}

	}

	fclose(m_data);
	
	
	while(t != NULL){
		
		if(strcmp(t->status , "FCT") == 0){
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->lname );
			printf("%-10s" , t->id );
			printf("%-10s" , t->hire_date );
			printf("%-15s" , t->tel );
			printf("%-25s" , t->email);
			printf("\n");

		}
		t = t->node;
	}


}
void deactive_m(void){


	struct cu_data{
		
		char status[4] ;
		char name[21] ;
		char lname[21] ;
		char hire_date[11] ;
		char id[12] ;
		char tel[13] ;
		char email[101] ;
		struct cu_data *node ;
	
	};

	struct cu_data  *q , *d;
	q = malloc(sizeof(struct cu_data));

	struct cu_data *s , *t ;
	s =  q ;
	t = s ;

	FILE *m_data ;
	m_data = fopen("CUSTOMER_DATA.txt" , "r");
	rewind(m_data);
	fflush(m_data);

	while(1 > 0){
	
		d = malloc(sizeof(struct cu_data));

		fscanf(m_data , "%s%s%s%s%s%s%s" , q->status , q->name ,  q->lname , q->id , q->hire_date , q->tel , q->email );
		q->node = d ;
		q = d ;
		d->node = NULL;

		if(feof(m_data) != 0 ){
			break;
		}

	}

	fclose(m_data);
	
	
	while(t != NULL){
		
			if(strcmp(t->status , "DCT") == 0){
			printf("%-5s" , t->status );
			printf("%-20s" , t->name );
			printf("%-20s" , t->lname );
			printf("%-10s" , t->id );
			printf("%-10s" , t->hire_date );
			printf("%-15s" , t->tel );
			printf("%-25s" , t->email);
			printf("\n");

		}
		t = t->node;
	}


}



// customer ------------------------------------------------------------------------


void customer_check(void){

	struct users{
		char status[4] ;
		char user_name[21] ;
		char password[21] ;
		char id[15] ;
		struct users *node ;
	};


	char user[21] , pass[21];

	printf("Enter User Name : \n");
	scanf("%s" , user);

	printf("Enter Password : \n");
	scanf("%s" , pass);

	struct users  *q , *d;
	q = malloc(sizeof(struct users));

	struct users *s , *t ;
	s =  q ;
	t = s ;

	FILE *cu_pass ;
	cu_pass = fopen("CUSTOMER_PASS.txt" , "r");
	rewind(cu_pass);
	fflush(cu_pass);

	while(1 > 0){
	
		d = malloc(sizeof(struct users));
		
		if(feof(cu_pass) != 0 ){
			break;
		}

		fscanf(cu_pass , "%s%s%s%s" , q->status , q->user_name , q->password , q->id);
		q->node = d ;
		q = d ;
		d->node = NULL;

	}

	fclose(cu_pass);

	
	while(t != NULL){
	
		if(strcmp(t->status , "ACT") == 0 && strcmp(t->user_name , user) == 0 && strcmp(t->password , pass) == 0){
			system("clear");
			active_user(user , pass);
			customer_page();
		}

		t = t->node ;
	}

	system("clear");

}


void customer_page(void){

	int page ;


	printf("\nMEMBERS MENU\n\n");
	

	printf("1 - Rent Book\n");
	printf("2 - ------\n");
	printf("3 - ------");
	printf("4 - Available Book\n");
	printf("5 - Setting\n");
	printf("6 - Return\n\n");


	printf("Enter Yout Choice\n");
	scanf("%d" , &page);
	

	switch(page){

		case 1: 
		case 2: 
		case 3: 
		case 4: 
		case 5: 
		case 6: 
			system("clear");
			menu();

		default : 
			printf("enter number 1 to 6");
			exit(0);

	}

}











































































//----------------------------------------------------------------------------------
void timer(long long int failed_time){

	long long int new_time ;
	do{
		new_time = time(NULL);
	}while(new_time - failed_time != 10);
}


void active_user(char user[21] , char pass[21] ){

	FILE *current ;
	current = fopen("cr_user.txt" , "w");

	fprintf(current , "%s\t%s" , user , pass);
	
	fclose(current);
}

void timer_sec(int sec){
	
	long long int cr_time = time(NULL) , new_time;

	do{
		new_time = time(NULL);
	}while(new_time - cr_time != sec);

}



