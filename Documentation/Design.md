# Design
__________

## UML Class Diagram

![image](https://user-images.githubusercontent.com/69856251/136705426-07eed840-d379-403a-873b-4ac59c868ec6.png)

_______________

## UML Sequence Diagram

![image](https://user-images.githubusercontent.com/69856251/136705433-aa31aaf3-7132-47f6-9ade-5bbb2ed68e0e.png)

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
