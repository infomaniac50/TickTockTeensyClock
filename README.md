## Tick Tock Teensy Clock

### Parts

 - Teensy 3.1
 - LinkSprite LCD Shield
 - Sparkfun Teensy Arduino Adapter Shield

### Setting the Time

```bash
# Print unix timestamp to shell
echo -n "T$(date +"%s")" # -> T1444522812
```
http://unixtimesta.mp/1444522812

Copy and paste this timestamp to the Teensy Serial console.