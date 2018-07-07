#https://github.com/karulis/pybluez
#nb: need to install c++ compilers on windows for pip install pybluez
#https://techtutorialsx.com/2017/07/09/esp32-bluetooth-finding-the-device-with-python-and-btstack/

import bluetooth

devices = bluetooth.discover_devices(lookup_names=True)
print(type(devices))

print("Devices found: %s" % len(devices))

for item in devices:
    print(item)
