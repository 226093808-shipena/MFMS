#ifndef ASSETS_H
#define ASSETS_H

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
extern Asset assets[MAX_ASSETS];
extern int assetCount;
void assetMenu();
void addAsset();
void displayAssets();
void searchAsset();
#endif