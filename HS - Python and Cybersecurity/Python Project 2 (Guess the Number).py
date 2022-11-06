import random
run = 0
value = random.randint(0, 20)
print("\nGuess a number between 0 and 20.")
while run == 0:
    number = input("Guess a number:\n")
    if not 0 <= int(number) <= 20:
        print("That's not a valid entry. Try again.\n")
    while number != value:
        if int(number) < int(value):
            print("The number you entered is less than the correct value.\n")
            break
        elif int(number) > int(value):
            print("The number you entered is greater than the correct value.\n")
            break
        elif int(number) == int(value):
            print("Congrats. You guessed the number.\n")
            run = 1
            break
