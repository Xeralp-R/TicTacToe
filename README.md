# TicTacToe
A Qt implementation of the game Tic Tac Toe

## Overview
This project was created in fulfillment of the 
requirements for bonus points in our CS class.
For sir, please read [ProjectDocumentation.md](https://github.com/Xeralp-R/TicTacToe/blob/master/ProjectDocumentation.md).

## Features
* Decent design
* Accompaniment music: 2 new playlists!
* 2 robots: 1 designed by the cocreator Brent, and a randomized robot
* Tournament Mode: play 5 turns against the opponent
* Replay button
* Player names and Characters: now supports unicode!

## Running the Project
1. Download the open-source version of QT.
    - General:
        - The online installer is [here](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)
        - The offline installer is [here](https://www.qt.io/offline-installers)
        - Make sure you get the version marked QT5, as this was developed for that version
        - Remember to export the path correctly: use ` export PATH="$PATH:/wherever/qt/is/installed" ', replacing the words "wherever/qt/is/installed" with wherever Qt is installed on your computer.
    - Mac:
        - Homebrew: ` brew install qt@5 `
        - MacPorts: ` sudo port install qt5`
    - Linux:
        - Apt-get: ` sudo apt-get install qt5-default `
2. Download this project:
    - Download with git using the following command: ` git clone https://github.com/Xeralp-R/TicTacToe `
    - Alternatively, use the download code button on the top-right?
3. Run
    1. If you installed QT Creator:
        - Open the PRO file in QT Creator (Double click)
        - Use the run button on the bottom-left: it's color green
    2. If you didn't install QT Creator:
        - go to the pertinent directory
        - run ` qmake `
        - run ` make `
        - run ` ./TicTacToe `

In the future, I might make a DMG file for mac— I will also place it in this repository.

## Dependencies
If you're going to download directly from github, you will need QT to dynamically link it,
along with a C++ compiler— consider GCC, Clang, or MinGW.
Else— that is, if you're going to use the dmg— I don't think there are any dependencies.

## Contributors
Me and Brent Cristobal of PSHS

## License
[MIT](https://choosealicense.com/licenses/mit/)

## Credits
Extraordinary credit to Brent Cristobal.
