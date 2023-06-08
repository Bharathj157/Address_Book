#include <stdio.h>
#include "address_book.h"
#include <string.h>
#include<stdlib.h>

int edit_contact(AddressBook *book,ContactInfo *contacts)
{
    int op,ret,con_num;
    char sname[50],buffer[100];
    char delim[]="#";
    char delim2[]=",";
    char *token;
     book->fptr = fopen("address_book.csv", "r+");
     if (book->fptr == NULL)
     {
         perror("fopen");
         printf("Unable to open address_book.csv file, plzz check the file\n");
         return 1;
     }

     FILE *temp_fptr;
     temp_fptr = fopen("temp_book.csv", "w+");
     if (temp_fptr == NULL)
     {
         perror("fopen");
         printf("Unable to open address_book.csv file, plzz check the file\n");
         return 1;
     }
     
      fgets(buffer,100,book->fptr);
      fputs(buffer,temp_fptr);
      token=strtok(buffer,delim);
      book->total_contacts=atoi(token);
   
      printf("%d\n",book->total_contacts);

      fseek(book->fptr,0, SEEK_SET); 

     printf("--------------------------------\n");
     printf("Edit Menu:\n1) Edit Name\n2) Edit Mobile Number\n3) Edit Email ID\n4) Edit Location\n5) Exit\n6) Previous Menu\nEnter Choice: ");
     scanf("%d",&op);   

     switch (op)
     {
       case 1:
	   printf("Enter name to search the contact \n");
	   scanf(" %[^\n]",sname);

	   fseek(book->fptr,0, SEEK_SET);

	   ret=search_in_file(book,sname,op); 
	   if(ret==-1)
	   {
	       printf("--------------------\n");
	       printf("Contact Not Found\n");
	       printf("--------------------\n");
	   }
	   else
	   {
	       
	          printf("Enter the contact number to edit\n");
		  scanf("%d",&con_num);

	          printf("Enter the name to update/edit\n");
		  scanf(" %[^\n]",contacts->name);

	          fseek(book->fptr,0, SEEK_SET);
	        //fseek(book->fptr,4, SEEK_SET);
	          fseek(temp_fptr,0, SEEK_SET);
	       // fseek(temp_fptr,4, SEEK_SET);
		  fgets(buffer,100,book->fptr);
		  fgets(buffer,100,temp_fptr);
		  printf("%d \n",book->contact_count[con_num]);
		  while(--book->contact_count[con_num])
		  {
		     fgets(buffer,100,book->fptr);
		     fputs(buffer,temp_fptr); 
		  }

		   fgets(buffer,100,book->fptr);
		   
		   strtok(buffer,delim2);

		   strcpy(contacts->phone_number,strtok(NULL,delim2));
		   strcpy(contacts->email_address,strtok(NULL,delim2));
		   strcpy(contacts->address,strtok(NULL,delim2));
	           fprintf(temp_fptr,"%s,%s,%s,%s",contacts->name,contacts->phone_number,contacts->email_address,contacts->address);

		   while(fgets(buffer,100,book->fptr)>0)
		   {
                      fputs(buffer,temp_fptr);   
		   }
		   fclose(book->fptr);
		   fclose(temp_fptr);
	   } 
	  break;
       case 2:
	   printf("Enter phone number to search the contact \n");
	   scanf(" %[^\n]",sname);

	   fseek(book->fptr,0, SEEK_SET);

	   ret=search_in_file(book,sname,op); 
	   if(ret==-1)
	   {
	       printf("--------------------\n");
	       printf("Contact Not Found\n");
	       printf("--------------------\n");
	   }
	   else
	   {
	       
	          printf("Enter the contact number to edit\n");
		  scanf("%d",&con_num);

	          printf("Enter the phone number to update/edit\n");
		  scanf(" %[^\n]",contacts->phone_number);

	          fseek(book->fptr,0, SEEK_SET);
	          fseek(book->fptr,4, SEEK_SET);
	          fseek(temp_fptr,0, SEEK_SET);
	          fseek(temp_fptr,4, SEEK_SET);
		  printf("%d \n",book->contact_count[con_num]);
		  while(--book->contact_count[con_num])
		  {
		     fgets(buffer,100,book->fptr);
		     fputs(buffer,temp_fptr); 
		  }

		   fgets(buffer,100,book->fptr);
		   
		   strcpy(contacts->name,strtok(buffer,delim2));
		   strtok(NULL,delim2);
		   strcpy(contacts->email_address,strtok(NULL,delim2));
		   strcpy(contacts->address,strtok(NULL,delim2));
	           fprintf(temp_fptr,"%s,%s,%s,%s",contacts->name,contacts->phone_number,contacts->email_address,contacts->address);

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }
		   fclose(book->fptr);
		   fclose(temp_fptr);
	   }
	  break;
       case 3:
	   printf("Enter mail id  to search the contact \n");
	   scanf(" %[^\n]",sname);

	   fseek(book->fptr,0, SEEK_SET);

	   ret=search_in_file(book,sname,op); 
	   if(ret==-1)
	   {
	       printf("--------------------\n");
	       printf("Contact Not Found\n");
	       printf("--------------------\n");
	   }
	   else
	   {
	          printf("Enter the contact detail to edit\n");
		  scanf("%d",&con_num);

	          printf("Enter the mail id to update/edit\n");
		  scanf(" %[^\n]",contacts->email_address);

	          fseek(book->fptr,0, SEEK_SET);
	         // fseek(book->fptr,4, SEEK_SET);
	          fseek(temp_fptr,0, SEEK_SET);
	        //  fseek(temp_fptr,4, SEEK_SET);
		     fgets(buffer,100,book->fptr);
		     fgets(buffer,100,temp_fptr);

		  printf("%d \n",book->contact_count[con_num]);
		  while(--book->contact_count[con_num])
		  {
		     fgets(buffer,100,book->fptr);
		     fputs(buffer,temp_fptr); 
		  }

		   fgets(buffer,100,book->fptr);
		   
		   strcpy(contacts->name,strtok(buffer,delim2));
		   strcpy(contacts->phone_number,strtok(NULL,delim2));
		   strtok(NULL,delim2);
		   strcpy(contacts->address,strtok(NULL,delim2));
	           fprintf(temp_fptr,"%s,%s,%s,%s",contacts->name,contacts->phone_number,contacts->email_address,contacts->address);

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }
		   fclose(book->fptr);
		   fclose(temp_fptr);
	   }
	   break;
       case 4:
	   printf("Enter address to search the contact \n");
	   scanf(" %[^\n]",sname);

	   fseek(book->fptr,0, SEEK_SET);

	   ret=search_in_file(book,sname,op); 
	   if(ret==-1)
	   {
	       printf("--------------------\n");
	       printf("Contact Not Found\n");
	       printf("--------------------\n");
	   }
	   else
	   {
	          printf("Enter the contact detail to edit\n");
		  scanf("%d",&con_num);

	          printf("Enter the address to update/edit\n");
		  scanf(" %[^\n]",contacts->address);

	          fseek(book->fptr,0, SEEK_SET);
	         // fseek(book->fptr,4, SEEK_SET);
	          fseek(temp_fptr,0, SEEK_SET);
	        //  fseek(temp_fptr,4, SEEK_SET);
		     fgets(buffer,100,book->fptr);
		     fgets(buffer,100,temp_fptr);

		  printf("%d \n",book->contact_count[con_num]);
		  while(--book->contact_count[con_num])
		  {
		     fgets(buffer,100,book->fptr);
		     fputs(buffer,temp_fptr); 
		  }

		   fgets(buffer,100,book->fptr);
		   
		   strcpy(contacts->name,strtok(buffer,delim2));
		   strcpy(contacts->phone_number,strtok(NULL,delim2));
		   strcpy(contacts->email_address,strtok(NULL,delim2));
	           fprintf(temp_fptr,"%s,%s,%s,%s\n",contacts->name,contacts->phone_number,contacts->email_address,contacts->address);

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }
		   fclose(book->fptr);
		   fclose(temp_fptr);
	   }
	   break;
     }
     printf("-----------------------------\n");
     printf("Editing contact is successful\n");
     printf("-----------------------------\n");

     book->fptr=fopen("address_book.csv","w+");
     temp_fptr=fopen("temp_book.csv","r+");

     while(fgets(buffer,100,temp_fptr))
     {
         fputs(buffer,book->fptr);
     }
    // fputs("\n",book->fptr);

     fclose(book->fptr);
     fclose(temp_fptr);
    // remove("temp_book.csv");     
}
