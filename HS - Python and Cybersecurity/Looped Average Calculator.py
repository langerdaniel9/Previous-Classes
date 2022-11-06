import statistics
d = {"100": 100, "A+": 100, "A": 95, "A-": 92, "B+": 88, "B": 85, "B-": 82, "C+": 77, "C": 75, "C-": 72, "D+": 68,
     "D": 65, "D-": 60, "F": 55, "F0": 0, "a+": 100, "a": 95, "a-": 92, "b+": 88, "b": 85, "b-": 82, "c+": 77, "c": 75,
     "c-": 72, "d+": 68, "d": 65, "d-": 60, "f": 55, "f0": 0, }
valid = 0
grades = []
num_grades = []
while valid == 0:
    print("Enter your letter grades one at a time.")
    print("Type 'done' when finished entering grades.")
    print(" ")
    var = input()
    if var == 'done':
        valid = 1
        break
    if var in d:
        grades.append(var)
    elif var not in d:
        invalid_input = True
        while invalid_input:
            print("Please enter a valid grade")
            var = input()
            if var in d:
                grades.append(var)
                break
for q in grades:
    num_grades.append(d[q])
avg = statistics.mean(num_grades)
if valid == 1:
    print("Your average is " + str(avg))
    if int(avg) == 100:
        print("A+")
    elif 90 <= int(avg) <= 99:
        print('A')
    elif 80 <= int(avg) <= 89:
        print("B")
    elif 70 <= int(avg) <= 79:
        print("C")
    elif 60 <= int(avg) <= 69:
        print("D")
    elif int(avg) < 60:
        print("F")
    else:
        print("I don't know how you managed to get this. Congrats, cause it should be impossible.")
