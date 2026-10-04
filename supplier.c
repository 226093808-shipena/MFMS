#include <stdio.h>
#include <string.h>

int ID;
char supplierName[50];
char email[15];
char phone[15];
char town[50];

void addSupplier();
{
    getchar();

    printf("Enter Supplier ID\n");
    scanf("%d",&ID);

    printf("Enter Supplier Name:");
    fgets(supplierName, sizeof(supplierName),stdin);
    supplierName[strcspn(supplierName,"\n")]='\0';

    printf("Enter Email:");
    fgets(email, sizeof(email),stdin);
    email[strcspn(email,"\n")]='\0';

    printf("Enter Town:");
    fgets(town, sizeof(town),stdin);
    town[strcspn(town,"\n")]='\0';
}

    void displaySupplier()
{
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("ID : %s\n", ID);
    printf("Name : %s\n", supplierName);
    printf("Email : %s\n", email);
    printf("Phone : %s\n", phone);
    printf("Town : %s\n", town);
}
void searchSupplier()
{
    char search[100]
    getchar();

    printf("Enter supplier name to be searched:");
    fgets(search, sizeof(search), stdin);

    search[strcspn(search,"\n")]= '\0';

    if(strcmp(search, supplierName)==0)
        printf("Supplier Found\n");
    else 
        printf("Supplier Not Found!\n");
}
void showLength()
{

    printf("Supplier name length: %lu\n",
    strlen(supplierName));
}

int main()
{
    int choice;

    do
    {
        printf("\n==========================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("\n==========================\n");

        
        printf("1.Add Supplier\n");
        printf("2.Display Supplier\n");
        printf("3.Search Supplier\n");
        printf("4.Show Name Length\n");
        printf("5.Add ID\n");
        printf("6.Exit\n");

        printf("Enter choice:\n");
        scanf("%d,&choice");

        switch(choice)
            {
                case 1:
                addsupplier();
                break;

                case 2:
                displaysupplier();
                break;

                case 3:
                searchsupplier();
                break;

                case 4:
                showLength();
                break;

                case 5:
                printf("The end\n");
                break;

                default:
                printf("Invalid choice\n")
                
            }
    }while(choice != 5);

 return 0;
    }

