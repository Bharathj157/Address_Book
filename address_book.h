#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#define DEFAULT_FILE				"address_book.csv"

/* Length of a contact name  */
#define NAME_LEN					32
/* Length of a phone number */
#define NUMBER_LEN					32
/* Length of an email address */
#define EMAIL_ID_LEN				32

/* Maximum number of Names per contact, Just for easy design */
#define NAME_COUNT					1
/* Maximum number of phones per contact */
#define PHONE_NUMBER_COUNT			5
/* Maximum number of email addresses per contact */
#define EMAIL_ID_COUNT				5

#define FIELD_DELIMITER				','
#define NEXT_ENTRY					'\n'

typedef struct
{
	char name[NAME_LEN];
	char phone_number[NUMBER_LEN];
	char email_address[EMAIL_ID_LEN];
	char address[NAME_LEN];
	
} ContactInfo;

typedef struct
{
	FILE *fptr;
	ContactInfo *list;
	int total_contacts;
	char contact_count[100];
	int con_count;	
} AddressBook;

int delete_contact(AddressBook *book,ContactInfo *contacts);
int list_contacts(AddressBook *book);
int search_name(AddressBook *book,char *name);
int add_contacts(AddressBook *book,ContactInfo *contact);
int edit_contact(AddressBook *book,ContactInfo *contacts);
void print_details(char *buffer,int j);
int search_in_file(AddressBook* book,char *name,int op);
int search_contact(AddressBook *book,ContactInfo *contact);


#endif
