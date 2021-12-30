# CS120 Programming Final Exam

## Introduction

You are to create a doodle program that has a button. 

Every time the button is pressed it spawns a random jelly character that moves around on the screen by itself. 

If it goes off screen or is clicked on then it goes away. 

The program will save all of the objects to a text file such that when the program is launched again it will be as if we never stopped running the program. In otherwords, upon relaunching we should see the same jelly characters at the same positions from when we closed the program.

See the provided sample program to get a feel for how the program should behave.

Note that the way the jelly's move around can be customized and yours does not need to behave exactly like the demo.

## Requirement Details

You must use a `std::map` or `std::unordered_map` to create a mapping from an Enum to it's string name and then another map to go from the string name to the Enum. The Enum will reprsent all six of the possible jelly characters : Blue, Green, Grey, Purple, Red, and Yellow.

You must use these mappings when saving to and reading from the save file.

## To earn an Excellent Score

Add some polish the experience of this program. Anything that makes it feel nicer would be a plus.

Alternatively, you may add extra features, animations, or interactions to make it more complex and interesting.

After you have satisfied the requirements, try to add something that you think is fun.

# Create a ReadMe


Create a **`ReadMe.md`** markdown file that defines the following.

1. Your name, exam name, course name, term
2. Section describing anything incomplete about the Exam
3. Section describing something you're proud of about the Exam
4. If applicable, Section describing what was added to earn an Excellent Score
5. Section that lists the File Name and Line Number for all code requirements
    - one example is enough if there are multiple instances

# Grading Rubric

- [x] [**core**] Used C++ and `doodle` framework to make a program
- [x] [**core**] Program has a working button to spawn random Jelly objects onto the screen
- [x] [**core**] Jelly objects that move off screen get deleted
- [x] [**core**] Jelly objects that are clicked on with the mouse get deleted
- [x] [**core**] Exiting the program by closing the window causes the scene to be saved to a text file
- [x] [**core**] If the scene text file exists then on start up the scene will be loaded
- [x] [**core**] Made good use of File IO with the `ifstream` and `ofstream` types
- [x] [**core**] Created a `std::map` or `std::unordered_map` with a jelly enum key and a string value to convert the enum to a string and use it for writing to the save file
- [x] [**core**] Created a `std::map` or `std::unordered_map` with a string key and a jelly enum value to convert the string to an enum and use it for reading from the save file
- [x] [**core**] Created and used your own `namespace`
- [x] [**core**] Make good use of functions
- [x] [**core**] Make good use of `class`/`struct`
- [x] [**core**] Code is reasonably organized across multiple files, so that there are no big monolithic source code files.
- [x] Uses the most appropriate loop statements for the kind loop that is done
- [x] Make good use of References
- [x] Make good use of `std::string`
- [x] Make good use of `std::vector`
- [x] Make good use of `int`
- [x] Make good use of `double`
- [x] Make good use of `bool`
- [x] Used exceptions for error checking at least one time
- [ ] All variables are initialized when **defined**.
- [ ] If using shared global variables then they are defined in a header file with the `inline` keyword.
- [x] Constants are defined as `constexpr` whenever possible
- [ ] If using fixed size arrays then they are defined with `std::array`
- [ ] If functions are defined in header files then they are marked as `inline` or `constexpr`
- [x] Window title contains student name
- [x] All source files compile without warnings and without errors.
- [x] Warning level 4 is set and treat warnings as errors is set.
- [x] Correct files submitted. No unnecessary files submitted.
- [x] **All** Source Code has a proper header comment: Name, Exam Name, Course Number, Term & Year.
- [x] Followed the appropriate Code Quality Guidelines and Code Style Guidelines.
- [x] Created a properly filled out `ReadMe.md` file

Scores for the Exam will be given as the following:

Score        | Assessment
------------ | ----------
Zero         | Nothing turned in at all
Failing      | Close to meeting core requirements
Rudimentary  | Meets all of the core requirements
Satisfactory | Close to meeting all requirements
Good         | Clearly meets all requirements 
Excellent    | High quality, well beyond the requirements

# Submission

You will submit a zip file of your work. Make sure it has all the required files needed to build and run the program in visual studio. It should not have unnecessary files like auto generated files.

Make sure the zip also contains your ReadMe.md file

The name of the ZIP file must follow this naming convention: `[class_name]_[login]_jelly.zip`

For example, if a student had the login name fun.frank then the appropriate filename would be `cs120_fun.frank_jelly.zip`.

## Unnecessary Files

Your repo must **NOT** contain

User-specific files

    *.suo
    *.user

Build results

    [Dd]ebug/
    [Rr]elease/
    x64/

Visual Studio Cache Files/Directories

    .vs/
