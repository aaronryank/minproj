/* Copyright (C) 2016 Ryan Klingler
   c-oop.c : C Object Oriented Programming
   A simple example of object-oriented programming in C. */

#include <stdio.h>

struct foo {
    int one, two;
    int (*bar)(int, int);
};

struct foo foo_init(int one, int two, int (*bar)(int, int))
{
    struct foo foo;

    foo.one = one;
    foo.two = two;
    foo.bar = bar;

    return foo;
}

/* test program */

int addTwoNumbers(int a, int b)
{
    return a+b;
}

int main(void)
{
    struct foo test = foo_init(2, 5, addTwoNumbers);

    printf("Test: %d\n", test.bar(test.one, test.two));
}
