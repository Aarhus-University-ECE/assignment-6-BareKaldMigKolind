#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size)
{
    // Excercise 2
    // Implement your code below...
    //Laver en variabel max til at gemme en max værdi i. 
    assert (size > 0);

    int max = numbers[0];

    //Laver et for-loop som kører arrayet igennem. Hvis en værdi number[i] er større end max, 
    //så bliver det den nye max. Dermed ender jeg med den største værdi i arrayet. 
    for (int i = 0; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}
