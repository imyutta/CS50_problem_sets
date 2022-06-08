#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-949-468-1000";

    people[1].name = "Carter";
    people[1].number = "+1-949-468-1000";
}