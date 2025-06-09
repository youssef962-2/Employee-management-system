/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 100


struct employee {
    int id ;
    char name [50];
    int age ;
    float salary;
    
};
struct employee employeeS[MAX];
int count = 0;

void add_record(){
    if (count < MAX)
    {
        struct employee e;
        printf("Enter employee ID:");
        scanf("%d",&e.id);
        printf("Enter name:");
        scanf(" %[^\n]s", e.name);
        printf("Enter Age: ");
        scanf("%d", &e.age);
        printf("Enter salary: ");
        scanf("%f", &e.salary);
        employeeS[count] = e;
        count++;
        printf("employee added successfully!\n");
        } else{
            printf("employee list is full!\n");
        }
} 

void View_list() {
    if (count==0) {
        printf("No employeeS to display.\n");
    } else {
        printf("employee list:\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d, name: %s, age: %d , salary: %.2f\n",
            employeeS[i].id, employeeS[i].name, employeeS[i].age, employeeS[i].salary);
        }
    }
    
}

void modify_record() {
    int id, found = 0;
    printf("Enter employee ID to modify: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++ ) {
        if(employeeS[i].id == id){
            found = 1;
            printf("Enter New Name: ");
            scanf(" %[^\n]s", employeeS[i].name);
            printf("Enter New Age: ");
            scanf("%d", &employeeS[i].age);
            printf("Enter New salary: ");
            scanf("%f", &employeeS[i].salary);
            printf("employee record updated successfully!\n");
            break;
        }
    }
    if(!found){
        printf("employee with ID %d not found.\n", id);
        
    }
}
void Delete_record() {
    int id, found = 0;
    printf("Enter employee ID to Delete: ");
    scanf("%d", &id);
    
    for(int i = 0; i < count; i++) {
        if(employeeS[i].id == id) {
            found = 1;
            for(int j = i; j < count - 1; j++) {
                employeeS[j] = employeeS[j + 1];
            }
            count --;
            printf("employee record deleted successfully!\n");
            break;
        }
    }

    
if(!found) {
    printf("employee with ID %d not found.\n", id);

}
}
 int main() {
    int choice;
    do{
        printf("\nEmployee Managment System\n");
        printf("1. Add employee\n");
        printf("2. View employee list\n");
        printf("3. Modify employee\n");
        printf("4. Delete employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_record(); break;
            case 2: View_list(); break;
            case 3: modify_record(); break;
            case 4: Delete_record(); break;
            case 5: printf("Exiting the system.\n"); break;
            default:printf("Invalid choice! please try again.\n");
        }
    } while (choice != 5);
    return 0;
 }
  
    
    

    


