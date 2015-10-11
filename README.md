## Tick Tock Teensy Clock

### Parts

 - [Teensy 3.1](http://www.pjrc.com/teensy/index.html)
 - [LinkSprite LCD Shield](https://www.sparkfun.com/products/13293)
 - [Sparkfun Teensy Arduino Adapter Shield](https://www.sparkfun.com/products/13288)

### Setting the Time

```bash
# Print unix timestamp to shell
echo -n "T$(date +"%s")" # -> T1444522812
```
http://unixtimesta.mp/1444522812

Copy and paste this timestamp to the Teensy Serial console.