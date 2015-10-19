#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// O say can you C 
//.......dalton plz
// C what I did there?

void print_list(song_node *front) {
	if(front) { 
		printf("%s — %s\n", front->artist, front->name);
		print_list(front->next);
	}
}

void print_node(song_node *front) {
	if(front)
		printf("%s — %s\n", front->artist, front->name);
	else 
		printf("nothing to see here …\n");
}

song_node *insert_front(song_node *front, char *song_name, char *artist_name) {
	song_node *new = (song_node *) malloc(sizeof(song_node));
	strcpy(new->name, song_name);
	strcpy(new->artist, artist_name);
	new->next = front;
	return new;
}

song_node *insert(song_node *front, char *song_name, char *artist_name) {
	if(!front) { //last song in list
		song_node *new = (song_node *)malloc(sizeof(song_node));
		strcpy(new->name, song_name);
		strcpy(new->artist, artist_name);
		return new;
	}
	else if(strcmp(front->artist, artist_name) < 0 || strcmp(front->name, song_name) < 0) { //after front
		front->next = insert(front->next, song_name,artist_name);
		return front;
	}
	else { //before current or same artist, just insert at current
		song_node *new = insert_front(front,song_name,artist_name);
		return new;
	}
}

song_node *find_song(song_node *front, char *song_name) {
	if(!front || !strncmp(front->name, song_name, strlen(song_name))) 
		return front;
	else 
		return find_song(front->next, song_name);
}

song_node *find_artist(song_node *front, char * artist_name) {
	if(!front || !strncmp(front->artist, artist_name, strlen(artist_name)))
		return front;
	else 
		return find_artist(front->next, artist_name);
}

int length(song_node *front) {
	int count = 0;
	if (front)
		count += length(front->next)+1;
	return count;
}

song_node *random_song(song_node *front) {
	int size = length(front);
	int i = rand() % size;
	while(i--) {
		front = front->next;
	}
	return front;
}

song_node *remove_song(song_node *front, char *song_name, char * artist_name) {
	if (front) {
		if (!strcmp(front->name,song_name)&&!strcmp(front->artist,artist_name)) {
			song_node * tmp = front->next;
			free(front);
			return tmp;
		}
		else
			front->next = remove_song(front->next,song_name,artist_name);
	}
	return front;
}

song_node *free_list(song_node *front) {
	if(front&&front->next) {
		front->next = free_list(front->next);
	}
	free(front);
	return NULL;
}

char *str_lower(char * input) { //converts to lowercase
	int i = 0;
	for (i;input[i];i++) {
		input[i]=tolower(input[i]); //source: stackoverflow
	}
	return input;
}

void add_song(song_node * song_table[]) {
	char songname[256];
	char artistname[256];
	
	printf("\nSong name: ");
	scanf(" %[^\n]s", songname); //reads space in string. source: stackoverflow
	char *song_name = str_lower(songname);
	
	printf("\nArtist name: \n");
	scanf(" %[^\n]s", artistname);
	char *artist_name = str_lower(artistname);
	
	if((*artist_name - 'a') >= 0 && (*artist_name - 'a') < 26) {
		song_table[*artist_name - 'a'] = insert(song_table[*artist_name - 'a'], song_name, artist_name);
		printf("Song added.\n");
	}
}

void printl(song_node *song_table[]) {
	char input[256];
	printf("Letter: \n");
	scanf("%s",input);
	if ((*input - 'a' >= 0 && (*input - 'a') < 26)) {
		printf("Search results:\n");
		print_list(song_table[tolower(*input) - 'a']);
	}
}


void *song_search(song_node *song_table[]) {
	char input[256];
	printf("Song name: \n");
	scanf(" %[^\n]s", input);
	char * song_name = str_lower(input);
	int i = 0;
	song_node * front = song_table[i];
	printf("Search results:\n");
	while (i<26) {
		while (front) {
			front = find_song(front, song_name);
			if (front&&i<26) {
				print_node(front);
				front = front->next;
			}
		}
		front = song_table[++i];
	}
}

song_node *artist_search(song_node *song_table[], char *artist_name) {
	song_node * front = song_table[*artist_name - 'a'];
	front = find_artist(front, artist_name);
	return front;
}

void printa(song_node *song_table[]) {
	char input[256];
	printf("Artist name: \n");
	scanf(" %[^\n]s", input);
	char * artist_name = str_lower(input);
	song_node * front = artist_search(song_table, artist_name);
	printf("Search results:\n");
	while (front && !strncmp(front->artist,artist_name,strlen(artist_name))) {
		print_node(front);
		front = front->next;
	}
}

void printall(song_node *song_table[]) {
	int i = 26;
	printf("Search results:\n");
	while (i--)
		print_list(song_table[25-i]);
}

void shuffle(song_node *song_table[]) {
	char input[256];
	int count[26];
	int i = 26;
	int sum = 0;
	while (i--) {
		count[25-i] = length(song_table[25-i]);
		sum += count[25-i];
	}
	printf("How many random songs: \n");
	scanf("%s",input);
	int num = atoi(input);
	if (num>sum) {
		num = sum;
	}
	i=0;
	song_node * front = song_table[i];
	printf("Search results:\n");
	while (!front&&i<26) 
		front = song_table[++i];
	while (num) {
		int prob = rand() % sum;
		if (prob < num) {
			print_node(front);
			num--;
		}
			sum--;
		if (front)
			front = front->next;
		while (!front) 
				front = song_table[(++i)%26];
	}
}

void del_song(song_node *song_table[]) {
	char artist_input[256];
	char song_input[256];
	printf("Artist name: \n");
	scanf(" %[^\n]s", artist_input);
	printf("Song name: \n");
	scanf(" %[^\n]s", song_input);
	char * song_name = str_lower(song_input);
	char * artist_name = str_lower(artist_input);
	if ((*artist_name - 'a') >= 0 && (*artist_name - 'a') < 26)
		song_table[*artist_name-'a'] = remove_song(song_table[*artist_name-'a'],song_name,artist_name);
}

void del_all(song_node *song_table[]) {
	int i = 26;
	while (i--)
		song_table[i] = free_list(song_table[i]);
}


void preload(song_node *song_table[]) { //15 more suggestions?
	song_table['t'-'a'] = insert(song_table['t'-'a'],"wildest dreams", "taylor swift");
	song_table['b'-'a'] = insert(song_table['b'-'a'],"too much heaven", "bee gees");
	song_table['b'-'a'] = insert(song_table['b'-'a'],"how deep is your love", "bee gees");
	song_table['b'-'a'] = insert(song_table['b'-'a'],"staying alive", "bee gees");
	song_table['t'-'a'] = insert(song_table['t'-'a'],"glad you came","the wanted");
	song_table['c'-'a'] = insert(song_table['c'-'a'],"viva la vida","coldplay");
	song_table['c'-'a'] = insert(song_table['c'-'a'],"the scientist","coldplay");
	song_table['d'-'a'] = insert(song_table['d'-'a'],"you spin me round","dead or alive");
	song_table['o'-'a'] = insert(song_table['o'-'a'],"counting stars","one republic");
	song_table['g'-'a'] = insert(song_table['g'-'a'],"somebody that i used to know","gotye");
	song_table['l'-'a'] = insert(song_table['l'-'a'],"royals","lorde");
	song_table['e'-'a'] = insert(song_table['e'-'a'],"ecstacy of gold","ennio morricone");
	song_table['m'-'a'] = insert(song_table['m'-'a'],"payphone","maroon 5");
	song_table['i'-'a'] = insert(song_table['i'-'a'],"let it go","idina menzel");
	song_table['z'-'a'] = insert(song_table['z'-'a'],"the end","ze end");
	
	song_table['a'-'a'] = insert(song_table['a'-'a'],"iberia", "albeniz");
	song_table['f'-'a'] = insert(song_table['f'-'a'],"requiem","faure");
	song_table['h'-'a'] = insert(song_table['h'-'a'],"music for the royal fireworks","handel");
	song_table['k'-'a'] = insert(song_table['k'-'a'],"the comedians", "kabalevsky");
	song_table['p'-'a'] = insert(song_table['p'-'a'],"dance of the knights", "prokofiev");
	song_table['r'-'a'] = insert(song_table['r'-'a'],"piano concerto no.2, op.18", "rachmaninoff");
	song_table['s'-'a'] = insert(song_table['s'-'a'],"jazz-like partita", "schulhoff");
	song_table['t'-'a'] = insert(song_table['t'-'a'],"1812 overture", "tchaikovsky");
	song_table['w'-'a'] = insert(song_table['w'-'a'],"the ring of the nibelung", "wagner");
	song_table['b'-'a'] = insert(song_table['b'-'a'],"piano sonata no.21","beethoven");
	song_table['c'-'a'] = insert(song_table['c'-'a'],"scherzo no.1", "chopin");
	song_table['s'-'a'] = insert(song_table['s'-'a'],"ave maria", "schubert");
	song_table['l'-'a'] = insert(song_table['l'-'a'],"paganini etude no.6", "liszt");
	song_table['b'-'a'] = insert(song_table['b'-'a'],"waltz in a-flat major, op.39, no.15", "brahms");
	song_table['d'-'a'] = insert(song_table['d'-'a'],"new world symphony", "dvorak");
}
