# Music Player Frontend

This is a storage system for artist names and their album titles. It has a graphical user interface.  My intent in writing this program was to use data structures in an applied setting. Artist names are stored in a binary search tree (ordered alphabetically).  Each node in the binary search tree contains a pointer to the head of a doubly linked list. It is in these lists that artists' albums are stored.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To run this code, you will need a C++ IDE (or familiarity with the command line) and the SFML graphics package.

### Installing

First, download SFML:

```
https://www.sfml-dev.org/download.php
```

Next, follow the "Getting Started" steps to ready SFML for the project (I used Microsoft VS 2017):

```
https://www.sfml-dev.org/tutorials/2.5/#getting-started
```

Finally, add the .cpp and .h files from this repository into a new project on your IDE.  If using VS 2017, note that you must also copy all the .dll files from  C:\...\SFML-2.5.0\bin  into your project folder  C:\...\VS_Project\VS_Project  before running the code.


## Customizing behavior

In InputBar.cpp, the function 'InputBar::process_get()' determines which strings are displayed when returning data to the user.  For example: if retrieving albums by artist Nils Frahm, it will display the string "Albums by Nils Frahm:" before the album list if it is nonempty; "There are no albums by Nils Frahm currently stored." is displayed if the list is empty.

These strings could be modified to change the user interface to another storage system that is similar in structure to an (Artist, Album) pairing.  One option would be to create a book storage system where the input year corresponds to the year the user finished reading a book.  

## Built With

* [Visual Studio 2017](https://docs.microsoft.com/en-us/visualstudio/) - The IDE used
* [SFML](https://www.sfml-dev.org/) - Graphics library

## Contributing

Please contact me if you are interested in contributing to this project.

## Authors

* **Zachary Barry** - [NamaChikara](https://github.com/NamaChikara)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Bjarne Stroustrup's text "Programming: Principles and Practices Using C++" is what lead me to this point.
