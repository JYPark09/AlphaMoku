#ifndef ALPHA_MOKU_BOARD_H
#define ALPHA_MOKU_BOARD_H

#include <AlphaMoku/Board/Common.h>

#include <memory>
#include <vector>

namespace AlphaMoku
{
class IRule;

struct BoardView
{
    using Ptr = std::unique_ptr<BoardView>;

    BoardView(std::size_t _size, StoneType _current,
              const std::vector<StoneType>& _board);

    std::size_t size;

    StoneType current;
    std::vector<StoneType> board;
};

class Board final
{
 public:
    Board(std::size_t size, bool renju = false);

    void Clear();

    std::size_t GetSize() const;

    void SetRenju(bool renju);
    bool IsRenju() const;

    bool IsValid(const Point& pt) const;
    bool IsOnBoard(const Point& pt) const;
    bool IsEmpty(const Point& pt) const;
    bool CheckRule(const Point& pt) const;

    StoneType CurrentPlayer() const;
    StoneType OpponentPlayer() const;

    StoneType At(const Point& pt) const;

    BoardView::Ptr MakeView() const;

 private:
    constexpr std::size_t p2i(const Point& pt) const
    {
        auto& [x, y] = pt;

        return x + y * size_;
    }

 private:
    std::size_t size_;
    bool renju_;

    StoneType current_;
    std::vector<StoneType> board_;
};
}  // namespace AlphaMoku

#endif  // ALPHA_MOKU_BOARD_H
