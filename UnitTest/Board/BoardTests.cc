#include "gtest/gtest.h"

#include <AlphaMoku/Board/Board.h>

using namespace AlphaMoku;

TEST(BoardTests, Initialize)
{
    Board board(15);

    EXPECT_EQ(board.GetSize(), 15);
    EXPECT_EQ(board.IsRenju(), false);

    EXPECT_EQ(board.CurrentPlayer(), StoneType::BLACK);
    EXPECT_EQ(board.OpponentPlayer(), StoneType::WHITE);

    for (std::size_t i = 0; i < 15; ++i)
        for (std::size_t j = 0; j < 15; ++j)
            EXPECT_EQ(board.At(std::make_tuple(i, j)), StoneType::NONE);
}

TEST(BoardTests, CheckNotRenju)
{
    Board board(15);

    EXPECT_EQ(board.IsValid(std::make_tuple(1, 1)), true);
    EXPECT_EQ(board.IsOnBoard(std::make_tuple(1, 1)), true);
    EXPECT_EQ(board.IsEmpty(std::make_tuple(1, 1)), true);
    EXPECT_EQ(board.CheckRule(std::make_tuple(1, 1)), true);
}

TEST(BoardTests, View)
{
    Board board(15);

    auto view = board.MakeView();

    EXPECT_EQ(view->size, 15);
    EXPECT_EQ(view->current, StoneType::BLACK);

    for (const auto& v : view->board)
        EXPECT_EQ(v, StoneType::NONE);
}
