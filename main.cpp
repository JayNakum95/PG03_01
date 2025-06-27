#include <iostream>
#include <list>
#include <string>
#include <utility>

// Prints the list of stations with a clear heading and numbering
void printList(const std::list<std::pair<std::string, std::string>>& stations, const std::string& year) {
    std::cout << "\n============================================\n";
    std::cout << "         YAMANOTE LINE STATIONS (" << year << ")\n";
    std::cout << "============================================\n";

    int index = 1;
    for (const auto& station : stations) {
        std::cout << "    JY" << index++ << ". " << station.first << " (" << station.second << ")\n";
    }
    std::cout << "============================================\n";
}

// 1970 station list
std::list<std::pair<std::string, std::string>> make1970List() {
    return {
        {"Tokyo", "����"}, {"Kanda", "�_�c"}, {"Akihabara", "�H�t��"}, {"Okachimachi", "��k��"}, {"Ueno", "���"},
        {"Uguisudani", "��J"}, {"Nippori", "���闢"}, {"Tabata", "�c�["}, {"Komagome", "�"}, {"Sugamo", "����"}, {"Otsuka", "���"},
        {"Ikebukuro", "�r��"}, {"Mejiro", "�ڔ�"}, {"Takadanobaba", "���c�n��"}, {"Shin-Okubo", "�V��v��"}, {"Shinjuku", "�V�h"},
        {"Yoyogi", "��X��"}, {"Harajuku", "���h"}, {"Shibuya", "�a�J"}, {"Ebisu", "�b���"}, {"Meguro", "�ڍ�"}, {"Gotanda", "�ܔ��c"},
        {"Osaki", "���"}, {"Shinagawa", "�i��"}, {"Tamachi", "�c��"}, {"Hamamatsucho", "�l����"}, {"Shimbashi", "�V��"}, {"Yurakucho", "�L�y��"}
    };
}

// 2019 station list (adds Nishi-Nippori)
std::list<std::pair<std::string, std::string>> make2019List() {
    auto stations = make1970List();
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (it->first == "Nippori") {
            ++it;
            stations.insert(it, { "Nishi-Nippori", "�����闢" });
            break;
        }
    }
    return stations;
}

// 2022 station list (adds Takanawa Gateway)
std::list<std::pair<std::string, std::string>> make2022List() {
    auto stations = make2019List();
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (it->first == "Shinagawa") {
            ++it;
            stations.insert(it, { "Takanawa Gateway", "���փQ�[�g�E�F�C" });
            break;
        }
    }
    return stations;
}

int main() {
    auto list1970 = make1970List();
    auto list2019 = make2019List();
    auto list2022 = make2022List();

    printList(list1970, "1970");
    printList(list2019, "2019");
    printList(list2022, "2022");

    return 0;
}
