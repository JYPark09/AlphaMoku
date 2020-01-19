#ifndef ALPHA_MOKU_STONE_H
#define ALPHA_MOKU_STONE_H

#include <tuple>

namespace AlphaMoku
{
enum class StoneType
{
    NONE,
    BLACK,
    WHITE
};

constexpr StoneType Opponent(StoneType type)
{
    switch (type)
    {
        case StoneType::BLACK:
            return StoneType::WHITE;
        case StoneType::WHITE:
            return StoneType::BLACK;
        default:
            return StoneType::NONE;
    }
}

using Point = std::tuple<std::size_t, std::size_t>;
}  // namespace AlphaMoku

#endif  // ALPHA_MOKU_STONE_H
