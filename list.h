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

	char * str_lower(char * input);

	void preload(song_node *song_table[]);
	
	void add_song(song_node *song_table[]);
	
	void *song_search(song_node *song_table[]);

	song_node *song_search_helper(song_node *song_table[], char * song_name);
	
	song_node *artist_search(song_node *song_table[], char *artist_name);
	
	void printl(song_node *song_table[]);
	
	void printa(song_node *song_table[]);
	
	void printall(song_node *song_table[]);
	
	void shuffle(song_node *song_table[]); 
	
	void del_song(song_node *song_table[]); 
	
	void del_all(song_node *song_table[]); 
#endif