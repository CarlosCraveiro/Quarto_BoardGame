#pragma once

#include <iostream>

/* Note:
 *      Each piece has four characteristics:
 *      
 *      - Height (Tall or Short);
 *      - Color (Light or Dark);
 *      - Geometry (Square or Circular);
 *      - Top Characteristic (Hollow-top or Solid-top);
 */

union Piece {
    int code;

    struct {
        unsigned int height : 1;
        unsigned int color : 1;
        unsigned int geometry : 1;
        unsigned int top : 1;
    };

    enum Characteristics {
        Short = 0,
        Tall = 1,
        Light = 0,
        Dark = 1,
        Circular = 0,
        Square = 1,
        Solid = 0,
        Hollowed = 1
    };
};

auto operator<<(std::ostream& os, const Piece& piece) -> std::ostream&
{
    if(piece.top) {
        os << "Hollowed-top";
    
    } else {
        os << "Solid-top";
    }
    
    if(piece.height) {
        os << " Tall";
    
    } else {
        os << " Short";
    }

    if(piece.color) {
        os << " Dark";
    
    } else {
        os << " Light";
    }

    if(piece.geometry) {
        os << " Square";
    
    } else {
        os << " Circular";
    }
    return os << " piece";
}
