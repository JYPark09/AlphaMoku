#include <AlphaMoku/Board/Board.h>

namespace AlphaMoku
{
Board::Board(std::size_t size) : size_(size)
{
    Clear();
}

void Board::Clear()
{
    std::fill(begin(board_), end(board_), StoneType::NONE);
}

bool Board::IsValid(const Point& pt) const
{
    return IsOnBoard(pt) && IsEmpty(pt);
}

bool Board::IsOnBoard(const Point& pt) const
{
    auto& [x, y] = pt;

    return (x < size_ && y < size_);
}

bool Board::IsEmpty(const Point& pt) const
{
    return board_[p2i(pt)] == StoneType::NONE;
}
}  // namespace AlphaMoku
