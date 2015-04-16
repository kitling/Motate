#ifndef motate_pin_assignments_h
#define motate_pin_assignments_h

namespace Motate { 

    // UNO   
    _MAKE_MOTATE_PORT8(B, 'B'); // Copied from AvrPins.h
    _MAKE_MOTATE_PORT8(C, 'C');
    _MAKE_MOTATE_PORT8(D, 'D');

    _MAKE_MOTATE_PIN( 0, D, 'D', 0);
    _MAKE_MOTATE_PIN( 1, D, 'D', 1);
    _MAKE_MOTATE_PIN( 2, D, 'D', 2);
    _MAKE_MOTATE_PIN( 3, D, 'D', 3);
    _MAKE_MOTATE_PIN( 4, D, 'D', 4);
    _MAKE_MOTATE_PIN( 5, D, 'D', 5);
    _MAKE_MOTATE_PIN( 6, D, 'D', 6);
    _MAKE_MOTATE_PIN( 7, D, 'D', 7);
    _MAKE_MOTATE_PIN( 8, B, 'B', 0);
    _MAKE_MOTATE_PIN( 9, B, 'B', 1);
    _MAKE_MOTATE_PIN(10, B, 'B', 2);
    _MAKE_MOTATE_PIN(11, B, 'B', 3);
    _MAKE_MOTATE_PIN(12, B, 'B', 4);
    _MAKE_MOTATE_PIN(13, B, 'B', 5);
    _MAKE_MOTATE_PIN(14, C, 'C', 0);
    _MAKE_MOTATE_PIN(15, C, 'C', 1);
    _MAKE_MOTATE_PIN(16, C, 'C', 2);
    _MAKE_MOTATE_PIN(17, C, 'C', 3);
    _MAKE_MOTATE_PIN(18, C, 'C', 4);
    _MAKE_MOTATE_PIN(19, C, 'C', 5);

    // TODO: Add PWM and SPI pins.

} // namespace Motate

// We're putting this in to make the autocomplete work for XCode,
// since it doesn't understand the special syntax coming up.
#ifdef XCODE_INDEX
#include <Uno-pinout.h>
#endif

#ifdef MOTATE_BOARD
#define MOTATE_BOARD_PINOUT < MOTATE_BOARD-pinout.h >
#include MOTATE_BOARD_PINOUT
#else
#error Unknown board layout
#endif

#endif // motate_pin_assignments_h
