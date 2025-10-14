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
    cout << "������� ��� �����, � ������� �� ������ ������� ������: ";
    getline(cin, name_file);

    // �������� ����� ��� ���������� ������
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
        cout << "������ ������� ��������� � ����!" << endl;
    }
    else {
        cout << "������ ��� �������� ����� ��� ������." << endl;
    }
    system("pause");
}

void new_DB()
{
    string n;
    string name_file;

    system("cls");

    cout << " ������� ��� �����." << endl;
    cout << " ��� ����� �� ������ ��������� ��������� �������� \\ / : * ? \" < > | + \n ������ � ����� ����� �� ����������� � ����� ����� �����." << endl;

    do {
        getline(cin,name_file);
        if (!isValidFileName(name_file)) {
            cout << "������������ ��� �����! ���������� ��� ���." << endl;
        }
    } while (!isValidFileName(name_file));

    if (fileExists(name_file + ".txt")) {
        system("cls");
        cout << "���� � ����� ������ ��� ����������!" << endl;
        system("pause");
    }
    else {
        ofstream fout(name_file + ".txt");
        system("cls");
        cout << "���� ������!" << endl;
        system("pause");
    }
}

void ArtGalleryList::load_DB(int& m) {
    string line;
    ifstream fin;
    string file;
    int tempm = 0;
    system("cls");
    cout << "������� ��� �����, �� �������� ������ ������� ������: ";
    getline(cin,file);
    fin.open(file + ".txt", ios_base::in);
    if (!fin.is_open()) {
        cout << "\n������ �������� �����..." << endl;
        system("pause");
        return;
    }
    else {
        while (getline(fin, line)) {
            if (line == "---------------------------------") { // ���������� �������������� ������
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
            addArtwork(tempData); // ��������� ����� ���� � ������
            getline(fin, line); // ���������� �������������� ������ ����� ������ ������
        }
        m = m + tempm;
        system("cls");
        cout << "������ ������� �� ����� " << (file + ".txt") << endl;
        system("pause");
    }
    fin.close();
}

void remove_DB()
{
    system("cls");
    string name_file;
    cout << "������� ��� �����, ������� �� ������ �������: ";
    getline(cin,name_file);
    system("cls");
    if (remove((name_file + ".txt").c_str()) == 0) {
        cout << "���� ��� ������� �����!" << endl;
    }
    else {
        cout << "��������� ������! ���� �� ������." << endl;
    }
    system("pause");
}

void read_DB() {
    system("cls");
    string line;
    string name_file;

    cout << "������� ��� �����, ������� �� ������ ���������: ";
    getline(cin,name_file);

    ifstream fromfile(name_file + ".txt"); // �������� ����� ��� ������

    if (fromfile.is_open()) {
        system("cls");
        cout << "���������� ����� " << name_file << ".txt:" << endl;

        while (getline(fromfile, line)) {
            cout << line << endl; // ����� ������ �� �����
        }

        fromfile.close(); // �������� �����
    }
    else {
        cout << "������ ��� �������� �����. ��������� ������������ ����� �����." << endl;
    }

    system("pause");
}
