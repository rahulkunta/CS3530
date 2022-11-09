#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int age;
	float height;
	double kilometers;
} Runner;

Runner temp;                                                //added a global variable temp

Runner * makeRunnerArray(){                                 //added helper function to initalize all the elements in the array of structs
    Runner *array = malloc(6*sizeof(Runner));

    for(int i = 0; i < 6; i++){
        array[i].age = (rand() % 20);
        array[i].height = (rand() % 60);
        array[i].kilometers = (rand() % 50);
    }
    
    return array;

}

// O(n^2)
void sortByHeight(Runner *array, int size){                  //used the boolean bubble sort from lecture
    bool Sort = 1;                                           //Sort is set to the Boolean value of TRUE
        do{                                                  //do while statement to run while Sort is 1 (true)
            Sort = 0;                                        //sets Sort equal to 0 (false) at the beginning of the loop
            for (int i = 0; i < size-1; i++) {               //for loop to run through the array of struct elements
            if (array[i].height > array[i+1].height){        //if statement comparing the first height to the next height
                temp = array[i];                             
                array[i] = array[i+1];                       //bubble sort 
                array[i+1] = temp;
                Sort = 1;
            }

             }
        }while(Sort);
}       

// O(log(n))
int getByHeight(Runner *array, int size, float height){
    int temp = 0;                                           //initialize temp value to 0
    int mid;                                                //declare mid 

    while(size){                                            //while loop to run when size is true (it's always true)
        mid = size/2;
        for(int i = 0; i < size; i++){                      //Binary Search 
            if(height > array[i].height){
                temp = mid + 1;
            }
            else if(height < array[i].height){
                temp = mid - 1;
            }
            else{
                return i;                                   //returns the index at which the height query was found
            }
        }
    }

    return 1;                                               //returns 1 if it does not work
}

int main(void){
    Runner *runner = makeRunnerArray();
    
    puts("Initial:");
    for(int i = 0; i < 6; i++){
        printf("%d %.0fin %.0fkm\n", runner[i].age,runner[i].height,runner[i].kilometers);
    }

    printf("\n\n");

    sortByHeight(runner, 6);

    puts("After sortByHeight:");
    for(int i = 0; i < 6; i++){
        printf("%d %.0fin %.0fkm\n", runner[i].age,runner[i].height,runner[i].kilometers);
    }

    printf("\n\nHeight found in index %d", getByHeight(runner, 6, 49));
}
