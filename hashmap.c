#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

t_hashmap* hashmap_create(int slots) {
    t_hashmap* map = malloc(sizeof(t_hashmap));
	map->slots = slots;
	map->load_factor = lf;
	map->grow_factor = gf;

	map->size = 0;
	map->entries = calloc(slots, sizeof(t_hashmap_entry*));

	return map;
}

int hashmap_hashcode(char* key){
	int hash = 0;
	while(*key)
        hash += *(key++);
	return hash;
}

void hashmap_put(t_hashmap* map, char* key, void* value) {
    int code = map_generate_hash(key);
    code = code % map->slots;
	
    t_hashmap_entry ** entry = &(map->entries[code]);
	
	while(*entry) {
        if ( 0 == strcmp(key,(*entry)->key)) {
            (*entry)->value = value;
            return 0;
        }
        entry = &(*entry)->next;
    }
    *entry = hashmap_entry_create(key,value);
    map->size++;
}

void * hashmap_get(t_hashmap* map, char* key) {
    int code = map_generate_hash(key);
    code = code % map->slots;
    t_hashmap_entry* entry = map->entries[code];

    while(entry) {
        if (map_generate_hash(key) ==  map_generate_hash(entry->key)) {
            return entry->value;
        }
        entry = entry->next;
    }
    return 0;
}

void hashmap_remove(t_hashmap* map, char* key) {
    int code = map_generate_hash(key) % map->slots;
    t_hashmap_entry** entry = &(map->entries[code]);
    while(*entry) {
        if (strcmp((*entry)->key, key) == 0) {
            t_hashmap_entry* toDel = *entry;
            *entry = (*entry)->next;
            free(toDel);
            map->size--;
            return;
        }
        entry = &((*entry)->next);
    }
}

void hashmap_delete(t_hashmap* map, char* key) {
    int code = map_generate_hash(key) % map->slots;
    t_hashmap_entry** entry = &(map->entries[code]);
    while(*entry) {
        if (strcmp((*entry)->key, key) == 0) {
            t_hashmap_entry* toDel = *entry;
            *entry = (*entry)->next;
            free(toDel);
            map->size--;
            return;
        }
        entry = &((*entry)->next);
    }
}

void* hashmap_traverse(t_hashmap* map, char* path) {
		
}

void hashmap_put(t_hashmap*map, char* path, void* value){
	
}
