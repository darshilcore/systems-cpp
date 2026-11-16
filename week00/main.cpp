#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3};
    std::cout << v[2] << "\n";   // out of bounds on purpose
    return 0;
}
