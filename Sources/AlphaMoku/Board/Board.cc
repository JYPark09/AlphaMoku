#include <AlphaMoku/Board/Board.h>

namespace AlphaMoku
{
BoardView::BoardView(std::size_t _size, StoneType _current,
                     const std::vector<StoneType>& _board)
    : size(_size), current(_current), board(_board)
{
    // Do nothing
}

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

BoardView::Ptr Board::MakeView() const
{
    return std::make_unique<BoardView>(size_, current_, board_);
}
}  // namespace AlphaMoku
