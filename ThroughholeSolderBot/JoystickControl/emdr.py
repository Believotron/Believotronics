import ctypes
import time

# Define necessary structures
class XINPUT_VIBRATION(ctypes.Structure):
    _fields_ = [("wLeftMotorSpeed", ctypes.c_ushort),
                ("wRightMotorSpeed", ctypes.c_ushort)]

xinput = ctypes.windll.xinput1_1  # Load Xinput.dll

# Set up function argument types and return type
XInputSetState = xinput.XInputSetState
XInputSetState.argtypes = [ctypes.c_uint, ctypes.POINTER(XINPUT_VIBRATION)]
XInputSetState.restype = ctypes.c_uint

# Now we're ready to call it.  Set left motor to 100%, right motor to 50%
# for controller 0
vibration = XINPUT_VIBRATION(65535, 32768)
XInputSetState(0, ctypes.byref(vibration))

# You can also create a helper function like this:
def set_vibration(controller, left_motor, right_motor):
    vibration = XINPUT_VIBRATION(int(left_motor * 65535), int(right_motor * 65535))
    XInputSetState(controller, ctypes.byref(vibration))

sleepTime = 0.005
dwellTime = 0.001
maxIntensity = 100

while 1:
    # Goesuppa
    for i in range(0,maxIntensity,1):
        set_vibration(0, i/100.0, 0)
        time.sleep(sleepTime)

    # Goesdowna
    for i in range(maxIntensity,0,-1):
        set_vibration(0, i/100.0, 0)
        time.sleep(sleepTime)

    set_vibration(0, 0, 0)
    time.sleep(dwellTime)

    # Goesuppa
    for i in range(0,maxIntensity,1):
        set_vibration(0, 0, i/100.0)
        time.sleep(sleepTime)

    # Goesdowna
    for i in range(maxIntensity,0,-1):
        set_vibration(0, 0, i/100.0)
        time.sleep(sleepTime)

    set_vibration(0, 0, 0)
    time.sleep(dwellTime)
