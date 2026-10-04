#ifndef ASSETS_H
#define ASSETS_H

#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

// Asset structure
typedef struct {
    int assetID;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

// Function prototypes
void assetMenu();
void addAsset();
void displayAssets();
void searchAsset();
#endif