#include "i2c_hw_interface.h"

CubeI2C::CubeI2C(MicroBitI2C* i2c_port, uint8_t address)
    : i2c_port_(i2c_port),Addr(address)
      {
}

uint32_t CubeI2C::I2CRead(uint8_t reg_address, uint8_t* temp) {
  int result;
  result = i2c_port_->write((uint8_t)Addr<<1, (const char *)&reg_address, 1);
  if (result !=0)
      return 1;
  result = i2c_port_->read((uint8_t)Addr<<1, (char *)temp, 1);
  if (result !=0)
      return 1;
  return 0;
}

uint32_t CubeI2C::I2CWrite(uint8_t reg_address, uint8_t value) {
  int ret = 0;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)&reg_address, 1);
  if (ret !=0)
      return 1;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)&value, 1);
  if (ret !=0)
      return 1;
  return ret;
}

uint32_t CubeI2C::I2CWrite16(uint8_t reg_address, uint16_t value) {
  int ret = 0;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)&reg_address, 1);
  if (ret !=0)
      return 1;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)&value, 2);
  if (ret !=0)
      return 1;
  return ret;
}



