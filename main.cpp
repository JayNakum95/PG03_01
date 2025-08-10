#include <iostream>
#include <string>
#include <chrono>

std::string zeroPad(int number, int width) {
    std::string str = std::to_string(number);
    while (str.length() < width) {
        str = "0" + str;
    }
    return str;
}

int main() {
    std::string a(1000000, 'a');  // 1,000,000文字で初期化

    std::cout << "1,000,000文字を移動とコピーで比較します。\n";
    std::cout << "Enterキーを押すと開始します...\n";
    std::cin.get();  // 計測開始トリガー

    // コピーの計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();
    int copy_time = static_cast<int>(
        std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count());

    // ムーブの計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);
    auto end_move = std::chrono::high_resolution_clock::now();
    int move_time = static_cast<int>(
        std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count());

    // 結果表示（7桁ゼロ埋め）
    std::cout << "\nコピー： " << zeroPad(copy_time, 7) << "μs\n";
    std::cout << "移動　： " << zeroPad(move_time, 7) << "μs\n";

    std::cout << "Press any key to continue . . .\n";
    std::cin.get();

    return 0;
}
