# Design
__________

## UML Class Diagram

[umlclass.pdf](https://github.com/TheCoolestMango/ContactGot/files/7317833/umlclass.pdf)

_______________

## UML Sequence Diagram

[seq diag.pdf](https://github.com/TheCoolestMango/ContactGot/files/7317834/seq.diag.pdf)

___________________

## SOLID principles

The SOLID principles were maintained as follows: 
* Single-responsiblity - Class Main window's only job is to create the table with desired columns, and Session class's job is to input the values of those columns.
* Open-closed - All classes are easily extendable and not modifiable 
* Liskov Substitution - was not implemented due to the small project scale
* Interface Segregation - the only two interfaces are split, both are always used by a user
* Dependency inversion - was not implemented due to the small project scale

____________________

## Design patterns

Our design pattern follows the Builder pattern:
* Instead of creating the entire table using a single class, the process is split and the Main Window acts as a Builder class
* Builder (main window) checks what the user has included in the checkboxes.
* Based on this information, builder includes property columns in the creation of the table
