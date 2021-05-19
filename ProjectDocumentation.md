# Project Documentation

## What did you specifically contribute?

### Rex

To this project, I contributed much of the interface.
I was the one who thought of using QT Widgets,
and I was the one who translated some portions of the code
from the original beta version.
I was the one who also thought of the styling
(more on that in the reflections section)
albeit Brent was the one who thought of the words.


### Brent

I worked on most of the lore of the program, for example the tournament lore.
I worked on the Brent Robot, that fights against the player.
I had the idea to create an About Us page.
I contributed with the music playlist.

---

## What help did you get?

### Rex

I think I received a lot of help from the QT documentation:
for example, data on the push buttons can be found 
[here](https://doc.qt.io/qt-5/qpushbutton.html), 
data on the music player can be found
[here](https://doc.qt.io/qt-5/qmediaplayer.html),
and data on the incredible signal-slot system
[here](https://doc.qt.io/qt-5/signalsandslots.html).
I had a lot of help from the QT forum, which is the place
many beginners go (e.g. instructions for using 
XCode, Apple's designer, with QT can be found 
[here](https://www.qtcentre.org/threads/53249-Setting-QT-in-Xcode-step-by-step-guide))
and lots of help as well from Stack Overflow (e.g. instructions
for generating random numbers for the RandoBot are found 
[here](https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c)).

This time, I don't think I got that much help from Youtube:
the only set that I can think of would be 
[this](https://www.youtube.com/watch?v=8ntEQpg7gck&list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy&index=2),
but I find the tutorial unnecessarily complex for a
tic-tac-toe implementation.

### Brent
I received quite alot of help from mostly just Rex.
I was inexperienced with coding, let anone creating AI that fights against the player.
Rex was the one who kind of guided me and showed me how.
Also, without a doubt, Rex was the reason I understood how to make a function.

---

## Create a Demonstration Video.

[Done!](https://drive.google.com/file/d/1Ig_6GjcdQI-uke6YHI0jXRwiId0WQf-t/view?usp=sharing)

---

## What are your reflections?

### Rex

I think that in the process of creating this software, 
I learned a lot of principles that can also be applied
to other projects.
From this one project, I think I'm going to be able to summon
multiple learning log submissions!
A major example of this would be the signal-slot patterns,
that are part of QTs meta-object system:
they are quite useful for implementing something Wikipedia calls
the Observer Pattern, and are useful for communicating information 
between 2 disparate objects or classes.
Another major thing would be polymorphism and inheritance:
the robot, for example, is a pure interface, with 2 children
which each inherit the "robot move" function to do what they need to.
I can also say that I learned a lot more about pointers:
specifically, the fact that they are automatically generated
on the heap (meaning they have an essentially infinite lifetime,
and that they can only be destroyed by a delete then a null-ptr)
rather than the stack (which will destroy itself
upon exiting the programme),
Lastly, I think I was able to learn how to use CSS:
to properly style a widget in QT, you need to use something
called QSS, which is essentially an implementation of CSS for QT widgets.
I think all of those insights helped me significantly
in the creation of the game.

As for improvement, I think that far less improvement, per se,
can be done to these files than the other files:
the project, I think, is well-endowed visually,
and I think the interface in sensible enough.
Thus, I think improvements will now lie in adding features:
this would include such things as allowing for a larger board,
allowing for users to add their own playlists, etc.
However, I think that this project does well enough for me to say
that I am contented with the entire work and 
now would rather look forward to future projects
rather than dwell on further improvement.
Thank you!

### Brent

Well, omce I heard Rex say we were gonna make an AI, I thought 
he was mad, like a mad scientist. Sure enough, he was mad, but
also knew what he had to do and how to do them. I enjoyed being
his teammate. In the end, I've learned way more  about coding
than I thought I would from this project. I understood functions,
basic A.I and also responsibility. For the changes, I think we started with 
a program that runs tic-tac-toe, now we have a program that RUNS 
tic-tac-toe, well basically it's way better. I also enjoyed picking
out music as me and Rex had a small competition for it but in the end
chose both. All in all, a fun bonus project for me and Rex.
