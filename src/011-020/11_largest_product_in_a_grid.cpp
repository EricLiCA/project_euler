// https://www.hackerrank.com/contests/projecteuler/challenges/euler011

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// 2D grid represented by 1D vector for cache optimization
auto getGrid(int rows, int columns) {
    auto values = rows * columns;
    std::vector<int> grid(values);
    std::copy_n(std::istream_iterator<int>(std::cin), values, grid.begin());

    if (std::cin.fail()) {
        throw std::runtime_error(
                "The input is invalid! Check the rows and columns in your input and that all numbers in the grid are integers between 0 and 100.");
    }
    return grid;
}

class LargestProductInAGrid {
public:
    LargestProductInAGrid(std::vector<int> &grid, int rows, int columns, int nAdjacents) : grid_(grid), rows_(rows),
                                                                                           columns_(columns),
                                                                                           nAdjacents_(nAdjacents) {}

    template<typename T>
    auto largestProductInAGrid() {
        T largestProduct = 0;

        for (auto row = 0; row < rows_; row++) {
            largestProduct = std::max(largestProduct,
                                      largestProductInASeries<T>(SeriesType::HORIZONTAL, row * columns_));
        }

        for (auto column = 0; column < columns_; column++) {
            largestProduct = std::max(largestProduct, largestProductInASeries<T>(SeriesType::VERTICAL, column));
            largestProduct = std::max(largestProduct, largestProductInASeries<T>(SeriesType::DIAGONAL_RIGHT, column));
            largestProduct = std::max(largestProduct, largestProductInASeries<T>(SeriesType::DIAGONAL_LEFT, column));
        }

        return largestProduct;
    }

private:
    enum SeriesType {
        HORIZONTAL, VERTICAL, DIAGONAL_RIGHT, DIAGONAL_LEFT
    };

    template<typename T>
    T largestProductInASeries(SeriesType type, int startingIndex) {
        int low = startingIndex, current = low;

        T currentProduct = initializeProductInASeries<T>(type, current);
        if (current < 0) return 0;
        T highestProduct = currentProduct;

        while (current >= 0) {
            if (currentProduct == 0) {
                while (grid_[low] != 0) low = nextIndex(type, low);
                low = nextIndex(type, low);
                current = low;
                currentProduct = initializeProductInASeries<T>(type, current);
            } else {
                currentProduct /= grid_[low];
                currentProduct *= grid_[current];

                low = nextIndex(type, low);
                current = nextIndex(type, current);
            }

            highestProduct = std::max(highestProduct, currentProduct);
        }

        return highestProduct;
    }

    template<typename T>
    T initializeProductInASeries(SeriesType type, int &index) {
        T product = 1;
        for (int i = 0; i < nAdjacents_ && product > 0; i++) {
            product *= grid_[index];
            index = nextIndex(type, index);
            if (index < 0) return 0;
        }
        return product;
    }

    int nextIndex(SeriesType type, int currentIndex) {

        auto canAdvanceRight = bool((currentIndex + 1) % columns_);
        if (type == SeriesType::HORIZONTAL && canAdvanceRight) {
            return currentIndex + 1;
        }

        auto canAdvanceDown = currentIndex / columns_ + 1 < rows_;
        if (type == SeriesType::VERTICAL && canAdvanceDown) {
            return currentIndex + columns_;
        }

        if (type == SeriesType::DIAGONAL_RIGHT && canAdvanceRight && canAdvanceDown) {
            return currentIndex + columns_ + 1;
        }

        auto canAdvanceLeft = bool(currentIndex % columns_);
        if (type == SeriesType::DIAGONAL_LEFT && canAdvanceLeft && canAdvanceDown) {
            return currentIndex + columns_ - 1;
        }

        return -1;
    }

    std::vector<int> grid_;
    int rows_;
    int columns_;
    int nAdjacents_;
};

int main() {
    const int rows = 20, columns = 20, nAdjacents = 4;
    auto grid = getGrid(rows, columns);
    LargestProductInAGrid solution(grid, rows, columns, nAdjacents);
    std::cout << solution.largestProductInAGrid<int>() << std::endl;
}