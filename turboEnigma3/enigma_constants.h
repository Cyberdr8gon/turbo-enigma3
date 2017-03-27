#pragma once


// constants for rendering
const int TILE_SQUARE_SIDE_LENGTH = 32;
const int SCREEN_WIDTH = TILE_SQUARE_SIDE_LENGTH * 48;
const int SCREEN_HEIGHT = TILE_SQUARE_SIDE_LENGTH * 30;

//constants for map generation
const int Y_MAX_MAP_SIZE = 200;
const int X_MAX_MAP_SIZE = 300;




// pressable buttons
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

