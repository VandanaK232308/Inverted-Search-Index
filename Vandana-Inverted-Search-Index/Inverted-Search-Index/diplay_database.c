#include "inverted_index.h"

int display_DB (main_node_t** head)
{
	int i = 0, flag = 0;

	printf("------------------------------------------------------------------------------------\n");
    printf("Index\tWord\t\t\tFiles\t\tFile Name\tWord Count\n");
	printf("-------------------------------------------------------------------------------------\n");
	
	while (i < SIZE)		//The loop shall run to go through the Complete Database and print each Word in each File.
	{
		if (head [i] != NULL)	//If the particular Key has no words, then that Key shall be ignored.
		{
			display_words (head [i], i);
			flag = 1;
		}

		i += 1; 		//Update the Key value to go to the next Word in the List.
	}

	if (flag == 0)			//If the Database is empty, none of the Keys will be printed (as their Heads will be NULL).
		return FAILURE;
	else
		return SUCCESS;
}

void display_words (main_node_t* temp1, int index)
{
	while (temp1 != NULL)		//The loop shall run till we reach the end of the Word List.
	{
		printf ( "%d\t" , index);
		printf ( "%-10s\t\t" , temp1->word);
		printf ( "%d"  " \t\t", temp1->f_count);
				
		display_files (temp1->sub_link);
		
		//printf ("-> NULL\n");	//Signifies the end of the Sub-List.
		printf("\n");
		temp1 = temp1->link;	//Update the 'temp1' to point to the Next node.
	}
}

void display_files (sub_node_t* temp2)
{
	while (temp2 != NULL)		//The loop shall run till we reach the end of the Sub-List.
	{
		printf (""  " %s\t\t" , temp2->f_name);
		printf ( "%d"  " \t", temp2->w_count);
		
		temp2 = temp2->link;	//Update the 'temp2' to point to the Next node.
		
		if (temp2 != NULL)	//If we have not reached the end of the List, then print the Separator.
			printf ("\n\t\t\t\t\t\t");
			//printf("\n");
	}
}
