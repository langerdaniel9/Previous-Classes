def encrypt(text, s):  # Defines the start of the function
    result = ""  # Defines result as a blank value, to be changed later

    # For every integer/character in the variable text:
    for i in range(len(text)):
        char = text[i]  # the variable 'char' will equal

        if char.isupper():  # If it meets this condition,
            # shift the character over 's' spaces to the right, starting
            result += chr((ord(char) + s - 65) % 26 + 65)
            # at 65, the unicode value of the uppercase alphabet.

        else:  # If it doesnt meet the previous condition,
            # shift the character over 's' spaces to the right, starting
            result += chr((ord(char) + s - 97) % 26 + 97)
            # at 97, the unicode value of the first letter of uppercase alphabet.

    return result  # ends the equation and returns result


text = "BUROSUCKS"  # defines the variable text as 'BUROSUCKS'
s = 4  # defines the variable s as '4'
print("Text  : " + text)  # It will print 'text' and the variable, text
# it will print 'shift' and the string value of variable s
print("Shift : " + str(s))
# it will print 'cypher' and the solution to the function above.
print("Cipher: " + encrypt(text, s))
