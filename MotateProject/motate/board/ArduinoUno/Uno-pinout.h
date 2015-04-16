/*
 * http://github.com/synthetos/motate/
 *
 * Copyright (c) 2015 Robert Giseburt
 * Copyright (c) 2015 Alden S. Hart Jr.
 *
 * This file is part of the Motate Library.
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software. If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef uno_pinout_h
#define uno_pinout_h

#include <MotatePins.h>

namespace Motate {
    pin_number kSerial_RX = 0;
    pin_number kSerial_TX = 1;

    pin_number kSerial0_RX = 0;
    pin_number kSerial0_TX = 1;

    pin_number kI2C_SDAPinNumber = 18; //Analog 4
    pin_number kI2C_SCLPinNumber = 19; //Analog 5

    /* pin_number kSPI_SCKPinNumber                =  76; //TODO: Find the pins for these.
     * pin_number kSPI_MISOPinNumber               =  74;
     * pin_number kSPI_MOSIPinNumber               =  75;
     * pin_number kSPI_CS0PinNumber                =  77;
     * pin_number kSPI_CS1PinNumber                =  65;
     * pin_number kSPI_CS2PinNumber                =  52;
     * pin_number kSPI_CS3PinNumber                =  78;
     *
     * pin_number kSPI0_SCKPinNumber               =  76;
     * pin_number kSPI0_MISOPinNumber              =  74;
     * pin_number kSPI0_MOSIPinNumber              =  75;
     * pin_number kSPI0_CS0PinNumber               =  77;
     * pin_number kSPI0_CS1PinNumber               =  68;
     * pin_number kSPI0_CS2PinNumber               =  52;
     * pin_number kSPI0_CS3PinNumber               =  78;
     */
    
    pin_number kLED1_PinNumber = 13;
    // pin_number kLED2_PinNumber = 72; //Not sure what pins these are yet. TODO.
    // pin_number kLED3_PinNumber = 73;

    // pin_number kLED_USBRXPinNumber = 72; //Same here. TODO.
    // pin_number kLED_USBTXPinNumber = 73;

    //The two others from Due don't make sense to me right now. TODO?
} // namespace Motate

#endif
