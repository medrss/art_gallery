#pragma once
#include "node.h"
#include <string>
#include <limits>
#include <iostream>
#include "checks.h"

using namespace std;

class ArtGalleryList {
private:
    Node* head;
    Node* tail;
public:
    ArtGalleryList() : head(nullptr),tail(nullptr) {}

    void output1();
    void output2(int m);
    void info(ArtGalleryList& list);
    void clear_DB(ArtGalleryList& list, int& m);
    void save_DB(int m);
    void load_DB(int& m);
    void searchPainting(const char* query);
    void addArtwork(ART_GALLERY newArtwork) {
        Node* newNode = new Node(newArtwork); // ������� ����� ����
        newNode->data = newArtwork; // ��������� �������
        newNode->next = nullptr;    // ��������� ���� ���� �� ���������
        newNode->prev = tail;       // ���������� ���� - ��� ������� ����� ������

        if (tail != nullptr) {      // ���� ������ �� ������
            tail->next = newNode;   // ������������� ����� ���� ��� ��������� ��� ������
        }
        else {                    // ���� ������ ������
            head = newNode;         // ����� ���� ���������� ������� ������
        }
        tail = newNode;             // ����� ���� ������ - ����� ������
    }
    void deletePaintingByNumber(int paintingNumber, int& m);
    void setNodeDataAtPosition(int position, const ART_GALLERY& data);
    void FloydSort(int& m, int num_sort, int sort_choice);
    void heapify_title_up(int i, int& m);
    void heapify_title_down(int i, int& m);
    void heapify_museum_up(int i, int& m);
    void heapify_museum_down(int i, int& m);
    void heapify_direction_up(int i, int& m);
    void heapify_direction_down(int i, int& m);
    void heapify_artist_up(int i, int& m);
    void heapify_artist_down(int i, int& m);
    void shellSortByYear_up(int& m);
    void shellSortByYear_down(int& m);
    ART_GALLERY getNodeDataAtPosition(int position);

    void editPainting(char* paintingTitle, string& field);

private:
    Node* getNodeAtIndex(int index) {
        int count = 0;
        Node* current = head;

        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }

        return current;
    }
};



