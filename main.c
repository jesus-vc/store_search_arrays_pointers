//
//  main.c
//
//  Created by Jesus Vasquez-Cipriano on 7/10/2021.
//  Copyright © 2021 Jesus Vasquez-Cipriano. All rights reserved.
//

/* ********************************************
 
* SUMMARY
* Function: int main()
* Input: User inputs chooses a number of ints to input.
* Output: Returns 0 on success.
* Procedure: Stores user-inputted ints into array and provides a menu to search the array for indices and counts. Results are processed by calling additional functions, with main() displaying the results.
 
 * Future Revisions:
1. To improve user experience, use strings to store and display indices where a number is found in the user-inputted array of ints.

******************************************* */

#include <stdio.h>

int menu(void);
int search_with_array(int a[],int b[],int size, int number_search);
int search_with_pointer(int a[], int b[],int size, int number_search);
int count_with_array(int a[], int size, int number_search);
int count_with_pointer(int a[], int size, int number_search);

/* Function Procedure: Use while loop and switch statements to get, process and store user's input. Call additional functions to search array of ints through array and pointer methods.*/
int main() {
    
    int choice = 0;
    int amount = 0;
    int n1 = 0;
    int search_option = 0;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    int array1[10];
    int array2[10];
    
   
    while (choice!=4) {
        choice = menu();
        switch(choice) {
            case 1:
                printf("How many integers do you want to enter? Less than 10, please: ");
                scanf("%d",&amount);
                for (int i = 0;i<amount;i++) {
                    printf("Enter an integer: ");
                    scanf("%d",&array1[i]);
                }
                break;
            case 2:
            
                printf("What number do you want to search for?: ");
                scanf("%d",&n1);
                                
                printf("Select 1 or 2, based on your search method.\n1. Array\n2. Pointers:\n");
                scanf("%d",&search_option);
                
                if (search_option==1) {
                    result1 = search_with_array(array1,array2,amount,n1);
                }
                else {
                    result2 = search_with_pointer(array1,array2,amount,n1);
                }
                
                for (int i = 0; i < amount; i++) {
                    if (array2[i]==1) {
                        printf("\n%d found in indice: %d\n",n1,i);
                    }
                }
                break;
            case 3:
                printf("What number do you want count?: ");
                scanf("%d",&n1);
                
                printf("Select 1 or 2, based on your search method.\n1. Array\n2. Pointer:\n");
                scanf("%d",&search_option);
                
                if (search_option==1) {
                    result3 = count_with_array(array1,amount,n1);
                    printf("\n%d is found %d number of times in your array.\n",n1,result3);
                }
                else {
                    result4 = count_with_pointer(array1,amount,n1);
                    printf("\n%d is found %d number of times in your array.\n",n1,result4);
                }
            
                break;
        }
    }
    printf("\nYou selected %d, so quitting. Thank you.\n",choice);
    return 0;
}

/* Function Procedure: Display menu. Return user's choice to main().*/
int menu(void) {
    
    int choice = 0;
    printf("Welcome. Please select a menu option. You may select Option 1 only if you haven't already inputted data.\n\n1.Enter Data\n2.Search Data\n3.Count Data\n4.Quit.\n");
    printf("Input your selection (an integer of 1, 2, 3 or 4): ");
    scanf("%d",&choice);
    return(choice);
}


/* Function Procedure: Use array method to return count (number of times number_search paramenter is found in int a[].*/

int count_with_array(int a[], int size, int number_search) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i]==number_search)
            count++;
    }
    return(count);
}

/* Function Procedure: Use pointer method to return count (number of times number_search paramenter is found in int a[].*/

int count_with_pointer(int a[], int size, int number_search) {
    int count = 0;
    int * a_Ptr;
    a_Ptr = a;
    
    for (int i = 0; i < size; i++) {
        if ((*(a_Ptr+i))==number_search)
            count++;
    }
    return(count);
}

/* Function Procedure: Use array method to return indice (where number_search paramenter is found in int a[]) by storing results in int b[].*/

int search_with_array(int a[],int b[],int size, int number_search) {

    for (int i = 0; i < size; i++) {
        if (a[i] == number_search) {
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }
    }
    return 0;
}

/* Function Procedure: Use pointer method to return indice (where number_search paramenter is found in int a[]) by storing results in int b[].*/

int search_with_pointer(int a[], int b[],int size, int number_search) {
    int * a_Ptr;
    a_Ptr = a;
    int * b_Ptr;
    b_Ptr = b;

    for (int i = 0;i < size; i++) {
        if(*(a_Ptr+i)==number_search) {
            *(b_Ptr+i) = 1;
    }
        else {
            *(b_Ptr+i) = 0;
        }
}
    return 0;
}
