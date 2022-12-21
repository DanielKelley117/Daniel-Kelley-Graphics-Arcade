import pyttsx3
import pause
import sys
import random
import keyboard
#Takes in a command line argument
seconds = sys.argv[1]

#Welcomes user to the game
engine = pyttsx3.init()

engine.say("Hello. Welcome to Four Corners.")

engine.runAndWait()

seconds = str(seconds)


#Checks to see if a valid argument for seconds was entered, and defaults to 10 if an invalid argument is entered.
if seconds.isnumeric():
   engine.say("Each round will last " + seconds + " seconds.")
   engine.runAndWait()
   secondsNum = int(seconds)

else:
    engine.say("An invalid amount of seconds was entered, so each round will last 10 seconds.")
    engine.runAndWait()
    secondsNum = 10
    seconds = "10"

engine.say("You have " + seconds + " seconds to get to your first corner")

engine.runAndWait()
counter = 0
pause.seconds(secondsNum)
#The loop begins and continues until all of the rounds are played
while counter < 10:

    x = random.randint(1, 100)

#Depending on the value of x, one of the corners is selected.
    if x < 25:
        engine.say("Corner number 1.")
        engine.say("You are eliminated.")
        engine.runAndWait()

    if x >= 25 and x < 50:
        engine.say("Corner number 2.")
        engine.say("You are eliminated.")
        engine.runAndWait()

    if x >= 50 and x < 75:
        engine.say("Corner number 3.")
        engine.say("You are eliminated.")
        engine.runAndWait()


    if x >= 75 and x <= 100:
        engine.say("Corner number 4.")
        engine.say("You are eliminated.")
        engine.runAndWait()

#If the user enters b, the game stops. If the user enters anything else, the game continues
    engine.say("Type a to continue, or b to quit.")
    engine.runAndWait()



    if keyboard.read_key() == "b":
        break

    engine.say("You have" + seconds + " seconds to get to your next corner")
    engine.runAndWait()
    pause.seconds(secondsNum)
    counter += 1




#The program thanks the user for playing
engine.say("Thank you for playing!")
engine.runAndWait()


