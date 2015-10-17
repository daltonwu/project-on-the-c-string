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
	srand(time(NULL));

	/*char preload_input[256];
	char no[2] = "0";
	printf("Preload table? (0 for no, anything else for yes.)\n");
	scanf("%s",preload_input);
	if (strcmp(preload_input,no))*/
		preload(table);

	// add_song(table);
	// add_song(table);
	// add_song(table);
	//print_list(table[0]);
	//print_list(table[1]);
	//printl(table);
	printall(table);
	song_search(table);
	printa(table);
	// shuffle(table);
	// shuffle(table);
	// shuffle(table);
	// shuffle(table);


	printf("\nemancipation‼\n");

	del_all(table);

	printall(table);

	return 0;
}
