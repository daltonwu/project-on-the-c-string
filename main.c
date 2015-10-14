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
	table[0] = insert_front(table[0],"blank space", "taylor swift");
	table[0] = insert_front(table[0],"wildest dreams", "taylor swift");
	printf("\ninsert front\n");
	print_list(table[0]);

	printf("\nfinding songs\n");
	song_node * song_search;
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"staying alive");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"too much heavens");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"wildest dreams");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"blank spacee");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"does not exist");
	print_node(song_search);
	printf("\n");

	return 0;
}