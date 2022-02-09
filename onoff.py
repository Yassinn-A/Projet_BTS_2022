#!/usr/bin/python3

import os
import logging
from time import sleep
from pijuice import PiJuice

pj = PiJuice(1,0x14)

# Make sure wakeup_enabled and wakeup_on_charge have the correct values
pj.rtcAlarm.SetWakeupEnabled(True)
pj.power.SetWakeUpOnCharge(0)

# Make sure power to the Raspberry Pi is stopped to not deplete
# the battery
pj.power.SetSystemPowerSwitch(0)
pj.power.SetPowerOff(30)
# Now turn off the system
os.system("sudo shutdown -h now")

