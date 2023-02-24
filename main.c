/* 
Write a function createEmployees() that takes the list of employees' names, list of their salaries, and 
length of the list (empCount) as the parameters, and returns a pointer to a dynamically allocated array 
of Employee storing the relevant information for empCount employees.  
The function dynamically allocates memory for empCount number of employees and assigns the name 
and salaries for each of them from the input parameters. During this process, the names are stored in 
the dynamically allocated memory of StringType, and also make sure you assign the length of the name 
appropriately. Your code should use exact amount of memory needed to store the corresponding 
names. You may assume no name is longer than 49 characters. 
*/

#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct StringType {  
    char *string;  
    int length;  
} StringType;  
 
typedef struct Employee {  
    StringType *ename;  
    double salary;  
} Employee;  
 
Employee* createEmployees(char names[][50], double *salaries, int empCount) { 

    Employee *employees = malloc (empCount * sizeof(Employee));

    for (int i = 0; i < empCount; i++) {
        employees[i].ename = malloc(sizeof(StringType)); 
        int length = strlen(names[i]);
        employees[i].ename->string = malloc(length * sizeof(char));
        strcpy(employees[i].ename->string, names[i]); 
        employees[i].ename->length = length; 
        employees[i].salary = salaries[i];
    } 

    return employees;
}
 
int main() {  
    const int EMPLOYEE_COUNT = 4; 
 
    //array of employees’ names  
    char nameList[][50] = {"Bill", "Mary", "Kevin", "Denise"};  
    
    //array of salaries, where 15.80 is the salary of Bill, 13.50 is  
    // the salary of Mary, etc.  
    double salaries[] = {15.80, 13.5, 20.9, 12.99};  
    
    Employee *pEmployees = createEmployees(nameList, salaries, EMPLOYEE_COUNT);  
 
    // Print Employees 
    int e = 0; 
    Employee *pEmployee = pEmployees; 
    printf("\tEMPLOYEE NAME\t\tSALARY\n"); 
 
    for (e=0;e<EMPLOYEE_COUNT;++e) { 
        printf("\t%s\t\t\t%.2lf\n",pEmployee->ename->string,pEmployee->salary); 
        pEmployee++; 
    } 
  
    // Deallocate memory 
    pEmployee = pEmployees; 
    for (e=0;e<EMPLOYEE_COUNT;++e) { 
        free(pEmployee->ename->string); 
        pEmployee->ename->string = NULL; 
        free(pEmployee->ename); 
        pEmployee->ename = NULL; 
        pEmployee++; 
    } 
 
    free(pEmployees); 
    pEmployees = NULL; 
  
    return 0;  
} 