#pragma once
#include <iostream>
#include <iomanip>
#include "list.h"

struct ART_GALLERY {
    char title[70];
    char artist[50];
    int year;
    char direction[40];
    char museum[70];
};

struct Node {
    ART_GALLERY data;
    Node* prev;
    Node* next;

    Node(){}
    Node(const ART_GALLERY& artwork) : data(artwork), prev(nullptr), next(nullptr) {}
};
