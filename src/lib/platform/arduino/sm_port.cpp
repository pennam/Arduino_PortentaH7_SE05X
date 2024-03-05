/*
  This file is part of the Arduino_PortentaH7_SE05X library.

  Copyright (c) 2024 Arduino SA

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "../../platform/arduino/sm_port.h"
#include <stdarg.h>

void smlog_print(const char *format, ...) {
    char debug_buf[1024];
    va_list argptr;
    va_start(argptr, format);
    vsprintf(debug_buf, format, argptr);
    va_end(argptr);
    Serial.print(debug_buf);
}

void smlog_none(const char *format, ...) {
    (void)format;
}
