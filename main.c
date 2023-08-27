/*
===================================================================================================
 * Auther : Salma Al-said Mohammed
 * Object : Clinic mangement system
 * date : 26/8/2023
 * main.c
===================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_Types.h"


typedef struct Node Node ;	
		   
	struct Node
	{
		char Name[20];
		int Age;
		char Gender;
		int ID ;
		int date ;
		Node *prev;
		Node *next;
		
	};
	
	Node *pfirst=NULL;    // points to first node
	Node *plast=NULL;    // points to last node
	u32 arr[5]={0};
	static u8 slot ;
	

	// function to create node in heep
	 Node* create(char name[] , int age , char gender , int id )
	{
	  Node*new = (Node*)malloc(sizeof(Node));
	  
	  strcpy(new->Name,name);
	  new->Age=age;
	  new->Gender=gender;
	  new->ID=id;
	  new->date=0;
	  
	  new->prev=NULL;
	  new->next=NULL;
	  return new ;         // return address of node
	}
	
	
	// function to add node in linked list
	void add(Node*node)
	{
		if(pfirst==NULL)
		{
			pfirst=plast=node;
		}
		else
		{
			plast->next=node;
            node->prev=plast;
            plast=node;			
		}
		
	}
	
	
	// function to search if id of patient exist in linked list or not
	Node *search(u32 id)
	{
		Node*psearch = pfirst;
		while(psearch!=NULL)
		{
			if(psearch->ID==id)
			{
				return psearch;
			}
			else
			{
				psearch=psearch->next;
			}
		}
		return NULL ;
	}
	
	

	
	
	// function to Reserve a slot with the doctor
	void reserve (Node*node)
	{
		
		printf("Avilable appointments : \n");
		if (arr[0]==0)
			printf("1 -> 2pm to 2:30pm \n");
		else 
			printf("1- booked up\n");
	    if(arr[1]==0)
		    printf("2 -> 2:30pm to 3pm\n");
		else
			printf("2- booked up\n");
		if(arr[2]==0)
			printf("3 -> 3pm to 3:30pm\n");
		else
			printf("3- booked up\n");
		if(arr[3]==0)
			printf("4 -> 4pm to 4:30pm\n");
		else
			printf("4- pm- booked up\n");
		if(arr[4]==0)
			printf("5 -> 4:30pm to 5pm\n");
		else
			printf("5- booked up\n");
		
		printf("enter the appropriate date for you : ");
		scanf("%d",&slot);
		
		if((slot<=5)&&(slot>=1))
		{
			arr[slot-1]=slot;  // stor nubmer of slot in array
			node->date=slot;
			printf("Reservation successfully done ");
			printf("\n*******************************************************************\n");
		}
		else 
		{
			printf("invalid number ");
			printf("\n*******************************************************************\n");
		}
		
		
	}
	
	
	// function to cancel Reservation
	void cancel_reservation(u8 id)
	{
		for(int i=0 ; i<5 ; i++)
		{
			if(arr[i]==slot)
			{
				arr[i]=0;
				printf("Reservation cancelled");
				printf("\n*******************************************************************\n");
			}
		}
	}
	
	
	//function to edit patient data added
	void edit_data(Node*node ,u8 *name,u8 age,u8 gender)
	{
		strcpy(node->Name,name);
		node->Age=age;
		node->Gender=gender;
	}
	
	
	
	
	//function to display patient data
	void display_patient(Node*node)
	{
		//Node *patient=pfirst;
		
				printf("ID : %d\n",node->ID);
				printf("Name : %s\n",node->Name);
				printf("Age : %d\n",node->Age);
				
				if (node->Gender=='f')
					printf("Gender : female \n");
				else if (node->Gender=='m')
					printf("Gender : male \n");
				
				if (node->date==1)
					printf("appointment : 2pm to 2:30pm\n");
				else if (node->date==2)
					printf("appointment : 2:30pm to 3pm\n");
				else if (node->date==3)
					printf("appointment : 3pm to 3:30pm\n");
				else if (node->date==4)
					printf("appointment : 4pm to 4:30pm\n");
				else if (node->date==5)
					printf("appointment : 4:30pm to 5pm\n");
				else 
					printf("No booked yet\n");
				
						
		
	}
	
	
	// function to display all patients data
	void display_all_patient(void)
	{
		Node*patient=pfirst;
		if(patient==NULL)
		{
			printf("NO Patient Yet\n");
		}
		else
		{
			u8 c=1;
			while(patient!=NULL)
			{
				printf("patient %d\n",c);
				printf("ID : %d\n",patient->ID);
				printf("Name : %s\n",patient->Name);
				printf("Age : %d\n",patient->Age);
				
				if (patient->Gender=='f')
					printf("Gender : female \n");
				else if (patient->Gender=='m')
					printf("Gender : male \n");
				
				if (patient->date==1)
					printf("appointment : 2pm to 2:30pm\n");
				else if (patient->date==2)
					printf("appointment : 2:30pm to 3pm\n");
				else if (patient->date==3)
					printf("appointment : 3pm to 3:30pm\n");
				else if (patient->date==4)
					printf("appointment : 4pm to 4:30pm\n");
				else if (patient->date==5)
					printf("appointment : 4:30pm to 5pm\n");
				else 
					printf("No booked yet\n");
				printf("-----------\n");
			
				patient=patient->next;
				c++;
				
			}
		}
	}
	
	
	//function to display available reservation for users
	void display_Reservations(void)
	{
		printf("Avilable appointments :\n");
		if(arr[0]==0)
			printf("- 2pm to 2:30pm\n");
		if (arr[1]==0)
			printf("- 2:30pm to 3pm\n");
		if (arr[2]==0)
			printf("- 3pm to 3:30pm\n");
		if (arr[3]==0)
			printf("- 4pm to 4:30pm\n");
		if (arr[4]==0)
			printf("- 4:30pm to 5pm\n");
	}
	
	
	
	
void main (void)
{
	u32  mode ,choice, password  ;
	u8  i ,flag =0 ;
	u8  ExitFlag = 0, Exit=0 , exit=0;
	char name[20] , gender ;
	int age ,id ;
	
	
	
	
	printf("\n|-----------------------------------------------------------------|\n");
	printf("|-------------------- Welcome to our clinic ----------------------|\n");
	printf("|-----------------------------------------------------------------|\n\n");
	
	
	// asks the user to choose between admin mode and user mode
	while(ExitFlag == 0)
 {	
	printf("\n*******************************************************************\n");
	printf("\n- for Admin mode enter 1 \n");
	printf("\n- for User mode enter 2 \n");
	printf("\n- for Exist enter 0  \n");
	printf("\n*******************************************************************\n");
	
	scanf("%d",&mode);
	
	switch(mode)
  {
		case 1: 
				//check the password
		          printf("Please Enter Password: ");
		           for (i = 0; i < 3; i++)
				   {
					   scanf ("%d",&password);
					   if(password == 1234)
					   {
						   printf("correct password");
						   flag = 1;
						   break;
					   }
					   
					   else if (i<2)
					   {
						   printf("Incorrect password , Try again: ");
						  
				       }
				    }   
	
	
	if (flag == 0)
	{
		printf("Incorrect password for 3 times, No more tries");
		ExitFlag=1;
	}

			

           if (password==1234)
		{
			while( Exit == 0)
		  {
			printf("\n********************** \"Welcome to Admin mode\" ****************************\n\n");
			printf("- Enter 1 to add new patient  \n");
			printf("- Enter 2 to reserve date to patient  \n");
			printf("- Enter 3 to cancel patient reservation  \n");
			printf("- Enter 4 to edit patient data  \n");
			printf("- Enter 5 to display all patient data  \n");
			printf("- Enter 0 to Back to the main menu : \n");
			printf("\n*******************************************************************\n");
			scanf("%d",&choice);
			
			
			if(choice==1)
			{
				
				printf("Enter patient ID : ");
				scanf("%d",&id);
				Node*Search=search(id);   
				if (Search!=NULL)          //check if patient has been added before
				{
					printf("ID Already exist \n");
					printf("\n*******************************************************************\n");
					
							
				}
				else
				{
					printf("Enter patient's Name : ");
					fflush(stdin);
					fflush(stdout);
					scanf("\n%[^\n]s",name);
					
					printf("Enter patient's Age : ");
					fflush(stdin);
					fflush(stdout);
					scanf("%d",&age);
					
					printf("Enter \'M\' if patient is Male or \'F\' if patient is Famale  : ");
					fflush(stdin);
					fflush(stdout);
					scanf("%c",&gender);
					
					add(create(name,age,gender,id));
					printf("patient successfully registered ");
					printf("\n*******************************************************************\n");
					
					
				}
			}
			else if (choice==2)
				{
				printf("please enter patient's ID : ");
				scanf("%d",&id);
				Node*S=search(id);
				    if(S==NULL)
						{
							printf("ID doesn't exist \n");
							printf("\n*******************************************************************\n");	
						}
					else
						{
							reserve(S);
						}
				     
				}
				else if (choice==3)
				{
					printf("please enter patient's ID : ");
					scanf("%d",&id);
					Node*S=search(id);
					if(S!=NULL)
					{
						cancel_reservation(id);
					}
					else
					{
						printf("ID doesn't exist \n");
						printf("\n*******************************************************************\n");
					}
					
				}
				else if (choice==4)
				{
					printf("please enter patient's ID : ");
					scanf("%d",&id);
					Node*S=search(id);
					if(S!=NULL)
					{
						printf("Enter patient's Name : ");
						fflush(stdin);
						fflush(stdout);
						scanf("\n%[^\n]%*c",&name);
					
						printf("Enter patient's Age : ");
						fflush(stdin);
						fflush(stdout);
						scanf("%d",&age);
					
						printf("Enter \'M\' if patient is Male or \'F\' if patient is Famale  : ");
						fflush(stdin);
						fflush(stdout);
						scanf("%c",&gender);
						
						edit_data(S,name,age,gender);
						printf("Patient data successfully modified ");
						printf("\n*******************************************************************\n");
					}
					else 
					{
						printf("ID doesn't exist \n");
						printf("*******************************************************************\n");
					}
				}
				else if(choice==5)
				{
					display_all_patient();
				}
				else if (choice==0)
				{
					Exit = 1 ;
				}
 
				
		  }
			
			
			
		}
		break;
		  
		case 2 :
		
		while(exit==0)
		{
			printf("\n********************** \"Welcome to User mode\" ****************************\n\n");
			printf("- Enter 1 to View patient record  \n");
			printf("- Enter 2 to View today's reservations  \n");
			printf("- Enter 0 Back to the main menu  \n");
			printf("\n*******************************************************************\n");
			scanf("%d",&choice);
			
			if (choice==1)
			{
				u8 id;
				printf("please enter patient's ID : ");
				scanf("%d",&id);
				Node*S=search(id);
				if (S!=NULL)
				{
					display_patient(S);
				}
				else
				{
					printf("ID doesn't exist \n");
				}
				
				
			}
			else if (choice==2)
			{
				display_Reservations();
			}
			else if (choice==0)
			{
				exit=1;
			}
		}
		break;
		
		case 0 :
			ExitFlag=1;
			break;
			
		default:
			printf("Invalid Choice please try again\n");
			break;
		
  }

 }	
		

}




	
	
	
	
	
	
	
	

	
	
	
	
	



		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	