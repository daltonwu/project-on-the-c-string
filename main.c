#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
	song_node *table[26];
	table[0] = (song_node*)malloc(sizeof(song_node)); //what if i malloc it...
	table[0] = 0;

	printf("\nempty table\n");
	print_list(table[0]);

	
	table[0] = insert_front(table[0],"piano concerto", "mozart");
	printf("\ninsert one song to front\n");
	print_list(table[0]);

	table[0] = insert(table[0],"wildest dreams", "taylor swift");
	table[0] = insert(table[0],"staying alive", "bee gees");
	table[0] = insert(table[0],"too much heavens", "bee gees");
	table[0] = insert(table[0],"violin concerto", "mozart");
	printf("\ninsert songs in artist name order\n");
	print_list(table[0]);

	printf("\nfinding songs\n");
	song_node *song_search;
	song_search = find_song(table[0],"staying alive");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"mozart");
	print_node(song_search);
	printf("\n");
	song_search = find_song(table[0],"blank spacee");
	print_node(song_search);
	printf("\n");

	printf("\nfinding artist\n");
	song_node *artist_search;
	artist_search = find_artist(table[0],"bee gees");
	print_node(artist_search);
	printf("\n");
	artist_search = find_artist(table[0],"mozart"); //piano 
	print_node(artist_search);
	printf("\n");
	artist_search = find_artist(table[0],"taylor slow");
	print_node(artist_search);
	printf("\n");




	return 0;
}
