#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_list(song_node * front) {
	if (front) {
		printf("%s -- %s\n", front->artist, front->name);
		print_list(front->next);
	}
}

song_node * insert_front(song_node * front, char * songName, char * artistName) {
	song_node * newNode = (song_node *)malloc(sizeof(song_node));
	strcpy(newNode->name, songName);
	strcpy(newNode->artist, artistName);
	newNode->next = front;
	return newNode;
}

song_node * insert(song_node * front, char * songName, char * artistName) {
	//idk what it means by in order
	return front;
}

song_node * find_song(song_node * front, char * songName) {
	
}

song_node * free_list(song_node * front) {
	if (front->next != 0) 
		front->next = free_list(front->next);
	free(front);
	return 0;
}