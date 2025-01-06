#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// function prototype -------------------
void menu(void);
void ADMIN(void);
void Admin_page(void);
void timer(long long int failed_time);
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

	system("clear");
}
//---------------------------------------



// ADMIN validity------------------------
void ADMIN(void){
	char user[6] , password[11] ;
	

	while(attempt < 3){
		printf("Enter User Name : \n");
		scanf("%s" , user);
		printf("Enter Password : \n");
		scanf("%s" , password);

		if(strcmp(admin_user , user) == 0 && strcmp(admin_password , password) == 0 ){
			
			Admin_page();
			break;
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
//---------------------------------------



void Admin_page(void){
	
	int  page ; 

	system("clear");
	
	printf("ADMIN MENU : \n\n");
	printf("1 - Add Staff\n");
	printf("2 - Staff List\n");
	printf("3 - Delete Staff\n");
	printf("4 - Logs\n");
	printf("5 - Exit\n\n");

	printf("Enter Your Choice : \n");
	scanf("%d" , &page);


	switch(page){
		case 1:
			//staff_add - PASS
			break;

		case 2:
			//staff_list - PASS
			break;

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


void timer(long long int failed_time){

	long long int new_time ;
	do{
		new_time = time(NULL);
	}while(new_time - failed_time != 300);

}











