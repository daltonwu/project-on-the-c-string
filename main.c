#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
	song_node *table[26];
	int table_ini = 0;
	for (table_ini; table_ini < 26; table_ini++) {
		table[table_ini] = (song_node*)malloc(sizeof(song_node)); //what if i malloc it...
		table[table_ini] = 0;
	}


	add_song(table);
	add_song(table);
	add_song(table);
	//print_list(table[0]);
	//print_list(table[1]);
	//printl(table);
	//printa(table);
	//printall(table);

/*
	printf("\nempty table\n");
	print_list(table[0]);

	
	table[0] = insert_front(table[0],"piano concerto no.2, op.18", "rachmaninoff");
	printf("\ninsert one song to front\n");
	print_list(table[0]);


	table[0] = insert(table[0],"wildest dreams", "taylor swift");
	table[0] = insert(table[0],"staying alive", "bee gees");
	table[0] = insert(table[0],"too much heaven", "bee gees");
	table[0] = insert(table[0],"violin sonata in g minor, d.408", "schubert");
	printf("\ninsert songs in artist name order\n");
	print_list(table[0]);
/*
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

	printf("\nrandom node\n");
	srand(time(NULL));
	print_node(random_song(table[0]));
	print_node(random_song(table[0]));
	print_node(random_song(table[0]));

	printf("\nremoving songs\n");
	table[0] = remove_song(table[0], "violin concerto");
	table[0] = remove_song(table[0], "too much heavens");
	table[0] = remove_song(table[0], "rick roll");
	print_list(table[0]);
*/
	printf("\nemancipation‼\n");
	table[0] = free_list(table[0]);
	print_list(table[0]);

	return 0;
}
