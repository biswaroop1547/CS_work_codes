#include <stdio.h>
#include <stdlib.h>

struct node1 {
    char name[50];
    int id;
    float salary;
    struct node1 *left;
    struct node1 *right;
};

struct node2 {
    char city[50];
    int id;
    char dept[50];
    struct node2 *left;
    struct node2 *right;
};

struct node1 *insert_node1(struct node1 *root1, char n[], int i, float s) {
    if (root1 == NULL) {
        struct node1 *curr = (struct node1 *)malloc(sizeof(struct node1));
        curr->left = curr->right = NULL;
        curr->id = i;
        for (int i = 0; n[i] != '\0'; i++) {
            curr->name[i] = n[i];
        }
        curr->salary = s;
        return curr;
    }

    else if (i > root1->id) {
        root1->right = insert_node1(root1->right, n, i, s);
        return root1;
    }

    else if (i < root1->id) {
        root1->left = insert_node1(root1->left, n, i, s);
        return root1;
    }
}

struct node2 *insert_node2(struct node2 *root2, char c[], int i, char d[]) {
    if (root2 == NULL) {
        struct node2 *curr = (struct node2 *)malloc(sizeof(struct node2));
        curr->left = curr->right = NULL;
        curr->id = i;
        for (int i = 0; c[i] != '\0'; i++) {
            curr->city[i] = c[i];
        }
        for (int i = 0; d[i] != '\0'; i++) {
            curr->dept[i] = d[i];
        }
        return curr;
    }

    else if (i > root2->id) {
        root2->right = insert_node2(root2->right, c, i, d);
        return root2;
    }

    else if (i < root2->id) {
        root2->left = insert_node2(root2->left, c, i, d);
        return root2;
    }
}

void disp_employee(struct node1 *root1, struct node2 *root2, char c[]) {
    if (root1 == NULL || root2 == NULL) {
        return;
    }
    int found = 1;
    for (int i = 0; root2->city[i] != '\0'; i++) {
        if (root2->city[i] != c[i]) {
            found = 0;
            break;
        }
    }
    if (found) {
        printf("%d  ", root1->id);
        printf("\n");
        for (int i = 0; root1->name[i] != '\0'; i++) {
            printf("%c", root1->name[i]);
        }
        printf("%f  ", root1->salary);
        printf("\n");
        for (int i = 0; root2->dept[i] != '\0'; i++) {
            printf("%c", root2->dept[i]);
        }
        printf("\n");
    }
    disp_employee(root1->left, root2->left, c);
    disp_employee(root1->right, root2->right, c);
}

int is_duplicate(struct node1 *root1, int i) {
    if (root1 == NULL) {
        return 0;
    } else {
        if (root1->id == i) {
            return 1;
        } else if (root1->id > i) {
            return is_duplicate(root1->left, i);
        } else {
            return is_duplicate(root1->right, i);
        }
    }
}


int inorder(struct node1 *root1){
    
    static float max_sal = 0;
    static int employee_id = 0;

    if(root1 == NULL){
        return -1;
    }

    inorder(root1->left);

    if(root1->salary > max_sal){
        max_sal = root1->salary;
        employee_id = root1->id;
    }

    inorder(root1->right);

    return employee_id;
}


void highest_salary(struct node1 *root1, struct node2 *root2) {
    if (root1 == NULL || root2 == NULL) {
        return;
    }
    

}

int main() {
    struct node1 *root1 = NULL;
    struct node2 *root2 = NULL;

    char key_pressed = 'a';

    int id;
    float salary;
    char name[50];
    char city[50];
    char dept[50];

    while(key_pressed != 'q'){
        printf("A. Press 'd' to display the employee details who belong to CITY \nB. Press a to add an employee\n");
        scanf("%c", &key_pressed);

        switch (key_pressed)
        {
        case 'a':
            printf("Enter the employee name: ");
            scanf("%[^\n]%*c ", name);

            printf("Enter employee city: ");
            scanf("%[^\n]%*c ", city);

            printf("Enter employee department: ");
            scanf("%[^\n]%*c ", dept);

            printf("Enter employee id: ");
            scanf("%d ", &id);

            printf("Enter employee salary: ");
            scanf("%f ", &salary);

            root1 = insert_node1(root1, name, id, salary);
            root2 = insert_node2(root2, city, id, dept);

            break;
        
        case 'd':
            printf("Enter employee city to display details: ");
            char city1[50];
            scanf("%[^\n]%*c", city1);

            disp_employee(root1, root2, "Bhubaneswar");

        default:
            break;
        }
    }

    // root1 = insert_node1(root1, "Sam", 3, 5000);
    // root1 = insert_node1(root1, "Anu", 1, 4000);
    // root1 = insert_node1(root1, "Priya", 5, 3000);
    // root1 = insert_node1(root1, "Riya", 4, 2000);

    // root2 = insert_node2(root2, "Bhubaneswar", 3, "CS");
    // root2 = insert_node2(root2, "Delhi", 1, "IT");
    // root2 = insert_node2(root2, "Bhubaneswar", 5, "CS");
    // root2 = insert_node2(root2, "Patna", 4, "IT");
    // disp_employee(root1, root2, "Bhubaneswar");
    // printf("\n%d", is_duplicate(root1, 4));

    // int highest_sal = inorder(root1);
    // printf("\nhighest_sal id : %d\n", highest_sal);
}