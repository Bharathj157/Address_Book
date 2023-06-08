#define _GNU_SOURCE
#include<string.h>
#include<stdio.h>
#include"address_book.h"

void print_details(char *buffer,int j)
{
    char delim[]=",";
    char *token;
    int i=1;
	    	    token=strtok(buffer,delim);
		    while(token!=NULL){
			switch (i)
			{
			    case 1:
				printf("--------------------------------\n");
				printf("Contact Detail - %d \n",j);
				printf("Name: ");
				break;
			    case 2:
				printf("Mobile No: ");
				break;
			    case 3:
				printf("Email ID: ");
				break;
			    case 4:
				printf("Location: ");
			}
			printf("%s \n",token);
			token=strtok(NULL,delim);
			i++;
		    }
		printf("--------------------------------\n");
		    
}

int search_in_file(AddressBook* book,char *name,int op)
{

    char buffer[100],check_name[50],temp[100];
    char delim[] = ",";
    char *token;
    int check=0,i=1;
    book->con_count=1;

    switch (op)
    {
	case 1:
            fgets(buffer, 100,book->fptr);
	    while(1)
	    {

                fgets(buffer, 100,book->fptr);

		if (feof(book->fptr))
                break;

		sscanf(buffer, "%[^,]",check_name);
		
	    	if(strcasestr(check_name,name)!=NULL)
	   	{
		    check=1;
	    	    print_details(buffer,book->con_count);
		    book->contact_count[book->con_count]=i;
		    book->con_count++;
		    
	    	}
		i++;
	    }
	    if(check==0)
		return -1;

            break;
       case 2:
	       
            fgets(buffer, 100,book->fptr);
	    while(1)
	    {
                fgets(buffer, 100,book->fptr);
		if (feof(book->fptr))
                break;

		strcpy(temp,buffer);
		token=strtok(buffer,delim);
        	token=strtok(NULL,delim);

	    	if(strstr(token,name)!=NULL)
	   	{
		    check=1;
	    	    print_details(temp,book->con_count);
		    book->contact_count[book->con_count]=i;
		    book->con_count++;
	    	}
		i++;
	    }
	    if(check==0)
		return -1;

	    break;
       case 3:
            fgets(buffer, 100,book->fptr); 
	    while(1)
	    {
                fgets(buffer, 100,book->fptr);
                
		if (feof(book->fptr))
                break;

		strcpy(temp,buffer);

		token=strtok(buffer,delim);
		token=strtok(NULL,delim);
		token=strtok(NULL,delim);

	    	if(strstr(token,name)!=NULL)
	   	{
		    check=1;
	    	    print_details(temp,book->con_count);
		    book->contact_count[book->con_count]=i;
		    book->con_count++;
	    	}
		i++;
	    }

	    if(check==0)
		return -1;
	    break;

       case 4:
                fgets(buffer, 100,book->fptr);
	    while(1)
	    {
                fgets(buffer, 100,book->fptr);
                
		if (feof(book->fptr))
                break;

		strcpy(temp,buffer);

		token=strtok(buffer,delim);
		token=strtok(NULL,delim);
		token=strtok(NULL,delim);
		token=strtok(NULL,delim);

	    	if(strstr(token,name)!=NULL)
	   	{
		    check=1;
	    	    print_details(temp,book->con_count);
		    book->contact_count[book->con_count]=i;
		    book->con_count++;
	    	}
		i++;
	    }

	    if(check==0)
		return -1;
	    break;  	    
    }
}



int search_contact(AddressBook *book,ContactInfo *contact)
{
    int op;
    char details[30];
    book->fptr = fopen("address_book.csv", "r+");
    if (book->fptr == NULL)
    {
	perror("fopen");
	printf("Unable to open address_book.csv file, plzz check the file\n");
	return 1;
    }

    printf("---------------------------------------------\n");
    printf("Search Menu:\n1.Search by Name\n2.Search by Mobile Number\n3.Search by Email ID\n4.Search by Location\n5.Exit from current menu \nEnter Choice: ");
    scanf("%d",&op);
    while (getchar() != '\n');

    switch (op)
    {
	case 1:
	   
	    printf("Enter Name to search: ");
	    scanf("%[^\n]", details);
	    while (getchar() != '\n');

	    search_in_file(book, details, 1);
	    break;

	case 2:
	    
	    printf("Enter number to search: ");
	    scanf("%[^\n]", details);
	    while (getchar() != '\n');

	    search_in_file(book, details, 2);
	    break;

	case 3:
	    printf("Enter mail id to search: ");
	    scanf("%[^\n]", details);
	    while (getchar() != '\n');

	    search_in_file(book, details, 3);
	    break;
	case 4:
	    printf("Enter location to search: ");
	    scanf("%[^\n]", details);
	    while (getchar() != '\n');

	    search_in_file(book, details, 4);
	    break;
    }
    fclose(book->fptr);
}

