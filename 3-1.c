//
// 3.1 Our binary search makes two tests inside the loop, when one would suffice
// (at the price of more tests outside.) Write a version with only one test inside the loop and measure the
// difference in run-time.
//

#include <stdio.h>
#include <time.h>

#define MAX_LENGTH 10

int binary_search_one(int input[], int x);
int binary_search_two(int input[], int x);
int get_size(int input[]);

int main() {
    
    clock_t start_one, start_two;
    
    int sorted_input[MAX_LENGTH] = {1,2,3,4,5,6,7,8,9};
    int search_input = 4;
    
    start_two = clock();
    int found_two = binary_search_two(sorted_input, search_input);
    printf("Two if's - %d, %ul \n", found_two, clock() - start_two);
    
    start_one = clock();
    int found_one = binary_search_one(sorted_input, search_input);
    printf("One if's - %d, %ul \n", found_one, clock() - start_one);
    
    return 0;
}

int binary_search_two(int arr[], int x) {
    
    int min = 0;
    int max = get_size(arr);
    
    while (min <= max) {
        int middle = (min + max) / 2;
        
        printf("%d min, %d max \n", min, max);
        
        if (middle < x) min = middle + 1;
        else if (middle > x) max = middle - 1;
        else return middle;
    }
    
    return -1;
}

int binary_search_one(int arr[], int x) {
    
    int min = 0;
    int max = get_size(arr);
    
    while (min <= max) {
        int middle = (min + max) / 2;
        
        printf("%d min, %d max \n", min, max);
        
        if (middle == x) return middle;
        else {
            if (middle < x) min = middle + 1;
            else if (middle > x) max = middle - 1;
        }
    }
    
    return -1;
}

int get_size(int arr[]) {
    
    int i = 0;
    while (arr[i] != '\0') i++;
    
    return i;
}
