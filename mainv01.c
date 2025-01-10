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
int  Staff_list(void);
//---------------------------------------








// global variable ----------------------


// admin
char admin_user[] = "ADMIN" , admin_password[] = "1234567890" , attempt = 0;



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
		
		case 2 :
			system("clear");
		
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
	

	while(attempt < 3){
		printf("Enter User Name : \n");
		scanf("%s" , user);
		printf("Enter Password : \n");
		scanf("%s" , password);

		if(strcmp(admin_user , user) == 0 && strcmp(admin_password , password) == 0 ){
			attempt = 0 ;
			Admin_page();
		}	
		else{
			system("clear");
			printf("Try Again!!!\n\n");
			attempt++;
			ADMIN();
		}
	}
	if( attempt >= 3){
		system("clear");
		printf("Login Failed , Attempt Another Time!!!!\n");

		timer(time(NULL));
		attempt = 0 ;

		menu();
	}
}

void Admin_page(void){
	
	int  page ; 

	system("clear");
	
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
			// delet_staf - PASS
			break;
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
	fprintf(staff_data , "%-50s" , email);
	fprintf(staff_data , "\n");

	// ???? 
	//fprintf(staff_data , "%s" , user_name);
	//fprintf(staff_data , "%s" , password);

	fclose(staff_data);

	user_pass = fopen("USER_PASS.txt" , "a");
	fprintf(user_pass , "%-5s%-20s%-20s\n" , "ACT" , user_name , password);
	fclose(user_pass);

}

int Staff_list(void){
	

	system("clear");
	char input , track = 0;
	FILE *staff_data ;
	staff_data = fopen("STAFF_DATA.txt" , "r");
	
	if(staff_data == NULL){
		printf("UNABLE TO LOACATE THE FILE!!!");
		return 0;
	}

	///// staff list
	do{
		input = fgetc(staff_data);
		printf("%c" , input);
	}while(1 > 0);

	fclose(staff_data);
	return 1;
}


//----------------------------------------------------------------------------------



// STAFF----------------------------------------------------------------------------



void timer(long long int failed_time){

	long long int new_time ;
	do{
		new_time = time(NULL);
	}while(new_time - failed_time != 10);
}









