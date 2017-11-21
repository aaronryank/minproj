/* Copyright (C) 2016 Ryan Klingler
   polymorphism.c : Polymorphism in C
   A simple example of experimenting with polymorphism in C,
    mainly to prove it's possible. */

#include <stdio.h>
#include <stdlib.h>

typedef void *Object;

typedef struct {
    char * (*sound)(void);
} __Animal__;

typedef struct {
    __Animal__ methods;
    char *name;
} Animal;

char *dog_sound(void)
{
    return "WOOF";
}

char *cat_sound(void)
{
    return "MEOW";
}

const __Animal__ DOG = { dog_sound };
const __Animal__ CAT = { cat_sound };

int main(void)
{
    Animal dog = { DOG, "Fido" };
    Animal cat = { CAT, "Spot" };

    printf("%s says %s\n", dog.name, dog.methods.sound());
    printf("%s says %s\n", cat.name, cat.methods.sound()); 
}
