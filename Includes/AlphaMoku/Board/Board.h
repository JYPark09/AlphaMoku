#ifndef ALPHA_MOKU_BOARD_H
#define ALPHA_MOKU_BOARD_H

#include <AlphaMoku/Board/Common.h>

#include <vector>

namespace AlphaMoku
{
class Board final
{
 public:
    Board(std::size_t size);

    void Clear();

    bool IsValid(const Point& pt) const;
    bool IsOnBoard(const Point& pt) const;
    bool IsEmpty(const Point& pt) const;

 private:
    constexpr std::size_t p2i(const Point& pt) const
    {
        auto& [x, y] = pt;
    
        return x + y * size_;
    }

 private:
    std::size_t size_;

    std::vector<StoneType> board_;
};
}  // namespace AlphaMoku

#endif  // ALPHA_MOKU_BOARD_H
