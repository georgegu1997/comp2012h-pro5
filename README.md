# comp2012h-project5-register

#Author: GU Qiao

I write this project in the very similar struture as the makefile on the website shows.
doubltlinkedlist.h and hashtable.h provide two template container classes.
records.h and records.cpp implements the record classes used in the Register.
constants.h store the constants in the program, mainly related to the constraints of the input data.
utility.h and utility.cpp implement the hash functions and the index classes
htmlgenerator.h and htmlgenerator.cpp stores 4 functions that take list as input and generator the html file.
registermanager.h and registermanager.cpp implement the RegitserManeger class, which works like a database, stores all the data and provide kinds of interface to manipulate the information in the data base.
main.cpp is where the program starts, which contains all the UI information of the program. It also do some input format checking work.
