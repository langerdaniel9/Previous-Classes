d = {"A+": 100, "A": 95, "A-": 92, "B+": 88, "B": 85, "B-": 82, "C+": 77, "C": 75, "C-": 72, "D+": 68, "D": 65,
     "D-": 60, "F": 55, "a+": 100, "a": 95, "a-": 92, "b+": 88, "b": 85, "b-": 82, "c+": 77, "c": 75, "c-": 72,
     "d+": 68, "d": 65, "d-": 60, "f": 55, }

print("Enter your Math letter grade")
print(" ")
var1 = input()
if var1 not in d:
    invalid_input = True
    while invalid_input:
        print("Please enter a valid grade")
        var1 = input()
        if var1 in d:
            break

print("Enter your English letter grade")
print(" ")
var2 = input()
if var2 not in d:
    invalid_input = True
    while invalid_input:
        print("Please enter a valid grade")
        var2 = input()
        if var2 in d:
            break

print("Enter your History letter grade")
print(" ")
var3 = input()
if var3 not in d:
    invalid_input = True
    while invalid_input:
        print("Please enter a valid grade")
        var3 = input()
        if var3 in d:
            break

print("Enter your Science letter grade")
print(" ")
var4 = input()
if var4 not in d:
    invalid_input = True
    while invalid_input:
        print("Please enter a grade")
        var4 = input()
        if var4 in d:
            break

var5 = (int(d[var1])) + (int(d[var2])) + (int(d[var3])) + (int(d[var4]))
var6 = (int(var5) / 4)

print("Your average is " + str(var6))
if int(var6) == 100:
    print("A+")
elif 90 <= int(var6) <= 99:
    print('A')
elif 80 <= int(var6) <= 89:
    print("B")
elif 70 <= int(var6) <= 79:
    print("C")
elif 60 <= int(var6) <= 69:
    print("D")
elif int(var6) < 60:
    print("F")
