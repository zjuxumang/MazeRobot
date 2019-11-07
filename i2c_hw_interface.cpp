#include "i2c_hw_interface.h"

CubeI2C::CubeI2C(MicroBitI2C* i2c_port, uint8_t address)
    : i2c_port_(i2c_port),Addr(address)
      {
}

uint32_t CubeI2C::I2CRead(uint8_t reg_address, uint8_t* temp) {
  int result;
  result=I2CWrite2Bytes(reg_address,0);
  if (result !=0)
      return 1;
  wait_ms(10);
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

uint32_t CubeI2C::I2CWrite2Bytes(uint8_t value1, uint8_t value2) {
  int ret = 0;
  uint8_t temp[2];
  temp[0]=value1;
  temp[1]=value2;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)&temp, 2);
  if (ret !=0)
      return 1;
  return ret;
}

uint32_t CubeI2C::I2CWriteBuffer(uint8_t* buf, uint8_t length) {
  int ret = 0;
  ret = i2c_port_->write((uint8_t)Addr<<1, (const char *)buf, length);
  if (ret !=0)
      return 1;
  return ret;
}



