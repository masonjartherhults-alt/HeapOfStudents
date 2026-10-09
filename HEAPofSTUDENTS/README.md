# HeapOfStudents

Progress:
     address and date are done
     student header is done
     student code will be done next week

Algorithm:

Address:
    start the address fields as emtpy strings
    intit saves street, city, state, and zip 
    print street on one line
    print city, state, and zip on the next line

Date:
    start month, day, and year at 0
    use stringstream to split the date at /
    convert each part to an int
    save month, day, and year
    find the month name in the array
    print month name, day, and year

Student (next week):
    split student data and commas
    save first and last name
    send address fields to address.init
    send each date to date.init
    convert credits to an int
    print student information
    return last name, first name

