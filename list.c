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

song_node *insert_front(song_node *front, char *songName, char *artistName) {
	song_node *newNode = (song_node *) malloc(sizeof(song_node));
	
	strcpy(newNode->name, songName);
	strcpy(newNode->artist, artistName);
	newNode->next = front;
	
	return newNode;
}

song_node *insert(song_node *front, char *songName, char *artistName) {
	// idk what it means by in order
	// let's find the place and then use insert_front
	return front;
}

song_node *find_song(song_node *front, char *songName) {
	if(!front || !strcmp(front->name, songName)) {
		return front;
	}
	else {
		return find_song(front->next, songName);
	}
}

song_node *find_artist(song_node *front, char * artistName) {
	if(!front || !strcmp(front->artist, artistName)) {
		return front;
	}
	else {
		return find_artist(front->next, artistName);
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
