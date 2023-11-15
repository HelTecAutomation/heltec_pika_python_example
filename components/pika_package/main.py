import PikaStdDevice
import time
gpio =  PikaStdDevice.GPIO()
gpio.setPin("P21")
gpio.setId(21)
gpio.setMode("out")
gpio.enable()
while True:
    gpio.high();
    time.sleep_ms(500)
    gpio.low();
    time.sleep_ms(500)
