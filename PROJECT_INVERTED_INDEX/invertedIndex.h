#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6


#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define BOLDRED "\033[1;31m"
#define BOLDGREEN "\033[1;32m"
#define BOLDYELLOW "\033[1;33m"
#define BOLDBLUE "\033[1;34m"

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 50

//inverted table

typedef struct file_table
{
	char f_name[NAMELENGTH];
	int w_count;
	struct file_table *link;
}file_table_t;

typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	file_table_t *t_link;
	int f_count;
}wlist_t;

typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

/* File validation */
void validate_n_store_filenames(file_node_t **, char *filenames[]);
int IsFileValid(char *);
int store_filenames_to_list(char *f_name, file_node_t **head);

/*Create DB*/
int create_DB(file_node_t *file_head, wlist_t **head);
void read_datafile(wlist_t **, char *f_name);
int insert_at_last_main(wlist_t **head, char *word, char *f_name);
int update_link_table(wlist_t **word_node, char *f_name);
int update_word_count(wlist_t **head, char *);

/*Display*/
int display_DB(wlist_t **head);

/*search */
int search_DB(wlist_t **head, char *word);

/*Save*/
int save_DB(wlist_t **head, char *fname);

/*Update */
int update_DB(file_node_t **, wlist_t **, char *);


#endif

