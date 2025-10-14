#include "list.h"
#include "checks.h"

using namespace std;

void ArtGalleryList::deletePaintingByNumber(int paintingNumber, int& m) {
    if (head == nullptr) {
        cout << "Список картин пуст!" << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    int count = 1;

    // Поиск картины по номеру и удаление
    while (current != nullptr) {
        if (count == paintingNumber) {
            if (previous == nullptr) {
                // Если удаляемый элемент - первый в списке
                head = current->next;
            }
            else {
                // Если удаляемый элемент - не первый в списке
                previous->next = current->next;
            }
            delete current;
            m--;
            cout << "Картина под номером " << paintingNumber << " удалена." << endl;
            return;
        }
        previous = current;
        current = current->next;
        count++;
    }

    // Если картина с указанным номером не найдена
    cout << "Картина с номером " << paintingNumber << " не найдена." << endl;
}

void ArtGalleryList::info(ArtGalleryList& list) {
    ART_GALLERY newArtwork;

    system("cls");

    do {
        cout << "Введите название картины: ";
        string input;
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "Ошибка! Название картины не может быть пустым или состоять только из пробелов." << endl;
            continue;
        }

        if (input.length() > 70) {
            cout << "Ошибка! Слишком длинное название." << endl;
        }
        else if (checkSpecialCharsNumbers(input.c_str())) {
            cout << "Ошибка! Строка содержит запрещенные символы." << endl;
        }
        else {
            strncpy_s(newArtwork.title, input.c_str(), strlen(input.c_str())); // Копирование строки в массив char
            break;
        }
    } while (true);

    do {
        cout << "Введите имя художника: ";
        string input;
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "Ошибка! Имя художника не может быть пустым или состоять только из пробелов." << endl;
            continue;
        }

        if (input.length() > 50) {
            cout << "Ошибка! Слишком длинное имя." << endl;
        }
        else if (checkSpecialChars(input.c_str())) {
            cout << "Ошибка! Строка содержит запрещенные символы." << endl;
        }
        else {
            strncpy_s(newArtwork.artist, input.c_str(), 50); // Копирование строки в массив char
            newArtwork.artist[input.length()] = '\0'; // Добавляем символ конца строки
            break;
        }
    } while (true);

    string choice1;
    while (true) {
        cout << "Введите год написания картины: ";
        getline(cin, choice1);
        bool isNumber = true;
        for (char c : choice1) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        if (!isNumber) {
            cout << "Неверное значение!" << endl;
            continue;
        }
        try {
            newArtwork.year = stoi(choice1);
            if (newArtwork.year > 2024 || newArtwork.year < 0) {
                cout << "Год введён неправильно!" << endl;
                continue;
            }
            break;
        }
        catch (const std::invalid_argument&) {
            cout << "Введено слишком большое число!" << endl;
            continue;
        }
        catch (const std::out_of_range&) {
            cout << "Введено слишком большое число!" << endl;
            continue;
        }
    }

    do {
        cout << "Направление искусства: ";
        string input;
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "Ошибка! Направление искусства не может быть пустым или состоять только из пробелов." << endl;
            continue;
        }

        if (input.length() > 40) {
            cout << "Ошибка! Слишком длинное название." << endl;
        }
        else if (checkSpecialChars(input.c_str())) {
            cout << "Ошибка! Строка содержит запрещенные символы." << endl;
        }
        else {
            strncpy_s(newArtwork.direction, input.c_str(), 40); // Копирование строки в массив char
            newArtwork.direction[input.length()] = '\0'; // Добавляем символ конца строки
            break;
        }
    } while (true);

    do {
        cout << "Введите название музея: ";
        string input;
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "Ошибка! Название музея не может быть пустым или состоять только из пробелов." << endl;
            continue;
        }

        if (input.length() > 70) {
            cout << "Ошибка! Слишком длинное название." << endl;
        }
        else if (checkSpecialCharsNumbers(input.c_str())) {
            cout << "Ошибка! Строка содержит запрещенные символы." << endl;
        }
        else {
            strncpy_s(newArtwork.museum, input.c_str(), 40); // Копирование строки в массив char
            newArtwork.museum[input.length()] = '\0'; // Добавляем символ конца строки
            break;
        }
    } while (true);

    list.addArtwork(newArtwork);
    system("cls");
}

void ArtGalleryList::output1() {
    system("cls");
    int i = 1;
    Node* current = head;
    while (current != nullptr) {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Название " << i << " картины: " << current->data.title << endl;
        cout << "Имя художника, который написал " << current->data.title << ": " << current->data.artist << endl;
        cout << "Год написания " << current->data.title << ": " << current->data.year << endl;
        cout << "Направление искусства " << current->data.title << ": " << current->data.direction << endl;
        cout << "В каком музее находится " << current->data.title << ": " << current->data.museum << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        // Увеличиваем значение i для следующей картины после вывода текущей
        i++;
        current = current->next;
    }
}

void ArtGalleryList::output2(int m) {
    system("cls");
    Node* current = head;
    int count = 0; // Добавляем счетчик для отслеживания количества выведенных элементов
    cout << string(190, '_') << endl;
    cout << "|" << setw(30) << "  Название картины  " << setw(21)
        << "|" << setw(23) << "    Художник    " << setw(11)
        << "|" << setw(13) << "  Год написания  "
        << "|" << setw(32) << "  Направление искусства  "
        << "|" << setw(38) << "Музей            " << setw(16) << "|" << endl;
    cout << string(190, '_') << endl;

    while (current != nullptr && count <= m) { // Добавляем условие для ограничения количества итераций
        cout << "|" << setw(50) << current->data.title
            << "|" << setw(33) << current->data.artist
            << "|" << setw(17) << current->data.year
            << "|" << setw(32) << current->data.direction
            << "|" << setw(53) << current->data.museum << "|" << endl;
        cout << string(190, '_') << endl;
        current = current->next; // Перемещаемся к следующему узлу
        count++; // Увеличиваем счетчик
    }
}

void ArtGalleryList::editPainting(char* paintingTitle, string& field) {
    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->data.title, paintingTitle) == 0) {
            string newData; // Максимальная длина данных
            if (field == "1") {
                cout << "Введите новое название картины: ";
                do {
                    getline(cin,newData);
                    if (newData.empty() || newData.find_first_not_of(' ') == string::npos) {
                        cout << "Ошибка! Название картины не может быть пустым или состоять только из пробелов." << endl;
                        continue;
                    }

                    if (newData.length() > 70) {
                        cout << "Ошибка! Слишком длинное название." << endl;
                    }
                    else if (checkSpecialCharsNumbers(newData.c_str())) {
                        cout << "Ошибка! Строка содержит запрещенные символы." << endl;
                    }
                    else {
                        strncpy_s(current->data.title, newData.c_str(), 70);
                        break;
                    }
                } while (true);

                cout << "Название картины " << paintingTitle << " было успешно изменено." << endl;
            }
            else if (field == "3") {
                cout << "Введите новый год написания: ";
                string choice;
                while (true) {
                    getline(cin,choice);
                    bool isNumber = true;
                    for (char c : choice) {
                        if (!isdigit(c)) {
                            isNumber = false;
                            break;
                        }
                    }
                    if (!isNumber) {
                        cout << "Неверное значение!" << endl;
                        continue;
                    }
                    int year = stoi(choice);
                    if (year > 2024 || year < 0) {
                        cout << "Год введён неправильно!" << endl;
                        continue;
                    }
                    current->data.year = year;
                    break;
                }
                cout << "Год написания картины " << paintingTitle << " был успешно изменён." << endl;
            }
            else if (field == "4") {
                cout << "Введите новое направление искусства: ";
                do {
                    getline(cin,newData);
                    if (newData.empty() || newData.find_first_not_of(' ') == string::npos) {
                        cout << "Ошибка! Название не может быть пустым или состоять только из пробелов." << endl;
                        continue;
                    }

                    if (newData.length() > 40) {
                        cout << "Ошибка! Слишком длинное название." << endl;
                    }
                    else if (checkSpecialCharsNumbers(newData.c_str())) {
                        cout << "Ошибка! Строка содержит запрещенные символы." << endl;
                    }
                    else {
                        strncpy_s(current->data.direction, newData.c_str(), 40);
                        break;
                    }
                } while (true);
                cout << "Направление искусства " << paintingTitle << " был успешно изменён." << endl;
            }
            else if (field == "2") {
                cout << "Введите новое имя художника: ";
                do {
                    getline(cin, newData);
                    if (newData.empty() || newData.find_first_not_of(' ') == string::npos) {
                        cout << "Ошибка! Имя художника не может быть пустым или состоять только из пробелов." << endl;
                        continue;
                    }

                    if (newData.length() > 50) {
                        cout << "Ошибка! Слишком длинное имя." << endl;
                    }
                    else if (checkSpecialCharsNumbers(newData.c_str())) {
                        cout << "Ошибка! Строка содержит запрещенные символы." << endl;
                    }
                    else {
                        strncpy_s(current->data.artist, newData.c_str(), 50);
                        break;
                    }
                } while (true);
                cout << "Имя художника картины " << paintingTitle << " было успешно изменено." << endl;
            }
            else if (field == "5") {
                cout << "Введите новое название музея: ";
                do {
                    getline(cin, newData);
                    if (newData.empty() || newData.find_first_not_of(' ') == string::npos) {
                        cout << "Ошибка! Название музея не может быть пустым или состоять только из пробелов." << endl;
                        continue;
                    }

                    if (newData.length() > 70) {
                        cout << "Ошибка! Слишком длинное название." << endl;
                    }
                    else if (checkSpecialCharsNumbers(newData.c_str())) {
                        cout << "Ошибка! Строка содержит запрещенные символы." << endl;
                    }
                    else {
                        strncpy_s(current->data.museum, newData.c_str(), 70);
                        break;
                    }
                } while (true);
                cout << "Музей картины " << paintingTitle << " был успешно изменён." << endl;
            }
            else {
                cout << "Выбор не определён!" << endl;
            }
            system("pause");
            return;
        }
        current = current->next;
    }
    cout << "Картина с названием " << paintingTitle << " не найдена." << endl;
    system("pause");
}

