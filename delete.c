#include <stdio.h>
#include "address_book.h"
#include <string.h>
#include<stdlib.h>

int delete_contact(AddressBook *book,ContactInfo *contacts)
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
     printf("Delete Menu:\n1) Search by Name\n2) Search by Mobile Number\n3) Search by Email ID\n4) Search by Edit Location\n5) Exit\n6) Previous Menu\nEnter Choice: ");
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
	       
	          printf("Enter the contact number to delete\n");
		  scanf("%d",&con_num);


	          fseek(book->fptr,0, SEEK_SET);
	        //  fseek(book->fptr,4, SEEK_SET);
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
		   
		   while(fgets(buffer,100,book->fptr)>0)
		   {
                      fputs(buffer,temp_fptr);   
		   }

		   book->total_contacts--;
		   rewind(temp_fptr);
                   fprintf(temp_fptr,"#%d#",book->total_contacts);

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
	          printf("Enter the contact number to delete\n");
		  scanf("%d",&con_num);


	          fseek(book->fptr,0, SEEK_SET);
	          fseek(temp_fptr,0, SEEK_SET);
                  fgets(buffer,100,book->fptr);
                  fgets(buffer,100,temp_fptr);

		  printf("%d \n",book->contact_count[con_num]);
		  while(--book->contact_count[con_num])
		  {
		     fgets(buffer,100,book->fptr);
		     fputs(buffer,temp_fptr); 
		  }

		   fgets(buffer,100,book->fptr);
		   

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }

		   book->total_contacts--;
		   rewind(temp_fptr);
                   fprintf(temp_fptr,"#%d#",book->total_contacts);

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
	          printf("Enter the contact order number to delete\n");
		  scanf("%d",&con_num);


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
		   

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }

		   book->total_contacts--;
		   rewind(temp_fptr);
                   fprintf(temp_fptr,"#%d#",book->total_contacts);

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
	          printf("Enter the contact order number to delete\n");
		  scanf("%d",&con_num);


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
		   

		   while(fgets(buffer,100,book->fptr)>0)
		   {
		       if(feof(book->fptr))
			   break;
                      fputs(buffer,temp_fptr);   
		   }

		   book->total_contacts--;
		   rewind(temp_fptr);
                   fprintf(temp_fptr,"#%d#\n",book->total_contacts);

		   fclose(book->fptr);
		   fclose(temp_fptr);
	   }
	   break;
     }

     printf("--------------------------------------\n");
     printf("Deleting Contact is Successfull\n");
     printf("--------------------------------------\n");
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
