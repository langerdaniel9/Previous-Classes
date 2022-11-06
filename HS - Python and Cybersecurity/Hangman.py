import random

my_list = ["hangman", "dragon", "tiger", "octopus", "shark", "money", "school", "stadium", "biker", "whale", "sphinx"]
my_list2 = []
word = random.choice(my_list)


print("There are", len(word), "letters in this word.")
#print(word)

def start():
    guesses_left = 3
    correct_guesses = len(set(word))
    while guesses_left > -1 and correct_guesses != 0:
        print("You have", str(guesses_left), "wrong guesses left.\n")
        guess = input("Guess a letter. \n").lower()
        if len(guess) != 1:
            print("Please enter a single letter.")
            continue
        if guess in my_list2:
            print("You already entered that letter.")
            continue
        if guess not in my_list2:
            my_list2.append(guess)
        if guess in word:
            print("Good guess. That letter was in the word.")
            correct_guesses -= 1
            continue
        if guess not in word:
            print("That letter isn't in the word.")
            guesses_left -= 1
            continue
    if correct_guesses <= 1:
        print("Congratulations! You won the game.\nPlay again.")
    elif guesses_left <= 1:
        print("Sorry, you lost. Play again.")


start()
