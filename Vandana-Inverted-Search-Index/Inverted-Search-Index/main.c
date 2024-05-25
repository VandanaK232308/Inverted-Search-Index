/*
NAME : Vandana K
DESCRIPTION : The purpose of storing an index is to optimize speed and performance in finding relevant documents for a search query. Without an index, the search engine would scan every document in the corpus, which would require considerable time and computing power.
PRE-REQUISITE : Hashing
Single linked list
 */

#include "inverted_index.h"

int main (int argc, char* argv [])
{
    if (argc < 2)	//The number of Arguments passed in Command Line shall be at least 2 (including the Executable File Name).
    {
	printf ( "ERROR: Invalid number of Arguments.\n" );
	printf ( "INFO: Usage ./inverted_index <file.txt> <file1.txt> ...\n" );
    }
    else
    {
	command_handler (argv);	//To perform all the Operations regarding the Inverted Search.
    }

    return 0;
}

int command_handler (char* argv [])
{
    file_node_t* files_H = NULL;		//To store the File Names whose Words are present in the Database.
    main_node_t* HT [SIZE] = {NULL};	//To store the Database.
    int ret, option, flag = 0;
    char choice;

    validate_n_store_filenames (&files_H, argv);	//To Validate the File Names passed as CLA and store them in the File List.

    while(1)
    {
	printf ("-----------------------------------------------------------------------\n");
	printf ( "1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. exit\n" );
	printf ( "INPUT: Enter the Operation to be performed: " );
	scanf ("%d", &option);		//Ask the User for Operation to be performed.

	switch (option)
	{
	    case 1:		/* Create Database */
		{
		    if (flag == 0)
		    {
			ret = create_DB (files_H, HT);
			if (ret == SUCCESS)
			{
			    printf ( "INFO: Database Creation Successful.\n" );
			}
			flag = 1;	//To prevent the User from calling the Create Database Operation again.
		    }
		    else
		    {
			printf ( "ERROR: Create Database Operation can only be called once while passing the Command Line Arguments.\n" );
		    }
		}
		break;
	    case 2:		/* Display Database */
		{
		    ret = display_DB (HT);
		    if (ret == FAILURE)
		    {
			printf ( "INFO: The Database is Empty.\n" );
		    }
		}
		break;
	    case 3:		/* Search Database */
		{
		    char word [BUFF_SIZE];
		    printf ( "INPUT: Enter the word to be searched: " );
		    scanf ("%s", word);	//To read the Word to be searched in the Database.

		    ret = search_DB (HT, word);
		    if (ret == SUCCESS)
		    {
			printf ( "INFO: Word Search Successful.\n" );
		    }
		}
		break;
	    case 4:		/* Update Database */
		{
		    if (flag == 0)		//Update Database can be called only after the Database has been created.
		    {
			char f_name [NAMELENGTH];
			printf ( "INPUT: Enter the File Name to be Updated in the Database: " );
			scanf ("%s", f_name);	//To read the File Name to be updated in the Database.

			ret = update_DB (&files_H, HT, f_name);
			if (ret == SUCCESS)
			{
			    printf ( "INFO: Database Update Successful.\n" );
			}
		    }
		    else
		    {
			printf ( "ERROR: Create Database Operation shall be called before trying to call the Update Database Operation.\n" );
		    }
		}
		break;
	    case 5:
		{
		    char f_name [NAMELENGTH];
		    printf ( "INPUT: Enter the File Name to which the Database will be stored: " );
		    scanf ("%s", f_name);	//To read the File Name in which the Current Database needs to be saved.

		    ret = save_DB (HT, f_name);
		    if (ret == SUCCESS)
		    {
			printf ( "INFO: Database Store Successful.\n" );
		    }
		}
		break;
	    case 6:
		{
		    exit(0);
		}
		break;
	    default: 
		printf ( "ERROR: Invalid Choice. Please enter a number between 1 to 5.\n" );
	}

    }

    return SUCCESS;
}
