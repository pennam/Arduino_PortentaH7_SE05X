/*
  This file is part of the Arduino_PortentaH7_SE05X library.

  Copyright (c) 2024 Arduino SA

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "../../platform/arduino/sm_i2c.h"
#include <Wire.h>

i2c_error_t axI2CInit(void **conn_ctx, const char *pDevName) {
    (void)conn_ctx;
    (void)pDevName;

    Wire1.begin();
    Wire1.setClock(400000);
    return I2C_OK;
}

void axI2CTerm(void *conn_ctx, int mode) {
    (void)conn_ctx;
    (void)mode;

    Wire1.end();
}

i2c_error_t axI2CWrite(void *conn_ctx, unsigned char bus, unsigned char addr, unsigned char *pTx, unsigned short txLen) {
    (void)conn_ctx;
    (void)bus;

    addr = addr >> 1;
    Wire1.beginTransmission(addr);
    Wire1.write(pTx, txLen);
    if (Wire1.endTransmission() != 0) {
        return I2C_FAILED;
    }

    return I2C_OK;
}

i2c_error_t axI2CRead(void *conn_ctx, unsigned char bus, unsigned char addr, unsigned char *pRx, unsigned short rxLen) {
    (void)conn_ctx;
    (void)bus;
    addr = addr >> 1;
    int retries = 20;

    while (Wire1.requestFrom((uint8_t)addr, (size_t)rxLen, (bool)true) != rxLen && retries--);

    for (size_t i = 0; Wire1.available(); i++) {
        pRx[i] = Wire1.read();
    }

    return I2C_OK;
}
