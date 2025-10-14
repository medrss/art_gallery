#include <cstdlib>
#include "menu.h"
#include "files.h"
#include "list.h"
#include "clear.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ART_GALLERY* List = new ART_GALLERY;

    int m = 0;
    int choice = 1;
    string choice_str;
    int variant; //выбор в меню
    ArtGalleryList list;
    char paintingTitle[30];
    char query[30];
    string field;
    int paintingNumber;
    string paintingNumber_str;

    do {
        print_menu();
        variant = get_variant();
        switch (variant) {

        case 1:
        {
            int choice = 1; // Инициализируем choice значением 1, чтобы цикл выполнился хотя бы один раз

            while (choice == 1) {
                m++;
                list.info(list);
                system("cls");
                cout << "Добавить ещё одну картину в галерею?" << endl;
                cout << ">-> да [1]" << endl;
                cout << ">-> нет [0]" << endl;
                getline(cin,choice_str);

                while (choice_str != "0" && choice_str != "1") {
                    cout << "Некорректный ввод. Пожалуйста, введите 0 или 1." << endl;
                    getline(cin, choice_str);
                }

                choice = stoi(choice_str); // Преобразование строки в целое число
            }

            system("cls");
            cout << "Данные записаны!" << endl;
            system("pause");
        }
        break;

        case 2:
        {
            system("cls");
            cout << "Как вы хотите отобразить галерею?" << endl;
            cout << ">-> Списком [1]" << endl;
            cout << ">-> Таблицей [2]" << endl;
            string num;
            getline(cin,num);

            while (num != "1" && num != "2") {
                cout << "Некорректный ввод. Пожалуйста, введите 1 или 2." << endl;
                getline(cin, num);
            }

            int num_choice = stoi(num);

            if (num_choice == 1) {
                system("cls");
                if (m == 0) {
                    cout << "В галерее нет картин!!\nВы можете ввести новую информацию или выгрузить её из готового файла!\n\n";
                    system("pause");
                }
                else {
                    system("cls");
                    
                    for (int i = 0; i <= m; i++) {
                        list.output1();
                    };
                    system("pause");
                    break;
                }
            }
            else if (num_choice == 2) {
                system("cls");
                if (m == 0) {
                    cout << "В галерее нет картин!!\nВы можете ввести новую информацию или выгрузить её из готового файла!\n\n";
                    system("pause");
                }
                else {
                    system("cls");
                    list.output2(m);
                    system("pause");
                }
                break;
            }
            break;
        }
        case 3:
            list.clear_DB(list, m);
            break;

        case 4: {
            system("cls");
            cout << "Введите название картины, элемент которой вы хотите отредактировать" << endl;
            cin.getline(paintingTitle, 30);
            system("cls");
            cout << "Введите элемент, который вы хотите отредактировать:" << endl;
            cout << "Название картины       -->>  [1]" << endl;
            cout << "Имя художника          -->>  [2]" << endl;
            cout << "Год написания          -->>  [3]" << endl;
            cout << "Направление искусства  -->>  [4]" << endl;
            cout << "Название музея         -->>  [5]" << endl;
            getline(cin,field);
            system("cls");
            list.editPainting(paintingTitle, field);
            break;
        }
        case 5: {
            system("cls");
            while (true) {
                cout << "Введите номер картины, которую вы хотите удалить: ";
                getline(cin,paintingNumber_str);

                bool isNumber = true;
                for (char c : paintingNumber_str) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                    }
                }
            if (!isNumber) {
                cout << "Неверное значение!" << endl;

                continue;
            }

            paintingNumber = stoi(paintingNumber_str);
            break;
            }

                list.deletePaintingByNumber(paintingNumber, m);
                system("pause");
                break;
            }
        case 6:
            new_DB();
            break;

        case 7:
            remove_DB();
            break;

        case 8:
            list.save_DB(m);
            break;

        case 9:
            list.load_DB(m);
            break;

        case 10:
            read_DB();
            break;

        case 11:
            system("cls");
            cout << "Введите информацию о картине, чтобы найти её:" << endl;
            cin.getline(query, 30);
            system("cls");
            list.searchPainting(query);
            system("pause");
            break;

        case 12:
            system("cls");

            if (m == 0) {
                cout << "В галерее нет картин!!" << endl;
                system("pause");
                break;
            }

            string sort;
            cout << "Каким образом вы хотите отсортировать картины?" << endl;
            cout << "По названию                |1|" << endl;
            cout << "По году написания          |2|" << endl;
            cout << "По имени художника         |3|" << endl;
            cout << "По направлению искусства   |4|" << endl;
            cout << "По музею                   |5|" << endl;

            getline(cin,sort);
            while (sort != "1" && sort != "2" && sort != "3" && sort != "4" && sort != "5") {
                cout << "Некорректный ввод." << endl;
                getline(cin, sort);
            }

            int num_sort = stoi(sort);

            system("cls");
            cout << "Как вы хотите отсортировать картины?" << endl;
            cout << "В порядке возрастания   --> [1]" << endl;
            cout << "В порядке убывания      --> [2]" << endl;

            string sort_str;
            getline(cin, sort_str);

            while (sort_str != "1" && sort_str != "2") {
                cout << "Неверный выбор!" << endl;
                getline(cin, sort_str);
            }

            int sort_choice = stoi(sort_str);

            system("cls");
            list.FloydSort(m, num_sort, sort_choice);
            cout << "Картины были отсортированы!" << endl;
            system("pause");
        }
    } while (variant != 0);
        return 0;
    }