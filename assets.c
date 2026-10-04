#include <stdio.h>
#include <string.h>

#define MAX_ASSETS 100   // limit of assets

// structure for asset info
typedef struct {
    int assetID;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

// global array and counter
Asset assets[MAX_ASSETS];
int assetCount = 0;

// add new asset
void addAsset() {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset list full!\n");
        return;
    }

    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", assets[assetCount].name);

    printf("Enter Asset Type: ");
    scanf(" %[^\n]", assets[assetCount].type);

    printf("Enter Purchase Value: ");
    scanf("%f", &assets[assetCount].purchaseValue);
    if (assets[assetCount].purchaseValue < 0) {
        printf("Invalid value. Must be positive.\n");
        return;
    }

    printf("Enter Department: ");
    scanf(" %[^\n]", assets[assetCount].department);

    printf("Enter Condition: ");
    scanf(" %[^\n]", assets[assetCount].condition);

    assetCount++;
    printf("Asset added.\n");
}

// show all assets
void displayAssets() {
    if (assetCount == 0) {
        printf("No assets stored.\n");
        return;
    }
    for (int i = 0; i < assetCount; i++) {
        printf("\nAsset ID: %d\n", assets[i].assetID);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

// search asset by ID
void searchAsset() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].assetID == id) {
            printf("Found asset:\n");
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            return;
        }
    }
    printf("Asset not found.\n");
}

// menu for asset management
void assetMenu() {
    int choice;
    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: break;
            default: printf("Invalid option.\n");
        }
    } while(choice != 4);
}