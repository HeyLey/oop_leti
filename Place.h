#ifndef PLACE_H
#define PLACE_H


enum Place { KITCHEN, BED_ROOM1, BED_ROOM2, BATH_ROOM, LIVING_ROOM, BALKON, ATTIC, UNKNOWN };


std::string placeToString(Place place) {
    switch (place) {
        case KITCHEN:
            return "kitchen";
        case BED_ROOM1:
            return "bed room 1";
        case BED_ROOM2:
            return "bed room 2";
        case BATH_ROOM:
            return "bath room";
        case LIVING_ROOM:
            return "living room";
        case BALKON:
            return "balkon";
        case ATTIC:
            return "attick";
        case UNKNOWN:
            return "UNKNOWN";
    }
}


#endif