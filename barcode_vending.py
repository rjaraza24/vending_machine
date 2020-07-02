import RPi.GPIO as GPIO
import os
import sys
import time
channel = 14

def cleanAndExit():
        print ("Cleaning...")
        GPIO.cleanup()
        print ("Bye!")
        sys.exit()


GPIO.setmode(GPIO.BCM)
GPIO.setup(channel, GPIO.OUT)

def relay_off(pin):
    GPIO.output(pin, GPIO.HIGH)  # Turn motor on


def relay_on(pin):
    GPIO.output(pin, GPIO.LOW)  # Turn motor off



number = ""

relay_off(channel)
while True: 
 try:


  number = input ("Enter number:")

  cream = "4800092113246" #cre
  choco = "4800092113253" #cho
  strawb = "4800092113260" #stra
  peanut = "4800092113284" #peanut
  butter = "4800092113277"
  pastillas = "4800092115288"
  ChoMuch = "4800092116513"
  MilkMuch = "4800092116537"
#ChoMuch
#MilkMuch
  if ( number == cream):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel) 
   print("cream")

  if ( number == choco):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("choco")

  if ( number == strawb):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("strawberry")

  if (number == peanut):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("peanut")
  if (number == butter):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("butter")
  if (number == pastillas):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("pastillas")
  if (number == ChoMuch):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("Mucho Choco")
  if (number == MilkMuch):
   relay_on(channel)
   time.sleep(5)
   relay_off(channel)
   print("Mucho Milky")
  else:
   relay_off(channel)
 except (KeyboardInterrupt, SystemExit):
    cleanAndExit()


