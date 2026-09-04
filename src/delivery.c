#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

#define MAX_DELIVERIES 100

// Structure to store delivery details
typedef struct {
    int map_no;
    int src;
    int end;
    int distance;
    char description[256];
} DeliveryDetail;

static DeliveryDetail deliveries[MAX_DELIVERIES];
static int deliveryCount = 0;

// Divider printing
void printDivider() {
    printf("------------------------------------------------------------\n");
}

// Add a new delivery
void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description) {
    if (deliveryCount >= MAX_DELIVERIES) {
        printf("Error: Cannot store more deliveries.\n");
        return;
    }

    deliveries[deliveryCount].map_no = map_no;
    deliveries[deliveryCount].src = src;
    deliveries[deliveryCount].end = end;
    deliveries[deliveryCount].distance = dist;

    // Store description safely
    strncpy(deliveries[deliveryCount].description, description, 255);
    deliveries[deliveryCount].description[255] = '\0';

    deliveryCount++;

    printf("\nDelivery detail added successfully!\n");
}

// Display all deliveries
void displayAllDeliveryDetails() {
    system("cls");
    printDivider();
    printf(" ALL DELIVERY DETAILS\n");
    printDivider();

    if (deliveryCount == 0) {
        printf("No deliveries recorded yet.\n");
        return;
    }

    for (int i = 0; i < deliveryCount; i++) {
        printf("Delivery #%d\n", i + 1);
        printf(" Map: %d\n", deliveries[i].map_no);
        printf(" Source Node: %d\n", deliveries[i].src);
        printf(" Destination Node: %d\n", deliveries[i].end);
        printf(" Distance: %d\n", deliveries[i].distance);
        printf(" Description: %s\n", deliveries[i].description);
        printDivider();
    }
}

// Get number of deliveries stored
int getDeliveryCount() {
    return deliveryCount;
}