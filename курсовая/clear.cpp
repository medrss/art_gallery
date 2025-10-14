#include "list.h"

void ArtGalleryList::clear_DB(ArtGalleryList& list, int& m) {
    string choice2;
    system("cls");
    cout << "Вы уверены, что хотите очистить введённые данные?" << endl;
    cout << ">-> Да [1]" << endl;
    cout << ">-> Нет [2]" << endl;
    cin >> choice2;

    while (choice2 != "1" && choice2 != "2") {
        cout << "Некорректный ввод. Пожалуйста, введите 1 или 2." << endl;
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
                // Так как ART_GALLERY не является указателем, мы не используем delete для data
                delete current; // Удаляем узел
                current = next;
            }
            list.head = nullptr; // Обнуляем указатель на начало списка
            list.tail = nullptr; // Обнуляем указатель на конец списка
        system("cls");
        cout << "Данные были успешно очищены!" << endl;
        system("pause");
        break;
    case 2:
        break;
    }
}
