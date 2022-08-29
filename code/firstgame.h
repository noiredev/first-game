#if !defined(FIRSTGAME_H)
#include "prototype_platform.h"

#define internal static
#define local_persist static
#define global_variable static

#define Pi32 3.14159265359f

#if FIRSTGAME_SLOW
#define Assert(Expression) if(!(Expression)) {*(int *)0 = 0;}
#else
#define Assert(Expression)
#endif

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

inline uint32_t SafeTruncateUInt64(uint64_t Value) {
    // TODO: Defines for maximum values
    Assert(Value <= 0xFFFFFFFF);
    uint32_t Result = (uint32_t)Value;
    return Result;
}

inline game_controller_input *GetController(game_input *Input, int ControllerIndex) {
    Assert(ControllerIndex < ArrayCount(Input->Controllers));
    game_controller_input *Result = &Input->Controllers[ControllerIndex];
    return Result;
}

#include "prototype_intrinsics.h"
#include "prototype_tile.h"

struct memory_arena {
    memory_index Size;
    uint8_t *Base;
    memory_index Used;
};

struct world {
    tile_map *TileMap;
};

struct game_state {
    memory_arena WorldArena;
    world *World;
    tile_map_position PlayerP;
};

#define FIRSTGAME_H
#endif