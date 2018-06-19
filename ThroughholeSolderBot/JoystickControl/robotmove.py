#to send a file of gcode to the printer
from printrun.printcore import printcore
from printrun import gcoder
from time import sleep
#p=printcore('/dev/ttyUSB0',115200) # or p.printcore('COM3',115200) on Windows
p=printcore('COM14',115200) #on Windows
sleep(10)
print(0)

#gcode=[i.strip() for i in open('filename.gcode')] # or pass in your own array of gcode lines instead of reading from a file
#gcode = gcoder.LightGCode(gcode)
#p.startprint(gcode) # this will start a print

#If you need to interact with the printer:



# Steps per unit:
p.send_now("M92 X100.00 Y100.00 Z400.00 E161.30")


# Maximum feedrates (mm/s):
p.send_now("M203 X500.00 Y500.00 Z12.00 E120.00")


# Maximum Acceleration (mm/s2):
p.send_now("M201 X9000 Y9000 Z500 E10000")


# Acceleration: S=acceleration, T=retract acceleration
p.send_now("M204 S1500.00 T1500.00")


# Advanced variables: S=Min feedrate (mm/s), T=Min travel feedrate (mm/s), B=minimum segment time (ms), X=maximum XY jerk (mm/s),  Z=maximum Z jerk (mm/s),  E=maximum E jerk (mm/s)
p.send_now("M205 S0.00 T0.00 B20000 X10.00 Y10.00 Z0.20 E2.50")


#Home offset (mm):
p.send_now("M206 X0.00 Y0.00 Z0.00")


# PID settings:
#p.send_now("M301 P40.93 I4.88 D86.08")


# Retract: S=Length (mm) F:Speed (mm/m) Z: ZLift (mm)
p.send_now("M207 S3.00 F2700.00 Z0.00")


# Recover: S=Extra length (mm) F:Speed (mm/m)
p.send_now("M208 S0.00 F480.00")


# Auto-Retract: S=0 to disable, 1 to interpret extrude-only moves as retracts or recoveries
p.send_now("M209 S0")



#-------------------------------------------------------------------------------



p.send_now("G1 X50") # this will send M105 immediately, ahead of the rest of the print
sleep(5)
p.send_now("G1 X-50") # this will send M105 immediately, ahead of the rest of the print
sleep(5)
#p.pause() # use these to pause/resume the current print
#p.resume()
p.disconnect() # this is how you disconnect from the printer once you are done. This will also stop running prints.
