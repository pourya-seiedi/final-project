#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





// function prototype -------------------
void menu(void);
void ADMIN(void);
void Admin_page(void);
void timer(long long int failed_time);
void Add_Staff(void);
void Staff_list(void);
void delete_staff(void);
//void staff_check(void);
void Staff_page(void);
void add_customer(void);
void customer_list(void);
void add_book(void);
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
			//staff_check();
			Staff_page();
		
		case 3 :
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
			// logs - PASS
			break;

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
	
	
	char name[20] , lname[20] , hire_date[10] , id[10];
	char tel[12] , email[100] , user_name[20] ;
	char password[20] ;

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
	fprintf(staff_data , "%-20s" , name);
	fprintf(staff_data , "%-20s" , lname);
	fprintf(staff_data , "%-10s" , id);

	// hire date - PASS
	fprintf(staff_data , "%-10s" , "----" );
	//---------
	
	fprintf(staff_data , "%-15s" , tel );
	fprintf(staff_data , "%-25s" , email);
	fprintf(staff_data , "\n");


	fclose(staff_data);


	user_pass = fopen("USER_PASS.txt" , "a");
	
	fprintf(user_pass , "%-5s%-20s%-20s\n" , "ACT" , user_name , password);
	
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

	struct cu_data *start , *end , *add;
	start = malloc(sizeof(struct cu_data));
	end = malloc(sizeof(struct cu_data));
	add = malloc(sizeof(struct cu_data));


	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");


	while(1 > 0){
		
		//fscanf(staff_data , "" , );
	}
}



//----------------------------------------------------------------------------------



// STAFF----------------------------------------------------------------------------

//void staff_check(void){}
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
		case 5 :
			add_book();
			Staff_page();
			
		case 6 :
		case 7 :

		case 8 :
			system("clear");
			menu();

		default :
			printf("Please enter Number 1 to 8!!!");
			exit(0);
	}
}


void add_customer(void){

	char name[20] , lname[20] , sub_date[10] , id[10];
	char tel[12] , email[100] , user_name[20] ;
	char password[20] ;

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
	fprintf(customer_data , "\n");


	fclose(customer_data);


	user_pass = fopen("USER_PASS.txt" , "a");
	
	fprintf(user_pass , "%-5s%-20s%-20s\n" , "ACT" , user_name , password);
	
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
	char status[3];
	char name[20] , publisher[20] , writer[20] ;
	char publish_date[10] ;

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


//----------------------------------------------------------------------------------
void timer(long long int failed_time){

	long long int new_time ;
	do{
		new_time = time(NULL);
	}while(new_time - failed_time != 10);
}









