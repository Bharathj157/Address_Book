#include<stdio.h>
#include<string.h>
#include "address_book.h"
/*Name:Bharath J
Date:
Description:
Input:
Output:*/

int search_name(AddressBook *book,char *name)
{
    char buffer[100],check_name[100];
    fseek(book->fptr,4, SEEK_SET);
	    while(1)
	    {
                fgets(buffer, 100,book->fptr);

		if (feof(book->fptr))
                break;

		sscanf(buffer, "%[^,]",check_name);
		
	    	if(strcasecmp(check_name,name)==0)
	   	{
		    printf("---------------------------------------------\n");
		    printf("Name already exits plzz provide different name\n");
		    printf("---------------------------------------------\n");
	    	    return 1;    
	    	}
	    }
	    return 0;
}

int add_contacts(AddressBook *book,ContactInfo *contact)
{
    book->fptr = fopen("address_book.csv", "r+");
    if (book->fptr == NULL)
    {
        perror("fopen");
        printf("Unable to open address_book.csv file, plzz check the file\n");
        return 1;
    }

    if(fgetc(book->fptr)<0)
	fprintf(book->fptr,"#%d# \n",0);

    fseek(book->fptr, 1, SEEK_SET);
    char buffer[50];
    fscanf(book->fptr, "%[^\n]",buffer);
    getc(book->fptr);
    sscanf(buffer, "%d", &book->total_contacts);
    fseek(book->fptr,0,SEEK_END);

  // printf("%d\n",book->total_contacts);

   char check;
   int count;
   while(1)
   {

    while(1)
    {
        printf("Enter the name: ");
        scanf(" %[^\n]", contact->name);

	if(search_name(book,contact->name))
	    continue;
        if (strchr(contact->name, ',') != NULL)
        {
            printf("Do not include character ',' in the name as we are storing in .csv file ,plzz re-enter name\n");
        }
	else
	{
	  break;
	}
    }

    while(1)
    {
	printf("Enter the contact number: ");
	scanf(" %s",contact->phone_number);
        
	int count = 0;
            for (int i = 0; i < 10; i++){
                if (contact->phone_number[i] >= '0' && contact->phone_number[i] <= '9')
                    count++;
	    }

            if (count != 10)
            {
                printf("10 Digits Not Entered properly , plzz re-enter the number\n");   
            }
	    else
	    {
	         break;
	    }
    }
    while(1)
    {
	printf("Enter the E-mail id: ");
	scanf(" %s",contact->email_address);

	if(strchr(contact->email_address,'@')!=NULL)
	{
	    int l=strlen(contact->email_address);
	    if(contact->email_address[l-1]=='m' && contact->email_address[l-2]=='o' && contact->email_address[l-3]=='c' && contact->email_address[l-4]=='.')
            {
		break;
	    }
	    else
	    {
	       printf("Email Invalid: Please enter in format username@domain_name \nAllowed Characters: [a-zA-Z0-9_.+-] + @[a-zA-Z0-9-] + .[a-zA-Z0-9]\n");
	    }
	}

    }

    while(1)
    {
        printf("Enter the address: ");
        scanf(" %[^\n]", contact->address);

        if (strchr(contact->address, ',') != NULL)
        {
            printf("Do not include character ',' in the name as we are storing in .csv file ,plzz re-enter name\n");
        }
	else
	{
	  break;
	}
    }

    printf("Confirmation to add details to address_book press y/Y else press n/N \n");
    scanf(" %c",&check);

    if(check=='y' || check=='Y')
    {
       fprintf(book->fptr,"%s,%s,%s,%s\n",contact->name,contact->phone_number,contact->email_address,contact->address);
       book->total_contacts++;  
           printf("----------------------------\n");
	    printf("Add contact is Successful\n"); 
	    printf("----------------------------\n"); 
    }

    printf("do yo want to add one more contact press y/Y else n/N \n");
    scanf(" %c",&check);

    if(check=='n'||check=='N')
    {
        fseek(book->fptr, 0, SEEK_SET);
        fprintf(book->fptr,"#%d#\n",book->total_contacts);	
     
	break;
    }

   }
   fclose(book->fptr);
}
