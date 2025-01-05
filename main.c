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
char admin_user[5] = "ADMIN" , admin_password[10] = "1234567890" , attempt = 0  ;
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
			ADMIN();
			system("clear");
		
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
	char user[5] , password[10] ;
	

	while(attempt < 3){
		printf("Enter User Name : \n");
		scanf("%s" , user);
		printf("Enter Password : \n");
		scanf("%s" , password);

		if(strcmp(admin_user , user) == 0 && strcmp(admin_password , password) == 0){
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
//---------------------------------------



void Admin_page(void){}


void timer(long long int failed_time){
	
	long long int new_time ;
	do{
		new_time = time(NULL);
	}while(new_time - failed_time != 10);
}














