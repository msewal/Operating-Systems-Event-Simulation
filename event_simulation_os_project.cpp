#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    srand(time(0));

    std::queue<int> olayKuyrugu;
    int zaman = 1;

    std::cout << "Simülasyon başladı" << std::endl;

    while (zaman <= 20) {
        if (rand() % 3 == 0) {
            olayKuyrugu.push(zaman);
        }

        if (!olayKuyrugu.empty() && olayKuyrugu.front() == zaman) {
            std::cout << "zaman: " << std::setw(3) << std::setfill('0') << zaman << " s: olay oldu." << std::endl;
            olayKuyrugu.pop();
        }

        zaman++;
    }

    return 0;
}