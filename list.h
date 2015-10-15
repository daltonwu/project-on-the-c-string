#ifndef LIST_H
#define LIST_H
	typedef struct n {
		char name[256];
		char artist[256];
		struct n *next;
	}	song_node;
	
	song_node *insert_front(song_node *front, char *songName, char *artistName);
	
	song_node *insert(song_node *front, char *songName, char *artistName);
	
	void print_list(song_node *front);
	
	void print_node(song_node *front);
	
	song_node *find_song(song_node *front, char *songName);
	
	song_node *find_artist(song_node *front, char *artistName);
	
	song_node *random_song(song_node *front);
	
	song_node *remove_song(song_node *front, char *songName);
	
	song_node *free_list(song_node *front);
#endif
