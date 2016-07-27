#include "json_parse.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

t_hashmap* JSON_parse(char* string) {// Convert a JSON String to a HashMap representation.
/**    t_hashmap * map = hashmap_create(100);

    while() {

        char* key = NULL;
        char* value = NULL;

        hashmap_put(map, key, value);
    }

    return map;*/
}

char* JSON_stringify(t_hashmap* map) {// Convert a HashMap to a JSON String representation.
/**    unsigned int i = 0;
    t_hashmap_entry* tmp;
    while(i < map->slots) {
        tmp = map->entry[i];
        while(tmp != NULL) {
            printf("%s -> %s\n", tmp->key, tmp->value);
            tmp = tmp->next;
        }
        i++;
    }*/
}

FILE* fileNosql(){
    FILE* file = NULL;
    file = fopen("test.json", "r+");

    if (file == NULL) {
        printf("FILE ERROR\n");
        return 0;
    } else {
        printf("File nosql find\n");
        return file;
    }
}
