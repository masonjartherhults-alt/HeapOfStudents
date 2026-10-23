# HeapOfStudents

Read student data from a CSV file, print names and full records,
search by last name, and sort the students.

## Algorithm

```text
Address constructor:
    start street, city, state, and zip as empty strings

Address init:
    save street, city, state, and zip

printAddress:
    print street on one line
    print city, state, and zip on the next line

Date constructor:
    start month, day, and year at 0

Date init:
    split the date at /
    convert each part to an int
    save month, day, and year

printDate:
    if month is between 1 and 12
        print month name, day, and year
    otherwise print invalid date

Student constructor:
    start names as empty strings
    start credits at 0
    create an Address and two Dates on the heap
    save their pointers

Student init:
    split the CSV line at commas
    save first and last name
    send address fields to address init
    send each date to date init
    convert credits to an int

printStudent:
    print first and last name
    print address
    print birth date and graduation date
    print credits
    print a dividing line

getLastFirst:
    return last name, first name

getLastName:
    return last name

getFirstName:
    return first name

getCreditHours:
    return credit hours

Student destructor:
    delete the address
    delete both dates

loadStudents:
    open students.csv
    if the file cannot open
        print a message and return
    for each line
        remove a trailing carriage return if present
        skip empty lines
        create a Student on the heap
        initialize it with the line
        add its pointer to the vector
    close the file

printStudents:
    loop through the vector
    print each student's full record

showStudentNames:
    loop through the vector
    print each student's last name, first name

findStudent:
    ask for a last name
    start found as false
    loop through the vector
        check if the last name contains the search text
        if it matches
            print the full record
            set found to true
    if nothing matched
        print no students found

menu:
    display choices 0 through 6
    read the choice as a string
    if input ends, return 0
    return the choice

sortLast:
    compare last names alphabetically

sortFirst:
    compare first names alphabetically

sortCredits:
    compare credits from highest to lowest

delStudents:
    loop through the vector
    delete each Student
    clear the vector

main:
    create a vector of Student pointers
    load the students
    repeat until the user chooses 0
        get the menu choice
        run the selected function
        sort the vector if a sort option was chosen
        print a message for invalid choices
    delete the students
    exit
```

## Compile and run

```bash
make
make run
```

## Check memory

```bash
make valgrind
```

Use the menu, then choose 0 to quit.
Check the Valgrind report for memory leaks and errors.
