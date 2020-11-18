#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char middle_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, middle_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, middle_rod, to_rod, from_rod); 
} 
  
int main() 
{ 
    int num_of_disks;
    
    printf("Enter the number of disks : ");
    scanf("%d", &num_of_disks);

    towerOfHanoi(num_of_disks, 'A', 'C', 'B');
    
    printf("\n");
    
    return 0; 
}