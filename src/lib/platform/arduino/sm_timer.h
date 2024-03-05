/*
  This file is part of the Arduino_PortentaH7_SE05X library.

  Copyright (c) 2024 Arduino SA

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef SM_TIMER_H_INC
#define SM_TIMER_H_INC

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* function used for delay loops */
void sm_sleep(uint32_t msec);

#ifdef __cplusplus
}
#endif

#endif //#ifndef SM_TIMER_H_INC
