#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * str_alphabet(char *input);

char * word_extract(char *input);

char (*str_sort_length(char (*input)[10], int length))[10];

int main(void)
{
    char a[] = "pi pi pa pa, bo bo lia lia.";
    char *p = a;
    char (*word_list)[10] = (char (*)[10])malloc(0);
    int counter = 0;
    int i;
    char *word;
    while ((p = str_alphabet(p)))
    {
        counter++;
        realloc(word_list, counter * 10 * sizeof(char));
        strcpy(word_list[counter - 1], word = word_extract(p));
        free(word);
    }
    str_sort_length(word_list, counter);
    printf("This article has %d words", counter);
    printf("This is the words sorted by length:\n");
    for(i = 0;i < counter;i++)
    {
        printf("%s\n", word_list[i]);
    }
    free(word_list);
    return 0;
}

char * str_alphabet(char *input)
{
    while((*input <= 'A' || *input >= 'Z') && (*input <= 'a' || *input >= 'z') && *input)
    {
        input++;
    }
    if(*input)
        return input;
    else
        return NULL;
}

char * word_extract(char *input)
{
    char *output = (char *)malloc(10 * sizeof(char));
    int counter = 0;
    while((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z'))
    {
        output[counter] = *input;
        *input = ' ';
        input++;
        counter++;
    }
    output[counter] = 0;
    return output;
}

char (*str_sort_length(char (*input)[10], int length))[10]
{
    char temp[10];
    int i, j;
    for(i = 0;i < length;i++)
    {
        for(j = i;j < length;j++)
        {
            if(strlen(input[j]) < strlen(input[i]))
            {
                strcpy(temp, input[i]);
                strcpy(input[i], input[j]);
                strcpy(input[j], temp);
            }
        }
    }
    return input;
}