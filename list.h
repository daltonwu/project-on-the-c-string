#ifndef LIST_H
#define LIST_H
	typedef struct n {
		char name[256];
		char artist[256];
		struct n *next;
	}	song_node;
	
	song_node *insert_front(song_node *front, char *song_name, char *artist_name);
	
	song_node *insert(song_node *front, char *song_name, char *artist_name);
	
	void print_list(song_node *front);
	
	void print_node(song_node *front);
	
	song_node *find_song(song_node *front, char *song_name);
	
	song_node *find_artist(song_node *front, char *artist_name);

	int length(song_node *front);
	
	song_node *random_song(song_node *front);
	
	song_node *remove_song(song_node *front, char *song_name);
	
	song_node *free_list(song_node *front);
	
	void add_song(char *song_name, char *artist_name);
	
	song_node *song_search(char *song_name);
	
	song_node *artist_search(char *artist_name);
	
	void printl(char letter);
	
	void printa(char *artist_name);
	
	void printall();
	
	void shuffle();
	
	void del_song(char *song_name, char *artist_name);
	
	void del_all(); // DROP table;
#endif
