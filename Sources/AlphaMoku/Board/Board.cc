#include <AlphaMoku/Board/Board.h>

#include <stdexcept>

namespace AlphaMoku
{
BoardView::BoardView(std::size_t _size, StoneType _current,
                     const std::vector<StoneType>& _board)
    : size(_size), current(_current), board(_board)
{
    // Do nothing
}

Board::Board(std::size_t size, bool renju)
    : size_(size), renju_(renju), board_(size * size)
{
    Clear();
}

void Board::Clear()
{
    std::fill(begin(board_), end(board_), StoneType::NONE);

    current_ = StoneType::BLACK;
}

std::size_t Board::GetSize() const
{
    return size_;
}

void Board::SetRenju(bool renju)
{
    renju_ = renju;
}

bool Board::IsRenju() const
{
    return renju_;
}

bool Board::IsValid(const Point& pt) const
{
    return IsOnBoard(pt) && IsEmpty(pt) && CheckRule(pt);
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

bool Board::CheckRule([[maybe_unused]] const Point& pt) const
{
    if (!renju_)
        return true;

    throw std::runtime_error("Renju is not supported now");
}

StoneType Board::CurrentPlayer() const
{
    return current_;
}

StoneType Board::OpponentPlayer() const
{
    return Opponent(current_);
}

StoneType Board::At(const Point& pt) const
{
    return board_[p2i(pt)];
}

BoardView::Ptr Board::MakeView() const
{
    return std::make_unique<BoardView>(size_, current_, board_);
}
}  // namespace AlphaMoku
