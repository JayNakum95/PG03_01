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
        {"Tokyo", "“Œ‹"}, {"Kanda", "_“c"}, {"Akihabara", "H—tŒ´"}, {"Okachimachi", "Œä“k’¬"}, {"Ueno", "ã–ì"},
        {"Uguisudani", "éò’J"}, {"Nippori", "“ú•é—¢"}, {"Tabata", "“c’["}, {"Komagome", "‹î"}, {"Sugamo", "‘ƒŠ›"}, {"Otsuka", "‘å’Ë"},
        {"Ikebukuro", "’r‘Ü"}, {"Mejiro", "–Ú”’"}, {"Takadanobaba", "‚“c”nê"}, {"Shin-Okubo", "V‘å‹v•Û"}, {"Shinjuku", "Vh"},
        {"Yoyogi", "‘ãX–Ø"}, {"Harajuku", "Œ´h"}, {"Shibuya", "a’J"}, {"Ebisu", "Œb”äõ"}, {"Meguro", "–Ú•"}, {"Gotanda", "ŒÜ”½“c"},
        {"Osaki", "‘åè"}, {"Shinagawa", "•iì"}, {"Tamachi", "“c’¬"}, {"Hamamatsucho", "•l¼’¬"}, {"Shimbashi", "V‹´"}, {"Yurakucho", "—LŠy’¬"}
    };
}

// 2019 station list (adds Nishi-Nippori)
std::list<std::pair<std::string, std::string>> make2019List() {
    auto stations = make1970List();
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (it->first == "Nippori") {
            ++it;
            stations.insert(it, { "Nishi-Nippori", "¼“ú•é—¢" });
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
            stations.insert(it, { "Takanawa Gateway", "‚—ÖƒQ[ƒgƒEƒFƒC" });
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
