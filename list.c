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
	if (!front) { //last song in list
		song_node *new = (song_node *)malloc(sizeof(song_node));
		strcpy(new->name, song_name);
		strcpy(new->artist, artist_name);
		return new;
	}
	else if (strcasecmp(front->artist, artist_name) < 0) { //after front
		front->next = insert(front->next, song_name,artist_name);
		return front;
	}
	else { //before current or same artist, just insert at current
		song_node *new = insert_front(front,song_name,artist_name);
		return new;
	}
}

song_node *find_song(song_node *front, char *song_name) {
	if(!front || !strcasecmp(front->name, song_name)) 
		return front;
	else 
		return find_song(front->next, song_name);
}

song_node *find_artist(song_node *front, char * artist_name) {
	if(!front || !strcasecmp(front->artist, artist_name))
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
	srand(time(NULL)); //idk how this works DX
	int index = rand() % size;
	while (size--!=index+1) {
		//printf("size: %d, index: %d\n", size, index);
		front = front->next;
	}
	return front;
}

song_node *remove_song(song_node *front, char *song_name) {
	if (front) {
		if (!strcasecmp(front->name,song_name)) {
			song_node * tmp = front->next;
			free(front);
			return tmp;
		}
		else
			front->next = remove_song(front->next,song_name);
	}
	return front;
}

song_node *free_list(song_node *front) {
	if(front->next) {
		front->next = free_list(front->next);
	}
	free(front);
	return NULL;
}
