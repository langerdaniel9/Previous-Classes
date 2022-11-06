import random
d = {'rock': 1, 'paper': 2, 'scissors': 3}
rd = {1: 'rock', 2: 'paper', 3: 'scissors'}


while True:
    number = input(
        "Which one do you want to choose?\nRock, paper, or scissors?\n").lower()
    human = (d[number])
    computer = rd[(random.randint(1, 3))]
    print("computer put",  computer)
    computerVal = d[computer]
    if computerVal == human:
        print("It is a tie")
    elif computerVal == 1 and human == 3:
        print("Computer wins")
    elif computerVal == 1 and human == 2:
        print("Human wins")
    elif computerVal == 2 and human == 1:
        print("Computer wins")
    elif computerVal == 2 and human == 3:
        print("Human wins")
    elif computerVal == 3 and human == 1:
        print("Human wins")
    elif computerVal == 3 and human == 2:
        print("Computer wins")

    print("\n")
