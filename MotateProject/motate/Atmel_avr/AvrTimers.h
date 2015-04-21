/*
  utility/AvrTimers.h - Library for the Arduino-compatible Motate system
  http://github.com/synthetos/motate/

  Copyright (c) 2013 Robert Giseburt

	This file is part of the Motate Library.

	This file ("the software") is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License, version 2 as published by the
	Free Software Foundation. You should have received a copy of the GNU General Public
	License, version 2 along with the software. If not, see <http://www.gnu.org/licenses/>.

	As a special exception, you may use this file as part of a software library without
	restriction. Specifically, if other files instantiate templates or use macros or
	inline functions from this file, or you compile this file and link it with  other
	files to produce an executable, this file does not by itself cause the resulting
	executable to be covered by the GNU General Public License. This exception does not
	however invalidate any other reasons why the executable file might be covered by the
	GNU General Public License.

	THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
	WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
	SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
	OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef AVRTIMERS_H_ONCE
#define AVRTIMERS_H_ONCE

#include <avr/io.h>
#include <util/atomic.h>

namespace Motate {
    enum TimerMode {
        kTimerUp           = 0,
	kTimerUpToMatch    = 1,
	kTimerUpDown       = 2,
	kTimerInputCapture = 3,
    };
	
    enum TimerChannelOutputOptions {
        kOutputDisconnected = 0,
	kToggleOnMatch      = 1,
	kClearOnMatch       = 2,
	kSetOnMatch         = 3,
    };
    
    enum TimerChannelInterruptOptions {
        kInterruptsOff       = 0,
        kInterruptOnMatchA   = 1<<0,
	kInterruptOnMatchB   = 1<<1,
	kInterruptOnOverflow = 1<<2,
	kSetOnMatch          = 1<<3,
    };

    struct Timer<SysTickTimerNum> {
        static volatile uint32_t _motateTickCount;

        Timer() { init(); };
//        Timer(const TimerMode mode, const uint32_t freq) {
//            _init();
//        };


        /*
         * Code originally from rtc.c of the TinyG project:
         * rtc_init() - initialize and start the clock
         *
         * This routine follows the code in app note AVR1314.
         */

        void init() {
            _motateTickCount = 0;

            OSC.CTRL |= OSC_RC32KEN_bm;							// Turn on internal 32kHz.
            do {} while ((OSC.STATUS & OSC_RC32KRDY_bm) == 0);	// Wait for 32kHz oscillator to stabilize.
            do {} while (RTC.STATUS & RTC_SYNCBUSY_bm);			// Wait until RTC is not busy

            CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCEN_bm;	// Set internal 32kHz osc as RTC clock source
            do {} while (RTC.STATUS & RTC_SYNCBUSY_bm);			// Wait until RTC is not busy

            // the following must be in this order or it doesn;t work
            RTC.PER = 0xfffe;	// set overflow period to maximum -- we'll use the count + out own overflow counter
            RTC.CNT = 0;
            RTC.COMP = 0xfffe;
            RTC.CTRL = RTC_PRESCALER_DIV1_gc;					// no prescale (1x)
            RTC.INTCTRL = RTC_OVFINTLVL_MED_gc;                 // interrupt on compare
        };

        // Return the current value of the counter. This is a fleeting thing...
        uint32_t getValue() {
            return _motateTickCount + RTC.CNT;
        };

        void _increment() { // called on overflow, every 0xffff ms
            _motateTickCount += 0xffff;
        };

        // Placeholder for user code.
        static void interrupt() __attribute__ ((weak));
    };
    extern Timer<SysTickTimerNum> SysTickTimer;

    static const timer_number WatchDogTimerNum = 0xFE;
    template <>
    struct Timer<WatchDogTimerNum> {

        Timer() { init(); };
//        Timer(const TimerMode mode, const uint32_t freq) {
//            init();
//            //			setModeAndFrequency(mode, freq);
//        };

        void init() {
        };

        void disable() {
        // FIXME
//            WDT->WDT_MR = WDT_MR_WDDIS;
        };

        void checkIn() {

        };

        // Placeholder for user code.
        static void interrupt();
    };
    extern Timer<WatchDogTimerNum> WatchDogTimer;

    // Provide a Arduino-compatible blocking-delay function
    inline void delay( uint32_t microseconds )
    {
        uint32_t doneTime = SysTickTimer.getValue() + microseconds;

        do
        {
            // Huh! No __NOP() macro. Oh well...
            __asm__ __volatile__ ("nop");
        } while ( SysTickTimer.getValue() < doneTime );
    }

}
#endif /* end of include guard: AVRTIMERS_H_ONCE */
