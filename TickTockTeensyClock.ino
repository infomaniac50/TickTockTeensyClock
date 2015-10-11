// Copyright (C) 2015 Derek Chafin

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public
// License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <SimpleTimer.h>
#include <LiquidCrystal.h>

#include <Time.h>

#include "runtime.h"
#include "clock.h"
#include "display.h"

int function = 0;
SimpleTimer timer;

void setup()
{
  // Pin 13 is a floater so explicitly turn it off.
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  // Set backlight brightness
  pinMode(BACKLIGHT_PWM_PIN, OUTPUT);

  Serial.begin(9600);

  Clock::boot();

  Display::boot();
  Display::brightness(DEFAULT_BRIGHTNESS);

  Runtime::banner();


  timer.setInterval(UPDATETIME_INTERVAL, Clock::update);

  timer.setInterval(STEP_DURATION, step);
  timer.setInterval(DISPLAY_INTERVAL, print);
}

void loop()
{
  timer.run();

  if (Serial.available()) {
      Clock::set(processSyncMessage());
  }
}

// echo -n "T$(date +"%s")"
unsigned long processSyncMessage() {
  unsigned long pctime = 0L;

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     return pctime;
     if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
       pctime = 0L; // return 0 to indicate that the time is not valid
     }
  }
  return pctime;
}

void step()
{
  function = ++function % 1;
}

void print()
{
  switch (function)
  {
    case 0:
      // Display Current Time
      Clock::printDateTime();
      break;
    default:
      break;
  }
}

