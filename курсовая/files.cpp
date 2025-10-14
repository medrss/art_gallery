#include "files.h"

using namespace std;

bool isValidFileName(const string& name) {
    string forbiddenCharsfile = "\\/:*?\"<>|+ ";
    if (name.find_first_of(forbiddenCharsfile) != string::npos || name.back() == '.' || name.back() == ' ') {
        return false;
    }
    return true;
}

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void ArtGalleryList::save_DB(int m) {
    system("cls");
    string name_file;
    cout << "Введите имя файла, в который вы хотите занести данные: ";
    getline(cin, name_file);

    // Открытие файла для добавления данных
    ofstream fout(name_file + ".txt", ios::app);

    if (fout.is_open()) {
        Node* current = head;
        while (current != nullptr) {
            fout << current->data.title << endl;
            fout << current->data.artist << endl;
            fout << current->data.year << endl;
            fout << current->data.direction << endl;
            fout << current->data.museum << endl;
            fout << "---------------------------------" << endl;
            m++;
            current = current->next;
        }
        fout.close();
        cout << "Данные успешно добавлены в файл!" << endl;
    }
    else {
        cout << "Ошибка при открытии файла для записи." << endl;
    }
    system("pause");
}

void new_DB()
{
    string n;
    string name_file;

    system("cls");

    cout << " Введите имя файла." << endl;
    cout << " Имя файла не должно содержать следующих символов \\ / : * ? \" < > | + \n Пробел и точка также не допускаются в конце имени файла." << endl;

    do {
        getline(cin,name_file);
        if (!isValidFileName(name_file)) {
            cout << "Некорректное имя файла! Попробуйте еще раз." << endl;
        }
    } while (!isValidFileName(name_file));

    if (fileExists(name_file + ".txt")) {
        system("cls");
        cout << "Файл с таким именем уже существует!" << endl;
        system("pause");
    }
    else {
        ofstream fout(name_file + ".txt");
        system("cls");
        cout << "Файл создан!" << endl;
        system("pause");
    }
}

void ArtGalleryList::load_DB(int& m) {
    string line;
    ifstream fin;
    string file;
    int tempm = 0;
    system("cls");
    cout << "Введите имя файла, из которого хотите считать данные: ";
    getline(cin,file);
    fin.open(file + ".txt", ios_base::in);
    if (!fin.is_open()) {
        cout << "\nОшибка открытия файла..." << endl;
        system("pause");
        return;
    }
    else {
        while (getline(fin, line)) {
            if (line == "---------------------------------") { // Пропускаем разделительную строку
                tempm++;
                continue;
            }
        }
        fin.clear();
        fin.seekg(0, ios::beg);
        for (int i = 0; i < tempm; i++) {
            ART_GALLERY tempData;
            fin.getline(tempData.title, 70);
            fin.getline(tempData.artist, 50);
            fin >> tempData.year;
            fin.ignore();
            fin.getline(tempData.direction, 40);
            fin.getline(tempData.museum, 70);
            addArtwork(tempData); // Добавляем новый узел в список
            getline(fin, line); // Пропускаем разделительную строку после каждой записи
        }
        m = m + tempm;
        system("cls");
        cout << "Данные считаны из файла " << (file + ".txt") << endl;
        system("pause");
    }
    fin.close();
}

void remove_DB()
{
    system("cls");
    string name_file;
    cout << "Введите имя файла, который вы хотите удалить: ";
    getline(cin,name_file);
    system("cls");
    if (remove((name_file + ".txt").c_str()) == 0) {
        cout << "Файл был успешно удалён!" << endl;
    }
    else {
        cout << "Произошла ошибка! Файл не найден." << endl;
    }
    system("pause");
}

void read_DB() {
    system("cls");
    string line;
    string name_file;

    cout << "Введите имя файла, который вы хотите прочитать: ";
    getline(cin,name_file);

    ifstream fromfile(name_file + ".txt"); // Открытие файла для чтения

    if (fromfile.is_open()) {
        system("cls");
        cout << "Содержимое файла " << name_file << ".txt:" << endl;

        while (getline(fromfile, line)) {
            cout << line << endl; // Вывод строки из файла
        }

        fromfile.close(); // Закрытие файла
    }
    else {
        cout << "Ошибка при открытии файла. Проверьте правильность имени файла." << endl;
    }

    system("pause");
}
