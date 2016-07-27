#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashmap.h"
#include "json_parse.h"

bool startsWith( const char * theString, const char * theBase );

int main(int argc, char **argv){
    if (3 > argc){
        printf("ERROR: MISSING ARGUMENTS");
        return 0;
    }

    if (4 < argc) {
        printf("TOO MANY ARGUMENTS");
        return 0;
    }

    FILE* file = fileNosql();

    char *collection,
            *insert,
            *set,
            *where,
            *remove,
            *tmp = NULL;

    if( startsWith(argv[1],"-collection")) {
        tmp = strchr(argv[1], '=') + 1;
        collection = malloc(sizeof(char) * strlen(tmp) + 1);
        strncpy(collection, tmp, strlen(tmp));
        collection[strlen(tmp)] = '\0';

        printf("COLLECTION: %s\n", collection);
    } else {
        printf("COLLECTION NOT FOUND\n");
        return 0;
    }

    if (startsWith(argv[2],"-insert")) {
        tmp = strchr(argv[2], '=') + 1;
        insert = malloc(sizeof(char) * strlen(tmp) + 1);
        strncpy(insert, tmp, strlen(tmp));
        insert[strlen(tmp)] = '\n';
        insert[strlen(tmp)+1] = '\0';

        fseek(file, 0, SEEK_END);
        fputs(insert, file);

        printf("INSERT: %s\n", insert);
    }

    if (startsWith(argv[2],"-set")) {
        tmp = strchr(argv[2], '=') + 1;
        set = malloc(sizeof(char) * strlen(tmp) + 1);
        strncpy(set, tmp, strlen(tmp));
        set[strlen(tmp)] = '\0';

        printf("SET: %s\n", set);

        if (argv[3] == NULL) {
            printf("\t\tWITHOUT WHERE CONDITION\n");
        } else {

            if (startsWith(argv[3],"-where")) {
                tmp = strchr(argv[3], '=') + 1;
                where = malloc(sizeof(char) * strlen(tmp) + 1);
                strncpy(where, tmp, strlen(tmp));
                where[strlen(tmp)] = '\0';

                printf("WHERE: %s\n", where);
            } else {
                printf("\t\tERROR WHERE");
                return 0;
            }
        }
    }

    if (startsWith(argv[2],"-remove")) {
        tmp = strchr(argv[2], '=') + 1;
        remove = malloc(sizeof(char) * strlen(tmp) + 1);
        strncpy(remove, tmp, strlen(tmp));
        remove[strlen(tmp)] = '\0';

        printf("REMOVE: %s\n", remove);
    }
    return 0;
}

bool startsWith( const char * theString, const char * theBase ) {
    return strncmp(theString, theBase, strlen(theBase)) == 0;
}
