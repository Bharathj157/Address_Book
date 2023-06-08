#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address_book.h"

int list_contacts(AddressBook *book)
{

    int i=1;
    book->fptr=fopen("address_book.csv", "r+");
    if (book->fptr == NULL)
    {
	perror("fopen");
	printf("Unable to open address_book.csv file, plzz check the file\n");
	return 1;
    }

    char buffer[100];

                fgets(buffer,100,book->fptr);
   //  fseek(book->fptr,4,SEEK_SET);
            while(1)
	    {
                fgets(buffer,100,book->fptr);
                
		if (feof(book->fptr))
                break;

	        print_details(buffer,i);
	        i++;	
	    }

	    fclose(book->fptr);
}

int main()
{
    ContactInfo contacts;
    AddressBook book;
    int ret,option;
    while (1)
    {
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Exit\n");
	printf("Please select an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            add_contacts(&book,&contacts);
            break;
	case 2:
	   ret=search_contact(&book,&contacts);
	   if(ret==-1)
	   {
	       printf("---------------------------\n");
	       printf("Contact Not Found\n");
	       printf("---------------------------\n");
	   }
	   break;
	case 3:
	   edit_contact(&book,&contacts);
	   break;
	case 4:
	   delete_contact(&book,&contacts);
	   break;
	case 5:
            list_contacts(&book);
	    break;    
	case 6:
	     return 0;
	}
    }
}
