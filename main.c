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
void add(int amount, int input[]);
void subtract(int amount, int input[]);
void multiply(int amount, int input[]);
void divide(int amount, int input[]);
void mod(int amount, int input[]);
void reverse(int amount, int input[]);


int
main(int argc, char* argv[]){
  int choice = 0;
  int array[15];
  
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
  print_menu(m);

  scanf("%d", &choice);

  for(int i = 0; i < argc; i++){
    array[i] = parse_input(argv[i]);
  }

  //exit
  if(choice == 0){
    printf("Quitting program.\n");
    exit(0);
  }

  //add
  else if(choice == 1){
    add(argc, array);
  }

  //subtract
  else if(choice == 2){
    subtract(argc, array);
  }

  //multiply
  else if(choice == 3){
    multiply(argc, array);
  }

  //divide
  else if(choice == 4){
    check_valid("division", argc);
    divide(argc, array);
  }

  //modulo
  else if(choice == 5){
    check_valid("mod", argc);
    mod(argc, array);
  }

  //reverse input
  else if(choice == 6){
    reverse(argc, array);
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
  printf("Menu item: ");
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
  return atoi(arg);
}

void add(int amount, int input[]){

}

void subtract(int amount, int input[]){

}

void multiply(int amount, int input[]){

}

void divide(int amount, int input[]){

}

void mod(int amount, int input[]){

}

void reverse(int amount, int input[]){

}
