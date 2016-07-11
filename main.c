#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashmap.h"
#include "json_parse.h"

bool startsWith( const char * theString, const char * theBase );

int main(int argc, char *argv[]){
    testHash();
    testJson();
    printf("Nb arg : %d\n\n", argc);
    // Debut du prog

    printf("#####START#####\n\n");

    if (3 > argc){
    printf("ERROR: MISSING ARGUMENTS");
    return 0;
    }

    if (4 < argc) {
        printf("TOO MANY ARGUMENTS");
        return 0;
    }

    char* collection=NULL;
    char* insert=NULL;
    char* set=NULL;
    char* where=NULL;
    char* find=NULL;
    char* projection=NULL;
    char* remove=NULL;

    if( startsWith(argv[1],"-collection")) {
        printf("COLLECTION\n");
    } else {
        printf("COLLECTION NOT FOUND\n");
        return 0;
    }

    if (startsWith(argv[2],"-insert")) {
        printf("\tINSERT\n");
    }

    if (startsWith(argv[2],"-set")) {
        printf("\tSET\n");
        if (argv[3] == NULL) {
            printf("\t\tWITHOUT WHERE CONDITION\n");
        } else {
            if (startsWith(argv[3],"-where")) {
                printf("\t\tWITH WHERE CONDITION\n");
            } else {
                printf("\t\tERROR WHERE");
                return 0;
            }
        }
    }

    if (startsWith(argv[2],"-find")) {
        printf("\tFIND\n");
        if (argv[3] == NULL) {
            printf("\t\tMISSING PROJECTION\n");
            return 0;
        }
        if (startsWith(argv[3],"-projection")) {
            printf("\t\tPROJECTION\n");
        } else {
            printf("\t\tERROR PROJECTION");
            return 0;
        }
    }

    if (startsWith(argv[2],"-remove")) {
        printf("\tREMOVE\n");
    }

    //Fin du prog
    printf("\n#####END#####\n");
    return 0;
}

bool startsWith( const char * theString, const char * theBase ) {
    return strncmp( theString, theBase, strlen( theBase ) ) == 0;
}
