#include "list.h"

void ArtGalleryList::clear_DB(ArtGalleryList& list, int& m) {
    string choice2;
    system("cls");
    cout << "�� �������, ��� ������ �������� �������� ������?" << endl;
    cout << ">-> �� [1]" << endl;
    cout << ">-> ��� [2]" << endl;
    cin >> choice2;

    while (choice2 != "1" && choice2 != "2") {
        cout << "������������ ����. ����������, ������� 1 ��� 2." << endl;
        cin >> choice2;
    }

    int clear_choice = stoi(choice2);

    Node* current;

    switch (clear_choice) {
    case 1:
        m = 0;
        current = list.head;
            while (current != nullptr) {
                Node* next = current->next;
                // ��� ��� ART_GALLERY �� �������� ����������, �� �� ���������� delete ��� data
                delete current; // ������� ����
                current = next;
            }
            list.head = nullptr; // �������� ��������� �� ������ ������
            list.tail = nullptr; // �������� ��������� �� ����� ������
        system("cls");
        cout << "������ ���� ������� �������!" << endl;
        system("pause");
        break;
    case 2:
        break;
    }
}
