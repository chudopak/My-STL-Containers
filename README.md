# About The Project
In this project I re-implement three **STL** containers:
- [vector](http://www.cplusplus.com/reference/vector/vector/)
- [map](http://www.cplusplus.com/reference/map/map/)
- [stack](http://www.cplusplus.com/reference/stack/stack/)

The implementation of these containers contains all the methods of the standard ***C++98***.

## Used Data Structures
- **Binary Search Tree** for ***map***
- **Dynamic array** for ***vector***

**Stack** is container adaptor, so it does not have its own data structure.

## Tests
I made my own tests, which can be run by doing `make` and then run `./allTests`.
If you don't trust me :scream: :cry: then do `make tester` and it will donwload and run tester from github.

## Notes
Re-implementing those containers wasn't meaningful to me so I found it to be boring. But now I have a better understanding of **binary search trees** and operations on them. Also I lost a ton of nerves when forgot to mark function as `const` and it was Segmentation fault every time I run tests. :smiling_face_with_tear: :exploding_head: