#include "list.h"

void ArtGalleryList::searchPainting(const char* query) {
    Node* current = head;
    bool found = false; // Флаг для отслеживания наличия хотя бы одной картины, удовлетворяющей запросу

    while (current != nullptr) {
        if (strcmp(current->data.title, query) == 0 ||
            strcmp(current->data.artist, query) == 0 ||
            strcmp(current->data.direction, query) == 0 ||
            strcmp(current->data.museum, query) == 0 ||
            current->data.year == atoi(query)) {
            // Если хотя бы одно поле соответствует запросу, выводим информацию о картине
            cout << "Название: " << current->data.title << endl;
            cout << "Художник: " << current->data.artist << endl;
            cout << "Год написания: " << current->data.year << endl;
            cout << "Направление искусства: " << current->data.direction << endl;
            cout << "Музей: " << current->data.museum << endl;
            cout << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        // Если ни одна картина не соответствует запросу, выводим сообщение об ошибке
        cout << "Картина, соответствующая запросу \"" << query << "\", не найдена." << endl;
    }
}

void ArtGalleryList::FloydSort(int& m, int num_sort, int sort_choice) {
    if (sort_choice == 2) {
        if (num_sort == 1) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_title_down(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_title_down(0, j);
            }
        }
        else if (num_sort == 2) {
            shellSortByYear_down(m);
        }
        else if (num_sort == 3) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_artist_up(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_artist_down(0, j);
            }
        }
        else if (num_sort == 4) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_direction_down(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_direction_down(0, j);
            }
        }
        else if (num_sort == 5) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_museum_down(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_museum_down(0, j);
            }
        }
    }
    else if (sort_choice == 1) {
        if (num_sort == 1) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_title_up(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_title_up(0, j);
            }
        }
        else if (num_sort == 2) {
            shellSortByYear_up(m);
        }
        else if (num_sort == 3) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_artist_up(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_artist_up(0, j);
            }
        }
        else if (num_sort == 4) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_direction_up(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_direction_up(0, j);
            }
        }
        else if (num_sort == 5) {
            for (int i = m / 2 - 1; i >= 0; i--) {
                heapify_museum_up(i, m);
            }
            for (int j = m - 1; j >= 0; j--) {
                ART_GALLERY temp = getNodeDataAtPosition(0);
                setNodeDataAtPosition(0, getNodeDataAtPosition(j));
                setNodeDataAtPosition(j, temp);
                heapify_museum_up(0, j);
            }
        }
    }
}

void ArtGalleryList::heapify_title_down(int i, int& m) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).title, getNodeDataAtPosition(largest).title) > 0) {
        largest = left;
    }
    if (right < m && strcmp(getNodeDataAtPosition(right).title, getNodeDataAtPosition(largest).title) > 0) {
        largest = right;
    }
    if (largest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(largest));
        setNodeDataAtPosition(largest, swap);
        heapify_title_down(largest, m);
    }
}

void ArtGalleryList::heapify_title_up(int i, int& m) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).title, getNodeDataAtPosition(smallest).title) < 0) {
        smallest = left;
    }

    if (right < m && strcmp(getNodeDataAtPosition(right).title, getNodeDataAtPosition(smallest).title) < 0) {
        smallest = right;
    }

    if (smallest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(smallest));
        setNodeDataAtPosition(smallest, swap);
        heapify_title_up(smallest, m);
    }
}

void ArtGalleryList::heapify_artist_down(int i, int& m) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).artist, getNodeDataAtPosition(largest).artist) > 0) {
        largest = left;
    }
    if (right < m && strcmp(getNodeDataAtPosition(right).artist, getNodeDataAtPosition(largest).artist) > 0) {
        largest = right;
    }
    if (largest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(largest));
        setNodeDataAtPosition(largest, swap);
        heapify_artist_down(largest, m);
    }
}

void ArtGalleryList::heapify_artist_up(int i, int& m) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).artist, getNodeDataAtPosition(smallest).artist) < 0) {
        smallest = left;
    }

    if (right < m && strcmp(getNodeDataAtPosition(right).artist, getNodeDataAtPosition(smallest).artist) < 0) {
        smallest = right;
    }

    if (smallest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(smallest));
        setNodeDataAtPosition(smallest, swap);
        heapify_artist_up(smallest, m);
    }
}

void ArtGalleryList::heapify_direction_down(int i, int& m) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).artist, getNodeDataAtPosition(largest).artist) > 0) {
        largest = left;
    }
    if (right < m && strcmp(getNodeDataAtPosition(right).artist, getNodeDataAtPosition(largest).artist) > 0) {
        largest = right;
    }
    if (largest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(largest));
        setNodeDataAtPosition(largest, swap);
        heapify_direction_down(largest, m);
    }
}

void ArtGalleryList::heapify_direction_up(int i, int& m) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).direction, getNodeDataAtPosition(smallest).direction) < 0) {
        smallest = left;
    }

    if (right < m && strcmp(getNodeDataAtPosition(right).direction, getNodeDataAtPosition(smallest).direction) < 0) {
        smallest = right;
    }

    if (smallest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(smallest));
        setNodeDataAtPosition(smallest, swap);
        heapify_direction_up(smallest, m);
    }
}

void ArtGalleryList::heapify_museum_down(int i, int& m) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).museum, getNodeDataAtPosition(largest).museum) > 0) {
        largest = left;
    }
    if (right < m && strcmp(getNodeDataAtPosition(right).museum, getNodeDataAtPosition(largest).museum) > 0) {
        largest = right;
    }
    if (largest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(largest));
        setNodeDataAtPosition(largest, swap);
        heapify_museum_down(largest, m);
    }
}

void ArtGalleryList::heapify_museum_up(int i, int& m) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < m && strcmp(getNodeDataAtPosition(left).museum, getNodeDataAtPosition(smallest).museum) < 0) {
        smallest = left;
    }

    if (right < m && strcmp(getNodeDataAtPosition(right).museum, getNodeDataAtPosition(smallest).museum) < 0) {
        smallest = right;
    }

    if (smallest != i) {
        ART_GALLERY swap = getNodeDataAtPosition(i);
        setNodeDataAtPosition(i, getNodeDataAtPosition(smallest));
        setNodeDataAtPosition(smallest, swap);
        heapify_museum_up(smallest, m);
    }
}

ART_GALLERY ArtGalleryList::getNodeDataAtPosition(int position) {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current == nullptr) {
        // Обработка ошибки: элемент не найден, можно выбрасывать исключение или возвращать значение по умолчанию
        return ART_GALLERY(); // Возвращаем пустой объект ART_GALLERY
    }
    return current->data;
}

void ArtGalleryList::setNodeDataAtPosition(int position, const ART_GALLERY& data) {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current == nullptr) {
        // Обработка ошибки: элемент не найден
        return;
    }
    current->data = data;
}

void ArtGalleryList::shellSortByYear_up(int& m) {

    for (int gap = m / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < m; i++) {
            ART_GALLERY temp = getNodeDataAtPosition(i); // Получаем данные узла по индексу i
            int j = i;

            while (j >= gap && getNodeDataAtPosition(j - gap).year > temp.year) {
                setNodeDataAtPosition(j, getNodeDataAtPosition(j - gap)); // Заменяем данные узла на позиции j данными узла на позиции j - gap
                j -= gap;
            }

            setNodeDataAtPosition(j, temp); // Устанавливаем данные узла на позиции j равными temp
        }
    }
}

void ArtGalleryList::shellSortByYear_down(int& m) {
    for (int gap = m / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < m; i++) {
            ART_GALLERY temp = getNodeDataAtPosition(i); // Получаем данные узла по индексу i
            int j = i;
            while (j >= gap && getNodeDataAtPosition(j - gap).year < temp.year) {
                setNodeDataAtPosition(j, getNodeDataAtPosition(j - gap)); // Заменяем данные узла на позиции j данными узла на позиции j - gap
                j -= gap;
            }
            setNodeDataAtPosition(j, temp); // Устанавливаем данные узла на позиции j равными temp
        }
    }
}