#ifndef JSON_PARSE_H_INCLUDED
#define JSON_PARSE_H_INCLUDED
#include "hashmap.h"

//***********************
//FONCTIONS JSON PARSER *
//***********************
t_hashmap* JSON_parse(char* string);// Convert a JSON String to a HashMap representation.
char* JSON_stringify(t_hashmap* map);// Convert a HashMap to a JSON String representation.

#endif
