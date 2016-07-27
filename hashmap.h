#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED

//*******************
//STRUCTURE HASHMAP *
//*******************
typedef struct s_hashmap_entry {
  char* key;
  void* value;
  struct s_hashmap_entry *next;
} t_hashmap_entry;

typedef struct s_hashmap{
  t_hashmap_entry** entries;
  int slots;
  int size;
} t_hashmap;

//*******************
//FONCTIONS HASHMAP *
//*******************
t_hashmap* hashmap_create(int slots);//Create a new hashmap

int hashmap_hashcode(char* key, int slots);//Hash Fonction

void hashmap_put(t_hashmap* map, char* key, void* value);

void* hashmap_get(t_hashmap* map, char* key);

void* hashmap_remove(t_hashmap* map, char* key);

void hashmap_resize(t_hashmap* map);

void* hashmap_delete(t_hashmap* map, char* key);

void* hashmap_traverse(t_hashmap* map, char* path);// Traverse a HashMap according to the given path
// Ex : hashmap_traverse(map, 'student.rate')   14

void hashmap_put(t_hashmap*map, char* path, void* value);// Traverse a HashMap according to the given path
// Ex : hashmap_put(map, 'student.rate', 56);
// hashmap_traverse(map, 'student.rate')    56

#endif
