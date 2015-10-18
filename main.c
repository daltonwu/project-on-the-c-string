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

	char preload_input[256];
	char no[2] = "0";
	printf("\nPreload table? (0 for no, anything else for yes.)\n");
	scanf("%s",preload_input);
	if (strcmp(preload_input,no))
		preload(table);
	char input[256];
	while (1) {
		input[0] = '0';
		input[1] = '0';
		printf("\n----------------------\n");
		printf("\n1. Add songs\n2. Song name that starts with...\n3. Artist name that starts with...\n4. Artist under Letter...\n5. Everything!\n6. Shuffle\n7. Delete song\n8. Emancipation\n9. Leave\nInput a number\n");
		scanf("%s",input);
		int choice = atoi(input);
		printf("\n\n");
		if (choice == 1)
			add_song(table);
		else if (choice == 2)
			song_search(table);
		else if (choice == 3)
			printa(table);
		else if (choice == 4)
			printl(table);
		else if (choice == 5)
			printall(table);
		else if (choice == 6)
			shuffle(table);
		else if (choice == 7)
			del_song(table);
		else if (choice == 8)
			del_all(table);
		else if (choice == 9) {
			del_all(table);
			return 0;
		}
		else
			printf("Choose again.\n");
	}
	return 0;
}
