#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {

	/*
	printf("\n");
	node * myNode = (node *)malloc(sizeof(node));
	myNode->data = 0;

	printf("Initialize one node.\n");
	print_list(myNode);

	printf("Add one node to the front.\n");
	myNode = insert_front(myNode,1);
	print_list(myNode);

	printf("Add a bunch of nodes.\n");
	int i = 1;
	while (i++ < 10)
		myNode = insert_front(myNode,i);
	print_list(myNode);

	printf("Free list.\n");
	myNode = free_list(myNode);
	print_list(myNode);

*/

	song_node * table[26];
	printf("\nempty table\n");
	print_list(table[0]);
	table[0] = insert_front(table[0],"too much heavens", "bee gees");
	printf("\nadded one song\n");
	print_list(table[0]);
	table[0] = insert_front(table[0],"staying alive", "bee gees");
	printf("\ninsert front\n");
	print_list(table[0]);
	return 0;
}