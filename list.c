#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_list(song_node *front) {
	if(front) {
		printf("%s — %s\n", front->artist, front->name);
		print_list(front->next);
	}
}

void print_node(song_node *front) {
	if(front) {
		printf("%s — %s\n", front->artist, front->name);
	}
	else {
		printf("nothing to see here …\n");
	}
}

song_node *insert_front(song_node *front, char *song_name, char *artist_name) {
	song_node *new = (song_node *) malloc(sizeof(song_node));
	
	strcpy(new->name, song_name);
	strcpy(new->artist, artist_name);
	new->next = front;
	
	return new;
}

song_node *insert(song_node *front, char *song_name, char *artist_name) {
	// idk what it means by in order
	// let's find the place and then use insert_front
	
	return front;
}

song_node *find_song(song_node *front, char *song_name) {
	if(!front || !strcasecmp(front->name, song_name)) {
		return front;
	}
	else {
		return find_song(front->next, song_name);
	}
}

song_node *find_artist(song_node *front, char * artist_name) {
	if(!front || !strcasecmp(front->artist, artist_name)) {
		return front;
	}
	else {
		return find_artist(front->next, artist_name);
	}
}

song_node *random_song(song_node *front) {
	//how to find size of linked list....
	//how to find random number
	return front;
}

song_node *free_list(song_node *front) {
	if(front->next) {
		front->next = free_list(front->next);
	}
	free(front);
	return NULL;
}
