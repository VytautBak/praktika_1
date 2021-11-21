#include "input.h"

#define MAX_LINE_LENGTH 255
#define FILE_NAME "zmones.txt"
#define NUM 3


void input_data(struct Node *first, struct Node *last)
{
    char *token;
    char buff[MAX_LINE_LENGTH];

    FILE *file = fopen(FILE_NAME, "r");

    for (int i = 0; i < NUM; i++)
    {
        struct Data *data = malloc(sizeof(struct Data));
        fscanf(file, "%s", buff);

        token = strtok(buff, ";");
        data->name = malloc(strlen(token) * sizeof(char));
        strcpy(data->name, token);
        //allocates the required memory for storing a string and then copies the string from line

        token = strtok(NULL, ";");
        data->lastname = malloc(strlen(token) * sizeof(char));
        strcpy(data->lastname, token);

        token = strtok(NULL, ";");
        data->phone = atoi(token);

        token = strtok(NULL, ";");
        data->email = malloc(strlen(token) * sizeof(char));
        strcpy(data->email, token);

        add_to_list_end(*data, first, last);
    }
}
