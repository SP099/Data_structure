#include "invertedIndex.h"

int main(int argc, char *argv[])
{
    int choice;
    char option;
	//Checking CLA not passed
	if (argc == 1)
	{
		printf(RED"Error: No filenames passed\nUsage: ./inverted_index.out <file1> <file2> ...\n"RESET);
		return FAILURE;
	}

	file_node_t *file_head = NULL;

	validate_n_store_filenames(&file_head, argv + 1);
	if (file_head == NULL)
	{
		printf( RED"No files are valid\n" RESET);
		return FAILURE;
	}


	wlist_t *HT_head[SIZE] = {NULL};
    
    do
	{
        printf(BLUE "1. Create Database\n2. Display Database\n3. Search Database\n4. Update database\n5. Save Database\n6.Exit\n"RESET RED "Please Enter your choice : "RESET);
		    if(scanf("%d", &choice) != 1){
          return 1;
        }

		    switch(choice)
		    {
			    case 1:
				    create_DB(file_head, HT_head);
                    break;
                case 2: 
                    // Display Database
                    display_DB(HT_head);
                    break;
                   
                case 3: 
                   // Search Database
    		        printf( BOLDBLUE "Enter the word to search : " RESET );
    		        char word[NAMELENGTH];
    		        if(scanf("%s", word)!=1){
                  return 1;
                }
    		        search_DB(HT_head, word);
                    break;
               
                case 4: // Update Database
                    printf( BOLDBLUE "Enter the file name to update : " RESET );
    		        char fname[NAMELENGTH];
    		        if(scanf("%s", fname)!=1){
                  return 1;
                }
    		        update_DB(&file_head, HT_head, fname);
                    break;

                case 5: 
                 // Save Database
                    printf( BLUE "Enter the file name to save : " RESET );
		            char s_fname[NAMELENGTH];
    		        if(scanf("%s", s_fname)!=1){
                  return 1;
                }
    		        save_DB(HT_head, s_fname);
                    break;
               
                case 6: 
                    // Exit
                    printf(RED"Exiting...\n"RESET);
                    exit(SUCCESS);
                default:
                    printf(RED"Invalid choice. Please try again.\n"RESET);

		}

		/* check for continue */
        	printf(MAGENTA"Do You Want To Continue (y/n): "RESET);
        	if(scanf("\n%c", &option) !=1){
            return 1;
          }

    	} while (option == 'y');
	return SUCCESS;
}
