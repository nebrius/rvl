/*
Copyright (c) Bryan Hughes <bryan@nebri.us>

This file is part of RVL Arduino.

RVL Arduino is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RVL Arduino is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RVL Arduino.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include "./rvl.h"
#include "./rvl/logging.h"

namespace rvl {

LogLevel logLevel = LogLevel::Debug;

void setLogLevel(LogLevel newLevel) {
  logLevel = newLevel;
}

void log(const char *s) {
  Serial.print(s);
}

void log(const char *s, va_list argptr) {
  int bufferLength = strlen(s) * 3;
  char* str = new char[bufferLength];
  vsnprintf(str, bufferLength, s, argptr);
  Serial.print(str);
  delete str;
}

void error(const char *s, ...) {
  if (logLevel >= LogLevel::Error) {
    Serial.print("[error]: ");
    va_list argptr;
    va_start(argptr, s);
    log(s, argptr);
    Serial.println();
  }
}

void info(const char *s, ...) {
  if (logLevel >= LogLevel::Info) {
    Serial.print("[info ]: ");
    va_list argptr;
    va_start(argptr, s);
    log(s, argptr);
    Serial.println();
  }
}

void debug(const char *s, ...) {
  if (logLevel >= LogLevel::Debug) {
    Serial.print("[debug]: ");
    va_list argptr;
    va_start(argptr, s);
    log(s, argptr);
    Serial.println();
  }
}

}  // namespace rvl
