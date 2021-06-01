/* Author: Allison Delgado
   Class: CS 201 Spring 2021
   This porgram performs many operations (addition,
   subtraction, multiplication, etc) on up to 15 arguments.
   
   Last updated: May 31, 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct menu {
  char* choices[7];
  int number_of_items;
} m;

void check_valid(char function[], int amount);
void print_menu(struct menu);
int parse_input(char* arg);
void exit_program(int amount, int input[], char* original_args[]);
void add(int amount, int input[], char* original_args[]);
void subtract(int amount, int input[], char* original_args[]);
void multiply(int amount, int input[], char* original_args[]);
void divide(int amount, int input[], char* original_args[]);
void mod(int amount, int input[], char* original_args[]);
void reverse(int amount, int input[], char* original_args[]);

//dispatch table for operations
void (*ops[])(int amount, int input[], char* original_args[]) = { 
  exit_program,
  add,
  subtract,
  multiply,
  divide,
  mod,
  reverse
};

int
main(int argc, char* argv[]){
  int choice = 10; //some arbitrary number to initialize this variable
  //(couldn't be 0 since that means quit the loop)
  int array[15];

  //if the user doesn't enter any arguments
  if(argc == 1){
    printf("Please enter command line arguments.\n");
    printf("Quitting program.\n");
    exit(0);
  }
  
  printf("Welcome to Operations Calculator.\n");  
  struct menu m;
  m.number_of_items = 7;
  m.choices[0] = "Exit";
  m.choices[1] = "Addition";
  m.choices[2] = "Subtraction";
  m.choices[3] = "Multiplication";
  m.choices[4] = "Division";
  m.choices[5] = "Modulo";
  m.choices[6] = "Reverse Input";

  //keep looping until the user exits the program
  while(choice != 0){
    print_menu(m);
    
    scanf("%d", &choice);

    //bad input:
    if(choice < 0 || choice > 6){
      printf("Invalid selection. Try again.\n");
      exit(0);
    }
    
    for(int i = 1; i < argc; i++){
      array[i] = parse_input(argv[i]);
    }

    ops[choice](argc, array, argv);
  }
  return 0;
}

void
print_menu(struct menu m){
  printf("Here are valid operations.\n");
  printf("To select one, type its corresponding number.\n");
  for(int i = 0; i < 7; i++){
    printf("%d: %s\n", i,  m.choices[i]);
  }
  printf("\nMenu item: ");
  
}

void
check_valid(char function[], int amount){
  if(strncmp(function, "division", 10) == 0){ //if it's a division request
    //check that there are at least 2 numbers
    if(amount < 3){
      printf("To divide, please enter at least two numbers.\n");
      exit(0);
    }
  }
  
  else if(strncmp(function, "mod", 10) == 0){ //mod request
    if(amount < 3){
      printf("To mod, please enter at least two numbers.\n");
      exit(0);
    }
  }
}

int
parse_input(char* arg){
  //hex
  
  if((arg[0] == '0' && arg[1] == 'x') || (arg[0] == '0' && arg[1] == 'X')){
    return (int) strtol(arg, NULL, 16);
  }
  return atoi(arg);
}

//exit program
void
exit_program(int amount, int input[], char* original_args[]){
  printf("Quitting program.\n");
  exit(0);
}

// add values summed from left to right, print out
void
add(int amount, int input[], char* original_args[]){
  int total = 0;
  for(int i = 1; i < amount; i++){
    total += input[i];
    if(i == 1){
      printf("%d", input[1]);
    } else {
      printf(" + %d", input[i]);
    }
  }
  printf(" = %d\n\n", total);
}

//subtract values from left to right, print out
void
subtract(int amount, int input[], char* original_args[]){
  int total = input[1];
  printf("%d", input[1]);
  for(int i = 2; i < amount; i++){
    total -= input[i];
    printf(" - %d", input[i]);
  }
  printf(" = %d\n\n", total);
}

//multiply values from left to right, print out
void
multiply(int amount, int input[], char* original_args[]){
  int product = input[1];
  printf("%d", input[1]);
  for(int i = 2; i < amount; i++){
    product *= input[i];
    printf(" * %d", input[i]);
  }
  printf(" = %d\n\n", product); 
}

//divide the first two numbers
void
divide(int amount, int input[], char* original_args[]){
  float quotient = (float) input[1] / (float) input[2];
  printf("%d / %d =  %f\n\n", input[1], input[2], quotient);
}

//mod the first two numbers
void
mod(int amount, int input[], char* original_args[]){
  int result = input[1] % input[2];
  printf("%d mod %d = %d\n\n", input[1], input[2], result);
}

//reverse the input
void
reverse(int amount, int input[], char* original_args[]){
  for(int i = amount-1; i > 0; i--){
    for(int j = strlen(original_args[i])-1; j >= 0; j--){
      printf("%c", original_args[i][j]);
    }
    printf(" ");
  }
  printf("\n");
}
